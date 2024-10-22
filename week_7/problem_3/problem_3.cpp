#include <iostream>
#include <fstream>
#include <string>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
std::cout << "GCD of Two Numbers by Recursive Function\n";
    std::ifstream testFile("test.txt");
    if (!testFile.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    int i = 1;
    while (std::getline(testFile, line)) {
        size_t comma_pos = line.find(',');
        int num1 = std::stoi(line.substr(7, comma_pos - 7));
        int num2 = std::stoi(line.substr(comma_pos + 1));            
        std::getline(testFile, line); 
        int expectedOutput = std::stoi(line.substr(8));
        int result = gcd(num1, num2);
    
        std::cout << "--- Test case " << i << " ---\n";    
        if (result == expectedOutput) {
            std::cout << "GCD between numbers: " << num1 << ", " << num2                      
                      << "\nProgram Output: " << result
                      << "\nExpected Output: " << expectedOutput
                      << "\n[Test Passed]\n";
        } else {
            std::cout << "GCD between numbers: " << num1 << ", " << num2
                      << "\nProgram Output: " << result
                      << "\nExpected Output: " << expectedOutput
                      << "\n[Test Failed]\n";
        }
        i++;
    }
    testFile.close();
    return 0;
}