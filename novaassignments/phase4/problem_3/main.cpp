#include <iostream>
#include <limits>
#include <stdexcept>
#include <iomanip>
#include "area.h"

template <typename T>
T getInput(const std::string& prompt) {
    T value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cout << "Invalid input. Please enter a valid number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}


int main() {
    double radius, length, width, base, height;
    double circleArea, rectangleArea, triangleArea;

    std::cout << std::fixed << std::setprecision(2);

    try {
        std::cout << "--- Circle Area Calculation ---" << std::endl;
        radius = getInput<double>("Enter the radius of the circle: ");
        circleArea = calculateArea(radius);
        std::cout << "Area of the circle: " << circleArea << std::endl;

        std::cout << "\n--- Rectangle Area Calculation ---" << std::endl;
        length = getInput<double>("Enter the length of the rectangle: ");
        width = getInput<double>("Enter the width of the rectangle: ");
        rectangleArea = calculateArea(length, width);
        std::cout << "Area of the rectangle: " << rectangleArea << std::endl;

        std::cout << "\n--- Triangle Area Calculation ---" << std::endl;
        base = getInput<double>("Enter the base of the triangle: ");
        height = getInput<double>("Enter the height of the triangle: ");
        triangleArea = calculateArea(base, height, true); // Pass true for the triangle overload
        std::cout << "Area of the triangle: " << triangleArea << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "\nError: Invalid input dimension: " << e.what() << std::endl;
        return 1;
    } catch (const std::logic_error& e) {
         std::cerr << "\nError: Programming logic error: " << e.what() << std::endl;
         return 1;
    } catch (const std::exception& e) {
        std::cerr << "\nAn unexpected standard error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "\nAn unknown error occurred." << std::endl;
        return 1;
    }

    return 0;
}