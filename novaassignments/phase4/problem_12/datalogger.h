#ifndef DATALOGGER_H
#define DATALOGGER_H

#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>

class DataLogger {
public:
    DataLogger(const std::string& logId);

    template <typename T>
    void logData(const T& data);

    void displayLog() const;
    void clearLog();

private:
    std::string identifier;
    std::vector<std::string> loggedData;
    static const size_t MAX_STRING_LOG_LENGTH = 100;
};

template <typename T>
void DataLogger::logData(const T& data) {
    std::ostringstream oss;
    oss << data;
    std::string dataStr = oss.str();

    if (std::is_same<T, std::string>::value && dataStr.length() > MAX_STRING_LOG_LENGTH) {
        throw std::runtime_error("Error: Log data string exceeds maximum length for logger " + identifier);
    }

    if (loggedData.size() >= 1000) {
         throw std::overflow_error("Error: Log buffer full for logger " + identifier);
    }


    loggedData.push_back(dataStr);
    std::cout << "Logged [" << identifier << "]: " << dataStr << std::endl;
}


#endif 