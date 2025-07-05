#include "Appointment.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>                 // For std::stringstream

using std::string; // Use using declaration in .cpp for convenience

// Default constructor implementation (if defined in header)
Appointment::Appointment()
    : appointmentID(""), patient(nullptr), doctor(nullptr), dateTime(""), reason("") {
    INCREMENT_COUNTER("Appointment");
    Logger::getInstance()->logCreated("Appointment");
    Logger::getInstance()->logGenericCount("Appointment");
}

// Parameterized constructor implementation
// Corrected to accept Patient* and Doctor*
Appointment::Appointment(string id, Patient* pat, Doctor* doc, string dt, string rsn)
    : appointmentID(id), patient(pat), doctor(doc), dateTime(dt), reason(rsn) {
    INCREMENT_COUNTER("Appointment");
    Logger::getInstance()->logCreated("Appointment");
    Logger::getInstance()->logGenericCount("Appointment");
}

// Destructor implementation - no explicit deletion needed if objects are not owned
Appointment::~Appointment() {
    // If patient and doctor pointers are NOT owned (i.e., not new'd inside Appointment)
    // then no 'delete' here. Assuming they are managed by ObjectCache or similar.
    DECREMENT_COUNTER("Appointment");
    Logger::getInstance()->logDeleted("Appointment");
}

// Getter implementations
string Appointment::getAppointmentID() const { return appointmentID; }
Patient* Appointment::getPatient() const { return patient; } // Returns pointer
Doctor* Appointment::getDoctor() const { return doctor; }     // Returns pointer
string Appointment::getDateTime() const { return dateTime; }
string Appointment::getReason() const { return reason; }

// Setter implementations
void Appointment::setAppointmentID(string id) { appointmentID = id; }
void Appointment::setPatient(Patient* pat) { patient = pat; } // Sets pointer
void Appointment::setDoctor(Doctor* doc) { doctor = doc; }     // Sets pointer
void Appointment::setDateTime(string dt) { dateTime = dt; }
void Appointment::setReason(string rsn) { reason = rsn; }

// toString() implementation
string Appointment::toString() const {
    string patName = (patient ? patient->getName() : "N/A");
    string docName = (doctor ? doctor->getName() : "N/A");
    return "Appointment ID: " + getAppointmentID() + ", Patient: " + patName +
           ", Doctor: " + docName + ", Date/Time: " + getDateTime();
}

// getDetailedInfo() implementation - ADDED
string Appointment::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Appointment Details ---\n";
    ss << "  Appointment ID: " << getAppointmentID() << "\n";
    ss << "  Patient       : " << (patient ? patient->getName() + " (ID: " + patient->getPatientID() + ")" : "N/A") << "\n";
    ss << "  Doctor        : " << (doctor ? doctor->getName() + " (ID: " + doctor->getID() + ")" : "N/A") << "\n";
    ss << "  Date/Time     : " << getDateTime() << "\n";
    ss << "  Reason        : " << getReason() << "\n";
    return ss.str();
}