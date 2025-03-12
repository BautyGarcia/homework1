#include <iostream>
#include <fstream>
#include <stdexcept>
#include "main.h"

using namespace std;

int main()
{
    try 
    {
        while (true)
        {
            string message;
            string username;
            int level;

            cout << DEBUG << " - DEBUG" << endl;
            cout << INFO << " - INFO" << endl;
            cout << WARNING << " - WARNING" << endl;
            cout << ERROR << " - ERROR" << endl;
            cout << CRITICAL << " - CRITICAL" << endl;
            cout << SECURITY << " - SECURITY" << endl;
            cout << "-1 - SALIR" << endl;
            cout << "Ingrese el tipo de log: ";

            cin >> level;

            if (level == -1)
            {
                break;
            }

            if (level < 0 || level > LOG_LEVEL_STRINGS->length()) {
                cout << "Nivel de log invalido" << endl;
                continue;
            }

            switch (level)
            {
                case ERROR:
                    throw runtime_error("Algo paso, algo malo seguro");
                    break;
                case SECURITY:
                    cout << "Ingrese el mensaje de acceso: ";
                    cin.ignore();
                    getline(cin, message);
                    cout << "Ingrese el nombre de usuario: ";
                    getline(cin, username);
                    logMessage(message, username);
                    break;
                default:
                    cout << "Ingrese el mensaje: ";
                    cin.ignore();
                    getline(cin, message);
                    logMessage(message, static_cast<LogLevel>(level));
                    break;
            }
        }
    }
    catch (const exception& e)
    {
        // No puse un ejemplo pero funciona, si queres registrar un error a voluntad, usa logMeesage pero no corta el programa
        logMeesage(e.what(), __FILE__, __LINE__);
        return 1;
    }
}

void logMessage(string message, LogLevel level)
{
    fstream logs;
    logs.open("logs.txt", ios::out | ios::app);

    logs << "[" << LOG_LEVEL_STRINGS[level] << "] " << message << endl;
    logs.close();
}

void logMessage(string message, string username)
{
    fstream logs;
    logs.open("logs.txt", ios::out | ios::app);

    logs << "[" << LOG_LEVEL_STRINGS[SECURITY] << "] " << username << " " << message << endl;
    logs.close();
}

void logMeesage(string message, string filename, int codeline)
{
    fstream logs;
    logs.open("logs.txt", ios::out | ios::app);

    logs << "[" << LOG_LEVEL_STRINGS[ERROR] << "] " << filename << ":" << codeline << " - " << message << endl;
    logs.close();
}