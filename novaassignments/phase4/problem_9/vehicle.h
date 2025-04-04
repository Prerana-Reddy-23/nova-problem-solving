#ifndef INHERITANCE_DEMO_H
#define INHERITANCE_DEMO_H

#include <string>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <vector>

class Vehicle {
protected:
    std::string make;
    std::string model;
    int year;

public:
    Vehicle(const std::string& mk, const std::string& mdl, int yr);
    virtual ~Vehicle() = default;
    virtual void displayDetails() const;

    const std::string& getMake() const;
    const std::string& getModel() const;
    int getYear() const;
};


class Electric {
protected:
    double batteryCapacity; // kWh
    double chargeLevel;     // Percentage

public:
    Electric(double capacity, double level);
    virtual ~Electric() = default;
    virtual void displayElectricDetails() const;

    double getBatteryCapacity() const;
    double getChargeLevel() const;
    void charge(double amountPercent);
};


class Car : public virtual Vehicle {
protected:
    int numberOfDoors;

public:
    Car(const std::string& mk, const std::string& mdl, int yr, int doors);
    ~Car() override = default;
    void displayDetails() const override;
};



class Truck : public virtual Vehicle {
protected:
    double payloadCapacity; 

public:
    Truck(const std::string& mk, const std::string& mdl, int yr, double payload);
     ~Truck() override = default;
    void displayDetails() const override;
};



class ElectricCar : public Car, public Electric {
private:
    std::string chargingPortType;

public:
    ElectricCar(const std::string& mk, const std::string& mdl, int yr, int doors,
                 double capacity, double level, const std::string& portType);
    ~ElectricCar() override = default;

    void displayDetails() const override;
    void displayElectricDetails() const override;
};



class ElectricTruck : public Truck, public Electric {
private:
    double towingCapacity; 

public:
    ElectricTruck(const std::string& mk, const std::string& mdl, int yr, double payload,
                   double capacity, double level, double towing);
    ~ElectricTruck() override = default;

    void displayDetails() const override;
    void displayElectricDetails() const override;
};


#endif 