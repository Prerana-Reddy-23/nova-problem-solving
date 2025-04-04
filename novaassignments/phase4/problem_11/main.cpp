#include "DiagnosticTool.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));

    DiagnosticTool advancedTool("AdvancedPro");
    DiagnosticTool basicTool("BasicTool");

    std::vector<std::string> tests = {
        "ENGINE_START",
        "FUEL_SYSTEM_CHECK",
        "ECU_CHECK",
        "SENSOR_CALIBRATION",
        "TRANSMISSION_SCAN"
    };

    for (const auto& test : tests) {
        try {
            if (test == "ECU_CHECK" || test == "SENSOR_CALIBRATION") {
                 advancedTool.runTest(test);
            } else {
                 basicTool.runTest(test);
            }
        } catch (const std::runtime_error& e) {
            std::cerr << "Runtime Exception Caught: " << e.what() << std::endl;
        } catch (const std::logic_error& e) {
             std::cerr << "Logic Exception Caught: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Standard Exception Caught: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Unknown exception caught during test: " << test << std::endl;
        }
    }

    DiagnosticTool::displayResults();

  
    try {
        basicTool.runTest("ECU_CHECK");
    } catch (const std::exception& e) {
         std::cerr << "\nException during forced ECU_CHECK on basic tool: " << e.what() << std::endl;
    }

     DiagnosticTool::displayResults();


    return 0;
}