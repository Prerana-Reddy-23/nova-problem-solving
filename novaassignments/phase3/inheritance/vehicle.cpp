
#include "Vehicle.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>  
#include <algorithm> 
#include <limits>   



Vehicle::Vehicle(int id, const std::string& mk, const std::string& mdl, double mil, double pr)
    : vehicleId(id), make(mk), model(mdl), mileage(mil), price(pr) {}


Vehicle::~Vehicle() {
    // std::cout << "Vehicle Destructor for ID: " << vehicleId << std::endl; 
}

void Vehicle::displayDetails() const {
    std::cout << "--------------------------\n";
    std::cout << "Type:     Generic Vehicle\n"; 
    std::cout << "ID:       " << vehicleId << "\n";
    std::cout << "Make:     " << make << "\n";
    std::cout << "Model:    " << model << "\n";
    std::cout << std::fixed << std::setprecision(1); 
    std::cout << "Mileage:  " << mileage << " miles\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Price:    $" << price << "\n";

}

int Vehicle::getVehicleId() const { return vehicleId; }
double Vehicle::getMileage() const { return mileage; }
double Vehicle::getPrice() const { return price; }
std::string Vehicle::getMake() const { return make; }
std::string Vehicle::getModel() const { return model; }




Car::Car(int id, const std::string& mk, const std::string& mdl, double mil, double pr, const std::string& engine)
    : Vehicle(id, mk, mdl, mil, pr), engineType(engine) {}

void Car::displayDetails() const {
    std::cout << "--------------------------\n";
    std::cout << "Type:     Car\n"; 
    std::cout << "ID:       " << vehicleId << "\n"; 
    
    std::cout << "Make:     " << make << "\n";      
    std::cout << "Model:    " << model << "\n";     
    std::cout << "Engine:   " << engineType << "\n"; 
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Mileage:  " << mileage << " miles\n"; 
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Price:    $" << price << "\n";      
}

std::string Car::getEngineType() const { return engineType; }



Truck::Truck(int id, const std::string& mk, const std::string& mdl, double mil, double pr, double capacity)
    : Vehicle(id, mk, mdl, mil, pr), payloadCapacity(capacity) {}

void Truck::displayDetails() const {
    std::cout << "--------------------------\n";
    std::cout << "Type:     Truck\n"; 
    std::cout << "ID:       " << vehicleId << "\n";
    std::cout << "Make:     " << make << "\n";
    std::cout << "Model:    " << model << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Payload:  " << payloadCapacity << " tons\n"; 
    std::cout << "Mileage:  " << mileage << " miles\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Price:    $" << price << "\n";
}

double Truck::getPayloadCapacity() const { return payloadCapacity; }




void displayVehicleDetails(Vehicle* vehicles[], int size) {
    std::cout << "\n======= Displaying All Vehicle Details =======\n";
    if (size <= 0 || vehicles == nullptr) {
        std::cout << "No vehicles to display.\n";
        return;
    }
    for (int i = 0; i < size; ++i) {
        if (vehicles[i] != nullptr) {
            vehicles[i]->displayDetails(); 
        } else {
             std::cout << "--------------------------\n";
             std::cout << "Encountered a null vehicle pointer at index " << i << "\n";
        }
    }
    std::cout << "============================================\n";
}

double calculateTotalMileage(Vehicle* vehicles[], int size) {
    std::cout << "\n======= Calculating Total Mileage =======\n";
    if (size <= 0 || vehicles == nullptr) {
        std::cout << "No vehicles to calculate mileage from.\n";
        return 0.0;
    }
    double totalMileage = 0.0;
    for (int i = 0; i < size; ++i) {
         if (vehicles[i] != nullptr) {
            totalMileage += vehicles[i]->getMileage();
         }
    }
     std::cout << "Total mileage of all vehicles: " << std::fixed << std::setprecision(1) << totalMileage << " miles\n";
     std::cout << "=========================================\n";
    return totalMileage;
}


bool compareVehiclesByPriceDesc(const Vehicle* a, const Vehicle* b) {
    if (a == nullptr || b == nullptr) return false; 
    return a->getPrice() > b->getPrice(); 
}

void sortVehiclesByPrice(Vehicle* vehicles[], int size) {
     std::cout << "\n======= Sorting Vehicles by Price (Descending) =======\n";
    if (size <= 1 || vehicles == nullptr) {
        std::cout << "Not enough vehicles to sort or array is null.\n";
        return;
    }

    std::sort(vehicles, vehicles + size, compareVehiclesByPriceDesc);
    
    std::cout << "Vehicles sorted by price (descending).\n";
    
    std::cout << "====================================================\n";

}

void searchVehiclesByVehicleId(Vehicle* vehicles[], int size, int searchId) {
    std::cout << "\n======= Searching for Vehicle ID: " << searchId << " =======\n";
     if (size <= 0 || vehicles == nullptr) {
        std::cout << "No vehicles to search within.\n";
        return;
    }
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (vehicles[i] != nullptr && vehicles[i]->getVehicleId() == searchId) {
            std::cout << "Vehicle Found:\n";
            vehicles[i]->displayDetails(); 
            found = true;
            break; 
        }
    }

    if (!found) {
        std::cout << "Vehicle with ID " << searchId << " not found.\n";
    }
    std::cout << "===============================================\n";
}