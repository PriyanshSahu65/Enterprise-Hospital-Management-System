#include "NurseBuilder.h"
#include "Nurse.h"
#include <vector>
#include <string>

NurseBuilder::NurseBuilder() {
    filePath = "data/nurses.csv";
}

std::vector<DataObject*>* NurseBuilder::constructDataObject(std::vector<std::vector<std::string>>* data) {
    std::vector<DataObject*>* nurses = new std::vector<DataObject*>();
    // Implement construction logic here
    return nurses;
}
