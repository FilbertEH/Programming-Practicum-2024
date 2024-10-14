#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string task(double a, double b, double c){
    double x1, x2;
    double discriminant = pow(b, 2) - (4 * a * c);
    std::string x = "";
    if (discriminant > 0){ 
        x1 = (-b + std::sqrt(discriminant)) / (2 * a);
        x2 = (-b - std::sqrt(discriminant)) / (2 * a);
        x = std::to_string(x1) + ", " + std::to_string(x2);
    }
    else if (discriminant == 0){
        x = std::to_string(-b / (2 * a));
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
        getline(testFile, line);
        std::stringstream ss(line.substr(line.find(":") + 1));
        std::string temp;
        while (std::getline(ss, temp, ',')) {
            std::istringstream inss(temp);
            char variable;
            double value;
            inss >> variable >> temp >> value;
            switch (variable) {
                case 'a': a = value; break;
                case 'b': b = value; break;
                case 'c': c = value; break;
            }
        }
        std::string output = task(a, b, c);

        std::string expected_output;
        getline(testFile, line);


        expected_output = line.substr((line.find("=") + 1));

        getline(testFile, line); 
        expected_output = line.substr(4);
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