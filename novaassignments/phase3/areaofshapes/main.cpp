#include <iostream>
#include <limits>   
#include "area.h" 
template <typename T>
T getPositiveInput(const std::string& prompt) {
    T value;
    std::cout << prompt;
    while (!(std::cin >> value) || value < 0) {
         if (std::cin.fail()) { 
             std::cerr << "Invalid input. Please enter a number: ";
         } else { 
              std::cerr << "Invalid input. Value cannot be negative. Please enter a non-negative number: ";
         }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << prompt; 
    }
     
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}


int main() {
    int choice;
    double area = -1.0; 

    std::cout << "--- Area Calculator ---" << std::endl;
    std::cout << "Select the shape:" << std::endl;
    std::cout << "1. Circle" << std::endl;
    std::cout << "2. Rectangle" << std::endl;
    std::cout << "3. Triangle" << std::endl;
    std::cout << "Enter your choice (1-3): ";

    while (!(std::cin >> choice) || choice < 1 || choice > 3) {
        std::cerr << "Invalid choice. Please enter 1, 2, or 3: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter your choice (1-3): ";
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    
    switch (choice) {
        case 1: { 
            double radius = getPositiveInput<double>("Enter the radius: ");
            area = calculateArea(radius);
            break;
        }
        case 2: { 
            double length = getPositiveInput<double>("Enter the length: ");
            double width = getPositiveInput<double>("Enter the width: ");
            area = calculateArea(length, width); 
            break;
        }
        case 3: { 
            int base = getPositiveInput<int>("Enter the base (integer): ");
            int height = getPositiveInput<int>("Enter the height (integer): ");
            area = calculateArea(base, height); 
            break;
        }
        default:
           
            std::cerr << "An unexpected error occurred." << std::endl;
            return 1; 
    }

    
    if (area >= 0.0) {
        std::cout << "\nThe calculated area is: " << area << std::endl;
    } else {
        std::cout << "\nArea calculation failed (likely due to invalid input)." << std::endl;
    }

    return 0; 
}