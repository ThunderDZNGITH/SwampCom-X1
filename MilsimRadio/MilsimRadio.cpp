// ============================================================================
// Projet      : MilsimRadio
// Fichier     : MilsimRadio.cpp
// Description : Point d'entrée principal du programme MilsimRadio.
// Auteur      : Xavier Amichot
// Date        : 05/08/2025
// Version     : 1.0
// ============================================================================
#include "Logger.h"
#include "BootCode.h"
#include "console.h"

int main()
{
	Logger logger;
	MilsimRadioBoot MilsimRadioBoot;
	RadioConsole radioConsole;

    SetConsoleOutputCP(CP_UTF8);
    std::ios::sync_with_stdio(false);
    std::wcout.imbue(std::locale("fr_FR.UTF-8"));
    MilsimRadioBoot.simulateBoot();
	radioConsole.console();
}
