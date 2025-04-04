#ifndef ROUTEPLANNER_H
#define ROUTEPLANNER_H

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <type_traits>

struct Car {
    std::string type = "Car";
    double maxSpeed = 180.0;
};

struct Truck {
    std::string type = "Truck";
    double maxHeight = 4.0;
    bool avoidsLowBridges = true;
};

struct Motorcycle {
    std::string type = "Motorcycle";
    bool canUseNarrowPaths = true;
    double agilityFactor = 0.8;
};

class PlanningError : public std::runtime_error {
public:
    PlanningError(const std::string& message) : std::runtime_error(message) {}
};

template <typename VehicleType>
class RoutePlanner {
public:
    RoutePlanner(const VehicleType& vehicle);
    void setEndpoints(const std::string& start, const std::string& end);
    void setPlanningParameters(bool useTraffic, bool avoidTolls);
    void planRoute();
    const std::vector<std::string>& getRoute() const;

private:
    VehicleType vehicleInfo;
    std::string startPoint;
    std::string endPoint;
    bool useTrafficData = false;
    bool avoidTollsRoute = false;
    std::vector<std::string> plannedRoute;

    void simulatePlanningLogic();
};

template <typename VehicleType>
RoutePlanner<VehicleType>::RoutePlanner(const VehicleType& vehicle)
    : vehicleInfo(vehicle) {}

template <typename VehicleType>
void RoutePlanner<VehicleType>::setEndpoints(const std::string& start, const std::string& end) {
    if (start.empty() || end.empty()) {
        throw std::invalid_argument("Start and end points cannot be empty.");
    }
    startPoint = start;
    endPoint = end;
    plannedRoute.clear();
}

template <typename VehicleType>
void RoutePlanner<VehicleType>::setPlanningParameters(bool useTraffic, bool avoidTolls) {
    useTrafficData = useTraffic;
    avoidTollsRoute = avoidTolls;
}

template <typename VehicleType>
void RoutePlanner<VehicleType>::planRoute() {
    if (startPoint.empty() || endPoint.empty()) {
        throw PlanningError("Endpoints not set before planning.");
    }

    std::cout << "\nPlanning route for " << vehicleInfo.type
              << " from " << startPoint << " to " << endPoint << "..." << std::endl;
    std::cout << "Parameters: Traffic=" << (useTrafficData ? "Yes" : "No")
              << ", Avoid Tolls=" << (avoidTollsRoute ? "Yes" : "No") << std::endl;

    plannedRoute.clear();
    simulatePlanningLogic();

    if (plannedRoute.empty()) {
         throw PlanningError("No suitable route found with the given parameters and vehicle constraints.");
    }

     std::cout << "Route planned successfully for " << vehicleInfo.type << "." << std::endl;
}

template <typename VehicleType>
void RoutePlanner<VehicleType>::simulatePlanningLogic() {

    plannedRoute.push_back("Start at " + startPoint);

    if (useTrafficData) {
         plannedRoute.push_back("Consider current traffic conditions.");
    }
     if (avoidTollsRoute) {
         plannedRoute.push_back("Avoid toll roads.");
     }


    if constexpr (std::is_same_v<VehicleType, Truck>) {
         plannedRoute.push_back("Check bridge heights (Max: " + std::to_string(vehicleInfo.maxHeight) + "m).");
         if (endPoint == "LowBridgePass") {
              plannedRoute.clear();
              return;
         }
    } else if constexpr (std::is_same_v<VehicleType, Motorcycle>) {
         if(vehicleInfo.canUseNarrowPaths) {
            plannedRoute.push_back("Utilize narrow paths if available and faster.");
         }
    } else if constexpr (std::is_same_v<VehicleType, Car>) {
         plannedRoute.push_back("Standard car routing applied.");
    }


    if (startPoint == "City A" && endPoint == "City B") {
        plannedRoute.push_back("Take Highway 101 North.");
        plannedRoute.push_back("Follow signs for City B.");
    } else if (startPoint == "Downtown" && endPoint == "Suburb") {
         plannedRoute.push_back("Use Main Street West.");
         plannedRoute.push_back("Turn right on Elm Avenue.");
    } else {
         plannedRoute.push_back("Generic Route Step 1");
         plannedRoute.push_back("Generic Route Step 2");
    }


    plannedRoute.push_back("Arrive at " + endPoint);
}


template <typename VehicleType>
const std::vector<std::string>& RoutePlanner<VehicleType>::getRoute() const {
    return plannedRoute;
}

#endif