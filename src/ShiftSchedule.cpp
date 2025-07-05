#include "ShiftSchedule.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>                 // For std::stringstream
#include <algorithm>               // For std::remove_if

using std::string;
using std::vector;

// Default constructor implementation (if defined in header)
ShiftSchedule::ShiftSchedule()
    : scheduleID("") {
    ObjectCounter::getInstance()->increment("ShiftSchedule");
    Logger::getInstance()->logCreated("ShiftSchedule");
    Logger::getInstance()->logGenericCount("ShiftSchedule");
}

// Parameterized constructor implementation
ShiftSchedule::ShiftSchedule(string id, vector<ShiftDetails*> shiftList)
    : scheduleID(id) {
    // Deep copy shifts here if ShiftSchedule OWNS them.
    // Assuming ShiftSchedule manages the lifetime of these ShiftDetails objects.
    for (ShiftDetails* shift : shiftList) {
        this->shifts.push_back(shift); // Takes ownership of the passed pointers
    }

    ObjectCounter::getInstance()->increment("ShiftSchedule");
    Logger::getInstance()->logCreated("ShiftSchedule");
    Logger::getInstance()->logGenericCount("ShiftSchedule");
}

// Destructor implementation - CRITICAL for memory management of ShiftDetails objects
ShiftSchedule::~ShiftSchedule() {
    // Delete all ShiftDetails objects owned by this ShiftSchedule
    for (ShiftDetails* shift : shifts) {
        delete shift; // ASSUMPTION: ShiftSchedule owns the ShiftDetails objects.
                      // If shifts are managed by a central cache, DO NOT delete them here.
    }
    shifts.clear(); // Clear the vector after deleting objects

    ObjectCounter::getInstance()->decrement("ShiftSchedule");
    Logger::getInstance()->logDeleted("ShiftSchedule");
}

// Getter implementations
string ShiftSchedule::getScheduleID() const { return scheduleID; }
const vector<ShiftDetails*>& ShiftSchedule::getShifts() const { return shifts; }

// Setter implementations
void ShiftSchedule::setScheduleID(string id) { scheduleID = id; }

void ShiftSchedule::setShifts(vector<ShiftDetails*> newShifts) {
    // First, delete existing ShiftDetails objects if owned
    for (ShiftDetails* shift : shifts) {
        delete shift;
    }
    shifts.clear();

    // Now, take ownership of new ShiftDetails objects
    for (ShiftDetails* shift : newShifts) {
        this->shifts.push_back(shift);
    }
}

// Add a single shift
void ShiftSchedule::addShift(ShiftDetails* shift) {
    if (shift) {
        shifts.push_back(shift); // Take ownership
        Logger::getInstance()->logActivity("ShiftSchedule", "Added Shift: " + shift->toString());
    }
}

// Remove a shift by its Shift ID
void ShiftSchedule::removeShift(const string& shiftID) {
    auto it = std::remove_if(shifts.begin(), shifts.end(),
        [&](ShiftDetails* shift) {
            if (shift && shift->getShiftID() == shiftID) {
                delete shift; // Delete the owned object
                Logger::getInstance()->logActivity("ShiftSchedule", "Removed Shift with ID: " + shiftID);
                return true;
            }
            return false;
        });
    shifts.erase(it, shifts.end());
}

// toString() implementation
string ShiftSchedule::toString() const {
    std::stringstream ss;
    ss << "Schedule ID: " << getScheduleID() << ", Total Shifts: " << shifts.size();
    return ss.str();
}

// getDetailedInfo() implementation - ADDED
string ShiftSchedule::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Shift Schedule Details ---\n";
    ss << "  Schedule ID: " << getScheduleID() << "\n";
    ss << "  Shifts     :\n";
    if (shifts.empty()) {
        ss << "    No shifts defined.\n";
    } else {
        for (const ShiftDetails* shift : shifts) {
            if (shift) {
                ss << "    - " << shift->toString() << "\n";
            }
        }
    }
    return ss.str();
}

// getInfoString() implementation for use in Doctor/Nurse detailed info
string ShiftSchedule::getInfoString() const {
    std::stringstream ss;
    if (shifts.empty()) {
        ss << "No shifts scheduled";
    } else {
        bool first = true;
        for (const ShiftDetails* shift : shifts) {
            if (shift) {
                if (!first) {
                    ss << "; ";
                }
                ss << shift->getDayOfWeek() << " " << shift->getStartTime() << "-" << shift->getEndTime();
                first = false;
            }
        }
    }
    return ss.str();
}