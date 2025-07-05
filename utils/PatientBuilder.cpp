#include "PatientBuilder.h"
#include "Patient.h"
#include <vector>
#include <string>

PatientBuilder::PatientBuilder() {
    filePath = "data/patients.csv";
}

std::vector<DataObject*>* PatientBuilder::constructDataObject(std::vector<std::vector<std::string>>* data) {
    std::vector<DataObject*>* patients = new std::vector<DataObject*>();
    // Implement construction logic here
    return patients;
}
