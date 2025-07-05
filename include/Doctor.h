#ifndef DOCTOR_H
#define DOCTOR_H

#include "Staff.h"         // Doctor inherits from Staff
#include "ShiftSchedule.h" // Doctor uses ShiftSchedule*
#include <string>          // For std::string

// Removed 'using namespace std;' from header

class Doctor : public Staff { // Already correctly inherits from Staff
private:
    std::string specialization;
    ShiftSchedule* shiftSchedule; // Pointer to ShiftSchedule object

public:
    Doctor(std::string id, std::string name, std::string dob, std::string gender,
           std::string mobile, std::string city, std::string specialization,
           ShiftSchedule* schedule);

    // Destructor declared as override, implicitly virtual from base classes (Staff, Person, DataObject)
    ~Doctor() override;

    std::string getSpecialization() const;
    void setSpecialization(std::string specialization);

    ShiftSchedule* getShiftSchedule() const; // Returns pointer
    void setShiftSchedule(ShiftSchedule* schedule); // Takes pointer

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // DOCTOR_H