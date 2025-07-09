#ifndef PATIENTBUILDER_H
#define PATIENTBUILDER_H
#include "Builder.h"
#include "Patient.h"

class PatientBuilder : public Builder {
public:
    PatientBuilder();
    std::vector<DataObject*>* constructDataObject(std::vector<std::vector<std::string>>* rawData) override;
    void setFilePath(const std::string& path);
    std::vector<DataObject*>* makeDataObjectList();
};

#endif // PATIENTBUILDER_H
