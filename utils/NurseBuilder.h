#ifndef NURSEBUILDER_H
#define NURSEBUILDER_H
#include "Builder.h"
#include "Nurse.h"

class NurseBuilder : public Builder {
public:
    NurseBuilder();
    std::vector<DataObject*>* constructDataObject(std::vector<std::vector<std::string>>* rawData) override;
};

#endif // NURSEBUILDER_H
