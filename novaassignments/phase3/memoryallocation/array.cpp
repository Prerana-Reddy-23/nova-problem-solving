#include "array.h"
#include <iostream>
#include <new> 
#include <algorithm> 
#include <limits>   


int* allocateIntArray(int size) {
    if (size <= 0) {
        std::cerr << "Error: Array size must be positive." << std::endl;
        return nullptr; 
    }
    try {
        
        int* arr = new int[size];
        return arr;
    } catch (const std::bad_alloc& e) {
       
        std::cerr << "Error: Memory allocation failed: " << e.what() << std::endl;
        return nullptr; 
    }
}


void populateIntArray(int* arr, int size) {
    if (arr == nullptr || size <= 0) {
        std::cerr << "Error: Cannot populate an invalid array." << std::endl;
        return;
    }
    std::cout << "Enter " << size << " integer values for the array:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Element [" << i << "]: ";
        
        while (!(std::cin >> arr[i])) {
            std::cerr << "Invalid input. Please enter an integer: ";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}


void sortIntArray(int* arr, int size) {
    if (arr == nullptr || size <= 0) {
         std::cerr << "Error: Cannot sort an invalid array." << std::endl;
        return;
    }
    
    std::sort(arr, arr + size); 
}


void printIntArray(const int* arr, int size) {
     if (arr == nullptr || size <= 0) {
        std::cerr << "Error: Cannot print an invalid array." << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


void deallocateIntArray(int* arr) {
    
    if (arr != nullptr) {
       delete[] arr; 
    }
}