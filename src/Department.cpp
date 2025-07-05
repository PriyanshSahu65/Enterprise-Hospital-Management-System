#include "Department.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>                 // For std::stringstream

using std::string;
using std::vector;

// Constructor implementation
Department::Department(string id, string name, string description, vector<Doctor*> doctors)
    : departmentID(id), name(name), description(description) {
    // Deep copy doctors here if Department OWNS them.
    // Assuming Department manages the lifetime of these Doctor objects.
    for (Doctor* doc : doctors) {
        this->doctors.push_back(doc); // Takes ownership of the passed pointers
    }

    ObjectCounter::getInstance()->increment("Department");
    Logger::getInstance()->logCreated("Department");
    Logger::getInstance()->logGenericCount("Department");
}

// Destructor implementation - CRITICAL for memory management of Doctor objects
Department::~Department() {
    // Delete all Doctor objects owned by this Department
    for (Doctor* doc : doctors) {
        delete doc; // ASSUMPTION: Department owns the Doctor objects.
                    // If doctors are managed by a central cache (e.g., ObjectCache),
                    // then DO NOT delete them here.
    }
    doctors.clear(); // Clear the vector after deleting objects

    ObjectCounter::getInstance()->decrement("Department");
    Logger::getInstance()->logDeleted("Department");
}

// Getter implementations
string Department::getDepartmentID() const { return departmentID; }
string Department::getName() const { return name; }
string Department::getDescription() const { return description; } // Implementation for new getter
const vector<Doctor*>& Department::getDoctors() const { return doctors; }

// Setter implementations
void Department::setDepartmentID(string id) { departmentID = id; }
void Department::setName(string n) { name = n; }
void Department::setDescription(string desc) { description = desc; } // Implementation for new setter

void Department::setDoctors(vector<Doctor*> newDoctors) {
    // First, delete existing Doctor objects if owned
    for (Doctor* doc : doctors) {
        delete doc;
    }
    doctors.clear();

    // Now, take ownership of new Doctor objects
    for (Doctor* doc : newDoctors) {
        this->doctors.push_back(doc);
    }
}

// toString() implementation
string Department::toString() const {
    std::stringstream ss;
    ss << "Department ID: " << getDepartmentID() << ", Name: " << getName() << ", Doctors: " << doctors.size();
    return ss.str();
}

// getDetailedInfo() implementation - ADDED
string Department::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Department Details ---\n";
    ss << "  Department ID : " << getDepartmentID() << "\n";
    ss << "  Name          : " << getName() << "\n";
    ss << "  Description   : " << getDescription() << "\n";
    ss << "  Doctors       :\n";
    if (doctors.empty()) {
        ss << "    No doctors assigned.\n";
    } else {
        for (const Doctor* doc : doctors) {
            if (doc) {
                ss << "    - " << doc->getName() << " (ID: " << doc->getID() << ", Spec: " << doc->getSpecialization() << ")\n";
            }
        }
    }
    return ss.str();
}