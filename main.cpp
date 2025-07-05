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
#include <iomanip> // For std::fixed and std::setprecision



// Use standard namespace within main.cpp for convenience
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
    // Ensure Logger and ObjectCounter instances are created early
    Logger* logger = Logger::getInstance();
    ObjectCounter* objCounter = ObjectCounter::getInstance();

    logger->log("Application started.");
    printAllObjectCounts();

    cout << "\n--- Creating Hospital Objects ---" << endl;

    // --- Shift Scheduling ---
    ShiftDetails* shiftMorningDoc = new ShiftDetails("SD001", "Monday", "09:00", "17:00");
    ShiftDetails* shiftEveningNurse = new ShiftDetails("SD002", "Tuesday", "14:00", "22:00");
    ShiftDetails* shiftAdminMorning = new ShiftDetails("SD003", "Wednesday", "08:00", "16:00");

    vector<ShiftDetails*> docShifts = {shiftMorningDoc};
    ShiftSchedule* docSchedule = new ShiftSchedule("SCH001", docShifts); // Takes ownership of shiftMorningDoc
    cout << "Created: " << docSchedule->toString() << endl;

    vector<ShiftDetails*> nurseShifts = {shiftEveningNurse};
    ShiftSchedule* nurseSchedule = new ShiftSchedule("SCH002", nurseShifts); // Takes ownership of shiftEveningNurse
    cout << "Created: " << nurseSchedule->toString() << endl;

    // --- Staff ---
    // Person constructor now takes ID as first argument
    // Doctor constructor takes ShiftSchedule*
    Doctor* doc = new Doctor("D001", "Dr. Riya Sharma", "1980-01-01", "Female", "9988776655", "Delhi", "Cardiologist", docSchedule); // Doctor takes ownership of docSchedule
    cout << "Created: " << doc->toString() << endl;

    Nurse* nurse = new Nurse("N001", "Nina Singh", "1985-05-05", "Female", "9876543210", "Delhi", "ICU", nurseSchedule); // Nurse takes ownership of nurseSchedule
    cout << "Created: " << nurse->toString() << endl;

    AdministrativeStaff* admin = new AdministrativeStaff("A001", "Rajiv Kumar", "1975-03-12", "Male", "9876501234", "Delhi", "Receptionist");
    cout << "Created: " << admin->toString() << endl;

    // --- Patient and Medical Record ---
    // Patient constructor now takes ID as first argument and medicalHistory as last
    Patient* patient = new Patient("P001", "Arjun Reddy", "1990-02-20", "Male", "9000000000", "Mumbai", "No significant history");
    cout << "Created: " << patient->toString() << endl;

    // MedicalRecord constructor takes Patient*, Doctor*, etc.
    MedicalRecord* medRec = new MedicalRecord("MR001", patient, doc, "2025-07-01", "Hypertension", "Medication", nullptr); // Prescription is nullptr for now
    cout << "Created: " << medRec->toString() << endl;

    // --- Appointment and Prescription ---
    // Appointment constructor takes Patient*, Doctor*
    Appointment* appointment = new Appointment("APP001", patient, doc, "2025-07-02 10:30", "Follow-up Checkup");
    cout << "Created: " << appointment->toString() << endl;

    // Create an Item for Prescription
    Item* prescribedItem = new Item("ITM002", "Amlodipine 5mg", 10.00); // Prescription will own this item
    vector<Item*> prescriptionItems = {prescribedItem};
    Prescription* prescription = new Prescription("PR001", "2025-07-02", prescriptionItems, "Take once daily after food."); // Prescription owns prescribedItem
    cout << "Created: " << prescription->toString() << endl;

    // Now set the prescription to the medical record
    medRec->setPrescription(prescription); // MedicalRecord takes ownership of prescription

    // --- Billing ---
    Billing* bill = new Billing("B001", patient, {"Consultation", "Blood Pressure Check"}, 1200.00);
    bill->setPaymentStatus(true);
    cout << "Created: " << bill->toString() << endl;

    // --- Department ---
    vector<Doctor*> departmentDoctors = {doc}; // Department will take ownership of doc
    Department* department = new Department("DEP001", "Cardiology", "Handles heart-related conditions", departmentDoctors); // Department takes ownership of doc
    cout << "Created: " << department->toString() << endl;

    // --- Inventory ---
    Supplier* supplier = new Supplier("SUP001", "MediSupply Ltd.", "9123456789"); // Main owns supplier
    Item* inventoryItem = new Item("ITM003", "Stethoscope", 500.00); // StockItem will own this item
    StockItem* stockItem = new StockItem("2025-06-15", 10, inventoryItem, supplier); // StockItem owns inventoryItem
    Inventory* inventory = new Inventory("INV001", {stockItem}); // Inventory owns stockItem
    cout << "Created: " << inventory->toString() << endl;

    // --- Lab and Tests ---
    Test* bloodSugarTest = new Test("T001", "Blood Sugar", 300.00); // Lab will own this test
    vector<Test*> labTests = {bloodSugarTest};
    Lab* lab = new Lab("L001", "PathLab Diagnostics", admin, labTests); // Lab owns bloodSugarTest
    cout << "Created: " << lab->toString() << endl;

    printAllObjectCounts();

    cout << "\n--- Displaying Detailed Object Information ---" << endl;
    cout << doc->getDetailedInfo() << endl;
    cout << patient->getDetailedInfo() << endl;
    cout << nurse->getDetailedInfo() << endl;
    cout << admin->getDetailedInfo() << endl;
    cout << medRec->getDetailedInfo() << endl;
    cout << appointment->getDetailedInfo() << endl;
    cout << prescription->getDetailedInfo() << endl;
    cout << bill->getDetailedInfo() << endl;
    cout << department->getDetailedInfo() << endl;
    cout << supplier->getDetailedInfo() << endl;
    cout << inventory->getDetailedInfo() << endl;
    cout << shiftMorningDoc->getDetailedInfo() << endl; // Note: shiftMorningDoc is owned by docSchedule, which is owned by doc
    cout << docSchedule->getDetailedInfo() << endl;     // Note: docSchedule is owned by doc
    cout << bloodSugarTest->getDetailedInfo() << endl;  // Note: bloodSugarTest is owned by lab
    cout << lab->getDetailedInfo() << endl;

    // Example of modifying an object and logging activity
    patient->setMobile("9988776655");
    logger->logActivity("Patient", "Updated mobile number for " + patient->getName());
    cout << "Patient " << patient->getName() << " new mobile: " << patient->getMobile() << endl;

    // Example of removing a shift and observing destructor being called implicitly
    // Using docSchedule for demonstration now that schedule1 is removed
    cout << "\n--- Removing Shift from Doctor's Schedule ---" << endl;
    docSchedule->removeShift("SD001"); // Removes shiftMorningDoc
    cout << "Remaining shifts in doctor's schedule: " << docSchedule->getShifts().size() << endl;
    printAllObjectCounts(); // Observe ShiftDetails count change

    // Example usage of BuilderFactory and builders
    Builder* docBuilder = BuilderFactory::createBuilder("Doctor");
    Builder* patientBuilder = BuilderFactory::createBuilder("Patient");
    Builder* nurseBuilder = BuilderFactory::createBuilder("Nurse");
    // Example: constructing empty data (replace with real data as needed)
    std::vector<std::vector<std::string>> dummyData;
    auto doctors = docBuilder->constructDataObject(&dummyData);
    auto patients = patientBuilder->constructDataObject(&dummyData);
    auto nurses = nurseBuilder->constructDataObject(&dummyData);
    // Clean up builders
    delete docBuilder;
    delete patientBuilder;
    delete nurseBuilder;

    // Example: Using makeDataObjectList to load from CSVs
    DoctorBuilder docCsvBuilder;
    auto doctorObjs = docCsvBuilder.makeDataObjectList();
    cout << "\n--- Doctors loaded from CSV ---" << endl;
    for (auto* obj : *doctorObjs) {
        Doctor* d = dynamic_cast<Doctor*>(obj);
        if (d) cout << d->toString() << endl;
    }
    delete doctorObjs;

    PatientBuilder patientCsvBuilder;
    auto patientObjs = patientCsvBuilder.makeDataObjectList();
    cout << "\n--- Patients loaded from CSV ---" << endl;
    for (auto* obj : *patientObjs) {
        Patient* p = dynamic_cast<Patient*>(obj);
        if (p) cout << p->toString() << endl;
    }
    delete patientObjs;

    NurseBuilder nurseCsvBuilder;
    auto nurseObjs = nurseCsvBuilder.makeDataObjectList();
    cout << "\n--- Nurses loaded from CSV ---" << endl;
    for (auto* obj : *nurseObjs) {
        Nurse* n = dynamic_cast<Nurse*>(obj);
        if (n) cout << n->toString() << endl;
    }
    delete nurseObjs;

    // Example: Using makeDataObjectList to load from large CSVs
    // NOTE: makeDataObjectList() does not accept a filename; it loads from the default file.
    // To support custom files, update the builder classes. For now, this will load the default CSVs.
    DoctorBuilder docLargeBuilder;
    auto doctorLargeObjs = docLargeBuilder.makeDataObjectList();
    cout << "\n--- Doctors loaded from large CSV (default file) ---" << endl;
    cout << "Loaded " << doctorLargeObjs->size() << " doctors from large file (default)." << endl;
    delete doctorLargeObjs;

    PatientBuilder patientLargeBuilder;
    auto patientLargeObjs = patientLargeBuilder.makeDataObjectList();
    cout << "\n--- Patients loaded from large CSV (default file) ---" << endl;
    cout << "Loaded " << patientLargeObjs->size() << " patients from large file (default)." << endl;
    delete patientLargeObjs;

    cout << "\n--- Deleting Objects (through main) ---" << endl;
    // Delete objects in reverse dependency order or by their primary owners.
    // Objects created with 'new' in main() must be 'delete'd here.
    // Objects owned by other objects will be deleted by their owners' destructors.

    // Delete top-level objects created in main() that own others
    delete lab;        // Deletes bloodSugarTest
    delete inventory;  // Deletes stockItem, which deletes inventoryItem
    delete department; // Deletes doc, which deletes docSchedule, which deletes shiftMorningDoc
    delete nurse;      // Deletes nurseSchedule, which deletes shiftEveningNurse
    delete patient;    // Patient doesn't own medical records, appointments, prescriptions
    delete admin;      // Admin doesn't own anything here

    // Delete objects created in main() that are NOT owned by others
    delete supplier;   // Supplier is not owned by StockItem based on current design
    delete appointment;
    delete medRec;     // Deletes prescription, which deletes prescribedItem
    delete bill;
    delete shiftAdminMorning; // Clean up unused ShiftDetails to avoid memory leak and object count issue

    // Note: shiftMorningDoc, shiftEveningNurse, prescribedItem, inventoryItem, bloodSugarTest
    // are implicitly deleted by their respective owners (Doctor, Nurse, StockItem, Prescription, Lab).
    // docSchedule and nurseSchedule are deleted by Doctor and Nurse destructors.

    logger->log("All dynamically allocated objects from main() deleted.");
    printAllObjectCounts(); // Should show all counts as 0 if all deletions were successful

    logger->log("Application finished.");
    return 0;
}