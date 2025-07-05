// include/DataObject.h
#ifndef DATA_OBJECT_H
#define DATA_OBJECT_H

#include <string>
#include <vector>
#include <iostream> // Still useful for derived classes if they print directly

// The abstract base class for all data objects.
// As per your request, it now contains ONLY a virtual destructor.
class DataObject {
public:
    // Virtual destructor: Essential for proper polymorphic cleanup of derived classes
    // when deleted via a base class pointer.
    virtual ~DataObject() = default;

    // No other methods are declared here, as per your instruction.
    // This means derived classes will need their own specific methods for functionality,
    // and common operations like printing cannot be done polymorphically via DataObject*.
};

// --- Placeholder Concrete DataObject Types (for demonstration/testing) ---
// These now only implement their constructors and a local toString() for their own use,
// but they DO NOT override a toString() from DataObject because DataObject no longer has it.
// They still inherit from DataObject to be managed by the Builder.

class DepartmentDataObject : public DataObject {
private:
    std::string name;
    std::string location;
public:
    DepartmentDataObject(const std::string& name = "", const std::string& location = "")
        : name(name), location(location) {}

    // No override for toString() from DataObject, as DataObject doesn't have it.
    std::string getInfoString() const { // Renamed to avoid confusion with DataObject's previous toString
        return "Placeholder Department: " + name + ", Location: " + location;
    }
};

class DoctorDataObject : public DataObject {
private:
    std::string name;
    std::string specialty;
public:
    DoctorDataObject(const std::string& name = "", const std::string& specialty = "")
        : name(name), specialty(specialty) {}

    // No override for toString() from DataObject
    std::string getInfoString() const { // Renamed
        return "Placeholder Doctor: " + name + ", Specialty: " + specialty;
    }
};

class PatientDataObject : public DataObject {
private:
    std::string name;
    int age;
public:
    PatientDataObject(const std::string& name = "", int age = 0)
        : name(name), age(age) {}

    // No override for toString() from DataObject
    std::string getInfoString() const { // Renamed
        return "Placeholder Patient: " + name + ", Age: " + std::to_string(age);
    }
};

#endif // DATA_OBJECT_H