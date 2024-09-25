#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> task(){
    std::vector<std::string> output;
    for(int i = 1; i <= 100; i++){
        if (i % 3 == 0 && i % 5 == 0){
            output.push_back("FizzBuzz");
        }
        else if (i % 3 == 0){
            output.push_back("Fizz");
        }
        else if (i % 5 == 0){
            output.push_back("Buzz");
        }
        else{
            output.push_back(std::to_string(i));
        }
    }
    return output;
}

int main(){
    std::cout << "FizzBuzz With Vectors\n";
    std::ifstream testFile("test.txt");
    std::string line;

    if (!testFile) {
        std::cerr << "Error: Could not open test.txt" << std::endl;
        return 1;
    }

    int i = 1;
    while (getline(testFile, line)) {
        int input;
        std::vector<std::string> output = task();

        std::vector<std::string> expected_output;
        for (int i = 1; i <= 100; i++) {
            expected_output.push_back(line);
            getline(testFile, line); 
        } 

        std::string genOutput = "Program Output:\n";
        for (int i = 0; i < output.size(); ++i) {
            genOutput += output[i] + '\n';
        }

        std::string genExpect = "Expected Output:\n";
        for (int i = 0; i < expected_output.size(); ++i) {
            genExpect += expected_output[i] + '\n';
        }

        if (output == expected_output) {
            std::cout << "----- TEST PASSED [OUTPUT MATCH] -----\n" <<
            "\n----------------\n" << genExpect << "---------------\n" << genOutput;
        } else {
            std::cout << "----- TEST FAILED [IRREGULARITY FOUND] -----\n" << 
            "\n----------------\n" << genExpect << "---------------\n" << genOutput;
        }
        i++;
    }
    return 0;
}
