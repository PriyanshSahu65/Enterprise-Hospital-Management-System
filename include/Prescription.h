#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H

#include "DataObject.h" // Inherits from DataObject
#include "Item.h"       // Needs Item definition
#include <string>       // For std::string
#include <vector>       // For std::vector

// Removed 'using namespace std;' from header

class Prescription : public DataObject {
private:
    std::string prescriptionID;
    std::string dateIssued;
    std::vector<Item*> prescribedItems; // Vector of pointers to Item objects (Assumed OWNED by Prescription)
    std::string dosageInstructions;

public:
    // Default constructor (if needed)
    Prescription();
    Prescription(std::string id, std::string date, std::vector<Item*> items, std::string instructions);

    // Destructor (virtual from DataObject)
    // Crucial if Prescription owns the Item objects (deletes them)
    ~Prescription() override; // Added override keyword

    std::string getPrescriptionID() const;
    std::string getDateIssued() const;
    const std::vector<Item*>& getPrescribedItems() const; // Returns const reference
    std::string getDosageInstructions() const;

    void setPrescriptionID(std::string id);
    void setDateIssued(std::string date);
    void setPrescribedItems(std::vector<Item*> items); // Handles existing items (deletes old ones, sets new)
    void setDosageInstructions(std::string instructions);
    void addPrescribedItem(Item* item); // Adds a single item
    void removePrescribedItem(const std::string& itemID); // Removes item by ID

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // PRESCRIPTION_H