#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

enum EngineType { PETROL, DIESEL, ELECTRIC, HYBRID };

class Engine {
    EngineType type;
    double capacity;
public:
    Engine(EngineType t, double c) : type(t), capacity(c) {}
    EngineType getType() const { return type; }
    double getCapacity() const { return capacity; }
};

class Vehicle {
protected:
    string make, model;
    int year;
    double price;
    Engine engine;
public:
    Vehicle(string mk, string mdl, int yr, double pr, Engine eng)
        : make(mk), model(mdl), year(yr), price(pr), engine(eng) {}
    virtual double calculateMileage() const = 0;
    virtual void printDetails() const = 0;
    double getPrice() const { return price; }
    friend void displayOutput(const Vehicle &v);
};

class TouristVehicle : public Vehicle {
    int seats;
    string transmission;
public:
    TouristVehicle(string mk, string mdl, int yr, double pr, Engine eng, int s, string tr)
        : Vehicle(mk, mdl, yr, pr, eng), seats(s), transmission(tr) {}
    double calculateMileage() const override { return (1000 / engine.getCapacity()) + seats; }
    void printDetails() const override;
};

class PrivateVehicle : public Vehicle {
    int doors;
    string transmission;
public:
    PrivateVehicle(string mk, string mdl, int yr, double pr, Engine eng, int d, string tr)
        : Vehicle(mk, mdl, yr, pr, eng), doors(d), transmission(tr) {}
    double calculateMileage() const override { return (1200 / engine.getCapacity()) + doors; }
    void printDetails() const override;
};

void displayOutput(const Vehicle &v);

#endif
