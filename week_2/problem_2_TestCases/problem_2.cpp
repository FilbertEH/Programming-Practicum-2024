#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

std::string task(double a, double b, double c){
    double x1, x2;
    double discriminant = pow(b, 2) - (4 * a * c);
    std::string x;
    if (discriminant > 0){ 
        x1 = (-b + std::sqrt(discriminant)) / (2 * a);
        x2 = (-b - std::sqrt(discriminant)) / (2 * a);
        x += std::to_string(x1) + ", " + std::to_string(x2);
    }
    else if (discriminant == 0){
        x1 = -b / (2 * a);
        x = std::to_string(x1);
    }
    else{
        x = "complex";
    }
    return x;
}

int main(){
    std::cout << "Solving a Quadratic Equation [ax^2 + bx + c = 0]" << std::endl;
    std::ifstream testFile("test.txt");
    std::string line;
    
    if (!testFile) {
        std::cerr << "Error: Could not open test.txt" << std::endl;
        return 1;
    }

    int i = 1;
    while (getline(testFile, line)) {
        double a, b, c;
        std::string discriminant, expected_output;
        getline(testFile, line);  
        a = stod(line.substr(4));
        getline(testFile, line); 
        b = stod(line.substr(4));
        getline(testFile, line); 
        c = stod(line.substr(4));
        getline(testFile, line); 
        std::string output = task(a, b, c);
        getline(testFile, line); 
        expected_output = std::string(line.substr(4));
        if (output == expected_output) {
            std::cout << "----- TEST CASE " << i << " PASSED [OUTPUT MATCH] -----\n" <<
            "Input: a = " << a << ", b = " << b << ", c = " << c
            << "\nExpected Output:\nx = " << expected_output 
            << "\nProgram Output:\nx = " << output << std::endl;
        } else {
            std::cout << "----- TEST CASE " << i << " FAILED [IRREGULARITY FOUND] -----\n" <<
            "Input: a = " << a << ", b = " << b << ", c = "  << c
            << "\nExpected Output:\nx = " << expected_output
            << "\nProgram Output:\nx = " << output << std::endl;
        }
        i++;
    }

    testFile.close();
    return 0;
}
