#include "Supplier.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>                 // For std::stringstream

using std::string; // Use using declaration in .cpp for convenience

// Constructor implementation
Supplier::Supplier(string id, string name, string mobile)
    : supplierID(id), name(name), mobile(mobile) {
    INCREMENT_COUNTER("Supplier");
    Logger::getInstance()->logCreated("Supplier");
    Logger::getInstance()->logGenericCount("Supplier");
}

// Destructor implementation
Supplier::~Supplier() {
    DECREMENT_COUNTER("Supplier");
    Logger::getInstance()->logDeleted("Supplier");
}

// Getter implementations
string Supplier::getSupplierID() const { return supplierID; }
string Supplier::getName() const { return name; }
string Supplier::getMobile() const { return mobile; }

// Setter implementations
void Supplier::setSupplierID(string id) { supplierID = id; }
void Supplier::setName(string n) { name = n; }
void Supplier::setMobile(string m) { mobile = m; }

// toString() implementation
string Supplier::toString() const {
    return getName() + " (ID: " + getSupplierID() + ", Mobile: " + getMobile() + ")";
}

// getDetailedInfo() implementation - ADDED
string Supplier::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Supplier Details ---\n";
    ss << "  Supplier ID: " << getSupplierID() << "\n";
    ss << "  Name       : " << getName() << "\n";
    ss << "  Mobile     : " << getMobile() << "\n";
    return ss.str();
}