#include "2darray.h"
#include <iostream>
#include <iomanip>
#include <stdexcept> 
#include <utility>   

void printMatrix(const int matrix[][COLS], int rows) {
    if (rows <= 0 || COLS <= 0) {
        std::cout << "Matrix dimensions are invalid or zero." << std::endl;
        return;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << std::setw(4) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void transposeMatrix(int matrix[][COLS], int rows) {
   
    if (rows != COLS) {
         
    }

    if (rows <= 0) return;

    for (int i = 0; i < rows; ++i) {
        
        for (int j = i + 1; j < COLS; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}