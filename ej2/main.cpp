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
        // No puse un ejemplo pero funciona, si queres registrar un error a voluntad, usa logMeesage pero no corta el programa
        logMeesage(e.what(), __FILE__, __LINE__);
        return 1;
    }
}

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

void handleMessage(LogLevel level) {
    string message;
    cout << "Ingrese el mensaje: ";
    cin.ignore();
    getline(cin, message);
    logMessage(message, static_cast<LogLevel>(level));
}

void logMessage(string message, LogLevel level) {
    fstream logs;
    logs.open("logs.txt", ios::out | ios::app);

    logs << "[" << LOG_LEVEL_STRINGS[level] << "] " << message << endl;
    logs.close();
}

void logMessage(string message, string username) {
    fstream logs;
    logs.open("logs.txt", ios::out | ios::app);

    logs << "[" << LOG_LEVEL_STRINGS[SECURITY] << "] " << username << " " << message << endl;
    logs.close();
}

void logMeesage(string message, string filename, int codeline) {
    fstream logs;
    logs.open("logs.txt", ios::out | ios::app);

    logs << "[" << LOG_LEVEL_STRINGS[ERROR] << "] " << filename << ":" << codeline << " - " << message << endl;
    logs.close();
}