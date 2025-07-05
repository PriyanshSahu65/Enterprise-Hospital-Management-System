#ifndef SHIFTDETAILS_H
#define SHIFTDETAILS_H

#include "DataObject.h" // Inherits from DataObject
#include <string>       // For std::string

// Removed 'using namespace std;' from header

class ShiftDetails : public DataObject {
private:
    std::string shiftID;
    std::string dayOfWeek;
    std::string startTime;
    std::string endTime;
public:
    ShiftDetails(std::string id, std::string day, std::string start, std::string end);

    // Destructor (virtual from DataObject)
    ~ShiftDetails() override; // Added override keyword

    std::string getShiftID() const;
    std::string getDayOfWeek() const;
    std::string getStartTime() const;
    std::string getEndTime() const;

    void setShiftID(std::string id);
    void setDayOfWeek(std::string day);
    void setStartTime(std::string start);
    void setEndTime(std::string end);

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // SHIFTDETAILS_H