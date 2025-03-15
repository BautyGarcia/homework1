#include <iostream>

using namespace std;

enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL,
    CRITICAL,
    SECURITY,
    COUNT // Solo sirve para contar el numero de logs, siempre tiene que ser el ultimo
};

const string LOG_LEVEL_STRINGS[] = {
    "DEBUG",
    "INFO", 
    "WARNING",
    "ERROR",
    "FATAL (Throw Error)",
    "CRITICAL",
    "SECURITY"
};

void logMessage(string message, LogLevel level);
void logMeesage(string message, string filename, int codeline);
void logMessage(string message, string username);
void handleSecurity();
void handleMessage(LogLevel level);