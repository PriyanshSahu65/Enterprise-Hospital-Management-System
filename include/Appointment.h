#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "DataObject.h" // Inherits from DataObject
#include "Patient.h"    // Needs Patient definition
#include "Doctor.h"     // Needs Doctor definition
#include <string>       // For std::string

// Removed 'using namespace std;' from header

class Appointment : public DataObject {
private:
    std::string appointmentID;
    Patient* patient; // CORRECTED: Changed from Patient to Patient*
    Doctor* doctor;   // CORRECTED: Changed from Doctor to Doctor*
    std::string dateTime;
    std::string reason;

public:
    // Default constructor (if needed)
    Appointment();
    // Parameterized constructor - CORRECTED parameters to take pointers
    Appointment(std::string id, Patient* pat, Doctor* doc, std::string dt, std::string reason);

    // Destructor (virtual from DataObject)
    ~Appointment() override; // Added override keyword

    std::string getAppointmentID() const;
    void setAppointmentID(std::string id);

    Patient* getPatient() const; // CORRECTED: Return Patient*
    void setPatient(Patient* pat); // CORRECTED: Take Patient*

    Doctor* getDoctor() const; // CORRECTED: Return Doctor*
    void setDoctor(Doctor* doc); // CORRECTED: Take Doctor*

    std::string getDateTime() const;
    void setDateTime(std::string dt);

    std::string getReason() const;
    void setReason(std::string rsn);

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // APPOINTMENT_H