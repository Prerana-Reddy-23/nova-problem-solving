
#ifndef BATTERY_H
#define BATTERY_H

#include <iostream>
#include <stdexcept>
#include <iomanip>

class Battery;

std::ostream& operator<<(std::ostream& os, const Battery& battery);
std::istream& operator>>(std::istream& is, Battery& battery);

class Battery {
private:
    double capacity;
    double chargeLevel;
    double voltage;
    double temperature;

    const double CHARGE_INCREMENT = 1.0;
    const double DISCHARGE_DECREMENT = 1.0;
    const double TEMP_CHANGE_ON_CHARGE = 0.5;
    const double TEMP_CHANGE_ON_DISCHARGE = 0.8;
    const double VOLTAGE_CHANGE_ON_CHARGE = 0.05;
    const double VOLTAGE_CHANGE_ON_DISCHARGE = -0.08;

    void clampChargeLevel();
    void updateState(double chargeChange);

public:
    Battery(double cap = 100.0, double initialCharge = 50.0, double initialVoltage = 12.0, double initialTemp = 20.0);
    Battery(const Battery& other);

    ~Battery() = default;

    void charge(double amount);
    void discharge(double amount);
    double getCapacity() const;
    double getChargeLevel() const;
    double getVoltage() const;
    double getTemperature() const;

    double& operator[](int index);
    const double& operator[](int index) const;

    double& operator*();
    const double& operator*() const;

    Battery* operator->();
    const Battery* operator->() const;

    Battery& operator++();
    Battery& operator--();

    Battery& operator=(const Battery& other);

    friend std::ostream& operator<<(std::ostream& os, const Battery& battery);
    friend std::istream& operator>>(std::istream& is, Battery& battery);
};

#endif 