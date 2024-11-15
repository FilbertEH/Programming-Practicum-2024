#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Student {
    std::string id;
    std::string name;
    int score;
};

int main() {
    std::vector<Student> students;
    std::string line;
    
    std::ifstream file("test.txt");
    if (!file) {
        std::cout << "Cannot open file\n";
        return 1;
    }
    
    while (std::getline(file, line) && line != "Input:") {}
    
    while (std::getline(file, line) && line != "Output:") {
        if (!line.empty()) {
            Student s;
            s.id = line.substr(0, 10);
            size_t lastSpace = line.rfind(' ');
            s.score = std::stoi(line.substr(lastSpace + 1));
            s.name = line.substr(11, lastSpace - 11);
            students.push_back(s);
        }
    }
    
    std::vector<std::string> expected;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            expected.push_back(line);
        }
    }
    file.close();
    
    for (auto& student : students) {
        if (student.score == 60) {
            student.name = "Joko";
        }
    }
    
    std::cout << "\nProgram Output:\n";
    bool passed = true;
    for (size_t i = 0; i < students.size(); i++) {
        std::string output = students[i].id + " " + 
                           students[i].name + " " + 
                           std::to_string(students[i].score);
        std::cout << output << "\n";
        
        if (i < expected.size() && output != expected[i]) {
            passed = false;
        }
    }
    
    std::cout << "\nExpected Output:\n";
    for (const auto& line : expected) {
        std::cout << line << "\n";
    }
    
    std::cout << "\nTest Result: " << (passed ? "PASSED" : "FAILED") << "\n";
    
    return 0;
}