#include "pch.h"
#include "framework.h"
#include <string>
#include <EventAPI.h>
#include <LoggerAPI.h>
#include <LLAPI.h>
#include <RegCommandAPI.h>
#include <MC/CommandOrigin.hpp>
#include <MC/CommandOutput.hpp>
//#include <MC/CommandPosition.hpp>
#include <MC/CommandRegistry.hpp>
#include "SimpleIni.h"
using namespace std;

#define _VER "1.5.3"
#define _CONF_PATH "plugins/BanExplosion/config.ini"

CSimpleIniA ini;
Logger logger("BanExplosion");

//Utils
std::string Raw_GetEntityTypeName(Actor* actor)
{
    return SymCall("?EntityTypeToString@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4ActorType@@W4ActorTypeNamespaceRules@@@Z",
        string, int, int)
        (actor->getEntityTypeId(), 1);
}

// 防爆
bool suspend = false;

// ===== onExplode & onBedExplode =====
THook(void, "?explode@Level@@UEAAXAEAVBlockSource@@PEAVActor@@AEBVVec3@@M_N3M3@Z",
    Level* _this, BlockSource* bs, Actor* actor, Vec3* pos, float power, bool isFire, bool isDestroy, float range, bool a9)
{
    if (!suspend)
    {
        if (actor)
        {
            //常规
            string name = Raw_GetEntityTypeName(actor);
            if (ini.GetBoolValue(name.c_str(), "NoExplosion"))
                return;
            if (ini.GetBoolValue(name.c_str(), "NoDestroyBlock"))
                isDestroy = false;
        }
        else
        {
            //床
            if (ini.GetBoolValue("minecraft:bed", "NoExplosion"))
                return;
            if (ini.GetBoolValue("minecraft:bed", "NoDestroyBlock"))
                isDestroy = false;
        }
    }
    original(_this, bs, actor, pos, power, isFire, isDestroy, range, a9);
}

// ===== onRespawnAnchorExplode =====
THook(void, "?explode@RespawnAnchorBlock@@CAXAEAVPlayer@@AEBVBlockPos@@AEAVBlockSource@@AEAVLevel@@@Z",
    void* _this, Player* pl, BlockPos* bp, BlockSource* bs, Level* level)
{
    if (!suspend && ini.GetBoolValue("minecraft:respawn_anchor", "NoExplosion"))
        return;
    return original(_this, pl, bp, bs, level);
}

// ===== onWitherBossDestroy =====
THook(void, "?_destroyBlocks@WitherBoss@@AEAAXAEAVLevel@@AEBVAABB@@AEAVBlockSource@@H@Z",
    void* _this, Level* a2, AABB* a3, BlockSource* a4, int a5)
{
    if (ini.GetBoolValue("minecraft:wither", "NoDestroyBlock"))
        return;
    original(_this, a2, a3, a4, a5);
}

// ===== onWitherBossDestroy =====
THook(bool, "?canDestroy@WitherBoss@@SA_NAEBVBlock@@@Z",
    Block *bl)
{
    if (ini.GetBoolValue("minecraft:wither", "NoDestroyBlock"))
        return false;
    return original(bl);
}

bool ReloadIni()
{
    ini.Reset();
    return ini.LoadFile(_CONF_PATH) == 0;
}

class BanExplosionCommand :
    public Command
{
public:
    void execute(CommandOrigin const& ori, CommandOutput& output) const override
    {
        switch (op)
        {
        case off:
            suspend = true;
            logger.info("=== 自定义防爆规则已临时关闭 ===");
            break;
        case on:
            suspend = false;
            logger.info("=== 自定义防爆规则已启用 ===");
            break;
        case reload:
            if (ReloadIni())
                logger.info("配置文件已重新加载。");
            else
                logger.error("配置文件解析失败！插件将不会正常工作");
            break;
        default:
            logger.warn("未知操作！");
        }
    }
    enum EXPOP : int
    {
        off = 1,
        on = 2,
        reload = 3
    } op;
    static void setup(CommandRegistry* registry)
    {
        using RegisterCommandHelper::makeMandatory;
        registry->registerCommand(
            "banexp",
            "Control custom explosion rule",
            CommandPermissionLevel::Console,
            { (CommandFlagValue)0 }, 
            { (CommandFlagValue)0x80 }
        );
        registry->addEnum<BanExplosionCommand::EXPOP>(
            "EXPOP", 
            { { "off", EXPOP::off } , 
            { "on", EXPOP::on} , 
            { "reload", EXPOP::reload} }
        );
        registry->registerOverload<BanExplosionCommand>(
            "Banexp", 
            makeMandatory<CommandParameterDataType::ENUM>(&BanExplosionCommand::op, "operator", "EXPOP")
            );
    }
};

// Main

void entry()
{
    ini.SetUnicode(true);
    auto res = ini.LoadFile(_CONF_PATH);
    if (res < 0)
    {
        logger.error("防爆插件加载配置文件失败！");
        logger.error("插件将不会正常工作。");
        return;
    }
    LL::registerPlugin("BanExplosion", "BanExplosion自定义防爆插件", LL::Version(1, 5, 3),
        "https://github.com/yqs112358/LLPlugins", "GPL-3");

    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent ev) {
        auto& reg = ev.mCommandRegistry;
        BanExplosionCommand::setup(reg);
        return true;
        });

    logger.info(string("BanExplosion自定义防爆插件-已装载  当前版本：") + _VER);
    logger.info(string("配置文件位于：") + _CONF_PATH);
    logger.info("作者：yqs112358   首发平台：MineBBS");
    logger.info("欲联系作者可前往MineBBS论坛");
}