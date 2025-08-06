#pragma once
#include <iostream>
#include <string>

class Logger
{
public:
    static void Info(const std::string& message)
    {
        std::string prefix = "[INFO] ";
        std::string colorCode = "\033[0m";
        std::cout << colorCode << prefix << message << "\033[0m" << std::endl;
    }

    static void Warn(const std::string& message)
    {
        std::string prefix = "[WARN] ";
        std::string colorCode = "\033[33m"; // Yellow
        std::cout << colorCode << prefix << message << "\033[0m" << std::endl;
	}

    static void Error(const std::string& message)
    {
        std::string prefix = "[ERROR] ";
        std::string colorCode = "\033[31m"; // Red
        std::cout << colorCode << prefix << message << "\033[0m" << std::endl;
	}

    static void Custom(const std::string& message, const std::string& colorCode)
    {
        std::cout << colorCode << message << "\033[0m" << std::endl;
	}
};
