#include "pch.h"
#include <filesystem>
#include "ConfigFile.h"
#include "BackupCommand.h"
#include <TranslationAPI.h>
#include "Backup.h"
#include "Tools.h"
using namespace std;

LL::Version ver(2, 0, 7);
CSimpleIniA ini;

Logger logger("BackupHelper");

// ===== onConsoleCmd =====
THook(bool, "??$inner_enqueue@$0A@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$SPSCQueue@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$0CAA@@@AEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
    void* _this, string& cmd)
{
    if (cmd.front() == '/')
        cmd = cmd.substr(1);
    if (cmd == "stop" && isWorking)
    {
        ErrorOutput("在备份过程中请不要stop！");
        return false;
    }
    return original(_this, cmd);
}

//存档开始加载前替换存档文件
//此函数是BDS在读取server..properties文件的配置，并在BDS启动完成后构析掉_this
THook(void, "??0PropertiesSettings@@QEAA@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
    void* _this, void* a2)
{
    RecoverWorld();
    return original(_this, a2);
}

bool Raw_IniOpen(const string& path, const std::string& defContent)
{
    if (!filesystem::exists(path))
    {
        //创建新的
        filesystem::create_directories(filesystem::path(path).remove_filename().u8string());

        ofstream iniFile(path);
        if (iniFile.is_open() && defContent != "")
            iniFile << defContent;
        iniFile.close();
    }

    //已存在
    ini.SetUnicode(true);
    auto res = ini.LoadFile(path.c_str());
    if (res < 0)
    {
        ErrorOutput("Failed to open Config File!");
        return false;
    }
    else
    {
        return true;
    }
}

void entry()
{
    _set_se_translator(seh_exception::TranslateSEHtoCE);

    LL::registerPlugin("BackupHelper", "One command to backup your level", ver, {
        {"GitHub","https://github.com/yqs112358/LLPlugins"} });

    Raw_IniOpen(_CONFIG_FILE,"");
    Translation::load(string("plugins/BackupHelper/LangPack/") + ini.GetValue("Main", "Language", "en_US") + ".json");

    
	logger.info("BackupHelper存档备份助手-已装载  当前版本：{}", ver.toString());
    logger.info("OP/后台命令： backup 开始备份");
    logger.info("OP/后台命令： backup reload 重新加载配置文件");
    logger.info("作者：yqs112358   首发平台：MineBBS");
    logger.info("欲联系作者可前往MineBBS论坛");

    //Cleanup Old
    if (filesystem::exists("plugins/BackupHelper.lxl.js"))
        filesystem::remove("plugins/BackupHelper.lxl.js");
    if (filesystem::exists("plugins/BackupHelper/BackupRunner.exe"))
        filesystem::remove("plugins/BackupHelper/BackupRunner.exe");

    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent e) {

#ifdef LEGACY_COMMAND
        //e.mCommandRegistry->registerCommand("backup", "Create a backup", CommandPermissionLevel::GameMasters, { (CommandFlagValue)0 },
        //    { (CommandFlagValue)0x80 });
#else
        BackupCommand::setup(e.mCommandRegistry);
#endif
        return true;
    });
}