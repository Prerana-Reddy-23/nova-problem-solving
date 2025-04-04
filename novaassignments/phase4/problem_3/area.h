#ifndef SHAPE_CALCULATIONS_H
#define SHAPE_CALCULATIONS_H

#include <stdexcept>

extern const double PI; 

double calculateArea(double radius);
double calculateArea(double length, double width);
double calculateArea(double base, double height, bool isTriangle);

#endif 