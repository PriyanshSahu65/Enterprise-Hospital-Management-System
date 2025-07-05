#ifndef STOCKITEM_H
#define STOCKITEM_H

#include "DataObject.h" // Inherits from DataObject
#include "Item.h"       // Needs Item definition
#include "Supplier.h"   // Needs Supplier definition
#include <string>       // For std::string

// Removed 'using namespace std;' from header

class StockItem : public DataObject {
private:
    std::string purchaseDate;
    int quantity;
    Item* item;       // Pointer to Item object (Assumed OWNED by StockItem)
    Supplier* supplier; // Pointer to Supplier object (Assumed NOT owned by StockItem)

public:
    // Default constructor (if needed)
    StockItem();
    StockItem(std::string purchaseDate, int quantity, Item* item, Supplier* supplier);

    // Destructor (virtual from DataObject)
    // Crucial if StockItem owns the Item object (deletes it)
    ~StockItem() override; // Added override keyword

    std::string getPurchase() const;
    int getQuantity() const;
    Item* getItem() const;       // Returns pointer
    Supplier* getSupplier() const; // Returns pointer

    void setPurchase(std::string p);
    void setQuantity(int q);
    void setItem(Item* i);       // Handles existing item (deletes old, sets new)
    void setSupplier(Supplier* s); // Sets pointer

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // STOCKITEM_H