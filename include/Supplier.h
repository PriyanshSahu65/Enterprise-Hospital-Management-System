#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "DataObject.h" // ADDED: Inherits from DataObject
#include <string>       // For std::string

// Removed 'using namespace std;' from header

class Supplier : public DataObject { // ADDED: Inherits from DataObject
private:
    std::string supplierID;
    std::string name;
    std::string mobile;
public:
    Supplier(std::string id, std::string name, std::string mobile);

    // Destructor (virtual from DataObject)
    ~Supplier() override; // Added override keyword

    std::string getSupplierID() const;
    std::string getName() const;
    std::string getMobile() const;

    void setSupplierID(std::string id);
    void setName(std::string name);
    void setMobile(std::string mobile);

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // SUPPLIER_H