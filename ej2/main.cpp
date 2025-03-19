#include <iostream>
#include <fstream>
#include <stdexcept>
#include "main.h"

using namespace std;

int main() {
    try {
        while (true) {
            int level;

            cout << DEBUG << " - " << LOG_LEVEL_STRINGS[DEBUG] << endl;
            cout << INFO << " - " << LOG_LEVEL_STRINGS[INFO] << endl;
            cout << WARNING << " - " << LOG_LEVEL_STRINGS[WARNING] << endl;
            cout << ERROR << " - " << LOG_LEVEL_STRINGS[ERROR] << endl;
            cout << FATAL << " - " << LOG_LEVEL_STRINGS[FATAL] << endl;
            cout << CRITICAL << " - " << LOG_LEVEL_STRINGS[CRITICAL] << endl;
            cout << SECURITY << " - " << LOG_LEVEL_STRINGS[SECURITY] << endl;
            cout << "-1 - SALIR" << endl;
            cout << "Ingrese el tipo de log: ";

            cin >> level;

            if (level == -1) {
                break;
            }

            if (level < 0 || level >= COUNT) {
                cout << "Nivel de log invalido" << endl;
                continue;
            }

            switch (level) {
                case FATAL:
                    throw runtime_error("Algo paso, algo malo seguro");
                    break;
                case SECURITY:
                    handleSecurity();
                    break;
                default:
                    handleMessage(static_cast<LogLevel>(level));
                    break;
            }
        }
    }
    catch (const exception &e) {
        logMeesage(e.what(), __FILE__, __LINE__);
        return 1;
    }
}

// Wrapper para loggear un mensaje de seguridad
void handleSecurity() {
    string message;
    string username;
    cout << "Ingrese el mensaje de acceso: ";
    cin.ignore();
    getline(cin, message);
    cout << "Ingrese el nombre de usuario: ";
    getline(cin, username);
    logMessage(message, username);
}

// Wrapper para loggear un mensaje de un tipo normal
void handleMessage(LogLevel level) {
    string message;
    cout << "Ingrese el mensaje: ";
    cin.ignore();
    getline(cin, message);
    logMessage(message, static_cast<LogLevel>(level));
}


// Loggea un mensaje de un tipo normal
void logMessage(string message, LogLevel level) {
    fstream logs;
    logs.open("logs.txt", ios::out | ios::app);

    logs << "[" << LOG_LEVEL_STRINGS[level] << "] " << message << endl;
    logs.close();
}

// Loggea un mensaje de seguridad
void logMessage(string message, string username) {
    fstream logs;
    logs.open("logs.txt", ios::out | ios::app);

    logs << "[" << LOG_LEVEL_STRINGS[SECURITY] << "] " << username << " " << message << endl;
    logs.close();
}

// Loggea un mensaje de error
void logMeesage(string message, string filename, int codeline) {
    fstream logs;
    logs.open("logs.txt", ios::out | ios::app);

    logs << "[" << LOG_LEVEL_STRINGS[ERROR] << "] " << filename << ":" << codeline << " - " << message << endl;
    logs.close();
}