#include "DataLogger.h"
#include <iostream>
#include <string>
#include <stdexcept>

int main() {
    DataLogger sensorLogger("SensorReadings");
    DataLogger systemLogger("SystemEvents");

    try {
        sensorLogger.logData(42);
        sensorLogger.logData(3.14159f);
        systemLogger.logData("System Initialized");
        sensorLogger.logData(-12.5);
        systemLogger.logData(std::string("User Login: admin"));

        std::string longString(150, 'A');
        systemLogger.logData(longString);

    } catch (const std::runtime_error& e) {
        std::cerr << "Runtime Exception Caught: " << e.what() << std::endl;
    } catch (const std::overflow_error& e) {
         std::cerr << "Overflow Exception Caught: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Standard Exception Caught: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception caught during logging." << std::endl;
    }

     try {
         systemLogger.logData("Attempting another log after potential error.");
         for(int i = 0; i < 1005; ++i) {
             sensorLogger.logData(i);
         }
     } catch (const std::runtime_error& e) {
        std::cerr << "Runtime Exception Caught: " << e.what() << std::endl;
     } catch (const std::overflow_error& e) {
         std::cerr << "Overflow Exception Caught: " << e.what() << std::endl;
     } catch (const std::exception& e) {
        std::cerr << "Standard Exception Caught: " << e.what() << std::endl;
     } catch (...) {
        std::cerr << "Unknown exception caught during logging." << std::endl;
     }


    sensorLogger.displayLog();
    systemLogger.displayLog();

    sensorLogger.clearLog();
    sensorLogger.displayLog();

    return 0;
}