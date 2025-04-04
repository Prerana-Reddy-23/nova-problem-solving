
#ifndef VEHICLES_H
#define VEHICLES_H

#include <string>
#include <iostream>
#include <iomanip> 
class Vehicle {
protected:
    std::string make;
    std::string model;
    int year;

public:
    Vehicle(const std::string& mk, const std::string& mdl, int yr);
    virtual ~Vehicle(); 

    virtual void displayDetails() const; 

  
    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
};


class Electric {
protected:
    double batteryCapacity; 
    double chargeLevel; 

public:
    Electric(double capacity, double level);
    virtual ~Electric();

    virtual void displayElectricDetails() const;

    
    void charge(double amount);
    void consumePower(double amount);


    double getBatteryCapacity() const;
    double getChargeLevel() const;
};


class Car : public virtual Vehicle { 
protected: 
 int numberOfDoors;

public:
    Car(const std::string& mk, const std::string& mdl, int yr, int doors);
    ~Car() override;

    void displayDetails() const override; 
    int getNumberOfDoors() const;
};


class Truck : public virtual Vehicle { 
protected: 
    double payloadCapacity; 

public:
    Truck(const std::string& mk, const std::string& mdl, int yr, double payload);
    ~Truck() override;

    void displayDetails() const override; 

    double getPayloadCapacity() const;
};


class ElectricCar : public Car, public Electric {
private:
    std::string chargingPortType; 

public:
    
    ElectricCar(const std::string& mk, const std::string& mdl, int yr, int doors,
                double capacity, double level, const std::string& portType);
    ~ElectricCar() override;

    
    void displayDetails() const override; 
    

    std::string getChargingPortType() const;
};



class ElectricTruck : public Truck, public Electric {
private:
    bool hasPowerTakeOff; 

public:
    
    ElectricTruck(const std::string& mk, const std::string& mdl, int yr, double payload,
                  double capacity, double level, bool pto);
    ~ElectricTruck() override;

    
    void displayDetails() const override;

    bool getHasPowerTakeOff() const;
};


#endif 