#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> task(int n){
    std::vector<std::string> output;
    for (int i = 1; i <= 10; i++) {
        int val = (n * i);
        output.push_back(std::to_string(n) + " x " + std::to_string(i) + " = " + std::to_string(val));
    }
    return output;
}

int main(){
    std::cout << "Multiplication Table Program\n";
    std::ifstream testFile("test.txt");
    std::string line;

    if (!testFile) {
        std::cerr << "Error: Could not open test.txt" << std::endl;
        return 1;
    }

    int i = 1;
    while (getline(testFile, line)) {
        int input;
        if (line.find("Input:") != std::string::npos){
            input = stoi(line.substr(7));
        }
        std::vector<std::string> output = task(input);

        std::vector<std::string> expected;
        getline(testFile, line); 
        for (int i = 1; i <= 10; i++) {
            getline(testFile, line); 
            expected.push_back(line);
        } 

        std::string genOutput = "Program Output:\n";
        for (size_t i = 0; i < output.size(); ++i) {
            genOutput += output[i] + '\n';
        }

        std::string genExpect = "Expected Output:\n";
        for (size_t i = 0; i < expected.size(); ++i) {
            genExpect += expected[i] + '\n';
        }

        if (output == expected) {
            std::cout << "----- TEST CASE " << i << " PASSED [OUTPUT MATCH] -----\n" <<
            "Input: " << input << "\n----------------\n" << genExpect << "---------------\n" << genOutput;
        } else {
            std::cout << "----- TEST CASE " << i << " FAILED [IRREGULARITY FOUND] -----\n" << 
            "Input: " << input << "\n----------------\n" << genExpect << "---------------\n" << genOutput;
        }
        i++;
    }

    testFile.close();
    return 0;
}
