#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

enum LogLevel { DEBUG, INFO, ERROR };

class Logger {
private:
    std::ofstream logFile;
    std::string getTimeStamp();
    std::string levelToString(LogLevel level);

public:
    Logger(const std::string& filename);
    ~Logger();

    void log(LogLevel level, const std::string& message);
    void debug(const std::string& message);
    void info(const std::string& message);
    void error(const std::string& message);
};

extern Logger debug;
extern Logger info;
extern Logger error;

#endif  // LOGGER_H
