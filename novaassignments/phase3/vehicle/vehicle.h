#ifndef ELECTRIC_VEHICLE_H
#define ELECTRIC_VEHICLE_H

#include <string> 
#include <iostream> 

class ElectricVehicle {
private:
    
    int vehicleId;
    std::string make;
    std::string model;
    double batteryCapacity; 
    double chargeLevel;     

   
    const double CHARGE_RATE_PER_HOUR = 20.0; 
    
    const double CONSUMPTION_RATE_PER_MILE = 0.5; 

public:
   
    ElectricVehicle(int id, const std::string& mk, const std::string& mdl, 
                    double capacity, double initialCharge);

   
    void charge(double hours);
    void drive(double miles);
    void displayVehicleDetails() const; 
};

#endif 