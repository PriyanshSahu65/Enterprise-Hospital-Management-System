#ifndef PERSON_H
#define PERSON_H

#include "DataObject.h" // Person inherits from DataObject
#include <string>       // For std::string

// Removed 'using namespace std;' from header

class Person : public DataObject { // Already correctly inherits from DataObject
protected: // Changed to protected as derived classes might need access
    std::string ID;
    std::string name;
    std::string dob; // Date of Birth
    std::string gender;
    std::string mobile;
    std::string city;

public:
    Person(std::string ID, std::string name, std::string dob,
           std::string gender, std::string mobile, std::string city);

    // Destructor declared as override, explicitly virtual from DataObject
    ~Person() override;

    std::string getID() const;
    std::string getName() const;
    std::string getDob() const;
    std::string getGender() const;
    std::string getMobile() const;
    std::string getCity() const;

    void setID(std::string ID);
    void setName(std::string name);
    void setDob(std::string dob);
    void setGender(std::string gender);
    void setMobile(std::string mobile);
    void setCity(std::string city);

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // PERSON_H