#include "Vehicle.h"

void TouristVehicle::printDetails() const {
    cout << "Tourist Vehicle - Make: " << make << ", Model: " << model
         << ", Year: " << year << ", Price: " << price
         << ", Engine Type: " << engine.getType()
         << ", Capacity: " << engine.getCapacity()
         << ", Seats: " << seats << ", Transmission: " << transmission
         << ", Mileage: " << calculateMileage() << endl;
}

void PrivateVehicle::printDetails() const {
    cout << "Private Vehicle - Make: " << make << ", Model: " << model
         << ", Year: " << year << ", Price: " << price
         << ", Engine Type: " << engine.getType()
         << ", Capacity: " << engine.getCapacity()
         << ", Doors: " << doors << ", Transmission: " << transmission
         << ", Mileage: " << calculateMileage() << endl;
}

void displayOutput(const Vehicle &v) {
    v.printDetails();
}
