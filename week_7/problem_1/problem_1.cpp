#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int operation(int a, char op, int b) {
    if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    }
    return 0;
}

int main() {
    std::cout << "Addition or Subtraction with Two Operands\n";
    std::ifstream testFile("test.txt");
    std::string line;

    if (!testFile) {
        std::cerr << "Error: Could not open test.txt" << std::endl;
        return 1;
    }
    int i = 1;
    while (std::getline(testFile, line)) {
        int a, b;
        char op;
        std::istringstream iss(line.substr(7));
        iss >> a >> op >> b;
        std::getline(testFile, line);
        int expectedOutput;
        std::istringstream oss(line.substr(8));
        oss >> expectedOutput;
        int result = operation(a, op, b);

        std::cout << "--- Test case " << i << " ---\n";
        if (result == expectedOutput) {
            std::cout << a << " " << op << " " << b << " = " << result
            << "\n[Test Passed]\n";
        } else {
            std::cout << a << " " << op << " " << b << " != " << result
            << "\nExpected Output: " << expectedOutput
            << "\n[Test Failed]\n";
        }
        i++;
    }
    testFile.close();
    return 0;
}