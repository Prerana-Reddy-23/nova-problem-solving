#include "array.h" 
#include <iostream>     
#include <iomanip>       
#include <utility>       


void printArray(const int arr[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
           
            std::cout << std::setw(4) << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


void transposeArray(int arr[][COLS], int size) {
   
    for (int i = 0; i < size; ++i) {
       
        for (int j = i + 1; j < size; ++j) {
           
             std::swap(arr[i][j], arr[j][i]);
        }
    }
}