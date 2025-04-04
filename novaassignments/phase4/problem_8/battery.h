#ifndef BATTERY_H
#define BATTERY_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <map>

class Battery {
private:
    double capacity;   
    double chargeLevel; 
    double voltage;     
    std::map<std::string, double> parameters;

    void initializeParameters(double initialTemp);
    void updateStateOnCharge(double amountPercent);
    void updateStateOnDischarge(double amountPercent);


public:
    
    Battery(double cap = 100.0, double level = 50.0, double volt = 12.0, double temp = 25.0);
    ~Battery() = default;

   
    void charge(double amountPercent);
    void discharge(double amountPercent);
    double getCapacity() const;
    double getChargeLevel() const;
    double getVoltage() const;
    double getTemperature() const; 
    double& operator[](const std::string& key);
    const double& operator[](const std::string& key) const; 
    Battery& operator*();
    const Battery& operator*() const;

   
    Battery* operator->();
    const Battery* operator->() const;

  
    Battery& operator++();

    Battery& operator--();

   
    Battery& operator=(const Battery& other);

  
    friend std::ostream& operator<<(std::ostream& os, const Battery& bat);
    friend std::istream& operator>>(std::istream& is, Battery& bat);
};

#endif 