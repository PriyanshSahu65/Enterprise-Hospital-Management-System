#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>   // For std::ofstream
#include <chrono>    // For std::chrono::system_clock
#include <ctime>     // For std::time_t, std::localtime, std::put_time
#include <iomanip>   // For std::put_time
#include <map>       // For std::map (if you want to show object counts directly from Logger)
#include "config.h"

// Forward declaration of ObjectCounter to avoid circular dependency
class ObjectCounter;

class Logger {
private:
    static Logger* instance; // Singleton instance
    std::ofstream logFile;   // Output file stream for logging
    std::string logFileName;

    // Private constructor to prevent direct instantiation
    Logger();

    // Private copy constructor and assignment operator to prevent copying
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // Helper to get current timestamp
    std::string getCurrentTimestamp() const;

public:
    // Public method to get the singleton instance
    static Logger* getInstance();

    // Destructor
    ~Logger();

    // Method to write a general log message
    void log(const std::string& message);

    // Specific logging methods for object lifecycle and activity
    void logCreated(const std::string& className);
    void logDeleted(const std::string& className);
    void logGenericCount(const std::string& className); // Logs the count of a specific class
    void logActivity(const std::string& className, const std::string& activity); // For specific actions/activities
};

#if ENABLE_LOGGER
#define LOG_OBJECT_EVENT(event, type) Logger::getInstance()->event(type)
#else
#define LOG_OBJECT_EVENT(event, type)
#endif

#endif // LOGGER_H