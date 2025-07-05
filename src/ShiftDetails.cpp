#include "ShiftDetails.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>                 // For std::stringstream

using std::string; // Use using declaration in .cpp for convenience

// Constructor implementation
ShiftDetails::ShiftDetails(string id, string day, string start, string end)
    : shiftID(id), dayOfWeek(day), startTime(start), endTime(end) {
    INCREMENT_COUNTER("ShiftDetails");
    Logger::getInstance()->logCreated("ShiftDetails");
    Logger::getInstance()->logGenericCount("ShiftDetails");
}

// Destructor implementation
ShiftDetails::~ShiftDetails() {
    DECREMENT_COUNTER("ShiftDetails");
    Logger::getInstance()->logDeleted("ShiftDetails");
}

// Getter implementations
string ShiftDetails::getShiftID() const { return shiftID; }
string ShiftDetails::getDayOfWeek() const { return dayOfWeek; }
string ShiftDetails::getStartTime() const { return startTime; }
string ShiftDetails::getEndTime() const { return endTime; }

// Setter implementations
void ShiftDetails::setShiftID(string id) { shiftID = id; }
void ShiftDetails::setDayOfWeek(string day) { dayOfWeek = day; }
void ShiftDetails::setStartTime(string start) { startTime = start; }
void ShiftDetails::setEndTime(string end) { endTime = end; }

// toString() implementation
string ShiftDetails::toString() const {
    return "Shift ID: " + getShiftID() + ", Day: " + getDayOfWeek() + ", Time: " + getStartTime() + "-" + getEndTime();
}

// getDetailedInfo() implementation - ADDED
string ShiftDetails::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Shift Details ---\n";
    ss << "  Shift ID   : " << getShiftID() << "\n";
    ss << "  Day of Week: " << getDayOfWeek() << "\n";
    ss << "  Start Time : " << getStartTime() << "\n";
    ss << "  End Time   : " << getEndTime() << "\n";
    return ss.str();
}