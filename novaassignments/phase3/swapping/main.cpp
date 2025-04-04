#include <iostream>
#include <limits> 
#include "swap.h" 

int main() {
    int num1, num2;

    
    std::cout << "Enter the first integer: ";
    while (!(std::cin >> num1)) { 
        std::cerr << "Invalid input. Please enter an integer: ";
        std::cin.clear(); 
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    
    std::cout << "Enter the second integer: ";
    while (!(std::cin >> num2)) {
        std::cerr << "Invalid input. Please enter an integer: ";
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    
    std::cout << "\nBefore swap:" << std::endl;
    std::cout << "First number: " << num1 << std::endl;
    std::cout << "Second number: " << num2 << std::endl;

   
    swap_integers(num1, num2);

    
    std::cout << "\nAfter swap:" << std::endl;
    std::cout << "First number: " << num1 << std::endl;
    std::cout << "Second number: " << num2 << std::endl;

    return 0; 