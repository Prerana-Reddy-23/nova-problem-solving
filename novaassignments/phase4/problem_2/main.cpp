#include <iostream>
#include <limits>
#include <stdexcept>
#include "swap.h"

int main() {
    int num1 = 0, num2 = 0;

    try {
        std::cout << "Enter the first integer: ";
        while (!(std::cin >> num1)) {
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Enter the second integer: ";
        while (!(std::cin >> num2)) {
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "\nBefore swap:" << std::endl;
        std::cout << "First integer: " << num1 << std::endl;
        std::cout << "Second integer: " << num2 << std::endl;

        swapIntegers(num1, num2);

        std::cout << "\nAfter swap:" << std::endl;
        std::cout << "First integer: " << num1 << std::endl;
        std::cout << "Second integer: " << num2 << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }

    return 0;
}