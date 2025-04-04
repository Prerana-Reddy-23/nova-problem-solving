#include "Battery.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <map>
#include <limits> 
#include <algorithm> 

void Battery::initializeParameters(double initialTemp) {
    parameters["chargeRate"] = 10.0; 
    parameters["dischargeRate"] = 15.0; 
    parameters["temperature"] = initialTemp;
}

void Battery::updateStateOnCharge(double amountPercent) {
    
    parameters["temperature"] += amountPercent * 0.05;
   
    if (chargeLevel < 95) voltage += amountPercent * 0.01;
}

void Battery::updateStateOnDischarge(double amountPercent) {
   
    parameters["temperature"] += amountPercent * 0.07;

    if (chargeLevel > 5) voltage -= amountPercent * 0.015;
    voltage = std::max(0.0, voltage); 
}


Battery::Battery(double cap, double level, double volt, double temp)
    : capacity(cap), chargeLevel(level), voltage(volt) {
    if (cap <= 0.0) throw std::invalid_argument("Capacity must be positive.");
    if (level < 0.0 || level > 100.0) throw std::invalid_argument("Initial charge level must be between 0.0 and 100.0.");
    if (volt < 0.0) throw std::invalid_argument("Initial voltage cannot be negative.");

    initializeParameters(temp); 
}


void Battery::charge(double amountPercent) {
    if (amountPercent < 0.0) throw std::invalid_argument("Charge amount cannot be negative.");
    double actualCharge = std::min(amountPercent, 100.0 - chargeLevel);
    chargeLevel += actualCharge;
    updateStateOnCharge(actualCharge);
}

void Battery::discharge(double amountPercent) {
    if (amountPercent < 0.0) throw std::invalid_argument("Discharge amount cannot be negative.");
    double actualDischarge = std::min(amountPercent, chargeLevel);
     if (actualDischarge == 0 && amountPercent > 0) {
         
     }
    chargeLevel -= actualDischarge;
    updateStateOnDischarge(actualDischarge);
}

double Battery::getCapacity() const { return capacity; }
double Battery::getChargeLevel() const { return chargeLevel; }
double Battery::getVoltage() const { return voltage; }
double Battery::getTemperature() const {
    
    auto it = parameters.find("temperature");
    if (it != parameters.end()) {
        return it->second;
    }
    
    return -999.0; 
}


double& Battery::operator[](const std::string& key) {
    try {
        return parameters.at(key); 
    } catch (const std::out_of_range& oor) {
        throw std::out_of_range("Invalid battery parameter key: '" + key + "'");
    }
}

const double& Battery::operator[](const std::string& key) const {
     try {
        return parameters.at(key);
    } catch (const std::out_of_range& oor) {
        throw std::out_of_range("Invalid battery parameter key: '" + key + "'");
    }
}


Battery& Battery::operator*() {
    return *this;
}
const Battery& Battery::operator*() const {
    return *this;
}

Battery* Battery::operator->() {
    return this;
}
const Battery* Battery::operator->() const {
     return this;
}

Battery& Battery::operator++() {
    double incrementAmount = 1.0; 
    this->charge(incrementAmount);
    return *this;
}

Battery& Battery::operator--() { 
     double decrementAmount = 1.0; 
     this->discharge(decrementAmount); 
    return *this;
}

Battery& Battery::operator=(const Battery& other) {
    if (this == &other) { 
        return *this;
    }
    capacity = other.capacity;
    chargeLevel = other.chargeLevel;
    voltage = other.voltage;
    parameters = other.parameters; 
    return *this;
}



std::ostream& operator<<(std::ostream& os, const Battery& bat) {
    os << std::fixed << std::setprecision(2);
    os << "Battery Details:\n";
    os << "  Capacity:    " << bat.capacity << " units\n"; 
    os << "  Charge Level:" << bat.chargeLevel << " %\n";
    os << "  Voltage:     " << bat.voltage << " V\n";
    try {
         os << "  Temperature: " << bat.parameters.at("temperature") << " C\n"; 
         os << "  Charge Rate: " << bat.parameters.at("chargeRate") << " %/op\n";
         os << "  Discharge Rate:" << bat.parameters.at("dischargeRate") << " %/op";
    } catch (const std::out_of_range&) {
        os << "  (Some parameters not available)";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Battery& bat) {
    double tempCap, tempLevel, tempVolt, tempTemp;
    std::cout << "Enter Capacity: ";
    is >> tempCap;
    std::cout << "Enter Charge Level (0-100): ";
    is >> tempLevel;
    std::cout << "Enter Voltage: ";
    is >> tempVolt;
    std::cout << "Enter Temperature: ";
    is >> tempTemp;


    if (is.fail()) {
       
       return is; 
    }

    if (tempCap <= 0.0 || tempLevel < 0.0 || tempLevel > 100.0 || tempVolt < 0.0) {
        std::cerr << "\nError: Invalid value entered during input. Battery state may be inconsistent." << std::endl;
        is.setstate(std::ios::failbit); 
    } else {
        bat.capacity = tempCap;
        bat.chargeLevel = tempLevel;
        bat.voltage = tempVolt;
        
        bat.initializeParameters(tempTemp);
    }

    return is;
}