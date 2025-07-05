// include/Builder.h
#ifndef BUILDER_H
#define BUILDER_H

#include "DataObject.h" // Include DataObject as it's used in method signatures
#include <string>
#include <vector>
#include <memory> // For std::unique_ptr (recommended for ownership in modern C++)

// The abstract base class for all specific builders.
// It defines the common interface and basic functionality for building DataObject lists.
class Builder {
protected:
    // #filepath: String (from UML)
    // This member variable is intended to hold the file path from which the builder
    // will read its raw data. It's protected so derived classes can access it.
    std::string filePath;

public:
    // +Builder() (from UML)
    // Default constructor.
    Builder();

    // Virtual destructor: Essential for proper polymorphic deletion of derived Builder objects.
    virtual ~Builder() = default;

    // <<virtual>>#constructDataObject(vector<vector<string>>*) : vector<DataObject*>* (from UML)
    // Pure virtual method: This must be implemented by all concrete builder classes.
    // It takes raw data (e.g., parsed from a file) and constructs a list of DataObject instances.
    //
    // Parameters:
    //   rawData: A pointer to a vector of vectors of strings. Each inner vector typically
    //            represents a row of data, and each string is a cell/field.
    //
    // Returns:
    //   A pointer to a vector of DataObject pointers. Each pointer in this vector
    //   points to a newly created DataObject (or a derived type like DoctorDataObject).
    //
    // Memory Management Note:
    //   In this design, the caller of `constructDataObject` (which is typically `makeDataObjectList`)
    //   is responsible for deleting the returned `std::vector<DataObject*>*` and
    //   all the individual `DataObject*` instances it contains.
    //   *** Modern C++ best practice strongly recommends using smart pointers (e.g.,
    //   `std::unique_ptr<std::vector<std::unique_ptr<DataObject>>>`) to automate
    //   memory management and prevent leaks. ***
    virtual std::vector<DataObject*>* constructDataObject(std::vector<std::vector<std::string>>* rawData) = 0;

    // +makeDataObjectList(): vector<DataObject*>* (from UML)
    // Orchestration method: This method typically handles reading data from the `filePath`
    // and then calls the `constructDataObject` method to build the actual objects.
    //
    // Returns:
    //   A pointer to a vector of DataObject pointers, similar to `constructDataObject`.
    //
    // Memory Management Note:
    //   Similar to `constructDataObject`, the caller of `makeDataObjectList` is
    //   responsible for deleting the returned `std::vector<DataObject*>*` and
    //   all the individual `DataObject*` instances it contains.
    //   *** Again, smart pointers are highly recommended for safer memory management. ***
    std::vector<DataObject*>* makeDataObjectList();
};

#endif // BUILDER_H