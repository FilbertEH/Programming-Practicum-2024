#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int task(int a, int b, int c){
    int large = a;
    if (large < b){
        large = b;
    }
    if (large < c){
        large = c;
    }
    return large;
}

int main(){
    std::cout << "Largest Number Among Three Numbers\n";
    std::ifstream testFile("test.txt");
    std::string line;
    if (!testFile) {
        std::cerr << "Error: Could not open test.txt" << std::endl;
        return 1;
    }

    int i = 1;
    while (getline(testFile, line)) {
        std::vector<double> input;
        std::stringstream ss(line.substr(line.find(":") + 1)); 
        std::string temp;
        while (getline(ss, temp, ',')){
            input.push_back(std::stoi(temp));
        }

        int a = input[0];
        int b = input[1];
        int c = input[2];
        int output = task(a, b, c);

        int expected;
        getline(testFile, line);
        ss.clear();
        ss.str(line.substr(line.find(":") + 1));
        ss >> expected;

        if (output == expected) {
            std::cout << "----- TEST CASE " << i << " PASSED [OUTPUT MATCH] -----\n" <<
            "Input: " << a << ", " << b << ", " << c << 
            "\nExpected Output: " << expected << 
            "\nProgram Output:  " << output << std::endl;
        } else {
            std::cout << "----- TEST CASE " << i << " FAILED [IRREGULARITY FOUND] -----\n" <<
            "Input: " << a << ", " << b << ", " << c << 
            "\nExpected Output: " << expected << 
            "\nProgram Output:  " << output << std::endl;
        }
        i++;
    }
    return 0;
}
