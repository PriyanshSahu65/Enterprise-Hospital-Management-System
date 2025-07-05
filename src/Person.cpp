#include "Person.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>                 // For std::stringstream

using std::string; // Use using declaration in .cpp for convenience

// Constructor implementation
Person::Person(string ID, string name, string dob,
               string gender, string mobile, string city)
    : ID(ID), name(name), dob(dob), gender(gender), mobile(mobile), city(city) {
    INCREMENT_COUNTER("Person"); // Track creation
    Logger::getInstance()->logCreated("Person");
    Logger::getInstance()->logGenericCount("Person"); // Log current count
}

// Destructor implementation
Person::~Person() {
    DECREMENT_COUNTER("Person"); // Track destruction
    Logger::getInstance()->logDeleted("Person");
}

// Getter implementations
string Person::getID() const { return ID; }
string Person::getName() const { return name; }
string Person::getDob() const { return dob; }
string Person::getGender() const { return gender; }
string Person::getMobile() const { return mobile; }
string Person::getCity() const { return city; }

// Setter implementations
void Person::setID(string id) { ID = id; }
void Person::setName(string n) { name = n; }
void Person::setDob(string d) { dob = d; }
void Person::setGender(string g) { gender = g; }
void Person::setMobile(string m) { mobile = m; }
void Person::setCity(string c) { city = c; }

// toString() implementation
string Person::toString() const {
    return "Name: " + getName() + " (ID: " + getID() + ")";
}

// getDetailedInfo() implementation - ADDED
string Person::getDetailedInfo() const {
    std::stringstream ss;
    ss << "  ID            : " << getID() << "\n";
    ss << "  Name          : " << getName() << "\n";
    ss << "  Date of Birth : " << getDob() << "\n";
    ss << "  Gender        : " << getGender() << "\n";
    ss << "  Mobile        : " << getMobile() << "\n";
    ss << "  City          : " << getCity() << "\n";
    return ss.str();
}