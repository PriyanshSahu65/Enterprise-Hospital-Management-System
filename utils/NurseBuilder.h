#ifndef NURSEBUILDER_H
#define NURSEBUILDER_H
#include "Builder.h"
#include "Nurse.h"

class NurseBuilder : public Builder {
public:
    NurseBuilder();
    void setFilePath(const std::string& path);
    std::vector<DataObject*>* constructDataObject(std::vector<std::vector<std::string>>* rawData) override;
    std::vector<DataObject*>* makeDataObjectList();
};

#endif // NURSEBUILDER_H
