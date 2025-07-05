#ifndef ITEM_H
#define ITEM_H

#include "DataObject.h" // Inherits from DataObject
#include <string>       // For std::string

// Removed 'using namespace std;' from header

class Item : public DataObject {
private:
    std::string itemID;
    std::string itemName;
    double unitPrice;
public:
    Item(std::string id, std::string name, double price);

    // Destructor (virtual from DataObject)
    ~Item() override; // Added override keyword

    std::string getItemID() const;
    std::string getItemName() const;
    double getUnitPrice() const;

    void setItemID(std::string id);
    void setItemName(std::string name);
    void setUnitPrice(double price);

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // ITEM_H