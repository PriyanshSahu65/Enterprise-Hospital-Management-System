#ifndef SHIFTSCHEDULE_H
#define SHIFTSCHEDULE_H

#include "DataObject.h"   // Inherits from DataObject
#include "ShiftDetails.h" // Needs ShiftDetails definition
#include <string>         // For std::string
#include <vector>         // For std::vector

// Removed 'using namespace std;' from header

class ShiftSchedule : public DataObject {
private:
    std::string scheduleID;
    std::vector<ShiftDetails*> shifts; // Vector of pointers to ShiftDetails objects (Assumed OWNED by ShiftSchedule)

public:
    // Default constructor (if needed)
    ShiftSchedule();
    ShiftSchedule(std::string id, std::vector<ShiftDetails*> shifts);

    // Destructor (virtual from DataObject)
    // Crucial if ShiftSchedule owns the ShiftDetails objects (deletes them)
    ~ShiftSchedule() override; // Added override keyword

    std::string getScheduleID() const;
    const std::vector<ShiftDetails*>& getShifts() const; // Returns const reference

    void setScheduleID(std::string id);
    void setShifts(std::vector<ShiftDetails*> newShifts); // Handles existing shifts (deletes old ones, sets new)
    void addShift(ShiftDetails* shift); // Adds a single shift
    void removeShift(const std::string& shiftID); // Removes shift by ID

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject

    // Utility method to get a summary string for Doctor/Nurse detailed info
    std::string getInfoString() const;
};

#endif // SHIFTSCHEDULE_H