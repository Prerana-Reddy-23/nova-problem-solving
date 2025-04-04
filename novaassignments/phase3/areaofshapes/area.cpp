#include "area.h"
#include <iostream> 
#include <cmath>    


double calculateArea(double radius) {
    if (radius < 0) {
        std::cerr << "Error: Radius cannot be negative." << std::endl;
        return -1.0; 
    }
    return PI * radius * radius; 
}


double calculateArea(double length, double width) {
    if (length < 0 || width < 0) {
        std::cerr << "Error: Length and width cannot be negative." << std::endl;
        return -1.0;
    }
    return length * width;
}


double calculateArea(int base, int height) {
     if (base < 0 || height < 0) {
        std::cerr << "Error: Base and height cannot be negative." << std::endl;
        return -1.0; 
    }
 
    return 0.5 * static_cast<double>(base) * static_cast<double>(height);
}