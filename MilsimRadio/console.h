#pragma once
#include <thread>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "var.h"
#include "color.h"

class RadioConsole {
public:

    std::vector<std::string> splitInput(const std::string& input) {
        std::istringstream iss(input);
        std::vector<std::string> tokens;
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
        return tokens;
    }

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

            std::istringstream iss(input);
            std::string cmd;
            iss >> cmd;
            if (cmd.empty()) continue;

            // Commande exit
            if (cmd == "exit") break;

            // Commande sendmsg avec parsing spécial
            if (cmd == "sendmsg") {
                std::string idReceveur;
                iss >> idReceveur;
                if (idReceveur.empty()) {
                    std::cout << "Usage : sendmsg <iddureceveur> [message]" << std::endl;
                    continue;
                }
                std::string message;
                std::getline(iss, message);
                if (!message.empty() && message[0] == ' ') message = message.substr(1);

                std::cout << COL_CYAN << "Message envoyé à " << idReceveur << " !";
                if (!message.empty()) {
                    std::cout << " Contenu : " << message;
                }
                std::cout << "\n" << COL_RESET;
                wait(1000);
                continue;
            }

            // Ajoute d'autres commandes ici, traitement simple :
            if (cmd == "help") {
                std::cout << "Commandes disponibles : sendmsg, help, exit" << std::endl;
                continue;
            }
            if (cmd == "ping") {
                std::cout << "pong !" << std::endl;
                continue;
            }

            // Commande inconnue :
            std::cout << "Commande inconnue: " << cmd << std::endl;
        }
    }
};