#include "area.h"
#include <cmath>
#include <stdexcept>

const double PI = 3.14159265358979323846; // Definition

double calculateArea(double radius) {
    if (radius < 0.0) {
        throw std::invalid_argument("Radius cannot be negative.");
    }
    return PI * radius * radius;
}

double calculateArea(double length, double width) {
    if (length < 0.0 || width < 0.0) {
        throw std::invalid_argument("Length and width cannot be negative.");
    }
    return length * width;
}


double calculateArea(double base, double height, bool isTriangle) {
     if (!isTriangle) {
          throw std::logic_error("This overload is specifically for triangles.");
     }
    if (base < 0.0 || height < 0.0) {
        throw std::invalid_argument("Base and height cannot be negative.");
    }
    return 0.5 * base * height;
}