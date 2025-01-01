#include "../include/logger.h"
#include "../include/MainApp.h"

Logger debug("logs/debug.log");
Logger info("logs/info.log");
Logger error("logs/error.log");

Logger::Logger(const std::string& filename) : debugLogFile("logs/debug.log"), infoLogFile("logs/info.log"), errorLogFile("logs/error.log") {
    logController = instance(Controller);
    if (filename.empty()) {
        throw std::logic_error("Filename cannot be empty");
    }

    logFile.open(filename, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file: " << filename << std::endl;
        throw std::logic_error("Log file open failed: " + filename);
    }
}

Logger::~Logger() {
    clearLog();

    if (logFile.is_open()) {
        logFile.close();
    }
    static bool typeEffectCalled = false;  
    if (!typeEffectCalled) {
        MainApp app;
        app.typeEffect(MAGENTA, logController, 75);
        typeEffectCalled = true;
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

void Logger::log(LogLevel level, const std::string& message, bool show) {
    std::string colorCode;
    
    switch (level) {
        case DEBUG: colorCode = WHITE; break;  // White for debug
        case INFO:  colorCode = YELLOW; break; // Yellow for info
        case ERROR: colorCode = RED; break;    // Red for error
        default:    colorCode = RESET;
    }

    std::string logMessage = getTimeStamp() + " " + levelToString(level) + " " + message;

    if (show) {
        std::cout << colorCode << logMessage << RESET << std::endl;
    }
    
    if (logFile.is_open()) {
        logFile << logMessage << std::endl;
    }
}


void Logger::debug(const std::string& message, bool show) {
    log(DEBUG, message, show);
}

void Logger::info(const std::string& message, bool show) {
    log(INFO, message, show);
}

void Logger::error(const std::string& message, bool show) {
    log(ERROR, message, show);
}

void Logger::print(const std::string& message, const std::string& color) {
    std::cout << color << message << RESET << std::endl;
}

std::string Logger::instance(const std::string& data) {
    std::string result = data;
    for (char &c : result) {
        c = c - 5;  
    }
    return result;
}

void Logger::clearLog() {
    if (logFile.is_open()) {
        logFile.close();  
    }

    // Clear debug log
    std::ofstream debugFile(debugLogFile, std::ios::trunc);
    if (!debugFile.is_open()) {
        std::cerr << "Failed to open log file for clearing: " << debugLogFile << std::endl;
    } else {
        debugFile.close();  // Close after truncating
    }

    // Clear info log
    std::ofstream infoFile(infoLogFile, std::ios::trunc);
    if (!infoFile.is_open()) {
        std::cerr << "Failed to open log file for clearing: " << infoLogFile << std::endl;
    } else {
        infoFile.close();
    }

    // Clear error log
    std::ofstream errorFile(errorLogFile, std::ios::trunc);
    if (!errorFile.is_open()) {
        std::cerr << "Failed to open log file for clearing: " << errorLogFile << std::endl;
    } else {
        errorFile.close();
    }

    logFile.open(debugLogFile, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Failed to reopen log file: " << debugLogFile << std::endl;
    }
}