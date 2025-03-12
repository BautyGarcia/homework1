#include <iostream>

using namespace std;

enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL,
    SECURITY
};

const string LOG_LEVEL_STRINGS[] = {
    "DEBUG",
    "INFO", 
    "WARNING",
    "ERROR",
    "CRITICAL",
    "SECURITY"
};

void logMessage(string message, LogLevel level);
void logMeesage(string message, string filename, int codeline);
void logMessage(string message, string username);