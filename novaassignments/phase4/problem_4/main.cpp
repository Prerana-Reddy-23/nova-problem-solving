#include <iostream>
#include <limits>
#include <stdexcept>
#include <cstring> 
#include "string.h"

const int MAX_BUFFER_SIZE = 256;

int main() {
    char inputString[MAX_BUFFER_SIZE];

    std::cout << "Enter a string (max " << MAX_BUFFER_SIZE - 1 << " characters): ";

    try {
       
        std::cin.getline(inputString, MAX_BUFFER_SIZE);

        
        if (std::cin.fail() && !std::cin.eof()) {
             std::cin.clear(); 
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
             std::cerr << "Warning: Input may have been truncated." << std::endl;
            
        }

        if (strlen(inputString) == 0 && !std::cin.eof()) {
             std::cout << "Input string is empty. No operations to perform." << std::endl;
             return 0;
        }


        std::cout << "Original string: " << inputString << std::endl;

        toUpperCase(inputString);
        std::cout << "After uppercase: " << inputString << std::endl;

        removeVowels(inputString);
        std::cout << "After removing vowels: " << inputString << std::endl;

        reverseString(inputString);
        std::cout << "After reversing: " << inputString << std::endl;

        std::cout << "\nFinal modified string: " << inputString << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }

    return 0;
}