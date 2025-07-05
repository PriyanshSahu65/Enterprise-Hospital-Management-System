#ifndef DATA_OBJECT_H
#define DATA_OBJECT_H

#include <string>

class DataObject {
public:
    // IMPORTANT: Virtual destructor is crucial for proper polymorphic deletion.
    virtual ~DataObject() = default; // Use '= default;' for a default-generated virtual destructor

    // Declare getDetailedInfo as a pure virtual function here.
    // This makes DataObject an abstract class, requiring derived classes to implement it.
    virtual std::string getDetailedInfo() const = 0; // MUST be const
    
    // You might also want a virtual toString() for general string representation
    virtual std::string toString() const = 0; // MUST be const if DataObject is truly abstract for printing
};

#endif // DATA_OBJECT_H