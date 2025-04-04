#include "FleetManager.h"
#include <iostream>
#include <vector>
#include <stdexcept>

int main() {
    std::vector<Vehicle*> fleet;

    try {
       
        Engine petrolEngine(EngineType::PETROL, 1.6);
        Engine dieselEngine(EngineType::DIESEL, 2.0);
        Engine electricEngine(EngineType::ELECTRIC, 75.0); 
        Engine hybridEngine(EngineType::HYBRID, 1.8);   

        
        fleet.push_back(new PrivateVehicle("Toyota", "Camry", 2022, 28000.00, hybridEngine, 4, "Automatic"));
        fleet.push_back(new TouristVehicle("Ford", "Transit", 2021, 45000.00, dieselEngine, 12, "Manual"));
        fleet.push_back(new PrivateVehicle("Tesla", "Model 3", 2023, 42000.00, electricEngine, 4, "Automatic"));
        fleet.push_back(new PrivateVehicle("Honda", "Civic", 2022, 24000.00, petrolEngine, 4, "CVT"));
        fleet.push_back(new TouristVehicle("Mercedes", "Sprinter", 2022, 55000.00, dieselEngine, 15, "Automatic"));


        
        printAllVehicleDetails(fleet);

        double totalFleetPrice = calculateTotalPrice(fleet);
        std::cout << "\nTotal Fleet Price: $" << std::fixed << std::setprecision(2) << totalFleetPrice << std::endl;

        
        std::cout << "\n--- Attempting Invalid Creation ---" << std::endl;
        try {
            PrivateVehicle invalidCar("Test", "Fail", 1800, -100.0, petrolEngine, 1, "");
        } catch (const std::invalid_argument& e) {
            std::cerr << "Caught expected exception during creation: " << e.what() << std::endl;
        }


    } catch (const std::invalid_argument& e) {
        std::cerr << "Error (Invalid Argument): " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected standard error occurred: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
    }

    
    std::cout << "\n--- Cleaning up fleet memory ---" << std::endl;
    for (Vehicle* vehiclePtr : fleet) {
        delete vehiclePtr; 
    }
    fleet.clear();
    std::cout << "Cleanup complete." << std::endl;

    return 0;
}