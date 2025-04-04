#include <iostream>
#include <string>
#include <stdexcept>
#include <limits> 
#include "Battery.h"


void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    try {
        std::cout << "--- Creating Batteries ---" << std::endl;
        Battery b1(100.0, 75.0, 12.6, 22.0);
        Battery b2; 

        std::cout << "Initial b1:\n" << b1 << std::endl;
        std::cout << "\nInitial b2 (default):\n" << b2 << std::endl;

        std::cout << "\n--- Demonstrating Assignment (=) ---" << std::endl;
        b2 = b1;
        std::cout << "b2 after b2 = b1:\n" << b2 << std::endl;

        std::cout << "\n--- Demonstrating Pre-increment (++) ---" << std::endl;
        ++b1;
        std::cout << "b1 after ++b1:\n" << b1 << std::endl;

        std::cout << "\n--- Demonstrating Pre-decrement (--) ---" << std::endl;
        --b1;
        std::cout << "b1 after --b1:\n" << b1 << std::endl;

        std::cout << "\n--- Demonstrating Subscript Operator ([]) ---" << std::endl;
        std::cout << "Current b1 temperature: " << b1["temperature"] << " C" << std::endl;
        b1["temperature"] = 28.5;
        std::cout << "Set b1 temperature to 28.5 C." << std::endl;
        std::cout << "New b1 temperature: " << b1["temperature"] << " C" << std::endl;
       


        std::cout << "\n--- Demonstrating Dereference (*) ---" << std::endl;
        Battery& refB1 = *b1;
        refB1.charge(10.0);
        std::cout << "b1 after charging 10% via * reference:\n" << b1 << std::endl;

        std::cout << "\n--- Demonstrating Member Access (->) ---" << std::endl;
        b1->discharge(5.0);
        std::cout << "b1 after discharging 5% via -> operator:\n" << b1 << std::endl;
        std::cout << "Charge level via ->: " << b1->getChargeLevel() << "%" << std::endl;


        std::cout << "\n--- Demonstrating Input Operator (>>) ---" << std::endl;
        Battery b3;
        std::cout << "Enter details for a new battery (b3):" << std::endl;
        while (!(std::cin >> b3)) {
             std::cerr << "Input failed. Please enter valid numeric values." << std::endl;
             std::cin.clear(); 
             clearInputBuffer(); 
             std::cout << "Retry entering details for b3:" << std::endl;
        }
        clearInputBuffer(); 
        std::cout << "\nb3 after successful input:\n" << b3 << std::endl;


       
        std::cout << "\n--- Demonstrating Exception Handling for [] ---" << std::endl;
        try {
            double invalidValue = b1["invalidKey"];
            std::cout << "Accessed invalid key? Value: " << invalidValue << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Caught expected exception: " << e.what() << std::endl;
        }

         
        std::cout << "\n--- Demonstrating Exception Handling for Constructor ---" << std::endl;
         try {
             Battery invalidBattery(-50.0, 50.0, 12.0, 20.0); 
         } catch (const std::invalid_argument& e) {
             std::cerr << "Caught expected exception: " << e.what() << std::endl;
         }


    } catch (const std::invalid_argument& e) {
        std::cerr << "\nError (Invalid Argument): " << e.what() << std::endl;
        return 1;
    } catch (const std::out_of_range& e) {
         std::cerr << "\nError (Out of Range): " << e.what() << std::endl;
         return 1;
    } catch (const std::runtime_error& e) {
        std::cerr << "\nError (Runtime): " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "\nAn unexpected standard error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "\nAn unknown error occurred." << std::endl;
        return 1;
    }

    return 0;
}