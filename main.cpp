// Include all your domain headers
#include "include/Person.h"
#include "include/Staff.h"
#include "include/Doctor.h"
#include "include/Nurse.h"
#include "include/AdministrativeStaff.h"
#include "include/Patient.h"
#include "include/MedicalRecord.h"
#include "include/Appointment.h"
#include "include/Prescription.h"
#include "include/Billing.h"
#include "include/Department.h"
#include "include/Item.h"
#include "include/Supplier.h"
#include "include/StockItem.h"
#include "include/Inventory.h"
#include "include/ShiftDetails.h"
#include "include/ShiftSchedule.h"
#include "include/Test.h"
#include "include/Lab.h"
#include "include/DataObject.h" // Assuming DataObject is a base class for polymorphic behavior

// Utility includes
#include "include/ObjectCounter.h" // For getting counts
#include "include/Logger.h"        // Our custom Logger
#include "utils/BuilderFactory.h"
#include "utils/DoctorBuilder.h"
#include "utils/PatientBuilder.h"
#include "utils/NurseBuilder.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip> 

using namespace std;

// Helper function to print all object counts
void printAllObjectCounts() {
    Logger::getInstance()->logActivity("main", "Displaying current object counts.");
    cout << "\n--- Current Object Counts ---" << endl;
    const map<string, int>& counts = ObjectCounter::getInstance()->getCounter();
    if (counts.empty()) {
        cout << "No objects tracked yet." << endl;
    } else {
        for (const auto& pair : counts) {
            cout << "  " << pair.first << ": " << pair.second << endl;
        }
    }
    cout << "-----------------------------" << endl;
}

int main() {
    // early instance creation
    Logger* logger = Logger::getInstance();
    ObjectCounter* objCounter = ObjectCounter::getInstance();

    logger->log("Application started.");
    printAllObjectCounts();

    const char* doctorCsv = "../data/doctors_large.csv";
    const char* patientCsv = "../data/patients_large.csv";
    const char* nurseCsv = "../data/nurses_large.csv";
    const char* adminCsv = "../data/admins_large.csv";
    const char* departmentCsv = "../data/departments_large.csv";
    const char* appointmentCsv = "../data/appointments_large.csv";
    const char* medicalRecordCsv = "../data/medicalrecords_large.csv";
    const char* prescriptionCsv = "../data/prescriptions_large.csv";
    const char* billingCsv = "../data/billing_large.csv";
    const char* itemCsv = "../data/items_large.csv";
    const char* supplierCsv = "../data/suppliers_large.csv";
    const char* stockItemCsv = "../data/stockitems_large.csv";
    const char* inventoryCsv = "../data/inventory_large.csv";
    const char* labCsv = "../data/labs_large.csv";
    const char* testCsv = "../data/tests_large.csv";
    const char* shiftDetailsCsv = "../data/shiftdetails_large.csv";
    const char* shiftScheduleCsv = "../data/shiftschedules_large.csv";

    std::map<std::string, std::vector<DataObject*>*> loadedObjects;
    
    // Helper lambda for loading and reporting any entity
    auto loadEntity = [&](const string& label, auto& builder, const char* path) {
        cout << "Loading " << label << "..." << endl;
        try {
            builder.setFilePath(path);
            loadedObjects[label] = builder.makeDataObjectList();
        } catch (const std::exception& ex) {
            Logger::getInstance()->log(label + "Builder error: " + ex.what());
            cout << "[ERROR] " << label << "Builder: " << ex.what() << endl;
        }
    };

    DoctorBuilder doctorBuilder;
    loadEntity("Doctor", doctorBuilder, doctorCsv);
    PatientBuilder patientBuilder;
    loadEntity("Patient", patientBuilder, patientCsv);
    NurseBuilder nurseBuilder;
    loadEntity("Nurse", nurseBuilder, nurseCsv);

    //obj count
    cout << "\nObjects created:" << endl;
    const map<string, int>& counts = ObjectCounter::getInstance()->getCounter();
    for (const auto& key : {"Doctor", "Nurse", "Patient", "Person", "ShiftSchedule", "Staff"}) {
        cout << "  " << key << ": " << (counts.count(key) ? counts.at(key) : 0) << endl;
    }

    //release
    cout << "\nReleasing all objs" << endl;
    for (auto& it : loadedObjects) {
        if (it.second) { for (auto* obj : *it.second) delete obj; delete it.second; }
    }
    loadedObjects.clear();

    //obj count
    const map<string, int>& countsAfter = ObjectCounter::getInstance()->getCounter();
    for (const auto& key : {"Doctor", "Nurse", "Patient", "Person", "ShiftSchedule", "Staff"}) {
        cout << "  " << key << ": " << (countsAfter.count(key) ? countsAfter.at(key) : 0) << endl;
    }

    logger->log("All dynamically allocated objects from main() deleted.");
    logger->log("Application finished.");
    return 0;
}