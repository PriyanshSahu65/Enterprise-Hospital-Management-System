#include "Nurse.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>                 // For std::stringstream

using std::string; // Use using declaration in .cpp for convenience

// Constructor implementation
Nurse::Nurse(string id, string name, string dob, string gender,
             string mobile, string city, string department,
             ShiftSchedule* schedule)
    : Staff(id, name, dob, gender, mobile, city, "Nurse"),
      department(department),
      shiftSchedule(schedule) { // Takes ownership of the ShiftSchedule pointer
    INCREMENT_COUNTER("Nurse");
    Logger::getInstance()->logCreated("Nurse");
    Logger::getInstance()->logGenericCount("Nurse");
}

// Destructor implementation - CRITICAL for ShiftSchedule memory management
Nurse::~Nurse() {
    // Delete the ShiftSchedule object if Nurse owns it.
    // ASSUMPTION: Nurse owns the ShiftSchedule object.
    // If ShiftSchedule objects are managed by a central cache,
    // then DO NOT delete 'shiftSchedule' here.
    if (shiftSchedule) {
        delete shiftSchedule;
        shiftSchedule = nullptr; // Prevent double deletion
    }

    DECREMENT_COUNTER("Nurse");
    Logger::getInstance()->logDeleted("Nurse");
}

// Getter implementations
string Nurse::getDepartment() const {
    return department;
}

ShiftSchedule* Nurse::getShiftSchedule() const {
    return shiftSchedule;
}

// Setter implementations
void Nurse::setDepartment(string department) {
    this->department = department;
}

void Nurse::setShiftSchedule(ShiftSchedule* schedule) {
    // If setting a new schedule, delete the old one if owned
    if (shiftSchedule && shiftSchedule != schedule) { // Avoid deleting if setting to same pointer
        delete shiftSchedule;
    }
    shiftSchedule = schedule;
}

// toString() implementation
string Nurse::toString() const {
    // Calls base class toString and adds specific info
    return Staff::toString() + " (Department: " + getDepartment() + ")";
}

// getDetailedInfo() implementation - ADDED
string Nurse::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Nurse Details ---\n";
    ss << Staff::getDetailedInfo(); // Call base class detailed info
    ss << "  Department    : " << getDepartment() << "\n";
    ss << "  Shift Schedule: " << (shiftSchedule ? shiftSchedule->getInfoString() : "N/A") << "\n"; // Using getInfoString
    return ss.str();
}