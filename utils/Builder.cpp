#include "Builder.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

Builder::Builder() = default;

std::vector<DataObject*>* Builder::makeDataObjectList() {
    std::vector<std::vector<std::string>>* rawData = new std::vector<std::vector<std::string>>();
    if (filePath.empty()) return new std::vector<DataObject*>();
    std::ifstream file(filePath);
    if (!file.is_open()) return new std::vector<DataObject*>();
    std::string line;
    // Optionally skip header
    if (std::getline(file, line)) {
        // Assume first line is header, skip it
    }
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        rawData->push_back(row);
    }
    file.close();
    auto result = constructDataObject(rawData);
    delete rawData;
    return result;
}
