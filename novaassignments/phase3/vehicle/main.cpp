
#include "vehicle.h" 
#include <iostream>        

int main() {
    std::cout << "=== Electric Vehicle Simulation Start ===" << std::endl;

   
    ElectricVehicle ev1(12345, "Tesla", "Model 3", 75.0, 50.0);

    ElectricVehicle ev2(67890, "Nissan", "Leaf", 60.0, 30.0);

    std::cout << "\n=== Initial State ===" << std::endl;
    ev1.displayVehicleDetails();
    ev2.displayVehicleDetails();


    std::cout << "\n=== EV1 Transactions ===" << std::endl;
    
    ev1.charge(2.0);
    ev1.displayVehicleDetails(); 

   
    ev1.drive(100.0);
    ev1.displayVehicleDetails(); 


    std::cout << "\n=== EV2 Transactions ===" << std::endl;


    ev2.charge(1.5);
    ev2.displayVehicleDetails(); 

  
    ev2.drive(50.0);
    ev2.displayVehicleDetails(); 

    std::cout << "\n=== Electric Vehicle Simulation End ===" << std::endl;

    return 0;
}