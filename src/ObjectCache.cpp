#include "ObjectCache.h"
#include <algorithm>

ObjectCache* ObjectCache::instance = nullptr;

ObjectCache* ObjectCache::getInstance() {
    if (!instance) instance = new ObjectCache();
    return instance;
}

void ObjectCache::touchLRU(std::list<std::string>& lru, const std::string& key) {
    lru.remove(key);
    lru.push_front(key);
}

// --- Patient ---
void ObjectCache::addPatient(Patient* p) {
    std::string id = p->getID();
    if (patients.count(id)) {
        delete patients[id];
        lruPatients.remove(id);
    }
    patients[id] = p;
    lruPatients.push_front(id);
    if (lruPatients.size() > maxSize) {
        std::string old = lruPatients.back();
        delete patients[old];
        patients.erase(old);
        lruPatients.pop_back();
    }
}
Patient* ObjectCache::getPatient(const std::string& id) {
    if (patients.count(id)) {
        touchLRU(lruPatients, id);
        return patients[id];
    }
    return nullptr;
}
void ObjectCache::releasePatients() {
    for (auto& pair : patients) delete pair.second;
    patients.clear();
    lruPatients.clear();
}

// --- Doctor ---
void ObjectCache::addDoctor(Doctor* d) {
    std::string id = d->getID();
    if (doctors.count(id)) {
        delete doctors[id];
        lruDoctors.remove(id);
    }
    doctors[id] = d;
    lruDoctors.push_front(id);
    if (lruDoctors.size() > maxSize) {
        std::string old = lruDoctors.back();
        delete doctors[old];
        doctors.erase(old);
        lruDoctors.pop_back();
    }
}
Doctor* ObjectCache::getDoctor(const std::string& id) {
    if (doctors.count(id)) {
        touchLRU(lruDoctors, id);
        return doctors[id];
    }
    return nullptr;
}
void ObjectCache::releaseDoctors() {
    for (auto& pair : doctors) delete pair.second;
    doctors.clear();
    lruDoctors.clear();
}

// --- Department ---
void ObjectCache::addDepartment(Department* d) {
    std::string id = d->getDepartmentID();
    if (departments.count(id)) {
        delete departments[id];
        lruDepartments.remove(id);
    }
    departments[id] = d;
    lruDepartments.push_front(id);
    if (lruDepartments.size() > maxSize) {
        std::string old = lruDepartments.back();
        delete departments[old];
        departments.erase(old);
        lruDepartments.pop_back();
    }
}
Department* ObjectCache::getDepartment(const std::string& id) {
    if (departments.count(id)) {
        touchLRU(lruDepartments, id);
        return departments[id];
    }
    return nullptr;
}
void ObjectCache::releaseDepartments() {
    for (auto& pair : departments) delete pair.second;
    departments.clear();
    lruDepartments.clear();
}

// --- MedicalRecord ---
void ObjectCache::addMedicalRecord(MedicalRecord* m) {
    std::string id = m->getRecordID();
    if (medicalRecords.count(id)) {
        delete medicalRecords[id];
        lruMedicalRecords.remove(id);
    }
    medicalRecords[id] = m;
    lruMedicalRecords.push_front(id);
    if (lruMedicalRecords.size() > maxSize) {
        std::string old = lruMedicalRecords.back();
        delete medicalRecords[old];
        medicalRecords.erase(old);
        lruMedicalRecords.pop_back();
    }
}
MedicalRecord* ObjectCache::getMedicalRecord(const std::string& id) {
    if (medicalRecords.count(id)) {
        touchLRU(lruMedicalRecords, id);
        return medicalRecords[id];
    }
    return nullptr;
}
void ObjectCache::releaseMedicalRecords() {
    for (auto& pair : medicalRecords) delete pair.second;
    medicalRecords.clear();
    lruMedicalRecords.clear();
}

// --- Prescription ---
void ObjectCache::addPrescription(Prescription* p) {
    std::string id = p->getPrescriptionID();
    if (prescriptions.count(id)) {
        delete prescriptions[id];
        lruPrescriptions.remove(id);
    }
    prescriptions[id] = p;
    lruPrescriptions.push_front(id);
    if (lruPrescriptions.size() > maxSize) {
        std::string old = lruPrescriptions.back();
        delete prescriptions[old];
        prescriptions.erase(old);
        lruPrescriptions.pop_back();
    }
}
Prescription* ObjectCache::getPrescription(const std::string& id) {
    if (prescriptions.count(id)) {
        touchLRU(lruPrescriptions, id);
        return prescriptions[id];
    }
    return nullptr;
}
void ObjectCache::releasePrescriptions() {
    for (auto& pair : prescriptions) delete pair.second;
    prescriptions.clear();
    lruPrescriptions.clear();
}
