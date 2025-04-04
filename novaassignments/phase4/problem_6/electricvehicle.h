#ifndef ELECTRIC_VEHICLE_H
#define ELECTRIC_VEHICLE_H

#include <string>
#include <stdexcept>

class ElectricVehicle {
private:
    int vehicleId;
    std::string make;
    std::string model;
    double batteryCapacity;
    double chargeLevel; 

    static const double DEFAULT_CHARGE_RATE_PERCENT_PER_HOUR;
    static const double DEFAULT_CONSUMPTION_PERCENT_PER_MILE;

public:
    ElectricVehicle(int id, const std::string& mk, const std::string& mdl, double capacity, double initialLevel);

    void charge(double hours);
    void drive(double miles);
    void displayVehicleDetails() const;

    int getVehicleId() const;
    const std::string& getMake() const;
    const std::string& getModel() const;
    double getBatteryCapacity() const;
    double getChargeLevel() const;
};

#endif 