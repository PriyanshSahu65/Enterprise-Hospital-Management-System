#ifndef LAB_H
#define LAB_H

#include "DataObject.h" // Inherits from DataObject
#include "AdministrativeStaff.h" // Needs AdministrativeStaff definition
#include "Test.h"       // Needs Test definition
#include <string>       // For std::string
#include <vector>       // For std::vector

// Removed 'using namespace std;' from header

class Lab : public DataObject {
private:
    std::string labID;
    std::string name;
    AdministrativeStaff* inCharge; // Pointer to administrative staff in charge (Assumed NOT owned)
    std::vector<Test*> tests; // Vector of pointers to Test objects (Assumed OWNED by Lab)

public:
    // Default constructor (if needed)
    Lab();
    Lab(std::string id, std::string name, AdministrativeStaff* inCharge, std::vector<Test*> tests);

    // Destructor (virtual from DataObject)
    // Crucial if Lab owns the Test objects (deletes them)
    ~Lab() override; // Added override keyword

    std::string getLabID() const;
    std::string getName() const;
    AdministrativeStaff* getInCharge() const; // Returns pointer
    const std::vector<Test*>& getTests() const; // Returns const reference

    void setLabID(std::string id);
    void setName(std::string name);
    void setInCharge(AdministrativeStaff* staff); // Takes pointer
    void setTests(std::vector<Test*> newTests); // Handles existing tests (deletes old ones, sets new)
    void addTest(Test* test); // Adds a single test
    void removeTest(const std::string& testID); // Removes test by ID

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // LAB_H