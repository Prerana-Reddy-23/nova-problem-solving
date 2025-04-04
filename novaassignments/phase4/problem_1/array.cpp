#include "array.h"
#include <iostream>
#include <algorithm>
#include <new>       

int* allocateArray(int size) {
    if (size < 0) {
         throw std::invalid_argument("Array size cannot be negative.");
    }
    
    return new int[size];
}

void fillArray(int* arr, int size) {
    std::cout << "Enter " << size << " integer elements:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << i << ": ";
        while (!(std::cin >> arr[i])) {
             std::cout << "Invalid input. Please enter an integer: ";
             std::cin.clear();
             //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void sortArray(int* arr, int size) {
    if (size > 1) {
        std::sort(arr, arr + size);
    }
}

void printArray(const int* arr, int size) {
    if (size <= 0) {
        std::cout << "Array is empty." << std::endl;
        return;
    }
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i == size - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

void deleteArray(int*& arr) {
    delete[] arr;
    arr = nullptr;
}