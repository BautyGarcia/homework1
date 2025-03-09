#include <iostream>

using namespace std;

enum LogLevel {
    DEBUG = 0,
    INFO = 1, 
    WARNING = 2,
    ERROR = 3,
    CRITICAL = 4,
    SECURITY = 5
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