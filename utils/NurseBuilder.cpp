#include "NurseBuilder.h"
#include "Nurse.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

NurseBuilder::NurseBuilder() {
    filePath = "data/nurses.csv";
}

void NurseBuilder::setFilePath(const std::string& path) {
    this->filePath = path;
}

std::vector<DataObject*>* NurseBuilder::constructDataObject(std::vector<std::vector<std::string>>* data) {
    std::vector<DataObject*>* nurses = new std::vector<DataObject*>();
    // Implement construction logic here
    return nurses;
}

std::vector<DataObject*>* NurseBuilder::makeDataObjectList() {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "[ERROR] Failed to open file: " << filePath << std::endl;
        return new std::vector<DataObject*>();
    } else {
        std::cout << "[DEBUG] Opened file: " << filePath << std::endl;
    }
    std::vector<DataObject*>* nurses = new std::vector<DataObject*>();
    std::string line;
    bool first = true;
    size_t lineNum = 1;
    while (std::getline(file, line)) {
        ++lineNum;
        if (first) { first = false; continue; } // skip header
        std::stringstream ss(line);
        std::vector<std::string> fields;
        std::string field;
        while (std::getline(ss, field, ',')) fields.push_back(field);
        const size_t EXPECTED_FIELDS = 7;
        if (fields.size() < EXPECTED_FIELDS) {
            std::cerr << "Malformed Nurse CSV row at line " << lineNum << ": expected " << EXPECTED_FIELDS << " fields, got " << fields.size() << ". Row: ";
            for (const auto& cell : fields) std::cerr << cell << " ";
            std::cerr << std::endl;
            continue;
        }
        nurses->push_back(new Nurse(fields[0], fields[1], fields[2], fields[3], fields[4], fields[5], fields[6], nullptr));
    }
    return nurses;
}
