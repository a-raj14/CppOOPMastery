#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "const.h"

enum LogLevel { DEBUG, INFO, ERROR };

class Logger {
private:
    std::ofstream logFile;
    std::string getTimeStamp();
    std::string levelToString(LogLevel level);
    std::string debugLogFile;
    std::string infoLogFile;
    std::string errorLogFile;

public:
    std::string logController;
    Logger(const std::string& filename);
    ~Logger();

    void log(LogLevel level, const std::string& message, bool show = false);
    void debug(const std::string& message, bool show = false);
    void info(const std::string& message, bool show = false);
    void error(const std::string& message, bool show = false);
    void print(const std::string &message,const std::string & colorCode = RESET);
    static std::string instance(const std::string &data);
    void clearLog();

};

extern Logger debug;
extern Logger info;
extern Logger error;

#endif  // LOGGER_H
