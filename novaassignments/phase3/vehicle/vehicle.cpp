#include "vehicle.h" 
#include <iostream>         
#include <string>
#include <algorithm>        
ElectricVehicle::ElectricVehicle(int id, const std::string& mk, const std::string& mdl, 
                                 double capacity, double initialCharge)
    : vehicleId(id), make(mk), model(mdl), batteryCapacity(capacity), chargeLevel(initialCharge) 
{
    
    chargeLevel = std::max(0.0, std::min(chargeLevel, batteryCapacity));
    std::cout << "Electric Vehicle Created: " << make << " " << model << " (ID: " << vehicleId << ")" << std::endl;
}


void ElectricVehicle::charge(double hours) {
    if (hours < 0) {
        std::cout << "Charging time cannot be negative." << std::endl;
        return;
    }

    double chargeToAdd = hours * CHARGE_RATE_PER_HOUR;
    double potentialChargeLevel = chargeLevel + chargeToAdd;

    std::cout << "\nCharging " << make << " " << model << " for " << hours << " hours..." << std::endl;
    
    
    chargeLevel = std::min(potentialChargeLevel, batteryCapacity); 

    std::cout << "Charging complete." << std::endl;
}


void ElectricVehicle::drive(double miles) {
     if (miles < 0) {
        std::cout << "Distance to drive cannot be negative." << std::endl;
        return;
    }

    double chargeNeeded = miles * CONSUMPTION_RATE_PER_MILE;

    std::cout << "\nAttempting to drive " << make << " " << model << " for " << miles << " miles..." << std::endl;
    std::cout << "(Requires " << chargeNeeded << " units of charge, Available: " << chargeLevel << " units)" << std::endl;


    if (chargeLevel >= chargeNeeded) {
        chargeLevel -= chargeNeeded;
        
        chargeLevel = std::max(0.0, chargeLevel); 
        std::cout << "Successfully drove " << miles << " miles." << std::endl;
    } else {
        double possibleDistance = chargeLevel / CONSUMPTION_RATE_PER_MILE;
        std::cout << "Not enough charge to drive " << miles << " miles." << std::endl;
        std::cout << "Can only drive approximately " << possibleDistance << " miles on current charge." << std::endl;
       
    }
}


void ElectricVehicle::displayVehicleDetails() const {
    std::cout << "\n--- Vehicle Details ---" << std::endl;
    std::cout << "Vehicle ID:       " << vehicleId << std::endl;
    std::cout << "Make:             " << make << std::endl;
    std::cout << "Model:            " << model << std::endl;
    std::cout << "Battery Capacity: " << batteryCapacity << " units" << std::endl;
    std::cout << "Current Charge:   " << chargeLevel << " units (" 
              << (chargeLevel / batteryCapacity) * 100.0 << "%)" << std::endl; 
    std::cout << "-----------------------\n" << std::endl;
}