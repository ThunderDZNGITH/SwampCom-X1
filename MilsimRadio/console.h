#pragma once
#include <thread>
#include <iostream>
#include <string>
#include "var.h"
#include "color.h"

class RadioConsole {
public:
    void console() {
        while (true) {

            auto wait = [](int ms) {
                std::this_thread::sleep_for(std::chrono::milliseconds(ms));
                };

            std::cout << COL_BGBLACK << COL_GREEN << COL_BOLD;

            std::cout << operatorId << " > ";
            std::cout.flush();

            std::string input;
            std::getline(std::cin, input);
            if (input == "exit") {
                break;
            }
            if (input == "sendmsg") {
                std::cout << COL_CYAN << "Message envoyé avec succès !\n" << COL_RESET;
                wait(1000);
            }
        }
    }
};