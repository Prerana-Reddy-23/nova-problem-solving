#include "vehicle.h"
#include <algorithm> // For std::min/max

// --- Vehicle Implementation ---
Vehicle::Vehicle(const std::string& mk, const std::string& mdl, int yr)
    : make(mk), model(mdl), year(yr) {
    if (mk.empty() || mdl.empty()) {
        throw std::invalid_argument("Make and Model cannot be empty.");
    }
    if (yr < 1886 || yr > 2100) {
        throw std::invalid_argument("Invalid year provided for Vehicle.");
    }
}

void Vehicle::displayDetails() const {
    std::cout << "Make: " << make << ", Model: " << model << ", Year: " << year;
}

const std::string& Vehicle::getMake() const { return make; }
const std::string& Vehicle::getModel() const { return model; }
int Vehicle::getYear() const { return year; }


// --- Electric Implementation ---
Electric::Electric(double capacity, double level)
    : batteryCapacity(capacity), chargeLevel(level) {
    if (capacity <= 0.0) {
        throw std::invalid_argument("Battery capacity must be positive.");
    }
    if (level < 0.0 || level > 100.0) {
        throw std::invalid_argument("Charge level must be between 0.0 and 100.0.");
    }
}

void Electric::displayElectricDetails() const {
     std::cout << std::fixed << std::setprecision(1);
     std::cout << "Battery: " << batteryCapacity << " kWh, Charge: " << chargeLevel << "%";
}

double Electric::getBatteryCapacity() const { return batteryCapacity; }
double Electric::getChargeLevel() const { return chargeLevel; }

void Electric::charge(double amountPercent) {
     if (amountPercent < 0.0) {
        throw std::invalid_argument("Charge amount cannot be negative.");
     }
     chargeLevel = std::min(100.0, chargeLevel + amountPercent);
}


// --- Car Implementation ---
Car::Car(const std::string& mk, const std::string& mdl, int yr, int doors)
    : Vehicle(mk, mdl, yr), numberOfDoors(doors) {
     if (doors < 1 || doors > 5) {
        throw std::invalid_argument("Invalid number of doors for Car.");
     }
}

void Car::displayDetails() const {
    std::cout << "Car - ";
    Vehicle::displayDetails();
    std::cout << ", Doors: " << numberOfDoors;
}



Truck::Truck(const std::string& mk, const std::string& mdl, int yr, double payload)
    : Vehicle(mk, mdl, yr), payloadCapacity(payload) {
     if (payload < 0.0) {
         throw std::invalid_argument("Payload capacity cannot be negative.");
     }
}

void Truck::displayDetails() const {
    std::cout << "Truck - ";
    Vehicle::displayDetails();
     std::cout << std::fixed << std::setprecision(1);
    std::cout << ", Payload: " << payloadCapacity << " tons";
}



ElectricCar::ElectricCar(const std::string& mk, const std::string& mdl, int yr, int doors,
                         double capacity, double level, const std::string& portType)
    : Vehicle(mk, mdl, yr),
      Car(mk, mdl, yr, doors),
      Electric(capacity, level),
      chargingPortType(portType)
{
     if (portType.empty()) {
         throw std::invalid_argument("Charging port type cannot be empty.");
     }
}

void ElectricCar::displayDetails() const {
    Car::displayDetails();
    std::cout << ", Port: " << chargingPortType << ", ";
    Electric::displayElectricDetails();
    std::cout << std::endl;
}

void ElectricCar::displayElectricDetails() const {
    Electric::displayElectricDetails();
    std::cout << " (Port: " << chargingPortType << ")";
}



ElectricTruck::ElectricTruck(const std::string& mk, const std::string& mdl, int yr, double payload,
                             double capacity, double level, double towing)
    : Vehicle(mk, mdl, yr),
      Truck(mk, mdl, yr, payload),
      Electric(capacity, level),
      towingCapacity(towing)
{
    if (towing < 0.0) {
        throw std::invalid_argument("Towing capacity cannot be negative.");
    }
}

void ElectricTruck::displayDetails() const {
    Truck::displayDetails();
     std::cout << std::fixed << std::setprecision(0);
    std::cout << ", Towing: " << towingCapacity << " lbs, ";
    Electric::displayElectricDetails();
    std::cout << std::endl;
}

void ElectricTruck::displayElectricDetails() const {
     Electric::displayElectricDetails();
     std::cout << std::fixed << std::setprecision(0);
     std::cout << " (Towing: " << towingCapacity << " lbs)";
}