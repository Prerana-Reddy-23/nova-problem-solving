#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip> 
#include "ElectricVehicle.h"

int main() {
    try {
        ElectricVehicle ev1(12345, "Tesla", "Model 3", 75.0, 50.0);
        ElectricVehicle ev2(67890, "Nissan", "Leaf", 60.0, 30.0);

        std::cout << "--- Initial Vehicle States ---" << std::endl;
        ev1.displayVehicleDetails();
        std::cout << "-----------------------------" << std::endl;
        ev2.displayVehicleDetails();
        std::cout << "=============================\n" << std::endl;


        std::cout << "--- Transaction 1: Charge ev1 (2 hours) ---" << std::endl;
        ev1.charge(2.0);
        ev1.displayVehicleDetails();
        std::cout << "=============================\n" << std::endl;


        std::cout << "--- Transaction 2: Drive ev1 (100 miles) ---" << std::endl;
        ev1.drive(100.0);
        ev1.displayVehicleDetails();
        std::cout << "=============================\n" << std::endl;


        std::cout << "--- Transaction 3: Charge ev2 (1.5 hours) ---" << std::endl;
        ev2.charge(1.5);
        ev2.displayVehicleDetails();
        std::cout << "=============================\n" << std::endl;


        std::cout << "--- Transaction 4: Drive ev2 (50 miles) ---" << std::endl;
        ev2.drive(50.0);
        ev2.displayVehicleDetails();
        std::cout << "=============================\n" << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error (Invalid Argument): " << e.what() << std::endl;
        return 1;
    } catch (const std::runtime_error& e) {
         std::cerr << "Error (Runtime): " << e.what() << std::endl;
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