#include <iostream>
#include <vector>
#include <stdexcept>
#include "vehicle.h" // Include the single header file

int main() {
    try {
        ElectricCar ec1("Tesla", "Model 3", 2022, 4, 75.0, 80.0, "CCS");
        ElectricTruck et1("Ford", "F-150 Lightning", 2023, 1.0, 131.0, 65.0, 10000.0);
        ElectricCar ec2("Nissan", "Leaf", 2021, 5, 62.0, 90.0, "CHAdeMO");
        ElectricTruck et2("Rivian", "R1T", 2023, 0.8, 135.0, 70.0, 11000.0);


        std::cout << "--- Displaying Vehicle Details ---" << std::endl;
        ec1.displayDetails();
        et1.displayDetails();
        ec2.displayDetails();
        et2.displayDetails();

        std::cout << "\n--- Displaying Electric Details Only ---" << std::endl;
        ec1.displayElectricDetails(); std::cout << std::endl;
        et1.displayElectricDetails(); std::cout << std::endl;

        std::cout << "\n--- Performing Actions ---" << std::endl;
        ec1.charge(15.0);
        std::cout << "Charged ec1. New level: " << ec1.getChargeLevel() << "%" << std::endl;
        ec1.displayDetails();


        std::cout << "\n--- Demonstrating Polymorphism (using Vehicle base pointers) ---" << std::endl;
        std::vector<Vehicle*> vehicleFleet;
        vehicleFleet.push_back(&ec1);
        vehicleFleet.push_back(&et1);
        vehicleFleet.push_back(&ec2);
        vehicleFleet.push_back(&et2);

        for (const auto* vPtr : vehicleFleet) {
            if (vPtr) {
                 vPtr->displayDetails();
            }
        }

        std::cout << "\n--- Demonstrating Polymorphism (using Electric base pointers) ---" << std::endl;
         std::vector<Electric*> electricFleet;
         electricFleet.push_back(&ec1);
         electricFleet.push_back(&et1);
         electricFleet.push_back(&ec2);
         electricFleet.push_back(&et2);

        for (const auto* ePtr : electricFleet) {
            if (ePtr) {
                 ePtr->displayElectricDetails();
                 std::cout << std::endl;
            }
        }


    } catch (const std::invalid_argument& e) {
        std::cerr << "Error creating object: " << e.what() << std::endl;
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