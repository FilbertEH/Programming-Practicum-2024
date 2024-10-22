#include <iostream>
#include <fstream>
#include <string>

unsigned long long factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    std::cout << "Factorial by Recursive Function (Max: 20!)\n";
    std::ifstream testFile("test.txt");
    if (!testFile) {
        std::cerr << "Error: Could not open test.txt" << std::endl;
        return 1;
    }

    std::string line;
    int i = 1;
    while (std::getline(testFile, line)) {
        int input = std::stoi(line.substr(7));
        std::getline(testFile, line);
        unsigned long long expectedOutput = std::stoull(line.substr(8));
        unsigned long long result = factorial(input);
        std::cout << "--- Test case " << i << " ---\n";    
        if (result == expectedOutput) {
            std::cout << "Input: " << input
                      << "\nProgram Output: " << result
                      << "\nExpected Output: " << expectedOutput
                      << "\n[Test Passed]\n";
        } else {
            std::cout << "Input: " << input
                      << "\nProgram Output: " << result
                      << "\nExpected Output: " << expectedOutput
                      << "\n[Test Failed]\n";
        }
        i++;
    }    
    testFile.close();
    return 0;
}