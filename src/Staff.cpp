#include "Staff.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>                 // For std::stringstream

using std::string; // Use using declaration in .cpp for convenience

// Constructor implementation
Staff::Staff(string id, string name, string dob, string gender,
             string mobile, string city, string role)
    : Person(id, name, dob, gender, mobile, city), // Call base class constructor
      staffID(id), role(role) { // Initialize redundant staffID
    ObjectCounter::getInstance()->increment("Staff"); // Track creation
    Logger::getInstance()->logCreated("Staff");
    Logger::getInstance()->logGenericCount("Staff"); // Log current count
}

// Destructor implementation
Staff::~Staff() {
    ObjectCounter::getInstance()->decrement("Staff"); // Track destruction
    Logger::getInstance()->logDeleted("Staff");
}

// Getter implementations
// string Staff::getStaffID() const { return staffID; } // Redundant, use Person::getID()
string Staff::getRole() const { return role; }

// Setter implementations
// void Staff::setStaffID(string id) { staffID = id; } // Redundant, use Person::setID()
void Staff::setRole(string r) { role = r; }

// toString() implementation
string Staff::toString() const {
    // Calls base class toString and adds specific info
    return Person::toString() + " (Role: " + getRole() + ")";
}

// getDetailedInfo() implementation - ADDED
string Staff::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Staff Details ---\n";
    ss << Person::getDetailedInfo(); // Call base class detailed info
    ss << "  Role          : " << getRole() << "\n";
    return ss.str();
}