
#include "vehicle.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
Vehicle::Vehicle(const std::string& mk, const std::string& mdl, int yr)
    : make(mk), model(mdl), year(yr) {
    std::cout << "Vehicle Constructor: " << make << " " << model << std::endl;
}

Vehicle::~Vehicle() {
    std::cout << "Vehicle Destructor: " << make << " " << model << std::endl;
}

void Vehicle::displayDetails() const {
    std::cout << "  Make: " << make << ", Model: " << model << ", Year: " << year;
    
}

std::string Vehicle::getMake() const { return make; }
std::string Vehicle::getModel() const { return model; }
int Vehicle::getYear() const { return year; }



Electric::Electric(double capacity, double level)
    : batteryCapacity(capacity > 0 ? capacity : 0.0), chargeLevel(level) {
    chargeLevel = std::max(0.0, std::min(chargeLevel, batteryCapacity)); 
    std::cout << "Electric Constructor - Capacity: " << batteryCapacity << " kWh" << std::endl;
}

Electric::~Electric() {
     std::cout << "Electric Destructor" << std::endl;
}

void Electric::displayElectricDetails() const {
     std::cout << std::fixed << std::setprecision(1);
     std::cout << "  Battery: " << chargeLevel << "/" << batteryCapacity << " kWh ("
               << (batteryCapacity > 0 ? (chargeLevel / batteryCapacity * 100.0) : 0.0) << "%)";
    
}

void Electric::charge(double amount) {
    if (amount > 0) {
        chargeLevel = std::min(batteryCapacity, chargeLevel + amount);
        std::cout << "Charged. Current level: " << chargeLevel << " kWh" << std::endl;
    }
}

void Electric::consumePower(double amount) {
     if (amount > 0) {
        chargeLevel = std::max(0.0, chargeLevel - amount);
         std::cout << "Power consumed. Current level: " << chargeLevel << " kWh" << std::endl;
    }
}

double Electric::getBatteryCapacity() const { return batteryCapacity; }
double Electric::getChargeLevel() const { return chargeLevel; }



Car::Car(const std::string& mk, const std::string& mdl, int yr, int doors)
    : Vehicle(mk, mdl, yr), numberOfDoors(doors) {
     std::cout << "Car Constructor" << std::endl;
}

Car::~Car() {
     std::cout << "Car Destructor" << std::endl;
}

void Car::displayDetails() const {
    std::cout << "Car Details:\n";
    Vehicle::displayDetails();
    std::cout << ", Doors: " << numberOfDoors << std::endl; 
}

int Car::getNumberOfDoors() const { return numberOfDoors; }



Truck::Truck(const std::string& mk, const std::string& mdl, int yr, double payload)
    : Vehicle(mk, mdl, yr), payloadCapacity(payload) {
     std::cout << "Truck Constructor" << std::endl;
}

Truck::~Truck() {
    std::cout << "Truck Destructor" << std::endl;
}

void Truck::displayDetails() const {
    std::cout << "Truck Details:\n";
    Vehicle::displayDetails(); 
    std::cout << std::fixed << std::setprecision(1);
    std::cout << ", Payload: " << payloadCapacity << " tons" << std::endl; 
}

double Truck::getPayloadCapacity() const { return payloadCapacity; }



ElectricCar::ElectricCar(const std::string& mk, const std::string& mdl, int yr, int doors,
                         double capacity, double level, const std::string& portType)
    : Vehicle(mk, mdl, yr),
      Car(mk, mdl, yr, doors),
      Electric(capacity, level),
      chargingPortType(portType)
{
     std::cout << "ElectricCar Constructor" << std::endl;
}

ElectricCar::~ElectricCar() {
    std::cout << "ElectricCar Destructor" << std::endl;
}


void ElectricCar::displayDetails() const {
    std::cout << "Electric Car Details:\n";
    
    std::cout << "  Make: " << make << ", Model: " << model << ", Year: " << year; 
    std::cout << ", Doors: " << numberOfDoors; 
    Electric::displayElectricDetails(); 
    std::cout << ", Port: " << chargingPortType << std::endl; 
}

std::string ElectricCar::getChargingPortType() const { return chargingPortType; }



ElectricTruck::ElectricTruck(const std::string& mk, const std::string& mdl, int yr, double payload,
                           double capacity, double level, bool pto)
    : Vehicle(mk, mdl, yr), 
      Truck(mk, mdl, yr, payload),
      Electric(capacity, level),
      hasPowerTakeOff(pto)
{
    std::cout << "ElectricTruck Constructor" << std::endl;
}

ElectricTruck::~ElectricTruck() {
     std::cout << "ElectricTruck Destructor" << std::endl;
}


void ElectricTruck::displayDetails() const {
     std::cout << "Electric Truck Details:\n";
     std::cout << "  Make: " << make << ", Model: " << model << ", Year: " << year; 
     std::cout << std::fixed << std::setprecision(1);
     std::cout << ", Payload: " << payloadCapacity << " tons"; 
     Electric::displayElectricDetails(); 
     std::cout << ", PTO: " << (hasPowerTakeOff ? "Yes" : "No") << std::endl; 
}

bool ElectricTruck::getHasPowerTakeOff() const { return hasPowerTakeOff; }