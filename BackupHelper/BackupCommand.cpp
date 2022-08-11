#include "pch.h"
#include "BackupCommand.h"
#include "Backup.h"
#include "ConfigFile.h"
#include "Tools.h"
#include "ScheduleAPI.h"
#include <filesystem>
using namespace std;

void CmdReloadConfig(Player *p)
{
    ini.Reset();
    auto res = ini.LoadFile(_CONFIG_FILE);
    if (res < 0)
    {
        SendFeedback(p, "Failed to open Config File!");
    }
    else
    {
        SendFeedback(p, "Config File reloaded.");
    }
}

void CmdBackup(Player* p)
{
    Player* oldp = nowPlayer;
    nowPlayer = p;
    if (isWorking)
    {
        SendFeedback(p, "An existing backup is working now...");
        nowPlayer = oldp;
    }
    else
        Schedule::nextTick(StartBackup);
}

void CmdCancel(Player* p)
{
    if (isWorking)
    {
        isWorking = false;
        nowPlayer = nullptr;
        SendFeedback(p, "Backup is Canceled.");
    }
    else
    {
        SendFeedback(p, "No backup is working now.");
    }
    if (ini.GetBoolValue("BackFile", "isBack", false)) {
        ini.SetBoolValue("BackFile", "isBack", false);
        ini.SaveFile(_CONFIG_FILE);
        std::filesystem::remove_all("./plugins/BackupHelper/temp1/");
        SendFeedback(p, "Recover is Canceled.");
    }
}

//接到回档指令，回档前文件解压
void CmdRecoverBefore(Player* p, int recover_Num)
{
    Player* oldp = nowPlayer;
    nowPlayer = p;
    if (isWorking)
    {
        SendFeedback(p, "An existing task is working now...Please wait and try again");
        nowPlayer = oldp;
    }
    else 
        Schedule::nextTick([recover_Num] {
        StartRecover(recover_Num);
            });
}
//列出存在的存档备份
void CmdListBackup(Player* player, int limit)
{
    backupList = getAllBackup();
    if (backupList.empty()) {
        SendFeedback(player, "No Backup Files");
        return;
    }
    int totalSize = backupList.size();
    int maxNum = totalSize < limit ? totalSize : limit;
    SendFeedback(player, "使用存档文件前的数字选择回档文件");
    for (int i = 0; i < maxNum; i++) {
        SendFeedback(player,"[{}]:{}", i, backupList[i].c_str());
    }
}

//重启时调用
void RecoverWorld()
{
    bool isBack = ini.GetBoolValue("BackFile", "isBack", false);
    if (isBack) {
        SendFeedback(nullptr, "正在回档......");
        std::string worldName = ini.GetValue("BackFile", "worldName", "Bedrock level");
        if (!CopyRecoverFile(worldName)) {
            ini.SetBoolValue("BackFile", "isBack", false);
            ini.SaveFile(_CONFIG_FILE);
            SendFeedback(nullptr, "回档失败！");
            return;
        }
        ini.SetBoolValue("BackFile", "isBack", false);
        ini.SaveFile(_CONFIG_FILE);
        SendFeedback(nullptr, "回档成功");
    }
}

#ifdef LEGACY_COMMAND

#include "MC/CommandContext.hpp"
#include "MC/CommandOrigin.hpp"
THook(bool, "?executeCommand@MinecraftCommands@@QEBA?AUMCRESULT@@V?$shared_ptr@VCommandContext@@@std@@_N@Z",
    MinecraftCommands* _this, unsigned int* a2, std::shared_ptr<CommandContext> x, char a4)
{
    Player* player = (Player *)x->getOrigin().getPlayer();
    string cmd = x->getCmd();
    if (cmd.front() == '/')
        cmd = cmd.substr(1);
    if (cmd.empty())
        return original(_this, a2, x, a4);
    if (cmd == "backup reload")
    {
        CmdReloadConfig(player);
        return false;
    }
    else if (cmd == "backup")
    {
        CmdBackup(player);
        return false;
    }
    else if (cmd == "backup cancel")
    {
        CmdCancel(player);
        return false;
    }
    return original(_this, a2, x, a4);
}

#else

using namespace RegisterCommandHelper;

void BackupCommand::execute(CommandOrigin const& ori, CommandOutput& outp) const
{
    Player* player = (Player*)ori.getPlayer();
    if (!op_isSet) {
        CmdBackup(player);
        return;
    }
    switch (op)
    {
    case BackupOP::reload:
        CmdReloadConfig(player);
        break;
    case BackupOP::cancel:
        CmdCancel(player);
        break;
    case BackupOP::list:
        CmdListBackup(player,100);
        break;
    case BackupOP::recover:
        CmdRecoverBefore(player,BackupCommand::recover_Num);
        break;
    default:
        logger.warn("未知操作！");
    }
}

void BackupCommand::setup(CommandRegistry* registry) {
    registry->registerCommand(
        "backup", "Create a backup", CommandPermissionLevel::GameMasters, { (CommandFlagValue)0 },
        { (CommandFlagValue)0x80 });
    registry->addEnum<BackupOP>("operation",
        {
                {"cancel", BackupOP::cancel},
                {"reload", BackupOP::reload},
                {"list", BackupOP::list},
        });
    registry->addEnum<BackupOP>("operation_recover",
        {
                {"recover", BackupOP::recover},
        });

    auto action = makeMandatory<CommandParameterDataType::ENUM>(&BackupCommand::op, "operation", "operation", &BackupCommand::op_isSet);
    auto actionRecover = makeMandatory<CommandParameterDataType::ENUM>(&BackupCommand::op, "operation", "operation_recover", &BackupCommand::op_isSet);
    
    actionRecover.addOptions(CommandParameterOption::EnumAutocompleteExpansion);

    auto recoverParam = makeMandatory(&BackupCommand::recover_Num, "Num", &BackupCommand::num_isSet);

    registry->registerOverload<BackupCommand>("backup");
    registry->registerOverload<BackupCommand>("backup",action);
    registry->registerOverload<BackupCommand>("backup",actionRecover,recoverParam);
}
#endif //LEGACY_COMMAND