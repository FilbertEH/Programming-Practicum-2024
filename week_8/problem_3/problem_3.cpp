#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Student {
    std::string line;
    std::string nisn;
    std::string name;
    int value;
};

void bubbleSort(std::vector<Student>& students, bool byNISN) {
    for (int i = 0; i < students.size() - 1; ++i) {
        for (int j = 0; j < students.size() - i - 1; ++j) {
            bool shouldSwap = byNISN ? 
                (students[j].nisn < students[j + 1].nisn) : 
                (students[j].value < students[j + 1].value);
            
            if (shouldSwap) {
                std::swap(students[j], students[j + 1]);
            }
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
    bool readingNISN = true;
    
    while (std::getline(file, line)) {
        if (line == "Sort by Value:") {
            readingNISN = false;
            continue;
        }
        if (!line.empty()) {
            (readingNISN ? expectedNISN : expectedValue).push_back(line);
        }
    }
    file.close();

    auto studentsByValue = students;
    bubbleSort(students, true); 
    bubbleSort(studentsByValue, false);

    std::vector<std::string> actualNISN, actualValue;
    for (const auto& s : students) actualNISN.push_back(s.line);
    for (const auto& s : studentsByValue) actualValue.push_back(s.line);

    std::cout << "Sorted by NISN (descending):\n";
    for (const auto& line : actualNISN) std::cout << line << '\n';

    std::cout << "\nSorted by Value (descending):\n";
    for (const auto& line : actualValue) std::cout << line << '\n';

    bool nisnMatch = actualNISN == expectedNISN;
    bool valueMatch = actualValue == expectedValue;

    std::cout << "\nNISN Sort Test: " << (nisnMatch ? "Passed" : "Failed") << '\n';
    std::cout << "Value Sort Test: " << (valueMatch ? "Passed" : "Failed") << '\n';

    return 0;
}