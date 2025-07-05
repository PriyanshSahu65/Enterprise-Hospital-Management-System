#include "AdministrativeStaff.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream> // For std::stringstream

using std::string; // Use using declaration in .cpp for convenience

// Constructor implementation
AdministrativeStaff::AdministrativeStaff(string id, string name, string dob,
                                         string gender, string mobile, string city,
                                         string designation)
    : Staff(id, name, dob, gender, mobile, city, "AdministrativeStaff"), designation(designation) {
    INCREMENT_COUNTER("AdministrativeStaff"); // Track creation
    Logger::getInstance()->logCreated("AdministrativeStaff");
    Logger::getInstance()->logGenericCount("AdministrativeStaff"); // Log current count
}

// Destructor implementation
AdministrativeStaff::~AdministrativeStaff() {
    DECREMENT_COUNTER("AdministrativeStaff"); // Track destruction
    Logger::getInstance()->logDeleted("AdministrativeStaff");
}

// Getter implementation
string AdministrativeStaff::getDesignation() const {
    return designation;
}

// Setter implementation
void AdministrativeStaff::setDesignation(string designation) {
    this->designation = designation;
}

// toString() implementation - already present but needs const override check
string AdministrativeStaff::toString() const {
    // Calls base class toString and adds specific info
    return Staff::toString() + " (Designation: " + getDesignation() + ")";
}

// getDetailedInfo() implementation - ADDED
string AdministrativeStaff::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Administrative Staff Details ---\n";
    ss << Staff::getDetailedInfo(); // Call base class detailed info
    ss << "  Designation : " << getDesignation() << "\n";
    return ss.str();
}