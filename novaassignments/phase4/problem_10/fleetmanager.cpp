#include "FleetManager.h"
#include <limits> /
#include <cmath>  

std::string engineTypeToString(EngineType type) {
    switch (type) {
        case EngineType::PETROL:   return "Petrol";
        case EngineType::DIESEL:   return "Diesel";
        case EngineType::ELECTRIC: return "Electric";
        case EngineType::HYBRID:   return "Hybrid";
        default:                   return "Unknown";
    }
}


Engine::Engine(EngineType et, double cap) : type(et), capacity(cap) {
    if (cap <= 0.0) {
        throw std::invalid_argument("Engine capacity must be positive.");
    }
}

EngineType Engine::getType() const { return type; }
double Engine::getCapacity() const { return capacity; }

void Engine::display() const {
     std::cout << "Type: " << engineTypeToString(type)
               << ", Capacity: " << std::fixed << std::setprecision(1) << capacity
               << (type == EngineType::ELECTRIC || type == EngineType::HYBRID ? " kWh" : " L");
}



Vehicle::Vehicle(const std::string& mk, const std::string& mdl, int yr, double pr, const Engine& eng)
    : make(mk), model(mdl), year(yr), price(pr), engine(eng) {
    if (mk.empty() || mdl.empty()) {
        throw std::invalid_argument("Vehicle make and model cannot be empty.");
    }
    if (yr < 1900 || yr > 2100) { 
        throw std::invalid_argument("Invalid vehicle year.");
    }
    if (pr < 0.0) {
        throw std::invalid_argument("Vehicle price cannot be negative.");
    }
}

void Vehicle::printDetails() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Make: " << make << ", Model: " << model << ", Year: " << year
              << ", Price: $" << price << ", Engine [";
    engine.display();
    std::cout << "]";
}

std::string Vehicle::getMake() const { return make; }
std::string Vehicle::getModel() const { return model; }
int Vehicle::getYear() const { return year; }
double Vehicle::getPrice() const { return price; }
const Engine& Vehicle::getEngine() const { return engine; }


void displayOutput(const Vehicle& v) {
    v.printDetails();
    std::cout << ", Est. Mileage: " << v.calculateMileage() << " units"; 
}



TouristVehicle::TouristVehicle(const std::string& mk, const std::string& mdl, int yr, double pr, const Engine& eng, int st, const std::string& trans)
    : Vehicle(mk, mdl, yr, pr, eng), seats(st), transmission(trans) {
     if (st < 2) {
         throw std::invalid_argument("Tourist vehicle must have at least 2 seats.");
     }
     if (trans.empty()){
         throw std::invalid_argument("Transmission type cannot be empty.");
     }
}

double TouristVehicle::calculateMileage() const {
    double baseFactor = 25.0; 
    double mileage = 0.0;
    double capacity = engine.getCapacity();
    EngineType type = engine.getType();

    switch (type) {
        case EngineType::PETROL:   mileage = baseFactor * (1.0 / std::max(0.5, capacity)) * 0.9; break; // Less efficient
        case EngineType::DIESEL:   mileage = baseFactor * (1.0 / std::max(0.5, capacity)) * 1.1; break; // More efficient
        case EngineType::ELECTRIC: mileage = capacity * 3.5; break; // km per kWh (example)
        case EngineType::HYBRID:   mileage = baseFactor * (1.0 / std::max(0.5, capacity)) * 1.2 + capacity * 0.5; break; // Mix
        default:                   mileage = 0.0; break;
    }
   
    mileage *= (1.0 - (seats / 100.0));
    return std::max(0.0, mileage);
}

void TouristVehicle::printDetails() const {
    std::cout << "Tourist Vehicle - ";
    Vehicle::printDetails();
    std::cout << ", Seats: " << seats << ", Transmission: " << transmission;
}

int TouristVehicle::getSeats() const { return seats; }
std::string TouristVehicle::getTransmission() const { return transmission; }


PrivateVehicle::PrivateVehicle(const std::string& mk, const std::string& mdl, int yr, double pr, const Engine& eng, int drs, const std::string& trans)
    : Vehicle(mk, mdl, yr, pr, eng), doors(drs), transmission(trans) {
     if (drs < 2 || drs > 5) {
         throw std::invalid_argument("Invalid number of doors for private vehicle.");
     }
      if (trans.empty()){
         throw std::invalid_argument("Transmission type cannot be empty.");
     }
}

double PrivateVehicle::calculateMileage() const {
    double baseFactor = 28.0;
    double mileage = 0.0;
    double capacity = engine.getCapacity();
    EngineType type = engine.getType();

     switch (type) {
        case EngineType::PETROL:   mileage = baseFactor * (1.0 / std::max(0.5, capacity)) * 1.0; break;
        case EngineType::DIESEL:   mileage = baseFactor * (1.0 / std::max(0.5, capacity)) * 1.2; break;
        case EngineType::ELECTRIC: mileage = capacity * 4.0; break; // km per kWh (example)
        case EngineType::HYBRID:   mileage = baseFactor * (1.0 / std::max(0.5, capacity)) * 1.3 + capacity * 0.7; break; // Mix
        default:                   mileage = 0.0; break;
    }
    
    mileage *= (1.0 - (doors / 150.0));
     return std::max(0.0, mileage);
}

void PrivateVehicle::printDetails() const {
    std::cout << "Private Vehicle - ";
    Vehicle::printDetails();
    std::cout << ", Doors: " << doors << ", Transmission: " << transmission;
}

int PrivateVehicle::getDoors() const { return doors; }
std::string PrivateVehicle::getTransmission() const { return transmission; }



double calculateTotalPrice(const std::vector<Vehicle*>& fleet) {
    double total = 0.0;
    for (const auto* vehiclePtr : fleet) {
        if (vehiclePtr) {
            total += vehiclePtr->getPrice();
        }
    }
    return total;
}

void printAllVehicleDetails(const std::vector<Vehicle*>& fleet) {
    std::cout << "\n--- Fleet Details ---" << std::endl;
    if (fleet.empty()) {
        std::cout << "The fleet is empty." << std::endl;
        return;
    }
    int count = 1;
    for (const auto* vehiclePtr : fleet) {
        if (vehiclePtr) {
            std::cout << count++ << ". ";
            displayOutput(*vehiclePtr); 
            std::cout << std::endl;
        } else {
             std::cout << count++ << ". [Invalid Vehicle Pointer]" << std::endl;
        }
    }
    std::cout << "---------------------" << std::endl;
}