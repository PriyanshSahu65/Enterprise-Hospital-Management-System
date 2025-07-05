#include "Lab.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>                 // For std::stringstream
#include <algorithm>               // For std::remove_if

using std::string;
using std::vector;

// Default constructor implementation (if defined in header)
Lab::Lab()
    : labID(""), name(""), inCharge(nullptr) {
    INCREMENT_COUNTER("Lab");
    Logger::getInstance()->logCreated("Lab");
    Logger::getInstance()->logGenericCount("Lab");
}

// Parameterized constructor implementation
Lab::Lab(string id, string name, AdministrativeStaff* inChargeStaff, vector<Test*> testList)
    : labID(id), name(name), inCharge(inChargeStaff) {
    // Deep copy tests here if Lab OWNS them.
    // Assuming Lab manages the lifetime of these Test objects.
    for (Test* test : testList) {
        this->tests.push_back(test); // Takes ownership of the passed pointers
    }

    INCREMENT_COUNTER("Lab");
    Logger::getInstance()->logCreated("Lab");
    Logger::getInstance()->logGenericCount("Lab");
}

// Destructor implementation - CRITICAL for memory management of Test objects
Lab::~Lab() {
    // Delete all Test objects owned by this Lab
    for (Test* test : tests) {
        delete test; // ASSUMPTION: Lab owns the Test objects.
                     // If tests are managed by a central cache, DO NOT delete them here.
    }
    tests.clear(); // Clear the vector after deleting objects

    // ASSUMPTION: Lab does NOT own the AdministrativeStaff* inCharge object,
    // so no 'delete inCharge;' here. It is managed externally.

    DECREMENT_COUNTER("Lab");
    Logger::getInstance()->logDeleted("Lab");
}

// Getter implementations
string Lab::getLabID() const { return labID; }
string Lab::getName() const { return name; }
AdministrativeStaff* Lab::getInCharge() const { return inCharge; }
const vector<Test*>& Lab::getTests() const { return tests; }

// Setter implementations
void Lab::setLabID(string id) { labID = id; }
void Lab::setName(string n) { name = n; }
void Lab::setInCharge(AdministrativeStaff* staff) { inCharge = staff; } // Sets pointer

void Lab::setTests(vector<Test*> newTests) {
    // First, delete existing Test objects if owned
    for (Test* test : tests) {
        delete test;
    }
    tests.clear();

    // Now, take ownership of new Test objects
    for (Test* test : newTests) {
        this->tests.push_back(test);
    }
}

// Add a single test
void Lab::addTest(Test* test) {
    if (test) {
        tests.push_back(test); // Take ownership
        Logger::getInstance()->logActivity("Lab", "Added Test: " + test->toString());
    }
}

// Remove a test by its Test ID
void Lab::removeTest(const string& testID) {
    auto it = std::remove_if(tests.begin(), tests.end(),
        [&](Test* test) {
            if (test && test->getTestID() == testID) {
                delete test; // Delete the owned object
                Logger::getInstance()->logActivity("Lab", "Removed Test with ID: " + testID);
                return true;
            }
            return false;
        });
    tests.erase(it, tests.end());
}


// toString() implementation
string Lab::toString() const {
    string inChargeName = (inCharge ? inCharge->getName() : "N/A");
    std::stringstream ss;
    ss << "Lab ID: " << getLabID() << ", Name: " << getName() << ", In Charge: " << inChargeName << ", Tests Offered: " << tests.size();
    return ss.str();
}

// getDetailedInfo() implementation - ADDED
string Lab::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Lab Details ---\n";
    ss << "  Lab ID      : " << getLabID() << "\n";
    ss << "  Name        : " << getName() << "\n";
    ss << "  In Charge   : " << (inCharge ? inCharge->getName() + " (ID: " + inCharge->getID() + ")" : "N/A") << "\n";
    ss << "  Tests Offered:\n";
    if (tests.empty()) {
        ss << "    No tests defined.\n";
    } else {
        for (const Test* test : tests) {
            if (test) {
                ss << "    - " << test->getName() << " (ID: " << test->getTestID() << ", Cost: " << test->getCost() << ")\n";
            }
        }
    }
    return ss.str();
}
