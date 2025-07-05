#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h" // Patient inherits from Person
#include <string>   // For std::string (though Person.h should bring it)

// Removed 'using namespace std;' from header

class Patient : public Person { // Already correctly inherits from Person
private:
    std::string patientID;
    std::string medicalHistory;
public:
    Patient(std::string id, std::string name, std::string dob,
            std::string gender, std::string mobile, std::string city,
            std::string medicalHistory);

    // Destructor declared as override, implicitly virtual from base classes (Person, DataObject)
    ~Patient() override;

    std::string getPatientID() const;
    std::string getMedicalHistory() const;

    void setPatientID(std::string id);
    void setMedicalHistory(std::string history);

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // PATIENT_H