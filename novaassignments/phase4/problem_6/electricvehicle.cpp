#include "ElectricVehicle.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm> // For std::min, std::max

const double ElectricVehicle::DEFAULT_CHARGE_RATE_PERCENT_PER_HOUR = 15.0;
const double ElectricVehicle::DEFAULT_CONSUMPTION_PERCENT_PER_MILE = 0.20; // 20% per 100 miles

ElectricVehicle::ElectricVehicle(int id, const std::string& mk, const std::string& mdl, double capacity, double initialLevel)
    : vehicleId(id), make(mk), model(mdl), batteryCapacity(capacity), chargeLevel(initialLevel) {
    if (capacity <= 0.0) {
        throw std::invalid_argument("Battery capacity must be positive.");
    }
    if (initialLevel < 0.0 || initialLevel > 100.0) {
        throw std::invalid_argument("Initial charge level must be between 0.0 and 100.0.");
    }
     if (id <= 0) {
         throw std::invalid_argument("Vehicle ID must be positive.");
     }
      if (mk.empty() || mdl.empty()) {
          throw std::invalid_argument("Make and Model cannot be empty.");
      }
}

void ElectricVehicle::charge(double hours) {
    if (hours < 0.0) {
        throw std::invalid_argument("Charging hours cannot be negative.");
    }
    double chargeAdded = hours * DEFAULT_CHARGE_RATE_PERCENT_PER_HOUR;
    chargeLevel = std::min(100.0, chargeLevel + chargeAdded);
    std::cout << "Charged vehicle " << vehicleId << " for " << hours << " hours." << std::endl;
}

void ElectricVehicle::drive(double miles) {
    if (miles < 0.0) {
        throw std::invalid_argument("Driving miles cannot be negative.");
    }
    double chargeNeeded = miles * DEFAULT_CONSUMPTION_PERCENT_PER_MILE;
    if (chargeNeeded > chargeLevel) {
        double maxMiles = chargeLevel / DEFAULT_CONSUMPTION_PERCENT_PER_MILE;
         throw std::runtime_error("Insufficient charge to drive " + std::to_string(miles)
                                 + " miles. Available range: " + std::to_string(maxMiles) + " miles.");
    }
    chargeLevel -= chargeNeeded;
     chargeLevel = std::max(0.0, chargeLevel); // Ensure not slightly negative due to precision
    std::cout << "Drove vehicle " << vehicleId << " for " << miles << " miles." << std::endl;
}

void ElectricVehicle::displayVehicleDetails() const {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Vehicle ID: " << vehicleId << std::endl;
    std::cout << "Make: " << make << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Battery Capacity: " << batteryCapacity << " kWh" << std::endl; // Assuming kWh unit
    std::cout << "Current Charge Level: " << chargeLevel << "%" << std::endl;
}

// --- Optional Getters Implementation ---
int ElectricVehicle::getVehicleId() const { return vehicleId; }
const std::string& ElectricVehicle::getMake() const { return make; }
const std::string& ElectricVehicle::getModel() const { return model; }
double ElectricVehicle::getBatteryCapacity() const { return batteryCapacity; }
double ElectricVehicle::getChargeLevel() const { return chargeLevel; }