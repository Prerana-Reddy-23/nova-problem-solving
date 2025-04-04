
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
#include <vector> 
class Vehicle {
protected: 
    int vehicleId;
    std::string make;
    std::string model;
   
    double mileage; 
    double price;

public:
   
    Vehicle(int id, const std::string& mk, const std::string& mdl, double mil, double pr);

    
    virtual ~Vehicle(); 

    
    virtual void displayDetails() const; 

   
    int getVehicleId() const;
    double getMileage() const;
    double getPrice() const;
    std::string getMake() const;
    std::string getModel() const;
};


class Car : public Vehicle {
private:
    std::string engineType;

public:
    
    Car(int id, const std::string& mk, const std::string& mdl, double mil, double pr, const std::string& engine);

    
    void displayDetails() const override; 

    
    std::string getEngineType() const;
};


class Truck : public Vehicle {
private:
    double payloadCapacity; 

public:
    
    Truck(int id, const std::string& mk, const std::string& mdl, double mil, double pr, double capacity);

   
    void displayDetails() const override;

  
    double getPayloadCapacity() const;
};



void displayVehicleDetails(Vehicle* vehicles[], int size);

double calculateTotalMileage(Vehicle* vehicles[], int size);


void sortVehiclesByPrice(Vehicle* vehicles[], int size);


void searchVehiclesByVehicleId(Vehicle* vehicles[], int size, int searchId);


#endif 