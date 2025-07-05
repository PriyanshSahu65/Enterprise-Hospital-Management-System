#ifndef MEDICALRECORD_H
#define MEDICALRECORD_H

#include "DataObject.h"    // Inherits from DataObject
#include "Patient.h"       // Needs Patient definition
#include "Doctor.h"        // Needs Doctor definition
#include "Prescription.h"  // Needs Prescription definition
#include <string>          // For std::string
#include <vector>          // For std::vector (if multiple diagnoses/treatments)

// Removed 'using namespace std;' from header

class MedicalRecord : public DataObject {
private:
    std::string recordID;
    Patient* patient;       // CORRECTED: Changed from Patient to Patient* (Assumed NOT owned)
    Doctor* doctor;         // CORRECTED: Changed from Doctor to Doctor* (Assumed NOT owned)
    std::string admissionDate;
    std::string diagnosis;
    std::string treatment;
    Prescription* prescription; // Pointer to Prescription object (Assumed OWNED by MedicalRecord)

public:
    // Default constructor (if needed)
    MedicalRecord();
    // Parameterized constructor - CORRECTED parameters to take Patient* and Doctor*
    MedicalRecord(std::string id, Patient* pat, Doctor* doc, std::string admDate,
                  std::string diagnosis, std::string treatment, Prescription* presc);

    // Destructor (virtual from DataObject)
    // Crucial if MedicalRecord owns the Prescription object (deletes it)
    ~MedicalRecord() override; // Added override keyword

    std::string getRecordID() const;
    void setRecordID(std::string id);

    Patient* getPatient() const;       // Returns pointer
    void setPatient(Patient* pat);     // Takes pointer

    Doctor* getDoctor() const;         // Returns pointer
    void setDoctor(Doctor* doc);       // Takes pointer

    std::string getAdmissionDate() const;
    void setAdmissionDate(std::string date);

    std::string getDiagnosis() const;
    void setDiagnosis(std::string diagnosis);

    std::string getTreatment() const;
    void setTreatment(std::string treatment);

    Prescription* getPrescription() const; // Returns pointer
    void setPrescription(Prescription* presc); // Handles existing prescription (deletes old, sets new)

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // MEDICALRECORD_H