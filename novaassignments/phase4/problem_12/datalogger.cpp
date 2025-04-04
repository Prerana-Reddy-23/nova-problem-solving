#include "DataLogger.h"
#include <iostream>
#include <vector>
#include <string>

DataLogger::DataLogger(const std::string& logId) : identifier(logId) {}

void DataLogger::displayLog() const {
    std::cout << "\n--- Log Contents for [" << identifier << "] ---" << std::endl;
    if (loggedData.empty()) {
        std::cout << "(Log is empty)" << std::endl;
    } else {
        for (const auto& entry : loggedData) {
            std::cout << "- " << entry << std::endl;
        }
    }
    std::cout << "-------------------------------------" << std::endl;
}

void DataLogger::clearLog() {
    loggedData.clear();
    std::cout << "Log cleared for [" << identifier << "]." << std::endl;
}