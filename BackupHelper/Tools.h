#pragma once
#include "pch.h"
#include <string>
#include <iostream>
#include <string>
#include <exception>
using namespace std;

inline void ErrorOutput(const string& err)
{
    logger.error("{}",err);
}

template<typename ... Args>
inline void SendFeedback(Player* p, const string& msg, Args ...args)
{
    auto pls = Level::getAllPlayers();
    bool found = false;
    for (auto& pl : pls)
    {
        if (pl == p)
        {
            found = true;
            break;
        }
    }
    if (!found)
    {
        extern Player* nowPlayer;
        nowPlayer = p = nullptr;
    }

    if (!p)
        logger.info(msg, args...);
    else
    {
        try
        {
            //p->sendTextPacket("§e[BackupHelper]§r " + msg, TextType::RAW);
            p->sendFormattedText("§e[BackupHelper]§r " + msg, args...);
        }
        catch (const seh_exception&)
        {
            extern Player* nowPlayer;
            nowPlayer = nullptr;
            logger.info(msg, args...);
        }
        catch (const exception&)
        {
            extern Player* nowPlayer;
            nowPlayer = nullptr;
            logger.info(msg, args...);
        }
    }
}

inline string wstr2str(wstring wstr) {
    auto  len = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
    char* buffer = new char[len + 1];
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, buffer, len + 1, NULL, NULL);
    buffer[len] = '\0';

    string result = string(buffer);
    delete[] buffer;
    return result;
}