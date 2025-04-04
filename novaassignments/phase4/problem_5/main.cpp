#include <iostream>
#include <stdexcept>
#include "2darray.h" 

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    try {
        std::cout << "Original Matrix:" << std::endl;
        printMatrix(matrix, ROWS);

        transposeMatrix(matrix, ROWS);

        std::cout << "\nTransposed Matrix:" << std::endl;
        printMatrix(matrix, ROWS);

    } catch (const std::logic_error& e) {
         std::cerr << "Error: " << e.what() << std::endl;
         return 1; 
    } catch (const std::exception& e) {
        std::cerr << "An unexpected standard error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }

    return 0; 
}