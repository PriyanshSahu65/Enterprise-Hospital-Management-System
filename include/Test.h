#ifndef TEST_H
#define TEST_H

#include "DataObject.h" // ADDED: Inherits from DataObject
#include <string>       // For std::string

// Removed 'using namespace std;' from header

class Test : public DataObject { // ADDED: Inherits from DataObject
private:
    std::string testID;
    std::string name;
    double cost; // Changed from 'price' to 'cost' for clarity in a lab test context
public:
    Test(std::string id, std::string name, double cost);

    // Destructor (virtual from DataObject)
    ~Test() override; // Added override keyword

    std::string getTestID() const;
    std::string getName() const;
    double getCost() const; // Changed from getPrice() to getCost()

    void setTestID(std::string id);
    void setName(std::string name);
    void setCost(double cost); // Changed from setPrice() to setCost()

    // Ensure toString() and getDetailedInfo() are properly overridden
    std::string toString() const override;
    std::string getDetailedInfo() const override; // ADDED: Must be overridden from DataObject
};

#endif // TEST_H