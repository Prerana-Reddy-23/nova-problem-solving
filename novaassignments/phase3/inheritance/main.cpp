
#include "Vehicle.h" 
#include <iostream>

int main() {
    std::cout << "=== Vehicle Inheritance & Polymorphism Demo Start ===\n";

   
    Car* car1 = new Car(101, "Toyota", "Camry", 50000.5, 25000.00, "Gasoline V6");
    Car* car2 = new Car(102, "Honda", "Civic", 30000.0, 22000.50, "Gasoline 1.5T");
    Truck* truck1 = new Truck(201, "Ford", "F-150", 80000.2, 45000.00, 1.5); 
    Truck* truck2 = new Truck(202, "RAM", "1500", 15000.8, 55000.75, 1.2);
    Truck* truck3 = new Truck(203, "Chevrolet", "Silverado", 120000.0, 48000.00, 1.8); 

    const int NUM_VEHICLES = 5;
    Vehicle* vehicles[NUM_VEHICLES] = {car1, car2, truck1, truck2, truck3}; 


    displayVehicleDetails(vehicles, NUM_VEHICLES);

    
    calculateTotalMileage(vehicles, NUM_VEHICLES);


    sortVehiclesByPrice(vehicles, NUM_VEHICLES);

    
    std::cout << "\n--- Displaying Vehicles After Sorting By Price ---\n";
    displayVehicleDetails(vehicles, NUM_VEHICLES);

    
    searchVehiclesByVehicleId(vehicles, NUM_VEHICLES, 201); 
    searchVehiclesByVehicleId(vehicles, NUM_VEHICLES, 999);

   
    std::cout << "\n=== Cleaning up allocated memory ===\n";
    for (int i = 0; i < NUM_VEHICLES; ++i) {
        delete vehicles[i]; 
        vehicles[i] = nullptr; 
    }

    std::cout << "\n=== Vehicle Inheritance & Polymorphism Demo End ===\n";

    return 0;
}