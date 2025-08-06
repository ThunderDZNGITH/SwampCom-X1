#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <windows.h>
#include "var.h"
#include "color.h"

class MilsimRadioBoot {
public:

    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

    // -------------------------
        // getTimeSinceBoot()
        // -------------------------
    const double getTimeSinceBoot() const
    {
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = now - start;
        return elapsed.count();
    }

    // -------------------------
    // Méthode de simulation Boot
    // -------------------------
    void simulateBoot() const
    {

        using namespace std::chrono_literals;

        auto wait = [](int ms) {
            std::this_thread::sleep_for(std::chrono::milliseconds(ms));
            };

        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] " << deviceModel << " Unité de Communication Sécurisée - Firmware " << firmwareVersion << " (© Swamp Arms 2025)\n"; wait(180);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Linux version " << kernelVersion << " (" << buildHost << ") #12 SMP " << buildDate << "\n"; wait(120);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Mode de démarrage : " << COL_GREEN << "OPÉRATIONNEL " << COL_RESET << "| THÉÂTRE : " << theatre << "\n"; wait(90);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Secure Boot : " << COL_GREEN << "ACTIVÉ" << COL_RESET << "(Niveau " << (int)secureBootLevel + 1 << " – " << secureBootAlgo << ")\n"; wait(80);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Initialisation du noyau temps réel : " << COL_GREEN << "OK\n" << COL_RESET; wait(60);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Architecture : " << architecture << " - " << cpuCores << " coeurs @ " << cpuFreqGHz << "GHz\n"; wait(70);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] RAM détectée : " << ramMB << " MB ECC\n"; wait(50);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Mémoire SWAP cryptée : " << swapMB << " MB\n"; wait(50);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Enclave sécurisée TrustZone : " << COL_GREEN << "ACTIVÉE " << COL_RESET << "(" << trustzoneMB << " MB)\n"; wait(40);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] eMMC " << emmcGB << "GB – Partition système : " << partitionMode << " (CRC : " << COL_GREEN << "OK" << COL_RESET << ")\n"; wait(60);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Batterie interne : " << batteriePercent << "% | Autonomie estimée : " << (int)autonomieH << "h" << std::setw(2) << std::setfill('0') << (int)((autonomieH - (int)autonomieH) * 60) << " | Température : " << temperatureC << "°C\n"; wait(100);

        std::cout << std::endl;

        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Vérification du système de fichiers : " << COL_GREEN << "OK\n" << COL_RESET; wait(30);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Détection sabotage : " << (sabotageDetected ? COL_RED "ALERTE!" : COL_GREEN "AUCUN RISQUE") << "\n" << COL_RESET; wait(40);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Génération d’entropie cryptographique : " << COL_GREEN << "OK\n" << COL_RESET; wait(30);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Module destruction d’urgence : " << (emergencyDestructionArmed ? COL_GREEN "ARMÉ (clé double requise)" : COL_RED "NON ARMÉ") << "\n" << COL_RESET; wait(60);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Microcode antenne directionnelle : " << COL_GREEN << "OK\n" << COL_RESET; wait(30);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Auto-test SDR : " << COL_GREEN << "PASSÉ " << COL_RESET << "| Bruit plancher RF : " << rfNoiseFloorDbm << "dBm\n"; wait(50);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] RF1 [" << rf1.band << "] : " << COL_GREEN << "PRÊTE " << COL_RESET << "| Puissance : " << rf1.powerW << "W | Antenne : " << rf1.antenna << "\n"; wait(40);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] RF2 [" << rf2.band << "] : " << COL_GREEN << "PRÊTE " << COL_RESET << "| Puissance : " << rf2.powerW << "W | Antenne : " << rf2.antenna << "\n"; wait(40);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Calibration SDR : " << COL_GREEN << "OK " << COL_RESET << "| Température RF : " << rfTemperatureC << "°C\n"; wait(40);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Diagnostic antennes : SWR = " << swr << " | Impédance : " << rfImpedanceOhm << "Ω\n"; wait(40);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Clé crypto externe : " << cryptoKeyExternal << "\n"; wait(40);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Module satellite L/S : " << COL_CYAN << "EN ATTENTE DE SIGNAL\n" << COL_RESET; wait(40);

        std::cout << std::endl;

        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Table militaire SWMC-RF-PROF détectée\n"; wait(30);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] GPS sécurisé : " << (gpsLocked ? COL_GREEN "SIGNAL LOCK" : COL_YELLOW "EN ATTENTE") << COL_RESET << " (" << gpsSatellites << " satellites) | Coordonnées : " << gpsLat << "N, " << gpsLon << "E\n"; wait(50);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] IMU (inertiel) : " << COL_GREEN << "OK" << COL_RESET << " | Altitude : " << altitudeM << "m\n"; wait(40);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Horloge système : UTC " << buildDate.substr(0, 10) << " 14:13:09 | RTC : OK\n"; wait(40);

        std::cout << std::endl;

        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Réseau LoRa MESH tactique : " << loraMeshId << " | " << meshNodes << " nœuds actifs\n"; wait(40);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Ethernet sécurisé : " << COL_GREEN << "LIEN ÉTABLI" << COL_RESET << " | 100Mbps | VLAN : " << ethernetVlan << "\n"; wait(40);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Tunnel VPN DEFENSE : " << (vpnActive ? COL_GREEN "ACTIF" : COL_YELLOW "NON CONNECTÉ") << COL_RESET " | Adresse IP : " << vpnIp << "\n"; wait(50);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Diagnostic hardware : " << COL_GREEN << "100% OPÉRATIONNEL\n" << COL_RESET; wait(60);

        std::cout << std::endl;

        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Montage /secure (chiffré " << partitionSecureAlgo << ") : " << COL_GREEN << "OK\n" << COL_RESET; wait(40);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Authentification biométrique : EMPREINTE #" << biometricId << COL_GREEN << " ACCEPTÉE\n" << COL_RESET; wait(40);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Authentification unité : " << COL_CYAN << operatorId << COL_GREEN << " VALIDÉE " << COL_RESET << "| Certificat : " << certificate << "\n"; wait(40);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Chargement profils de communication...\n"; wait(30);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "]   - VHF/FM Analog : " << (vhfAnalogEnabled ? "ACTIVÉ" : "NON ACTIVÉ") << " | Squawk " << vhfSquawk << "\n"; wait(30);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "]   - UHF/TDMA Numérique : " << (uhfDigitalEnabled ? "ACTIVÉ" : "NON ACTIVÉ") << " | Hopping : " << (freqHoppingEnabled ? "ON" : "OFF") << " | Crypto : " << cryptoMode << "\n"; wait(30);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "]   - Canal prioritaire : " << canalPrio << " (CRYPTÉ)\n"; wait(30);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "]   - Canaux secondaires : ";
        for (auto& c : canauxSecondaires) std::cout << c << " ";
        std::cout << "\n"; wait(30);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "]   - Appareils connectés : ";
        for (auto& a : appareilsConnectes) std::cout << a << " ";
        std::cout << "\n"; wait(30);

        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Journal événements : " << lastEventTime << " | ";
        switch (lastEvent) {
        case EventType::OK:        std::cout << "Aucun incident\n"; break;
        case EventType::Incident:  std::cout << "Incident détecté\n"; break;
        case EventType::Alerte:    std::cout << "ALERTE !\n"; break;
        case EventType::Maintenance: std::cout << "Maintenance requise\n"; break;
        }
        wait(30);

        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Protocole STP (Super Transfer Protocol) v2.1 : OK\n"; wait(30);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Réseau MESH ID: " << loraMeshId << " | " << meshNodes << " nœuds actifs\n"; wait(30);

        std::cout << std::endl;

        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Synchronisation horloge crypto avec HQ : OK\n"; wait(20);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Module SMS sécurisé (milSMS) : " << (milsmsEnabled ? "ACTIVÉ" : "NON ACTIVÉ") << "\n"; wait(20);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Canal DATA : PRÊT | Débit : " << dataRateMbps << " Mbps\n"; wait(20);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Enregistrement audio : " << (audioRecording ? "SURVEILLANCE" : "INACTIF") << "\n"; wait(20);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Microphone : " << (microphoneOK ? "OK" : "DEFAILLANT") << " | Haut-parleur : " << (speakerOK ? "OK" : "DEFAILLANT") << "\n"; wait(20);

        std::cout << std::endl;

        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Environnement combat temps réel : OK\n"; wait(20);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Règles de mission : " << missionRulesPath << "\n"; wait(20);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Communications : Sécurisées OTAN 3 | Filtrage EMI : ACTIF\n"; wait(20);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Interface opérateur tactile : " << (operatorTouchscreenOK ? "OK" : "DEFAILLANTE") << " | Affichage " << displaySizeInch << "” | Luminosité auto\n"; wait(20);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] TEST ÉCRAN : " << (operatorTouchscreenOK ? "PASS" : "FAIL") << " | TACTILE : " << (operatorTouchscreenOK ? "PASS" : "FAIL") << "\n"; wait(20);

        std::cout << std::endl;

        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Tests finaux…\n"; wait(40);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Alerte test : PAS DE DÉFAUTS\n"; wait(30);
        std::cout << "[    " << std::fixed << std::setprecision(6) << getTimeSinceBoot() << "] Tous modules opérationnels\n"; wait(80);

        // Bloc statut final
        std::cout << "\n[  OK  ] Initialisation système terminée.\n";
        wait(80);
        std::cout << "[  OK  ] Unité prête au déploiement.\n";
        wait(80);
        std::cout << "[  OK  ] Ligne sécurisée disponible.\n\n";
        wait(400);

        std::cout << COL_BGBLACK << COL_GREEN << COL_BOLD;

        std::cout << "\033[H";     // Cursor to home (0,0)
        std::cout << "\033[0J";


        // Bloc ASCII "console militaire"
        std::cout << "████████████████████████████████████████████████████████████████\n";
        std::cout << "█                                                              █\n";
        std::cout << "█   SWAMPCOM-X1 RADIO TACTIQUE MILITAIRE - MODE OPÉRATION      █\n";
        std::cout << "█                                                              █\n";
        std::cout << "█   STATUT : OPÉRATIONNEL      SÉCURITÉ : ACTIVE (OTAN N3)     █\n";
        std::cout << "█   ID : " << operatorId << "           FREQ ACTUELLE : " << canalPrio << "      █\n";
        std::cout << "█   GPS : " << gpsLat << "N, " << gpsLon << "E   NOEUDS RÉSEAU : " << meshNodes << "            █\n";
        std::cout << "█   AUTONOMIE : " << (int)autonomieH << "h" << std::setw(2) << std::setfill('0') << (int)((autonomieH - (int)autonomieH) * 60)
            << "         BATTERIE : " << batteriePercent << "%                   █\n";
        std::cout << "█   MISSION : " << mission << "         DERNIER ÉVÉNEMENT : ";
        switch (lastEvent) {
        case EventType::OK:        std::cout << "OK"; break;
        case EventType::Incident:  std::cout << "Incident"; break;
        case EventType::Alerte:    std::cout << "Alerte"; break;
        case EventType::Maintenance: std::cout << "Maintenance"; break;
        }
        std::cout << "           █\n";
        std::cout << "█                                                              █\n";
        std::cout << "████████████████████████████████████████████████████████████████\n";

    }
};
