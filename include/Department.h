#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string> // For std::string
#include <vector> // For std::vector
#include "DataObject.h" // ADDED: Department now inherits from DataObject
#include "Doctor.h"     // Uses Doctor*

// Removed 'using namespace std;' from header

class Department : public DataObject { // CORRECTED: Inherit from DataObject
private:
    std::string departmentID;
    std::string name;
    std::vector<Doctor*> doctors; // Vector of pointers to Doctor objects
    std::string description; // Added getter/setter for consistency

public:
    Department(std::string id, std::string name, std::string description, std::vector<Doctor*> doctors);

    // Destructor - Crucial if Department owns the Doctor objects (deletes them)
    // Declared as virtual override because DataObject has a virtual destructor.
    ~Department() override;

    std::string getDepartmentID() const;
    std::string getName() const;
    std::string getDescription() const; // ADDED: Getter for description
    const std::vector<Doctor*>& getDoctors() const; // Returns const reference to prevent external modification

    void setDepartmentID(std::string id);
    void setName(std::string name);
    void setDescription(std::string description); // ADDED: Setter for description
    void setDoctors(std::vector<Doctor*> doctors); // Handles existing doctors (deletes old ones, sets new)

    // Ensure toString() and getDetailedInfo() are properly overridden from DataObject
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // DEPARTMENT_H