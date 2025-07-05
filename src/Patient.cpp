#include "Patient.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>                 // For std::stringstream

using std::string; // Use using declaration in .cpp for convenience

// Constructor implementation
Patient::Patient(string id, string name, string dob, string gender,
                 string mobile, string city, string medicalHistory)
    : Person(id, name, dob, gender, mobile, city), // Call base class constructor
      patientID(id), medicalHistory(medicalHistory) {
    INCREMENT_COUNTER("Patient"); // Track creation
    Logger::getInstance()->logCreated("Patient");
    Logger::getInstance()->logGenericCount("Patient"); // Log current count
}

// Destructor implementation
Patient::~Patient() {
    DECREMENT_COUNTER("Patient"); // Track destruction
    Logger::getInstance()->logDeleted("Patient");
}

// Getter implementations
string Patient::getPatientID() const {
    return patientID;
}

string Patient::getMedicalHistory() const {
    return medicalHistory;
}

// Setter implementations
void Patient::setPatientID(string id) {
    patientID = id;
}

void Patient::setMedicalHistory(string history) {
    medicalHistory = history;
}

// toString() implementation
string Patient::toString() const {
    // Calls base class toString and adds specific info
    return Person::toString() + " (Patient ID: " + getPatientID() + ")";
}

// getDetailedInfo() implementation - ADDED
string Patient::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Patient Details ---\n";
    ss << Person::getDetailedInfo(); // Call base class detailed info
    ss << "  Patient ID     : " << getPatientID() << "\n";
    ss << "  Medical History: " << getMedicalHistory() << "\n";
    return ss.str();
}