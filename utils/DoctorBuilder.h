// include/DoctorBuilder.h
#ifndef DOCTOR_BUILDER_H
#define DOCTOR_BUILDER_H

#include "Builder.h"   // Base class for all builders
#include "Doctor.h"    // The concrete Doctor class to be built

#include <string>
#include <vector>

class DoctorBuilder : public Builder {
public:
    // Constructor for DoctorBuilder
    DoctorBuilder();

    // Overrides the pure virtual method from the base Builder class.
    // This method provides the concrete implementation for constructDataObject
    // for Doctor objects.
    std::vector<DataObject*>* constructDataObject(std::vector<std::vector<std::string>>* rawData) override;

    void setFilePath(const std::string& path);
};

#endif // DOCTOR_BUILDER_H