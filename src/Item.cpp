#include "Item.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>                 // For std::stringstream
#include <iomanip>                 // For std::fixed, std::setprecision

using std::string; // Use using declaration in .cpp for convenience

// Constructor implementation
Item::Item(string id, string name, double price)
    : itemID(id), itemName(name), unitPrice(price) {
    INCREMENT_COUNTER("Item");
    Logger::getInstance()->logCreated("Item");
    Logger::getInstance()->logGenericCount("Item");
}

// Destructor implementation
Item::~Item() {
    DECREMENT_COUNTER("Item");
    Logger::getInstance()->logDeleted("Item");
}

// Getter implementations
string Item::getItemID() const { return itemID; }
string Item::getItemName() const { return itemName; }
double Item::getUnitPrice() const { return unitPrice; }

// Setter implementations
void Item::setItemID(string id) { itemID = id; }
void Item::setItemName(string name) { itemName = name; }
void Item::setUnitPrice(double price) { unitPrice = price; }

// toString() implementation
string Item::toString() const {
    return getItemName() + " (ID: " + getItemID() + ", Price: " + std::to_string(getUnitPrice()) + ")";
}

// getDetailedInfo() implementation - ADDED
string Item::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Item Details ---\n";
    ss << "  Item ID   : " << getItemID() << "\n";
    ss << "  Item Name : " << getItemName() << "\n";
    ss << "  Unit Price: " << std::fixed << std::setprecision(2) << getUnitPrice() << "\n";
    return ss.str();
}