
#include "Battery.h"
#include <iostream>
#include <limits>

int main() {
    std::cout << "=== Battery Operator Overloading Demo ===\n\n";

    Battery b1(150.0, 75.0, 12.5, 22.0);
    Battery b2(100.0, 20.0, 11.8, 18.0);
    Battery b3;

    std::cout << "\n--- Initial States ---" << std::endl;
    std::cout << "Battery b1:\n" << b1 << std::endl;
    std::cout << "Battery b2:\n" << b2 << std::endl;
    std::cout << "Battery b3 (default):\n" << b3 << std::endl;


    std::cout << "\n--- Testing Assignment (=) ---" << std::endl;
    b3 = b1;
    std::cout << "b3 after b3 = b1:\n" << b3 << std::endl;


    std::cout << "\n--- Testing Pre-increment (++) ---" << std::endl;
    std::cout << "b1 before ++:\n" << b1 << std::endl;
    ++b1;
    std::cout << "b1 after ++:\n" << b1 << std::endl;

    b1.charge(73);
    std::cout << "b1 after charging near full:\n" << b1 << std::endl;
    ++b1;
    std::cout << "b1 after ++ near full:\n" << b1 << std::endl;


    std::cout << "\n--- Testing Pre-decrement (--) ---" << std::endl;
    std::cout << "b2 before --:\n" << b2 << std::endl;
    --b2;
    std::cout << "b2 after --:\n" << b2 << std::endl;

    b2.discharge(18.5);
     std::cout << "b2 after discharging near empty:\n" << b2 << std::endl;
    --b2;
    std::cout << "b2 after -- near empty:\n" << b2 << std::endl;


    std::cout << "\n--- Testing Subscript ([]) ---" << std::endl;
    try {
        std::cout << "b1's current temperature (b1[2]): " << b1[2] << " C" << std::endl;
        std::cout << "Setting b1's temperature to 28.5 C using b1[2] = 28.5..." << std::endl;
        b1[2] = 28.5;
        std::cout << "b1 after modifying temp:\n" << b1 << std::endl;


        std::cout << "b1's charge level via b1[0]: " << b1[0] << std::endl;
        // std::cout << b1[3] << std::endl; // Uncomment to test invalid index exception
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    const Battery& const_b1_ref = b1;
    std::cout << "b1's voltage via const_b1_ref[1]: " << const_b1_ref[1] << std::endl;



    std::cout << "\n--- Testing Dereference (*) ---" << std::endl;
    std::cout << "Value of *b1 (charge level): " << *b1 << std::endl;
    *b1 = 100.0;
    std::cout << "b1 after *b1 = 100.0:\n" << b1 << std::endl;

    std::cout << "Value of *const_b1_ref: " << *const_b1_ref << std::endl;



    std::cout << "\n--- Testing Member Access (->) ---" << std::endl;
    std::cout << "Accessing getVoltage() via b1->getVoltage(): " << b1->getVoltage() << std::endl;
    std::cout << "Calling charge(5.0) via b1->charge(5.0)..." << std::endl;
    b1->charge(5.0);
    std::cout << "b1 after b1->charge(5.0):\n" << b1 << std::endl;

    std::cout << "Accessing getCapacity() via const_b1_ref->getCapacity(): " << const_b1_ref->getCapacity() << std::endl;




    std::cout << "\n--- Testing Input (>>) ---" << std::endl;
    Battery b4;
    std::cout << "Enter details for a new battery (b4):" << std::endl;
    std::cout << "Format: capacity current_charge voltage temperature" << std::endl;
    std::cout << "Example: 120 60 12.2 25.0" << std::endl;
    std::cout << "> ";
    std::cin >> b4;

    if (std::cin) {
         std::cout << "\nSuccessfully read data for b4:\n" << b4 << std::endl;
    } else {
         std::cerr << "\nInput operation failed. Please ensure you entered four valid numbers." << std::endl;
         std::cerr << "Battery b4 might be in an invalid state." << std::endl;
         std::cin.clear();
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }


    std::cout << "\n=== Demo End ===\n";
    return 0;
}