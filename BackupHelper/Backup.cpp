#include "pch.h"
#include "ConfigFile.h"
#include "Backup.h"
#include "Tools.h"
#include <shellapi.h>
#include <string>
#include <thread>
#include <filesystem>
#include <regex>
using namespace std;

#define TEMP_DIR "./plugins/BackupHelper/temp/"
#define TEMP1_DIR "./plugins/BackupHelper/temp1/"
#define ZIP_PATH ".\\plugins\\BackupHelper\\7za.exe"

bool isWorking = false;
Player* nowPlayer = nullptr;
std::vector<std::string> backupList = {};

struct SnapshotFilenameAndLength
{
	string path;
	size_t size;
};

void ResumeBackup();

void SuccessEnd()
{
    SendFeedback(nowPlayer, "备份成功结束");
    nowPlayer = nullptr;
    // The isWorking assignment here has been moved to line 321
}

void FailEnd(int code=-1)
{
    SendFeedback(nowPlayer, string("备份失败！") + (code == -1 ? "" : "错误码：" + to_string(code)));
    ResumeBackup();
    nowPlayer = nullptr;
    isWorking = false;
}

void ControlResourceUsage(HANDLE process)
{
    //Job
    HANDLE hJob = CreateJobObject(NULL, L"BACKUP_HELPER_HELP_PROGRAM");
    if (hJob)
    {
        JOBOBJECT_BASIC_LIMIT_INFORMATION limit = { 0 };
        limit.PriorityClass = BELOW_NORMAL_PRIORITY_CLASS;
        limit.LimitFlags = JOB_OBJECT_LIMIT_PRIORITY_CLASS;

        SetInformationJobObject(hJob, JobObjectBasicLimitInformation, &limit, sizeof(limit));
        AssignProcessToJobObject(hJob, process);
    }

    //CPU Limit
    SYSTEM_INFO si;
    memset(&si, 0, sizeof(SYSTEM_INFO));
    GetSystemInfo(&si);
    DWORD cpuCnt = si.dwNumberOfProcessors;
    DWORD cpuMask = 1;
    if (cpuCnt > 1)
    {
        if (cpuCnt % 2 == 1)
            cpuCnt -= 1;
        cpuMask = int(sqrt(1 << cpuCnt)) - 1;    //sqrt(2^n)-1
    }
    SetProcessAffinityMask(process, cpuMask);
}

void ClearOldBackup()
{
    int days = ini.GetLongValue("Main", "MaxStorageTime", -1);
    if (days < 0)
        return;
    SendFeedback(nowPlayer, "备份最长保存时间：" + to_string(days) + "天");

    time_t timeStamp = time(NULL) - days * 86400;
    wstring dirBackup = str2wstr(ini.GetValue("Main", "BackupPath", "backup"));
    wstring dirFind = dirBackup + L"\\*";

    WIN32_FIND_DATA findFileData;
    ULARGE_INTEGER createTime;
    int clearCount = 0;

    HANDLE hFind = FindFirstFile(dirFind.c_str(), &findFileData);
    if (hFind == INVALID_HANDLE_VALUE)
    {
        SendFeedback(nowPlayer, "Fail to locate old backups.");
        return;
    }
    do
    {
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            continue;
        else
        {
            createTime.LowPart = findFileData.ftCreationTime.dwLowDateTime;
            createTime.HighPart = findFileData.ftCreationTime.dwHighDateTime;
            if (createTime.QuadPart / 10000000 - 11644473600 < (ULONGLONG)timeStamp)
            {
                DeleteFile((dirBackup + L"\\" + findFileData.cFileName).c_str());
                ++clearCount;
            }
        }
    } while (FindNextFile(hFind, &findFileData));
    FindClose(hFind);

    if (clearCount > 0)
        SendFeedback(nowPlayer, to_string(clearCount) + " old backups cleaned.");
    return;
}

void CleanTempDir()
{
    error_code code;
    filesystem::remove_all(filesystem::path(TEMP_DIR),code);
}

bool CopyFiles(const string &worldName, vector<SnapshotFilenameAndLength>& files)
{
    SendFeedback(nowPlayer, "已抓取到BDS待备份文件清单。正在处理...");
    SendFeedback(nowPlayer, "正在复制文件...");

    //Copy Files
    CleanTempDir();
    error_code ec;
    filesystem::create_directories(TEMP_DIR,ec);
    ec.clear();
    
    filesystem::copy(str2wstr("./worlds/" + worldName), str2wstr(TEMP_DIR + worldName), std::filesystem::copy_options::recursive,ec);
    if (ec.value() != 0)
    {
        SendFeedback(nowPlayer, "Failed to copy save files!\n" + ec.message());
        FailEnd(GetLastError());
        return false;
    }

    //Truncate
    for (auto& file : files)
    {
        string toFile = TEMP_DIR + file.path;

        LARGE_INTEGER pos;
        pos.QuadPart = file.size;
        LARGE_INTEGER curPos;
        HANDLE hSaveFile = CreateFileW(str2wstr(toFile).c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, 0);

        if (hSaveFile == INVALID_HANDLE_VALUE || !SetFilePointerEx(hSaveFile, pos, &curPos, FILE_BEGIN)
            || !SetEndOfFile(hSaveFile))
        {
            SendFeedback(nowPlayer, "Failed to truncate " + toFile + "!");
            FailEnd(GetLastError());
            return false;
        }
        CloseHandle(hSaveFile);
    }
    SendFeedback(nowPlayer, "压缩过程可能花费相当长的时间，请耐心等待");
    return true;
}

bool ZipFiles(const string &worldName)
{
    try
    {
        //Get Name
        char timeStr[32];
        time_t nowtime;
        time(&nowtime);
        struct tm* info = localtime(&nowtime);
        strftime(timeStr, sizeof(timeStr), "%Y-%m-%d_%H-%M-%S", info);

        string backupPath = ini.GetValue("Main", "BackupPath", "backup");
        int level = ini.GetLongValue("Main", "Compress", 0);

        //Prepare command line
        char tmpParas[_MAX_PATH * 4] = { 0 };
        sprintf(tmpParas, "a \"%s\\%s_%s.7z\" \"%s%s\" -sdel -mx%d -mmt"
            , backupPath.c_str(), worldName.c_str(), timeStr, TEMP_DIR, worldName.c_str(), level);

        wchar_t paras[_MAX_PATH * 4] = { 0 };
        str2wstr(tmpParas).copy(paras, strlen(tmpParas), 0);

        DWORD maxWait = ini.GetLongValue("Main", "MaxWaitForZip", 0);
        if (maxWait <= 0)
            maxWait = 0xFFFFFFFF;
        else
            maxWait *= 1000;

        //Start Process
        wstring zipPath = str2wstr(ZIP_PATH);
        SHELLEXECUTEINFO sh = { sizeof(SHELLEXECUTEINFO) };
        sh.fMask = SEE_MASK_NOCLOSEPROCESS;
        sh.hwnd = NULL;
        sh.lpVerb = L"open";
        sh.nShow = SW_HIDE;
        sh.lpFile = zipPath.c_str();
        sh.lpParameters = paras;
        if (!ShellExecuteEx(&sh))
        {
            SendFeedback(nowPlayer, "Fail to create Zip process!");
            FailEnd(GetLastError());
            return false;
        }
        
        ControlResourceUsage(sh.hProcess);
        SetPriorityClass(sh.hProcess, BELOW_NORMAL_PRIORITY_CLASS);

        //Wait
        DWORD res;
        if ((res = WaitForSingleObject(sh.hProcess, maxWait)) == WAIT_TIMEOUT || res == WAIT_FAILED)
        {
            SendFeedback(nowPlayer, "Zip process timeout!");
            FailEnd(GetLastError());
        }
        CloseHandle(sh.hProcess);
    }
    catch (const seh_exception& e)
    {
        SendFeedback(nowPlayer, "Exception in zip process! Error Code:" + to_string(e.code()));
        FailEnd(GetLastError());
        return false;
    }
    catch (const exception& e)
    {
        SendFeedback(nowPlayer, string("Exception in zip process!\n") + e.what());
        FailEnd(GetLastError());
        return false;
    }
    return true;
}

bool UnzipFiles(const string& fileName)
{
    try
    {
        //Get Name

        string backupPath = ini.GetValue("Main", "BackupPath", "backup");
        int level = ini.GetLongValue("Main", "Compress", 0);

        //Prepare command line
        char tmpParas[_MAX_PATH * 4] = { 0 };
        sprintf(tmpParas, "x \"%s\\%s\" -o%s"
            , backupPath.c_str(), fileName.c_str(), TEMP1_DIR);

        wchar_t paras[_MAX_PATH * 4] = { 0 };
        str2wstr(tmpParas).copy(paras, strlen(tmpParas), 0);
        filesystem::remove_all(TEMP1_DIR);

        DWORD maxWait = ini.GetLongValue("Main", "MaxWaitForZip", 0);
        if (maxWait <= 0)
            maxWait = 0xFFFFFFFF;
        else
            maxWait *= 1000;

        //Start Process
        wstring zipPath = str2wstr(ZIP_PATH);
        SHELLEXECUTEINFO sh = { sizeof(SHELLEXECUTEINFO) };
        sh.fMask = SEE_MASK_NOCLOSEPROCESS;
        sh.hwnd = NULL;
        sh.lpVerb = L"open";
        sh.nShow = SW_HIDE;
        sh.lpFile = zipPath.c_str();
        sh.lpParameters = paras;
        if (!ShellExecuteEx(&sh))
        {
            SendFeedback(nowPlayer, "Fail to Unzip process!");
            //FailEnd(GetLastError());
            return false;
        }

        ControlResourceUsage(sh.hProcess);
        SetPriorityClass(sh.hProcess, BELOW_NORMAL_PRIORITY_CLASS);

        //Wait
        DWORD res;
        if ((res = WaitForSingleObject(sh.hProcess, maxWait)) == WAIT_TIMEOUT || res == WAIT_FAILED)
        {
            SendFeedback(nowPlayer, "Unzip process timeout!");
            //FailEnd(GetLastError());
        }
        CloseHandle(sh.hProcess);
    }
    catch (const seh_exception& e)
    {
        SendFeedback(nowPlayer, "Exception in unzip process! Error Code:" + to_string(e.code()));
        //FailEnd(GetLastError());
        return false;
    }
    catch (const exception& e)
    {
        SendFeedback(nowPlayer, string("Exception in unzip process!\n") + e.what());
        //FailEnd(GetLastError());
        return false;
    }
    ini.SetBoolValue("BackFile", "isBack", true);
    ini.SaveFile(_CONFIG_FILE);
    return true;
}

std::vector<std::string> getAllBackup() {
    string backupPath = ini.GetValue("Main", "BackupPath", "backup");
    filesystem::directory_entry entry(backupPath);
    regex isBackFile(".*7z");
    std::vector<std::string> backupList;
    if (entry.status().type() == filesystem::file_type::directory) {
        for (const auto& iter : filesystem::directory_iterator(backupPath)) {
            string str = iter.path().filename().string();
            if (std::regex_match(str, isBackFile)) {
                backupList.push_back(str);
            }
        }
    }
    std::reverse(backupList.begin(), backupList.end());
    return backupList;
}

bool CopyRecoverFile(const string& worldName) {
    std::error_code error;
    //判断回档文件存在
    auto file_status = std::filesystem::status(TEMP1_DIR + worldName, error);
    if (error) return false;
    if (!std::filesystem::exists(file_status)) return false;

    //开始回档
    //先重名原来存档，再复制回档文件
    auto file_status1 = std::filesystem::status("./worlds/" + worldName, error);
    if (error) return false;
    if (std::filesystem::exists(file_status1) && std::filesystem::exists(file_status)) {
        filesystem::rename("./worlds/" + worldName, "./worlds/" + worldName + "_bak");
    }
    else {
        return false;
    }
    filesystem::copy(TEMP1_DIR, "./worlds", std::filesystem::copy_options::recursive, error);
    if (error.value() != 0)
    {
        SendFeedback(nowPlayer, "Failed to copy files!\n" + error.message());
        filesystem::remove_all(TEMP1_DIR);
        filesystem::rename("./worlds/" + worldName + "_bak", "./worlds/" + worldName);
        return false;
    }
    filesystem::remove_all(TEMP1_DIR);
    filesystem::remove_all("./worlds/" + worldName + "_bak");
    return true;
}

bool StartBackup()
{
    SendFeedback(nowPlayer, "备份已启动");
    isWorking = true;
    ClearOldBackup();
    try
    {
        Level::runcmd("save hold");
    }
    catch(const seh_exception &e)
    {
        SendFeedback(nowPlayer, "Failed to start backup snapshot!");
        FailEnd(e.code());
        return false;
    }
    return true;
}

bool StartRecover(int recover_NUM)
{
    SendFeedback(nowPlayer, "回档前准备已启动");
    if (backupList.empty())
    {
        SendFeedback(nowPlayer, "插件内部存档列表为空，请使用list子指令后再试");
        return false;
    }
    unsigned int i = recover_NUM + 1;
    if (i > backupList.size()) {
        SendFeedback(nowPlayer, "存档选择参数不在已有存档数内，请重新选择");
        return false;
    }
    isWorking = true;
    SendFeedback(nowPlayer, "正在进行回档文件解压复制");
    if (!UnzipFiles(backupList[recover_NUM])) {
        SendFeedback(nowPlayer, "回档文件准备失败");
        isWorking = false;
        return false;
    };
    SendFeedback(nowPlayer, "回档文件准备完成,即将进行回档前备份");
    Level::runcmd("save hold");
    SendFeedback(nowPlayer, "回档准备已完成，重启可回档,使用backup cancel指令可取消回档");
    backupList.clear();
    return true;
}

#define RETRY_TIME 60
int resumeTime = -1;

void ResumeBackup()
{
    try
    {
        std::pair<bool, string> res = Level::runcmdEx("save resume");
        if (!res.first)
        {
            SendFeedback(nowPlayer, "Failed to resume backup snapshot!");
            if (isWorking)
                resumeTime = RETRY_TIME;
            else
                resumeTime = -1;
        }
        else
        {
            SendFeedback(nowPlayer, res.second);
            resumeTime = -1;
        }
    }
    catch (const seh_exception& e)
    {
        SendFeedback(nowPlayer, "Failed to resume backup snapshot! Error Code:" + to_string(e.code()));
        if (isWorking)
            resumeTime = RETRY_TIME;
        else
            resumeTime = -1;
    }
}

THook(void, "?tick@ServerLevel@@UEAAXXZ",
    void* _this)
{
    if (resumeTime > 0)
        --resumeTime;
    else if (resumeTime == 0)
    {
        if (!isWorking)
            resumeTime = -1;
        ResumeBackup();
    }
    return original(_this);
}

THook(vector<SnapshotFilenameAndLength>&, "?createSnapshot@DBStorage@@UEAA?AV?$vector@USnapshotFilenameAndLength@@V?$allocator@USnapshotFilenameAndLength@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z",
    DBStorage* _this, vector<SnapshotFilenameAndLength>& fileData, string& worldName)
{
    if (isWorking) {
        ini.SetValue("BackFile", "worldName", worldName.c_str());
        ini.SaveFile(_CONFIG_FILE);
        auto& files = original(_this, fileData, worldName);
        if (CopyFiles(worldName, files))
        {
            thread([worldName]()
                {
                    _set_se_translator(seh_exception::TranslateSEHtoCE);
                    ZipFiles(worldName);
                    CleanTempDir();
                    SuccessEnd();
                }).detach();
        }

        resumeTime = 20;
        return files;
    }
    else {
        isWorking = true; // Prevent the backup command from being accidentally executed during a map hang
        return original(_this, fileData, worldName);
    }
}

THook(void, "?releaseSnapshot@DBStorage@@UEAAXXZ", DBStorage* _this) {
    isWorking = false;
    original(_this);
}