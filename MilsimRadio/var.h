#pragma once
#include <string>
#include <vector>

enum class BootMode {
    Operationnel,
    Maintenance,
    Diagnostics,
    EffacementUrgence,
    MiseAJour,
    Arret
};

enum class RFStatus {
    NonInitialise,
    Pret,
    Defaillant,
    AttenteSignal
};

enum class AuthMode {
    Aucun,
    Biometrique,
    MotDePasse,
    CleCrypto
};

enum class SecurityLevel {
    Niveau0,
    Niveau1,
    Niveau2,
    Niveau3
};

enum class EventType {
    OK,
    Incident,
    Alerte,
    Maintenance
};

enum class CommProtocol {
    STP,
    IP,
    LoRa,
    SatCom
};

enum class CommunicationMode {
    Analogique,
    Numerique,
    Hybride
};

struct RFModule {
    std::string band;
    std::string antenna;
    unsigned int powerW;
    RFStatus status = RFStatus::NonInitialise;
};

// Variables principales
std::string firmwareVersion = "v3.12.4";
std::string deviceModel = "SwampCom-X1";
std::string kernelVersion = "5.15.128-swmc";
std::string buildDate = "2025-08-05 03:22:13 UTC";
std::string buildHost = "forge.incidence.fr";
std::string architecture = "ARMv8-A Cortex-A72";
unsigned int cpuCores = 4;
float cpuFreqGHz = 1.5;
unsigned int ramMB = 4096;
unsigned int swapMB = 512;
unsigned int trustzoneMB = 256;
unsigned int emmcGB = 32;
std::string partitionMode = "lecture seule";
unsigned int batteriePercent = 94;
float autonomieH = 14.63; // 14h38
float temperatureC = 36.0;
std::string theatre = "EUROPE_NORD";

// Sécurité
bool secureBootEnabled = true;
SecurityLevel secureBootLevel = SecurityLevel::Niveau3;
std::string secureBootAlgo = "RSA2048+SHA256";
bool sabotageDetected = false;
bool emergencyDestructionArmed = true;
AuthMode authMode = AuthMode::Biometrique;
unsigned int biometricId = 2;

// RF & modules radio
RFModule rf1 = { "30-88 MHz", "Whip", 20, RFStatus::Pret };
RFModule rf2 = { "225-512 MHz", "Blade", 5, RFStatus::Pret };

float rfNoiseFloorDbm = -115.0;
float rfTemperatureC = 34.0;
float swr = 1.2;
unsigned int rfImpedanceOhm = 50;

// Crypto, stockage
bool partitionSecureMounted = true;
std::string partitionSecureAlgo = "AES-XTS-512";
std::string cryptoKeyExternal = "NON_INSEREE";
std::string certificate = "2025-09";
bool cryptoSyncHQ = true;

// GPS, IMU, réseau
bool gpsLocked = true;
float gpsLat = 48.8566;
float gpsLon = 2.3522;
unsigned int gpsSatellites = 4;
unsigned int altitudeM = 39;
std::string loraMeshId = "BASTION";
unsigned int meshNodes = 7;
std::string ethernetVlan = "OPERATIONS";
bool vpnActive = true;
std::string vpnIp = "10.51.23.6";

// Profils et canaux
std::string canalPrio = "148.250 MHz";
std::vector<std::string> canauxSecondaires = { "51.500 MHz", "243.000 MHz", "315.300 MHz" };
std::vector<std::string> appareilsConnectes = { "#FR-77B-Q7", "#FR-82C-V4" };
std::string mission = "alpha01";
std::string missionRulesPath = "/secure/missions/alpha01.mis";

// Communication
bool vhfAnalogEnabled = true;
std::string vhfSquawk = "04";
bool uhfDigitalEnabled = true;
bool freqHoppingEnabled = true;
std::string cryptoMode = "OTAR-AES256";
unsigned int dataRateMbps = 2;
bool milsmsEnabled = true;
bool audioRecording = true;

// Événement, interfaces, tests
EventType lastEvent = EventType::OK;
std::string lastEventTime = "2025-08-05 13:47:12";
bool operatorTouchscreenOK = true;
float displaySizeInch = 5.0;
bool displayAutoBrightness = true;
bool microphoneOK = true;
bool speakerOK = true;
std::string operatorId = "#FR-92A-X1";

BootMode bootMode = BootMode::Operationnel;