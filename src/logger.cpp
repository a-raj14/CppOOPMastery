#include "../include/logger.h"

Logger debug("logs/debug.log");
Logger info("logs/info.log");
Logger error("logs/error.log");

Logger::Logger(const std::string& filename) {
    logFile.open(filename, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file: " << filename << std::endl;
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

std::string Logger::getTimeStamp() {
    time_t now = time(0);
    char buf[80];
    strftime(buf, sizeof(buf), "[%Y-%m-%d %H:%M:%S]", localtime(&now));
    return std::string(buf);
}

std::string Logger::levelToString(LogLevel level) {
    switch (level) {
        case DEBUG: return "[DEBUG]";
        case INFO:  return "[INFO]";
        case ERROR: return "[ERROR]";
        default:    return "[UNKNOWN]";
    }
}

void Logger::log(LogLevel level, const std::string& message) {
    std::string logMessage = getTimeStamp() + " " + levelToString(level) + " " + message;
    std::cout << logMessage << std::endl;
    if (logFile.is_open()) {
        logFile << logMessage << std::endl;
    }
}

void Logger::debug(const std::string& message) {
    log(DEBUG, message);
}

void Logger::info(const std::string& message) {
    log(INFO, message);
}

void Logger::error(const std::string& message) {
    log(ERROR, message);
}
