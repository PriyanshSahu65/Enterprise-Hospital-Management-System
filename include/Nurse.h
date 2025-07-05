#ifndef NURSE_H
#define NURSE_H

#include "Staff.h"         // Nurse inherits from Staff
#include "ShiftSchedule.h" // Nurse uses ShiftSchedule*
#include <string>          // For std::string

// Removed 'using namespace std;' from header

class Nurse : public Staff { // Already correctly inherits from Staff
private:
    std::string department;
    ShiftSchedule* shiftSchedule; // Pointer to ShiftSchedule object

public:
    Nurse(std::string id, std::string name, std::string dob, std::string gender,
          std::string mobile, std::string city, std::string department,
          ShiftSchedule* schedule);

    // Destructor declared as override, implicitly virtual from base classes (Staff, Person, DataObject)
    ~Nurse() override;

    std::string getDepartment() const;
    void setDepartment(std::string department);

    ShiftSchedule* getShiftSchedule() const; // Returns pointer
    void setShiftSchedule(ShiftSchedule* schedule); // Takes pointer

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // NURSE_H