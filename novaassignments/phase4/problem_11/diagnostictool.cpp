#include "DiagnosticTool.h"
#include <iostream>
#include <stdexcept>
#include <string>

int DiagnosticTool::totalTestsPerformed = 0;

DiagnosticTool::DiagnosticTool(const std::string& toolId) : id(toolId) {
}

void DiagnosticTool::runTest(const std::string& testName) {
    std::cout << "Tool " << id << " running test: " << testName << "..." << std::endl;
    totalTestsPerformed++;

    if (testName == "ECU_CHECK" && id == "BasicTool") {
         throw std::runtime_error("Error: Tool " + id + " cannot perform ECU_CHECK.");
    }
     if (testName == "SENSOR_CALIBRATION") {
         std::cout << "Performing complex calibration..." << std::endl;
         bool calibration_failed = (rand() % 5 == 0); 
         if (calibration_failed) {
            throw std::logic_error("Calibration failed for test: " + testName);
         }
     }

    std::cout << "Test '" << testName << "' completed successfully by Tool " << id << "." << std::endl;
}

void DiagnosticTool::displayResults() {
    std::cout << "\n--- Diagnostic Test Summary ---" << std::endl;
    std::cout << "Total tests performed across all tools: " << totalTestsPerformed << std::endl;
    std::cout << "-----------------------------" << std::endl;
}

int DiagnosticTool::getTotalTestsPerformed() {
    return totalTestsPerformed;
}