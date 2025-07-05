#ifndef ADMINISTRATIVESTAFF_H
#define ADMINISTRATIVESTAFF_H

#include "Staff.h" // AdministrativeStaff inherits from Staff
#include <string>  // For std::string (though Staff.h should bring it)

// Removed 'using namespace std;' from header

class AdministrativeStaff : public Staff { // Already correctly inherits from Staff
private:
    std::string designation;
public:
    AdministrativeStaff(std::string id, std::string name, std::string dob,
                        std::string gender, std::string mobile, std::string city,
                        std::string designation);

    // Destructor declared as override, implicitly virtual from base classes
    ~AdministrativeStaff() override;

    std::string getDesignation() const;
    void setDesignation(std::string designation);

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // ADMINISTRATIVESTAFF_H