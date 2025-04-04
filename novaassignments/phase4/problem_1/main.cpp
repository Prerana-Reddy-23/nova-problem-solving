#include <iostream>
#include <limits>
#include <stdexcept>
#include <new>
#include "array.h"

int main() {
    int size = 0;
    int* dynamicArray = nullptr;

    std::cout << "Enter the size of the array: ";
    while (!(std::cin >> size) || size < 0) {
         std::cout << "Invalid input. Please enter a non-negative integer size: ";
         std::cin.clear();
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    try {
        dynamicArray = allocateArray(size);
        std::cout << "Memory allocated successfully." << std::endl;

        if (size > 0) {
            fillArray(dynamicArray, size);
            sortArray(dynamicArray, size);
            printArray(dynamicArray, size);
        } else {
             std::cout << "Array size is 0. No elements to process." << std::endl;
        }

        deleteArray(dynamicArray);
        std::cout << "Memory deallocated successfully." << std::endl;

    } catch (const std::bad_alloc& e) {
        std::cerr << "Error: Memory allocation failed: " << e.what() << std::endl;
        return 1;
    } catch (const std::invalid_argument& e) {
         std::cerr << "Error: Invalid argument: " << e.what() << std::endl;
          if (dynamicArray != nullptr) {
              deleteArray(dynamicArray); // Clean up if allocated before error
          }
         return 1;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected standard error occurred: " << e.what() << std::endl;
         if (dynamicArray != nullptr) {
             deleteArray(dynamicArray); // Ensure cleanup
         }
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
         if (dynamicArray != nullptr) {
            deleteArray(dynamicArray); // Ensure cleanup
         }
        return 1;
    }

    return 0;
}