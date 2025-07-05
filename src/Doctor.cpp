#include "Doctor.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>   
#include "Staff.h"             // For std::stringstream

using std::string; // Use using declaration in .cpp for convenience

// Constructor implementation
Doctor::Doctor(string id, string name, string dob, string gender,
               string mobile, string city, string specialization,
               ShiftSchedule* schedule)
    : Staff(id, name, dob, gender, mobile, city, "Doctor"),
      specialization(specialization),
      shiftSchedule(schedule) { // Takes ownership of the ShiftSchedule pointer
    ObjectCounter::getInstance()->increment("Doctor");
    Logger::getInstance()->logCreated("Doctor");
    Logger::getInstance()->logGenericCount("Doctor");
}

// Destructor implementation - CRITICAL for ShiftSchedule memory management
Doctor::~Doctor() {
    // Delete the ShiftSchedule object if Doctor owns it.
    // ASSUMPTION: Doctor owns the ShiftSchedule object.
    // If ShiftSchedule objects are managed by a central cache,
    // then DO NOT delete 'shiftSchedule' here.
    if (shiftSchedule) {
        delete shiftSchedule;
        shiftSchedule = nullptr; // Prevent double deletion
    }

    ObjectCounter::getInstance()->decrement("Doctor");
    Logger::getInstance()->logDeleted("Doctor");
}

// Getter implementations
string Doctor::getSpecialization() const {
    return specialization;
}

ShiftSchedule* Doctor::getShiftSchedule() const {
    return shiftSchedule;
}

// Setter implementations
void Doctor::setSpecialization(string specialization) {
    this->specialization = specialization;
}

void Doctor::setShiftSchedule(ShiftSchedule* schedule) {
    // If setting a new schedule, delete the old one if owned
    if (shiftSchedule && shiftSchedule != schedule) { // Avoid deleting if setting to same pointer
        delete shiftSchedule;
    }
    shiftSchedule = schedule;
}

// toString() implementation
string Doctor::toString() const {
    // Calls base class toString and adds specific info
    return Staff::toString() + " (Specialization: " + getSpecialization() + ")";
}

// getDetailedInfo() implementation - ADDED
string Doctor::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Doctor Details ---\n";
    ss << Staff::getDetailedInfo(); // Call base class detailed info
    ss << "  Specialization: " << getSpecialization() << "\n";
    ss << "  Shift Schedule: " << (shiftSchedule ? shiftSchedule->getInfoString() : "N/A") << "\n"; // Using getInfoString
    return ss.str();
}