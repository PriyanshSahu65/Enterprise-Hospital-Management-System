#include "Prescription.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>                 // For std::stringstream
#include <algorithm>               // For std::remove_if

using std::string;
using std::vector;

// Default constructor implementation (if defined in header)
Prescription::Prescription()
    : prescriptionID(""), dateIssued(""), dosageInstructions("") {
    ObjectCounter::getInstance()->increment("Prescription");
    Logger::getInstance()->logCreated("Prescription");
    Logger::getInstance()->logGenericCount("Prescription");
}

// Parameterized constructor implementation
Prescription::Prescription(string id, string date, vector<Item*> items, string instructions)
    : prescriptionID(id), dateIssued(date), dosageInstructions(instructions) {
    // Deep copy items here if Prescription OWNS them.
    // Assuming Prescription manages the lifetime of these Item objects.
    for (Item* item : items) {
        this->prescribedItems.push_back(item); // Takes ownership of the passed pointers
    }

    ObjectCounter::getInstance()->increment("Prescription");
    Logger::getInstance()->logCreated("Prescription");
    Logger::getInstance()->logGenericCount("Prescription");
}

// Destructor implementation - CRITICAL for memory management of Item objects
Prescription::~Prescription() {
    // Delete all Item objects owned by this Prescription
    for (Item* item : prescribedItems) {
        delete item; // ASSUMPTION: Prescription owns the Item objects.
                     // If items are managed by a central cache, DO NOT delete them here.
    }
    prescribedItems.clear(); // Clear the vector after deleting objects

    ObjectCounter::getInstance()->decrement("Prescription");
    Logger::getInstance()->logDeleted("Prescription");
}

// Getter implementations
string Prescription::getPrescriptionID() const { return prescriptionID; }
string Prescription::getDateIssued() const { return dateIssued; }
const vector<Item*>& Prescription::getPrescribedItems() const { return prescribedItems; }
string Prescription::getDosageInstructions() const { return dosageInstructions; }

// Setter implementations
void Prescription::setPrescriptionID(string id) { prescriptionID = id; }
void Prescription::setDateIssued(string date) { dateIssued = date; }
void Prescription::setDosageInstructions(string instructions) { dosageInstructions = instructions; }

void Prescription::setPrescribedItems(vector<Item*> newItems) {
    // First, delete existing Item objects if owned
    for (Item* item : prescribedItems) {
        delete item;
    }
    prescribedItems.clear();

    // Now, take ownership of new Item objects
    for (Item* item : newItems) {
        this->prescribedItems.push_back(item);
    }
}

// Add a single prescribed item
void Prescription::addPrescribedItem(Item* item) {
    if (item) {
        prescribedItems.push_back(item); // Take ownership
        Logger::getInstance()->logActivity("Prescription", "Added Item: " + item->toString());
    }
}

// Remove a prescribed item by its Item ID
void Prescription::removePrescribedItem(const string& itemID) {
    auto it = std::remove_if(prescribedItems.begin(), prescribedItems.end(),
        [&](Item* item) {
            if (item && item->getItemID() == itemID) {
                delete item; // Delete the owned object
                Logger::getInstance()->logActivity("Prescription", "Removed Item with ID: " + itemID);
                return true;
            }
            return false;
        });
    prescribedItems.erase(it, prescribedItems.end());
}


// toString() implementation
string Prescription::toString() const {
    std::stringstream ss;
    ss << "Prescription ID: " << getPrescriptionID() << ", Date: " << getDateIssued() << ", Items: " << prescribedItems.size();
    return ss.str();
}

// getDetailedInfo() implementation - ADDED
string Prescription::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Prescription Details ---\n";
    ss << "  Prescription ID   : " << getPrescriptionID() << "\n";
    ss << "  Date Issued       : " << getDateIssued() << "\n";
    ss << "  Dosage Instructions: " << getDosageInstructions() << "\n";
    ss << "  Prescribed Items  :\n";
    if (prescribedItems.empty()) {
        ss << "    No items prescribed.\n";
    } else {
        for (const Item* item : prescribedItems) {
            if (item) {
                ss << "    - " << item->getItemName() << " (ID: " << item->getItemID() << ", Price: " << item->getUnitPrice() << ")\n";
            }
        }
    }
    return ss.str();
}