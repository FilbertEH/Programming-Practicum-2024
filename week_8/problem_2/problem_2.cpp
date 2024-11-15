#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Student {
    std::string nisn;
    std::string name;
    int value;
    std::string line;
};

void selectionSort(std::vector<Student>& students, bool byNISN) {
    for (int i = 0; i < students.size() - 1; ++i) {
        int maxIdx = i;
        for (int j = i + 1; j < students.size(); ++j) {
            bool shouldSwap = byNISN ? 
                (students[j].nisn > students[maxIdx].nisn) : 
                (students[j].value > students[maxIdx].value);
            
            if (shouldSwap) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            std::swap(students[i], students[maxIdx]);
        }
    }
}

int main() {
    std::ifstream file("test.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    std::vector<Student> students;
    std::string line;
    
    while (std::getline(file, line) && line != "Sort by NISN:") {
        if (!line.empty() && line != "Student Data:") {
            Student s;
            s.line = line;
            s.nisn = line.substr(0, 10);
            size_t lastSpace = line.rfind(' ');
            size_t firstSpace = line.find(' ');
            s.value = std::stoi(line.substr(lastSpace + 1));
            s.name = line.substr(firstSpace + 1, lastSpace - firstSpace - 1);
            students.push_back(s);
        }
    }

    std::vector<std::string> expectedNISN, expectedValue;
    while (std::getline(file, line) && line != "Sort by Value:") {
        if (!line.empty()) {
            expectedNISN.push_back(line);
        }
    }

    while (std::getline(file, line)) {
        if (!line.empty()) {
            expectedValue.push_back(line);
        }
    }
    file.close();

    auto studentsByValue = students;
    selectionSort(students, true);       
    selectionSort(studentsByValue, false); 

    std::vector<std::string> actualNISN, actualValue;
    for (const auto& s : students) actualNISN.push_back(s.line);
    for (const auto& s : studentsByValue) actualValue.push_back(s.line);

    std::cout << "Sorted by NISN (descending):\n";
    for (const auto& line : actualNISN) {
        std::cout << line << '\n';
    }

    std::cout << "\nSorted by Value (descending):\n";
    for (const auto& line : actualValue) {
        std::cout << line << '\n';
    }

    bool nisnMatch = actualNISN == expectedNISN;
    bool valueMatch = actualValue == expectedValue;

    std::cout << "\nNISN Sort Test: " << (nisnMatch ? "Passed" : "Failed") << '\n';
    std::cout << "Value Sort Test: " << (valueMatch ? "Passed" : "Failed") << '\n';
    
    return 0;
}