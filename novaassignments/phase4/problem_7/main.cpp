#include <iostream>
#include <vector>
#include <stdexcept>
#include "Vehicle.h" /

int main() {
    try {
       
        Car car1(101, "Toyota", "Camry", 30000, 25000.00, "Gasoline");
        Car car2(102, "Honda", "Civic", 15000, 22000.00, "Gasoline");
        Truck truck1(201, "Ford", "F-150", 50000, 45000.00, 1.5); 
        Truck truck2(202, "Chevrolet", "Silverado", 60000, 48000.00, 1.7);
        Truck truck3(203, "RAM", "1500", 10000, 52000.00, 1.4);


        const int numVehicles = 5;
        Vehicle* vehicles[numVehicles] = {&car1, &car2, &truck1, &truck2, &truck3};

      
        displayVehicleDetails(vehicles, numVehicles);

        
        calculateTotalMileage(vehicles, numVehicles);

        
        sortVehiclesByPrice(vehicles, numVehicles);

        
         std::cout << "\n--- Vehicle Details After Sorting By Price ---" << std::endl;
        displayVehicleDetails(vehicles, numVehicles);

    
        int searchIdExists = 201;
        int searchIdNotExists = 999;

        searchVehiclesByVehicleId(vehicles, numVehicles, searchIdExists);
        searchVehiclesByVehicleId(vehicles, numVehicles, searchIdNotExists);


    } catch (const std::invalid_argument& e) {
        std::cerr << "Error creating vehicle (Invalid Argument): " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected standard error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }

    return 0;
}