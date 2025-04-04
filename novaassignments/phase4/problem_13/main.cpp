#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "RoutePlanner.h"

void displayRoute(const std::vector<std::string>& route) {
    if (route.empty()) {
        std::cout << "No route generated." << std::endl;
    } else {
        std::cout << "--- Generated Route ---" << std::endl;
        for (const auto& step : route) {
            std::cout << "- " << step << std::endl;
        }
        std::cout << "-----------------------" << std::endl;
    }
}

int main() {
    Car myCar;
    Truck myTruck;
    Motorcycle myBike;

    RoutePlanner<Car> carPlanner(myCar);
    RoutePlanner<Truck> truckPlanner(myTruck);
    RoutePlanner<Motorcycle> bikePlanner(myBike);

    try {
        carPlanner.setEndpoints("City A", "City B");
        carPlanner.setPlanningParameters(true, false);
        carPlanner.planRoute();
        displayRoute(carPlanner.getRoute());
    } catch (const PlanningError& e) {
        std::cerr << "Planning Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
         bikePlanner.setEndpoints("Downtown", "Suburb");
         bikePlanner.setPlanningParameters(false, true);
         bikePlanner.planRoute();
         displayRoute(bikePlanner.getRoute());
    } catch (const PlanningError& e) {
        std::cerr << "Planning Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }


    try {
        truckPlanner.setEndpoints("Warehouse", "LowBridgePass");
        truckPlanner.setPlanningParameters(false, false);
        truckPlanner.planRoute();
        displayRoute(truckPlanner.getRoute());
    } catch (const PlanningError& e) {
        std::cerr << "\nPlanning Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }


     try {
        RoutePlanner<Car> invalidPlanner(myCar);
        invalidPlanner.planRoute();
     } catch (const PlanningError& e) {
        std::cerr << "\nPlanning Error: " << e.what() << std::endl;
     } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
     }

     try {
         carPlanner.setEndpoints("", "City C");
     } catch (const std::exception& e) {
          std::cerr << "\nError setting endpoints: " << e.what() << std::endl;
     }


    return 0;
}