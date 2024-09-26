#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::string> task(std::vector<std::string> input){
    std::vector<std::string> output;
    for (int i = input.size() - 1; i >= 0; i--){
        output.push_back(input[i]);
    }
    return output;
}

std::string format(std::vector<std::string> temp){
    std::string result;
    for (size_t i = 0; i < temp.size(); ++i) {
            result += temp[i];
            if(i < temp.size() - 1){
                result += ", ";
            }
        }
    return " [" + result + "]\n";
}

std::vector<std::string> read(const std::string& line) {
    std::vector<std::string> vec;
    size_t start = line.find('['), end = line.find(']');
    std::stringstream ss(line.substr(start + 1, end - start - 1));
    std::string temp;
    while (getline(ss, temp, ',')) {
        vec.push_back(std::to_string(std::stoi(temp)));
    }
    return vec;
}

int main(){
    std::cout << "Array Reversal\n";
    std::ifstream testFile("test.txt");
    std::string line;
    if (!testFile) {
        std::cerr << "Error: Could not open test.txt" << std::endl;
        return 1;
    }

    int i = 1;
    while (getline(testFile, line)) {
        std::vector<std::string> input = read(line);
        getline(testFile, line);
        std::vector<std::string> expected = read(line);
        std::vector<std::string> output = task(input);

        std::string genInput = "Input: " + format(input);
        std::string genOutput = "Program Output: " + format(output);
        std::string genExpect = "Expected Output:" + format(expected);
    
        if (output == expected) {
            std::cout << "----- TEST CASE " << i << " PASSED [OUTPUT MATCH] -----\n" <<
            genInput << genExpect << genOutput;
        } else {
            std::cout << "----- TEST CASE " << i << " FAILED [IRREGULARITY FOUND] -----\n" << 
            genInput << genExpect << genOutput;
        }
        i++;
    }
    return 0;
}
