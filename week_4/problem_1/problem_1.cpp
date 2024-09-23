#include <iostream>
#include <fstream>
#include <string>

std::string task(int n){
    int output = 0;
    for (int i = 1; i <= n; i++) {
        output += i;
    }
    return std::to_string(output);
}

int main(){
    std::cout << "Sum of Natural Numbers Program\n";
    std::ifstream testFile("test.txt");
    int input;
    std::string temp;
    std::string expected_output;

    if (!testFile) {
        std::cerr << "Error: Could not open test.txt" << std::endl;
        return 1;
    }

    int i = 1;
    while (testFile >> temp >> input && testFile >> temp >> expected_output) {
        std::string output = task(input);
        if (output == expected_output) {
            std::cout << "----- TEST CASE " << i << " PASSED [OUTPUT MATCH] -----\n" <<
            "Input: " << input << "\nExpected Output: " << expected_output << "\nProgram Output: " << output << std::endl;
        } else {
            std::cout << "----- TEST CASE " << i << " FAILED [IRREGULARITY FOUND] -----\n" << 
            "Input: " << input << "\nExpected Output: " << expected_output << "\nProgram Output: " << output << std::endl;
        }
        i++;
    }

    testFile.close();
    return 0;
}
