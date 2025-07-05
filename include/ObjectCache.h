#ifndef OBJECTCACHE_H
#define OBJECTCACHE_H

#include <unordered_map>
#include <list>
#include <string>
#include <vector>
#include "Patient.h"
#include "Doctor.h"
#include "Department.h"
#include "MedicalRecord.h"
#include "Prescription.h"

class ObjectCache {
private:
    static ObjectCache* instance;
    // LRU cache for each type
    size_t maxSize = 100;
    // Patient
    std::unordered_map<std::string, Patient*> patients;
    std::list<std::string> lruPatients;
    // Doctor
    std::unordered_map<std::string, Doctor*> doctors;
    std::list<std::string> lruDoctors;
    // Department
    std::unordered_map<std::string, Department*> departments;
    std::list<std::string> lruDepartments;
    // MedicalRecord
    std::unordered_map<std::string, MedicalRecord*> medicalRecords;
    std::list<std::string> lruMedicalRecords;
    // Prescription
    std::unordered_map<std::string, Prescription*> prescriptions;
    std::list<std::string> lruPrescriptions;

    ObjectCache() = default;
    void touchLRU(std::list<std::string>& lru, const std::string& key);
    void evictIfNeeded(std::unordered_map<std::string, void*>& map, std::list<std::string>& lru);
public:
    static ObjectCache* getInstance();
    // Patient
    void addPatient(Patient* p);
    Patient* getPatient(const std::string& id);
    void releasePatients();
    // Doctor
    void addDoctor(Doctor* d);
    Doctor* getDoctor(const std::string& id);
    void releaseDoctors();
    // Department
    void addDepartment(Department* d);
    Department* getDepartment(const std::string& id);
    void releaseDepartments();
    // MedicalRecord
    void addMedicalRecord(MedicalRecord* m);
    MedicalRecord* getMedicalRecord(const std::string& id);
    void releaseMedicalRecords();
    // Prescription
    void addPrescription(Prescription* p);
    Prescription* getPrescription(const std::string& id);
    void releasePrescriptions();
};

#endif // OBJECTCACHE_H
