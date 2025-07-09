#include "PatientBuilder.h"
#include "Patient.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

PatientBuilder::PatientBuilder() {
    filePath = "data/patients.csv";
}

void PatientBuilder::setFilePath(const std::string& path) {
    this->filePath = path;
}

std::vector<DataObject*>* PatientBuilder::constructDataObject(std::vector<std::vector<std::string>>* data) {
    std::vector<DataObject*>* patients = new std::vector<DataObject*>();
    // Implement construction logic here
    return patients;
}

std::vector<DataObject*>* PatientBuilder::makeDataObjectList() {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "[ERROR] Failed to open file: " << filePath << std::endl;
        return new std::vector<DataObject*>();
    } else {
        std::cout << "[DEBUG] Opened file: " << filePath << std::endl;
    }
    std::vector<DataObject*>* patients = new std::vector<DataObject*>();
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
            std::cerr << "Malformed Patient CSV row at line " << lineNum << ": expected " << EXPECTED_FIELDS << " fields, got " << fields.size() << ". Row: ";
            for (const auto& cell : fields) std::cerr << cell << " ";
            std::cerr << std::endl;
            continue;
        }
        patients->push_back(new Patient(fields[0], fields[1], fields[2], fields[3], fields[4], fields[5], fields[6]));
    }
    return patients;
}
