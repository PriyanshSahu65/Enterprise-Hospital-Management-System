#include "Logger.h"
#include "ObjectCounter.h" // Include ObjectCounter to get counts
#include <iostream>        // For std::cerr in case of file open error

// Initialize the static instance to nullptr
Logger* Logger::instance = nullptr;

// Private constructor implementation
Logger::Logger() : logFileName("../data/log.txt") {
    logFile.open(logFileName, std::ios::app); // Open in append mode
    if (!logFile.is_open()) {
        std::cerr << "Error: Could not open log file: " << logFileName << std::endl;
    } else {
        log("Logger initialized.");
    }
}

// Public method to get the singleton instance
Logger* Logger::getInstance() {
    if (instance == nullptr) {
        instance = new Logger();
    }
    return instance;
}

// Destructor implementation
Logger::~Logger() {
    log("Logger shutting down.");
    if (logFile.is_open()) {
        logFile.close();
    }
    // Clean up the singleton instance
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

// Helper to get current timestamp
std::string Logger::getCurrentTimestamp() const {
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&currentTime);

    std::stringstream ss;
    ss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

// Method to write a general log message
void Logger::log(const std::string& message) {
    if (logFile.is_open()) {
        logFile << getCurrentTimestamp() << " - " << message << std::endl;
        // Optionally, also print to console for immediate feedback during development
        // std::cout << getCurrentTimestamp() << " - " << message << std::endl;
    } else {
        std::cerr << "Error: Log file not open. Message: " << message << std::endl;
    }
}

// Specific logging methods for object lifecycle and activity
void Logger::logCreated(const std::string& className) {
    log("CREATED - " + className + " object.");
}

void Logger::logDeleted(const std::string& className) {
    log("DELETED - " + className + " object.");
}

void Logger::logGenericCount(const std::string& className) {
    // Get instance of ObjectCounter and retrieve counts
    ObjectCounter* ocInstance = ObjectCounter::getInstance();
    std::map<std::string, int> counts = ocInstance->getCounter();

    std::string countStr = "N/A";
    auto it = counts.find(className);
    if (it != counts.end()) {
        countStr = std::to_string(it->second);
    }
    log("COUNT   - " + className + ": " + countStr + " active objects.");
}

void Logger::logActivity(const std::string& className, const std::string& activity) {
    log("ACTIVITY - " + className + ": " + activity);
}