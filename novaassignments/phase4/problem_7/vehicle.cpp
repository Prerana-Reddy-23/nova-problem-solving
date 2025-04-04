#include "Vehicle.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm> 
#include <limits>    
Vehicle::Vehicle(int id, const std::string& mk, const std::string& mdl, double mlg, double prc)
    : vehicleId(id), make(mk), model(mdl), mileage(mlg), price(prc) {
    if (id <= 0) throw std::invalid_argument("Vehicle ID must be positive.");
    if (mk.empty() || mdl.empty()) throw std::invalid_argument("Make and Model cannot be empty.");
    if (mlg < 0.0) throw std::invalid_argument("Mileage cannot be negative.");
    if (prc < 0.0) throw std::invalid_argument("Price cannot be negative.");
}

void Vehicle::displayDetails() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "  ID: " << vehicleId
              << ", Make: " << make
              << ", Model: " << model
              << ", Mileage: " << mileage << " miles"
              << ", Price: $" << price;
}

int Vehicle::getVehicleId() const { return vehicleId; }
double Vehicle::getMileage() const { return mileage; }
double Vehicle::getPrice() const { return price; }



Car::Car(int id, const std::string& mk, const std::string& mdl, double mlg, double prc, const std::string& engType)
    : Vehicle(id, mk, mdl, mlg, prc), engineType(engType) {
    if (engType.empty()) throw std::invalid_argument("Engine type cannot be empty.");
}

void Car::displayDetails() const {
    std::cout << "Car   -"; 
    Vehicle::displayDetails();
    std::cout << ", Engine: " << engineType << std::endl;
}


Truck::Truck(int id, const std::string& mk, const std::string& mdl, double mlg, double prc, double payload)
    : Vehicle(id, mk, mdl, mlg, prc), payloadCapacity(payload) {
    if (payload < 0.0) throw std::invalid_argument("Payload capacity cannot be negative.");
}

void Truck::displayDetails() const {
    std::cout << "Truck -"; 
    Vehicle::displayDetails(); 
    std::cout << ", Payload: " << payloadCapacity << " tons" << std::endl; 
}



void displayVehicleDetails(Vehicle* vehicles[], int size) {
    std::cout << "\n--- Displaying All Vehicle Details ---" << std::endl;
    if (size <= 0) {
        std::cout << "No vehicles to display." << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        if (vehicles[i] != nullptr) {
            vehicles[i]->displayDetails(); 
        } else {
            std::cout << "  Skipping null vehicle pointer at index " << i << std::endl;
        }
    }
    std::cout << "--------------------------------------" << std::endl;
}

double calculateTotalMileage(Vehicle* vehicles[], int size) {
     std::cout << "\n--- Calculating Total Mileage ---" << std::endl;
    double totalMileage = 0.0;
     if (size <= 0) {
        std::cout << "No vehicles to calculate mileage from." << std::endl;
        return 0.0;
    }
    for (int i = 0; i < size; ++i) {
        if (vehicles[i] != nullptr) {
            totalMileage += vehicles[i]->getMileage();
        }
    }
    std::cout << "Total mileage for all vehicles: " << totalMileage << " miles" << std::endl;
     std::cout << "---------------------------------" << std::endl;
    return totalMileage;
}

bool compareVehiclesByPriceDesc(const Vehicle* a, const Vehicle* b) {
    
    if (!a && !b) return false; 
    if (!a) return false;       
    if (!b) return true;        
    return a->getPrice() > b->getPrice(); 
}

void sortVehiclesByPrice(Vehicle* vehicles[], int size) {
    std::cout << "\n--- Sorting Vehicles by Price (Descending) ---" << std::endl;
     if (size <= 0) {
        std::cout << "No vehicles to sort." << std::endl;
        return;
    }
    std::sort(vehicles, vehicles + size, compareVehiclesByPriceDesc);
    std::cout << "Vehicles sorted." << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    
}

Vehicle* searchVehiclesByVehicleId(Vehicle* vehicles[], int size, int searchId) {
    std::cout << "\n--- Searching for Vehicle ID: " << searchId << " ---" << std::endl;
     if (size <= 0) {
        std::cout << "No vehicles to search within." << std::endl;
        return nullptr;
    }
    for (int i = 0; i < size; ++i) {
        if (vehicles[i] != nullptr && vehicles[i]->getVehicleId() == searchId) {
            std::cout << "Vehicle Found:" << std::endl;
            vehicles[i]->displayDetails();
             std::cout << "-----------------------------------------" << std::endl;
            return vehicles[i]; 
        }
    }
    std::cout << "Vehicle with ID " << searchId << " not found." << std::endl;
     std::cout << "-----------------------------------------" << std::endl;
    return nullptr; 
}