#include "Billing.h"
#include "ObjectCounter.h" // Assuming ObjectCounter is in util/
#include "Logger.h"        // Assuming Logger is in util/
#include <sstream>                 // For std::stringstream
#include <numeric>                 // For std::accumulate if used for services string

using std::string; // Use using declaration in .cpp for convenience

// Default constructor implementation (if defined in header)
Billing::Billing()
    : billID(""), patient(nullptr), cost(0.0), paymentStatus(false) {
    INCREMENT_COUNTER("Billing");
    Logger::getInstance()->logCreated("Billing");
    Logger::getInstance()->logGenericCount("Billing");
}

// Parameterized constructor implementation
// Corrected to accept Patient*
Billing::Billing(string billID, Patient* pat, std::vector<string> services, double cost)
    : billID(billID), patient(pat), servicesProvided(services), cost(cost), paymentStatus(false) {
    INCREMENT_COUNTER("Billing");
    Logger::getInstance()->logCreated("Billing");
    Logger::getInstance()->logGenericCount("Billing");
}

// Destructor implementation
Billing::~Billing() {
    // If patient pointer is NOT owned, then no 'delete' here.
    DECREMENT_COUNTER("Billing");
    Logger::getInstance()->logDeleted("Billing");
}

// Getter implementations
string Billing::getBillID() const { return billID; }
Patient* Billing::getPatient() const { return patient; } // Returns pointer
std::vector<string> Billing::getServicesProvided() const { return servicesProvided; }
double Billing::getCost() const { return cost; }
bool Billing::getPaymentStatus() const { return paymentStatus; }

// Setter implementations
void Billing::setBillID(string id) { billID = id; }
void Billing::setPatient(Patient* pat) { patient = pat; } // Sets pointer
void Billing::setServicesProvided(std::vector<string> services) { servicesProvided = services; }
void Billing::setCost(double c) { cost = c; }
void Billing::setPaymentStatus(bool status) { paymentStatus = status; }

// toString() implementation
string Billing::toString() const {
    string patName = (patient ? patient->getName() : "N/A");
    string status = (paymentStatus ? "Paid" : "Unpaid");
    return "Bill ID: " + getBillID() + ", Patient: " + patName + ", Cost: " + std::to_string(getCost()) + ", Status: " + status;
}

// getDetailedInfo() implementation - ADDED
string Billing::getDetailedInfo() const {
    std::stringstream ss;
    ss << "--- Billing Details ---\n";
    ss << "  Bill ID          : " << getBillID() << "\n";
    ss << "  Patient          : " << (patient ? patient->getName() + " (ID: " + patient->getPatientID() + ")" : "N/A") << "\n";
    ss << "  Services Provided: ";
    if (servicesProvided.empty()) {
        ss << "None";
    } else {
        for (size_t i = 0; i < servicesProvided.size(); ++i) {
            ss << servicesProvided[i];
            if (i < servicesProvided.size() - 1) {
                ss << ", ";
            }
        }
    }
    ss << "\n";
    ss << "  Total Cost       : " << std::fixed << std::setprecision(2) << getCost() << "\n";
    ss << "  Payment Status   : " << (getPaymentStatus() ? "Paid" : "Unpaid") << "\n";
    return ss.str();
}