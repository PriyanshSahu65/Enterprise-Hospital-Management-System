#include "MedicalRecord.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>                 // For std::stringstream

using std::string; // Use using declaration in .cpp for convenience

// Default constructor implementation (if defined in header)
MedicalRecord::MedicalRecord()
    : recordID(""), patient(nullptr), doctor(nullptr), admissionDate(""),
      diagnosis(""), treatment(""), prescription(nullptr) {
    INCREMENT_COUNTER("MedicalRecord");
    Logger::getInstance()->logCreated("MedicalRecord");
    Logger::getInstance()->logGenericCount("MedicalRecord");
}

// Parameterized constructor implementation
MedicalRecord::MedicalRecord(string id, Patient* pat, Doctor* doc, string admDate,
                             string diagnosis, string treatment, Prescription* presc)
    : recordID(id), patient(pat), doctor(doc), admissionDate(admDate),
      diagnosis(diagnosis), treatment(treatment), prescription(presc) { // Takes ownership of Prescription pointer
    INCREMENT_COUNTER("MedicalRecord");
    Logger::getInstance()->logCreated("MedicalRecord");
    Logger::getInstance()->logGenericCount("MedicalRecord");
}

// Destructor implementation - CRITICAL for Prescription memory management
MedicalRecord::~MedicalRecord() {
    // Delete the Prescription object if MedicalRecord owns it.
    // ASSUMPTION: MedicalRecord owns the Prescription object.
    // If Prescription objects are managed by a central cache,
    // then DO NOT delete 'prescription' here.
    if (prescription) {
        delete prescription;
        prescription = nullptr; // Prevent double deletion
    }

    // ASSUMPTION: MedicalRecord does NOT own Patient* or Doctor* objects,
    // so no 'delete patient;' or 'delete doctor;' here. They are managed externally.

    DECREMENT_COUNTER("MedicalRecord");
    Logger::getInstance()->logDeleted("MedicalRecord");
}

// Getter implementations
string MedicalRecord::getRecordID() const { return recordID; }
Patient* MedicalRecord::getPatient() const { return patient; }
Doctor* MedicalRecord::getDoctor() const { return doctor; }
string MedicalRecord::getAdmissionDate() const { return admissionDate; }
string MedicalRecord::getDiagnosis() const { return diagnosis; }
string MedicalRecord::getTreatment() const { return treatment; }
Prescription* MedicalRecord::getPrescription() const { return prescription; }

// Setter implementations
void MedicalRecord::setRecordID(string id) { recordID = id; }
void MedicalRecord::setPatient(Patient* pat) { patient = pat; }
void MedicalRecord::setDoctor(Doctor* doc) { doctor = doc; }
void MedicalRecord::setAdmissionDate(string date) { admissionDate = date; }
void MedicalRecord::setDiagnosis(string diag) { diagnosis = diag; }
void MedicalRecord::setTreatment(string treat) { treatment = treat; }

void MedicalRecord::setPrescription(Prescription* presc) {
    // If setting a new prescription, delete the old one if owned
    if (prescription && prescription != presc) { // Avoid deleting if setting to same pointer
        delete prescription;
    }
    prescription = presc;
}

// toString() implementation
string MedicalRecord::toString() const {
    string patName = (patient ? patient->getName() : "N/A");
    string docName = (doctor ? doctor->getName() : "N/A");
    return "Medical Record ID: " + getRecordID() + ", Patient: " + patName + ", Doctor: " + docName;
}

// getDetailedInfo() implementation - ADDED
string MedicalRecord::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Medical Record Details ---\n";
    ss << "  Record ID     : " << getRecordID() << "\n";
    ss << "  Patient       : " << (patient ? patient->getName() + " (ID: " + patient->getPatientID() + ")" : "N/A") << "\n";
    ss << "  Doctor        : " << (doctor ? doctor->getName() + " (ID: " + doctor->getID() + ")" : "N/A") << "\n";
    ss << "  Admission Date: " << getAdmissionDate() << "\n";
    ss << "  Diagnosis     : " << getDiagnosis() << "\n";
    ss << "  Treatment     : " << getTreatment() << "\n";
    ss << "  Prescription  :\n";
    if (prescription) {
        ss << prescription->getDetailedInfo() << "\n";
    } else {
        ss << "    No prescription issued.\n";
    }
    return ss.str();
}