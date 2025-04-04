
#include "Battery.h"
#include <iostream>
#include <stdexcept> 
#include <algorithm> 
#include <iomanip>   
#include <limits>    



void Battery::clampChargeLevel() {
    chargeLevel = std::max(0.0, std::min(chargeLevel, capacity));
}

void Battery::updateState(double chargeChange) {
    if (chargeChange > 0) { 
        temperature += TEMP_CHANGE_ON_CHARGE * (chargeChange / CHARGE_INCREMENT); 
        voltage += VOLTAGE_CHANGE_ON_CHARGE * (chargeChange / CHARGE_INCREMENT);
    } else if (chargeChange < 0) { 
        temperature += TEMP_CHANGE_ON_DISCHARGE * (-chargeChange / DISCHARGE_DECREMENT);
        voltage += VOLTAGE_CHANGE_ON_DISCHARGE * (-chargeChange / DISCHARGE_DECREMENT);
    }
 
    voltage = std::max(10.0, std::min(voltage, 14.5)); 

    temperature = std::max(-10.0, std::min(temperature, 60.0)); 
}




Battery::Battery(double cap, double initialCharge, double initialVoltage, double initialTemp)
    : capacity(cap > 0 ? cap : 100.0),
      chargeLevel(initialCharge),
      voltage(initialVoltage),
      temperature(initialTemp) 
{
    clampChargeLevel(); 
    std::cout << "Battery created. Capacity: " << capacity << std::endl;
}

Battery::Battery(const Battery& other)
    : capacity(other.capacity),
      chargeLevel(other.chargeLevel),
      voltage(other.voltage),
      temperature(other.temperature)
{
     std::cout << "Battery copied." << std::endl;
}


void Battery::charge(double amount) {
    if (amount < 0) {
        std::cerr << "Warning: Cannot charge by a negative amount. Use discharge()." << std::endl;
        return;
    }
    std::cout << "Charging by " << amount << " units..." << std::endl;
    double oldChargeLevel = chargeLevel;
    chargeLevel += amount;
    clampChargeLevel();
    updateState(chargeLevel - oldChargeLevel); 
}

void Battery::discharge(double amount) {
    if (amount < 0) {
         std::cerr << "Warning: Cannot discharge by a negative amount. Use charge()." << std::endl;
        return;
    }
    std::cout << "Discharging by " << amount << " units..." << std::endl;
    double oldChargeLevel = chargeLevel;
    chargeLevel -= amount;
    clampChargeLevel();
    updateState(chargeLevel - oldChargeLevel); 
}

double Battery::getCapacity() const { return capacity; }
double Battery::getChargeLevel() const { return chargeLevel; }
double Battery::getVoltage() const { return voltage; }
double Battery::getTemperature() const { return temperature; }

double& Battery::operator[](int index) {
    switch (index) {
        case 0: return chargeLevel; 
        case 1: return voltage;
        case 2: return temperature;
        default:
            throw std::out_of_range("Battery::operator[]: Invalid index");
    }
}


const double& Battery::operator[](int index) const {
     switch (index) {
        case 0: return chargeLevel;
        case 1: return voltage;
        case 2: return temperature;
        default:
            throw std::out_of_range("Battery::operator[] const: Invalid index");
    }
}

double& Battery::operator*() {
    return chargeLevel; 
}


const double& Battery::operator*() const {
    return chargeLevel;
}


Battery* Battery::operator->() {
    return this; 
}


const Battery* Battery::operator->() const {
     return this;
}


Battery& Battery::operator++() {
    std::cout << "Pre-incrementing charge..." << std::endl;
    double oldChargeLevel = chargeLevel;
    chargeLevel += CHARGE_INCREMENT;
    clampChargeLevel();
    updateState(chargeLevel - oldChargeLevel);
    return *this; 
}
Battery& Battery::operator--() {
    std::cout << "Pre-decrementing charge..." << std::endl;
    double oldChargeLevel = chargeLevel;
    chargeLevel -= DISCHARGE_DECREMENT;
    clampChargeLevel();
     updateState(chargeLevel - oldChargeLevel);
    return *this; 
}


Battery& Battery::operator=(const Battery& other) {
    std::cout << "Assignment operator called..." << std::endl;
   
    if (this == &other) {
        return *this;
    }

   
    capacity = other.capacity;
    chargeLevel = other.chargeLevel;
    voltage = other.voltage;
    temperature = other.temperature;

   
    return *this;
}


std::ostream& operator<<(std::ostream& os, const Battery& battery) {
    os << std::fixed << std::setprecision(2); 
    os << "Battery Status:\n";
    os << "  Capacity:     " << battery.capacity << " units\n";
    os << "  Charge Level: " << battery.chargeLevel << " units ("
       << (battery.chargeLevel / battery.capacity * 100.0) << "%)\n";
    os << "  Voltage:      " << battery.voltage << " V\n";
    os << "  Temperature:  " << battery.temperature << " C"; 
    return os;
}


std::istream& operator>>(std::istream& is, Battery& battery) {
    double tempCap, tempCharge, tempVolt, tempTemp;
    std::cout << "Enter Battery Data:\n";

    std::cout << "  Capacity: ";
    is >> tempCap;

    std::cout << "  Initial Charge Level: ";
    is >> tempCharge;

    std::cout << "  Initial Voltage: ";
    is >> tempVolt;

    std::cout << "  Initial Temperature: ";
    is >> tempTemp;

    
    if (is) { 
        if (tempCap <= 0) {
             std::cerr << "Warning: Capacity must be positive. Using default 100.0.\n";
             battery.capacity = 100.0;
        } else {
            battery.capacity = tempCap;
        }
        battery.chargeLevel = tempCharge;
        battery.voltage = tempVolt;
        battery.temperature = tempTemp;
        battery.clampChargeLevel(); 
    } else {
        std::cerr << "Error reading battery data from input stream." << std::endl;
        
        is.clear(); 
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }

    return is;
}