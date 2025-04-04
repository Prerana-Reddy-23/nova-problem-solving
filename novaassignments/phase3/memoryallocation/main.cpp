#include <iostream>
#include <limits> 
#include "array.h"

int main() {
    int size = 0;
    int* dynamicArray = nullptr; 

   
    std::cout << "Enter the desired size for the integer array: ";
    while (!(std::cin >> size) || size <= 0) {
         std::cerr << "Invalid input. Please enter a positive integer for the size: ";
         std::cin.clear(); 
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }


    dynamicArray = allocateIntArray(size);

 
    if (dynamicArray == nullptr) {
        return 1; 
    }

   
    populateIntArray(dynamicArray, size);


    sortIntArray(dynamicArray, size);

 
    std::cout << "\nSorted array:" << std::endl;
    printIntArray(dynamicArray, size);

    deallocateIntArray(dynamicArray);
    dynamicArray = nullptr; 

    std::cout << "\nMemory deallocated successfully." << std::endl;

    return 0; 
}