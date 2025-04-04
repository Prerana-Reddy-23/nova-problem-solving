#ifndef FLEET_MANAGER_H
#define FLEET_MANAGER_H

#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

enum class EngineType {
    PETROL,
    DIESEL,
    ELECTRIC,
    HYBRID
};

std::string engineTypeToString(EngineType type);

class Engine {
private:
    EngineType type;
    double capacity; 

public:
    Engine(EngineType et = EngineType::PETROL, double cap = 1.0);
    EngineType getType() const;
    double getCapacity() const;
    void display() const;
};

class Vehicle {
protected:
    std::string make;
    std::string model;
    int year;
    double price;
    Engine engine;

public:
    Vehicle(const std::string& mk, const std::string& mdl, int yr, double pr, const Engine& eng);
    virtual ~Vehicle() = default;

    virtual double calculateMileage() const = 0;
    virtual void printDetails() const;

    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
    double getPrice() const;
    const Engine& getEngine() const;

    friend void displayOutput(const Vehicle& v);
};


class TouristVehicle : public Vehicle {
private:
    int seats;
    std::string transmission;

public:
    TouristVehicle(const std::string& mk, const std::string& mdl, int yr, double pr, const Engine& eng, int st, const std::string& trans);
    ~TouristVehicle() override = default;

    double calculateMileage() const override;
    void printDetails() const override;

    int getSeats() const;
    std::string getTransmission() const;
};


class PrivateVehicle : public Vehicle {
private:
    int doors;
    std::string transmission;

public:
    PrivateVehicle(const std::string& mk, const std::string& mdl, int yr, double pr, const Engine& eng, int drs, const std::string& trans);
    ~PrivateVehicle() override = default;

    double calculateMileage() const override;
    void printDetails() const override;

    int getDoors() const;
    std::string getTransmission() const;
};


double calculateTotalPrice(const std::vector<Vehicle*>& fleet);
void printAllVehicleDetails(const std::vector<Vehicle*>& fleet);


#endif