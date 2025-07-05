#ifndef INVENTORY_H
#define INVENTORY_H

#include "DataObject.h" // Inherits from DataObject
#include "StockItem.h"  // Needs StockItem definition
#include <vector>       // For std::vector
#include <string>       // For std::string

// Removed 'using namespace std;' from header

class Inventory : public DataObject {
private:
    std::string inventoryID;
    std::vector<StockItem*> stockItems; // Vector of pointers to StockItem objects

public:
    // Default constructor (if needed)
    Inventory();
    Inventory(std::string id, std::vector<StockItem*> items);

    // Destructor (virtual from DataObject)
    // Crucial if Inventory owns the StockItem objects (deletes them)
    ~Inventory() override; // Added override keyword

    std::string getInventoryID() const;
    void setInventoryID(std::string id);

    const std::vector<StockItem*>& getStockItems() const; // Returns const reference
    void setStockItems(std::vector<StockItem*> items); // Handles existing items (deletes old ones, sets new)
    void addStockItem(StockItem* item); // Adds a single item
    void removeStockItem(const std::string& itemID); // Removes item by ID

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // INVENTORY_H