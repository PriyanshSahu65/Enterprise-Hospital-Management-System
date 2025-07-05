#include "StockItem.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>                 // For std::stringstream

using std::string; // Use using declaration in .cpp for convenience

// Default constructor implementation (if defined in header)
StockItem::StockItem()
    : purchaseDate(""), quantity(0), item(nullptr), supplier(nullptr) {
    ObjectCounter::getInstance()->increment("StockItem");
    Logger::getInstance()->logCreated("StockItem");
    Logger::getInstance()->logGenericCount("StockItem");
}

// Parameterized constructor implementation
StockItem::StockItem(string purchaseDate, int quantity, Item* itemObj, Supplier* supplierObj)
    : purchaseDate(purchaseDate), quantity(quantity), item(itemObj), supplier(supplierObj) { // Takes ownership of Item pointer
    ObjectCounter::getInstance()->increment("StockItem");
    Logger::getInstance()->logCreated("StockItem");
    Logger::getInstance()->logGenericCount("StockItem");
}

// Destructor implementation - CRITICAL for Item memory management
StockItem::~StockItem() {
    // Delete the Item object if StockItem owns it.
    // ASSUMPTION: StockItem owns the Item object.
    // If Item objects are managed by a central cache,
    // then DO NOT delete 'item' here.
    if (item) {
        delete item;
        item = nullptr; // Prevent double deletion
    }

    // ASSUMPTION: StockItem does NOT own the Supplier* object,
    // so no 'delete supplier;' here. It is managed externally.

    ObjectCounter::getInstance()->decrement("StockItem");
    Logger::getInstance()->logDeleted("StockItem");
}

// Getter implementations
string StockItem::getPurchase() const { return purchaseDate; }
int StockItem::getQuantity() const { return quantity; }
Item* StockItem::getItem() const { return item; }
Supplier* StockItem::getSupplier() const { return supplier; }

// Setter implementations
void StockItem::setPurchase(string p) { purchaseDate = p; }
void StockItem::setQuantity(int q) { quantity = q; }

void StockItem::setItem(Item* newItem) {
    // If setting a new item, delete the old one if owned
    if (item && item != newItem) { // Avoid deleting if setting to same pointer
        delete item;
    }
    item = newItem;
}

void StockItem::setSupplier(Supplier* newSupplier) { supplier = newSupplier; } // Sets pointer

// toString() implementation
string StockItem::toString() const {
    string itemName = (item ? item->getItemName() : "N/A Item");
    return itemName + " x" + std::to_string(quantity);
}

// getDetailedInfo() implementation - ADDED
string StockItem::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Stock Item Details ---\n";
    ss << "  Purchase Date: " << getPurchase() << "\n";
    ss << "  Quantity     : " << getQuantity() << "\n";
    ss << "  Item         : ";
    if (item) {
        ss << item->getItemName() << " (ID: " << item->getItemID() << ", Price: " << item->getUnitPrice() << ")\n";
    } else {
        ss << "N/A\n";
    }
    ss << "  Supplier     : ";
    if (supplier) {
        ss << supplier->getName() << " (ID: " << supplier->getSupplierID() << ", Mobile: " << supplier->getMobile() << ")\n";
    } else {
        ss << "N/A\n";
    }
    return ss.str();
}