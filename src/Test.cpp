#include "Test.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>                 // For std::stringstream
#include <iomanip>                 // For std::fixed, std::setprecision

using std::string; // Use using declaration in .cpp for convenience

// Constructor implementation
Test::Test(string id, string name, double cost) // Parameter name changed to cost
    : testID(id), name(name), cost(cost) { // Member name changed to cost
    INCREMENT_COUNTER("Test");
    Logger::getInstance()->logCreated("Test");
    Logger::getInstance()->logGenericCount("Test");
}

// Destructor implementation
Test::~Test() {
    DECREMENT_COUNTER("Test");
    Logger::getInstance()->logDeleted("Test");
}

// Getter implementations
string Test::getTestID() const { return testID; }
string Test::getName() const { return name; }
double Test::getCost() const { return cost; } // Method name changed to getCost()

// Setter implementations
void Test::setTestID(string id) { testID = id; }
void Test::setName(string n) { name = n; }
void Test::setCost(double c) { cost = c; } // Method name changed to setCost()

// toString() implementation
string Test::toString() const {
    std::stringstream ss;
    ss << getName() << " (ID: " << getTestID() << ", Cost: " << std::fixed << std::setprecision(2) << getCost() << ")";
    return ss.str();
}

// getDetailedInfo() implementation - ADDED
string Test::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Test Details ---\n";
    ss << "  Test ID: " << getTestID() << "\n";
    ss << "  Name   : " << getName() << "\n";
    ss << "  Cost   : " << std::fixed << std::setprecision(2) << getCost() << "\n";
    return ss.str();
}