#ifndef DIAGNOSTICTOOL_H
#define DIAGNOSTICTOOL_H

#include <string>

class DiagnosticTool {
public:
    DiagnosticTool(const std::string& toolId);
    void runTest(const std::string& testName);
    static void displayResults();
    static int getTotalTestsPerformed();

private:
    std::string id;
    static int totalTestsPerformed;
};

#endif 