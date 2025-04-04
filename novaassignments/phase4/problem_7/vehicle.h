#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <stdexcept>
#include <vector> 
class Vehicle;
class Car;
class Truck;


class Vehicle {
protected:
    int vehicleId;
    std::string make;
    std::string model;
    double mileage; 
    double price; 

public:
    Vehicle(int id, const std::string& mk, const std::string& mdl, double mlg, double prc);
    virtual ~Vehicle() = default; 
    virtual void displayDetails() const; 

   
    int getVehicleId() const;
    double getMileage() const;
    double getPrice() const;
};


class Car : public Vehicle {
private:
    std::string engineType;

public:
    Car(int id, const std::string& mk, const std::string& mdl, double mlg, double prc, const std::string& engType);
    void displayDetails() const override; 
};


class Truck : public Vehicle {
private:
    double payloadCapacity;

public:
    Truck(int id, const std::string& mk, const std::string& mdl, double mlg, double prc, double payload);
    void displayDetails() const override; 
};


void displayVehicleDetails(Vehicle* vehicles[], int size);
double calculateTotalMileage(Vehicle* vehicles[], int size);
void sortVehiclesByPrice(Vehicle* vehicles[], int size);
Vehicle* searchVehiclesByVehicleId(Vehicle* vehicles[], int size, int searchId); 

#endif 