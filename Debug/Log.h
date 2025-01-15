#pragma once

#include <string>
#include <iostream>
#include <deque>
#include <format>

#include "LogType.h"

class Log
{
public:
    static void PrintLog(LogType type, std::string Text)
    {
        std::string Prefix = "";
        switch (type)
        {
        case LOG_Default:
            Prefix = "Log : ";
                break;
        case LOG_Warning:
            Prefix = "Warning : ";
            break;
        case LOG_Game:
            Prefix = "Game : ";
            break;
        default:
            break;
        }
        std::cout << Prefix << Text << std::endl;
    }

    static std::string ToString(std::deque<int> input)
    {
        std::string result;
        for(int current : input)
        {
            result.append(std::to_string(current));
        }
        return result;
    }
};