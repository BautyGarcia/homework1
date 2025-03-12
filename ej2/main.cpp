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

            cout << "0 - DEBUG" << endl;
            cout << "1 - INFO" << endl;
            cout << "2 - WARNING" << endl;
            cout << "3 - ERROR" << endl;
            cout << "4 - CRITICAL" << endl;
            cout << "5 - SECURITY" << endl;
            cout << "-1 - SALIR" << endl;
            cout << "Ingrese el tipo de log: ";

            cin >> level;

            if (level == -1)
            {
                break;
            }

            if (level < 0 || level > 5) {
                cout << "Nivel de log invalido" << endl;
                continue;
            }

            switch (level)
            {
                case 3:
                    throw runtime_error("Algo paso, algo malo seguro");
                    break;
                case 5:
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
                    logMessage(message, INFO);
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

    logs << "[" << LOG_LEVEL_STRINGS[static_cast<int>(SECURITY)] << "] " << username << " " << message << endl;
    logs.close();
}

void logMeesage(string message, string filename, int codeline)
{
    fstream logs;
    logs.open("logs.txt", ios::out | ios::app);

    logs << "[" << LOG_LEVEL_STRINGS[static_cast<int>(ERROR)] << "] " << filename << ":" << codeline << " - " << message << endl;
    logs.close();
}