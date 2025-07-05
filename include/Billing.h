#ifndef BILLING_H
#define BILLING_H

#include "DataObject.h"   // Inherits from DataObject
#include "Patient.h"      // Needs Patient definition
#include <vector>         // For std::vector
#include <string>         // For std::string

// Removed 'using namespace std;' from header

class Billing : public DataObject {
private:
    std::string billID;
    Patient* patient; // CORRECTED: Changed from Patient to Patient*
    std::vector<std::string> servicesProvided;
    double cost;
    bool paymentStatus;

public:
    // Default constructor (if needed)
    Billing();
    // Parameterized constructor - CORRECTED parameter to take Patient*
    Billing(std::string billID, Patient* pat, std::vector<std::string> servicesProvided, double cost);

    // Destructor (virtual from DataObject)
    ~Billing() override; // Added override keyword

    std::string getBillID() const;
    void setBillID(std::string billID);

    Patient* getPatient() const; // CORRECTED: Return Patient*
    void setPatient(Patient* pat); // CORRECTED: Take Patient*

    std::vector<std::string> getServicesProvided() const;
    void setServicesProvided(std::vector<std::string> servicesProvided);

    double getCost() const;
    void setCost(double cost);

    bool getPaymentStatus() const;
    void setPaymentStatus(bool paymentStatus);

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // BILLING_H