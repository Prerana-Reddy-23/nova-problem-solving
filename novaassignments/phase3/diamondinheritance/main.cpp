
#include "vehicle.h"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    std::cout << "=== Multiple & Diamond Inheritance Demo ===\n\n";

    std::cout << "--- Creating Objects ---\n";
   
    ElectricCar* eCar = new ElectricCar("Tesla", "Model Y", 2023, 4, 75.0, 60.0, "CCS");
    std::cout << "------------------------\n";
    ElectricTruck* eTruck = new ElectricTruck("Ford", "F-150 Lightning", 2023, 1.0, 131.0, 100.0, true);
    std::cout << "------------------------\n";
    Car* simpleCar = new Car("Toyota", "Corolla", 2022, 4); 
    std::cout << "------------------------\n";
    Truck* simpleTruck = new Truck("RAM", "2500", 2021, 2.5); 
    std::cout << "------------------------\n";


    std::cout << "\n--- Storing in Vehicle* Array ---\n";

    const int numVehicles = 4;
    Vehicle* vehicleFleet[numVehicles] = {eCar, eTruck, simpleCar, simpleTruck};


    std::cout << "\n--- Displaying Details (Polymorphism via Vehicle*) ---\n";
    for (int i = 0; i < numVehicles; ++i) {
        if (vehicleFleet[i]) {
            vehicleFleet[i]->displayDetails();
            std::cout << "---\n";

          
            Electric* electricPtr = dynamic_cast<Electric*>(vehicleFleet[i]);
            if(electricPtr) {
                std::cout << "  (Also testing electric charge...)\n";
                electricPtr->charge(5.0); 
                electricPtr->displayElectricDetails();
                std::cout << "\n---\n";
            }
        }
    }

    std::cout << "\n--- Cleaning Up Memory ---\n";
    
    for (int i = 0; i < numVehicles; ++i) {
        delete vehicleFleet[i]; 
        vehicleFleet[i] = nullptr;
    }

    std::cout << "\n=== Demo End ===\n";
    return 0;
}