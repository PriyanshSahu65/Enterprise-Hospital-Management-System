#ifndef STAFF_H
#define STAFF_H

#include "Person.h" // Staff inherits from Person
#include <string>   // For std::string (though Person.h should bring it)

// Removed 'using namespace std;' from header

class Staff : public Person { // Already correctly inherits from Person
protected: // Changed to protected as derived classes might need access
    std::string staffID; // Redundant if Person::ID is used, but kept for now as per original code structure
    std::string role;
public:
    Staff(std::string id, std::string name, std::string dob,
          std::string gender, std::string mobile, std::string city,
          std::string role);

    // Destructor declared as override, implicitly virtual from base classes (Person, DataObject)
    ~Staff() override;

    // Use Person::getID() for staffID. Keeping redundant staffID member for now.
    // std::string getStaffID() const; // Redundant if Person::ID is used
    std::string getRole() const;

    // void setStaffID(std::string id); // Redundant if Person::ID is used
    void setRole(std::string role);

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // STAFF_H