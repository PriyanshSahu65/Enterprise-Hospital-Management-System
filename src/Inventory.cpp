#include "Inventory.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>                 // For std::stringstream
#include <algorithm>               // For std::remove_if

using std::string;
using std::vector;

// Default constructor implementation (if defined in header)
Inventory::Inventory() : inventoryID("") {
    INCREMENT_COUNTER("Inventory");
    Logger::getInstance()->logCreated("Inventory");
    Logger::getInstance()->logGenericCount("Inventory");
}

// Parameterized constructor implementation
Inventory::Inventory(string id, vector<StockItem*> items)
    : inventoryID(id) {
    // Deep copy items here if Inventory OWNS them.
    // Assuming Inventory manages the lifetime of these StockItem objects.
    for (StockItem* item : items) {
        this->stockItems.push_back(item); // Takes ownership of the passed pointers
    }

    INCREMENT_COUNTER("Inventory");
    Logger::getInstance()->logCreated("Inventory");
    Logger::getInstance()->logGenericCount("Inventory");
}

// Destructor implementation - CRITICAL for memory management of StockItem objects
Inventory::~Inventory() {
    // Delete all StockItem objects owned by this Inventory
    for (StockItem* item : stockItems) {
        delete item; // ASSUMPTION: Inventory owns the StockItem objects.
                     // If items are managed by a central cache, DO NOT delete them here.
    }
    stockItems.clear(); // Clear the vector after deleting objects

    DECREMENT_COUNTER("Inventory");
    Logger::getInstance()->logDeleted("Inventory");
}

// Getter implementations
string Inventory::getInventoryID() const { return inventoryID; }
const vector<StockItem*>& Inventory::getStockItems() const { return stockItems; }

// Setter implementations
void Inventory::setInventoryID(string id) { inventoryID = id; }

void Inventory::setStockItems(vector<StockItem*> newItems) {
    // First, delete existing StockItem objects if owned
    for (StockItem* item : stockItems) {
        delete item;
    }
    stockItems.clear();

    // Now, take ownership of new StockItem objects
    for (StockItem* item : newItems) {
        this->stockItems.push_back(item);
    }
}

// Add a single stock item
void Inventory::addStockItem(StockItem* item) {
    if (item) {
        stockItems.push_back(item); // Take ownership
        Logger::getInstance()->logActivity("Inventory", "Added StockItem: " + item->toString());
    }
}

// Remove a stock item by its Item ID
void Inventory::removeStockItem(const string& itemID) {
    auto it = std::remove_if(stockItems.begin(), stockItems.end(),
        [&](StockItem* item) {
            if (item && item->getItem() && item->getItem()->getItemID() == itemID) {
                delete item; // Delete the owned object
                Logger::getInstance()->logActivity("Inventory", "Removed StockItem with Item ID: " + itemID);
                return true;
            }
            return false;
        });
    stockItems.erase(it, stockItems.end());
}


// toString() implementation
string Inventory::toString() const {
    std::stringstream ss;
    ss << "Inventory ID: " << getInventoryID() << ", Total Items: " << stockItems.size();
    return ss.str();
}

// getDetailedInfo() implementation - ADDED
string Inventory::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Inventory Details ---\n";
    ss << "  Inventory ID : " << getInventoryID() << "\n";
    ss << "  Stock Items  :\n";
    if (stockItems.empty()) {
        ss << "    No items in stock.\n";
    } else {
        for (const StockItem* item : stockItems) {
            if (item) {
                ss << "    - " << item->toString() << " (Purchase Date: " << item->getPurchase() << ")\n";
            }
        }
    }
    return ss.str();
}