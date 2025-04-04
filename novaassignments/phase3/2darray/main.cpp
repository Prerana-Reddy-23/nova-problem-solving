#include <iostream>
#include "array.h" 

int main() {
    
    int matrix[ROWS][COLS] = {
        {11, 12, 13},
        {21, 22, 23},
        {31, 32, 33}
    };

    std::cout << "--- C++ 2D Array Operations ---" << std::endl << std::endl;

    
    std::cout << "Original Matrix (" << ROWS << "x" << COLS << "):" << std::endl;
    printArray(matrix, ROWS, COLS);
    std::cout << std::endl;

    
    std::cout << "Transposing the matrix..." << std::endl;
    transposeArray(matrix, ROWS); 
    std::cout << "Transpose complete." << std::endl << std::endl;


    
    std::cout << "Transposed Matrix (" << ROWS << "x" << COLS << "):" << std::endl;
    printArray(matrix, ROWS, COLS); 
    std::cout << std::endl;

    return 0;
}