#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Student {
    std::string nisn;
    std::string name;
    int value;
};

void selectionSort(std::vector<Student>& students) {
    for (size_t i = 0; i < students.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < students.size(); ++j) {
            if (students[j].nisn < students[minIndex].nisn) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(students[i], students[minIndex]);
        }
    }
}

int binarySearch(const std::vector<Student>& students, const std::string& targetNISN) {
    int left = 0;
    int right = students.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].nisn == targetNISN) {
            return mid;
        }
        if (students[mid].nisn < targetNISN) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    std::ifstream file("test.txt");
    if (!file.is_open()) {
        std::cout << "Error opening file\n";
        return 1;
    }

    std::vector<Student> students;
    std::string line, targetNISN, expectedName;
    int expectedValue;
    
    while (std::getline(file, line)) {
        if (line == "Input:") break;
        if (line == "Student Data:") continue;
        
        Student student;
        student.nisn = line.substr(0, 10);
        size_t lastSpace = line.rfind(' ');
        student.name = line.substr(11, lastSpace - 11);
        student.value = std::stoi(line.substr(lastSpace + 1));
        students.push_back(student);
    }

    std::getline(file, line);
    targetNISN = line.substr(6);
    
    std::getline(file, line); 
    std::getline(file, line);
    expectedName = line.substr(6);
    std::getline(file, line);
    expectedValue = std::stoi(line.substr(7));
    
    file.close();

    selectionSort(students);
    int index = binarySearch(students, targetNISN);

    std::cout << "Input:\nNISN: " << targetNISN << "\n\n";
    std::cout << "Expected Output:\n";
    std::cout << "Name: " << expectedName << "\n";
    std::cout << "Value: " << expectedValue << "\n\n";
    
    std::cout << "Program Output:\n";
    if (index != -1) {
        std::cout << "Name: " << students[index].name << "\n";
        std::cout << "Value: " << students[index].value << "\n\n";
        
        bool passed = (students[index].name == expectedName && 
                      students[index].value == expectedValue);
        std::cout << "Result: " << (passed ? "Pass" : "Failure") << "\n";
    } else {
        std::cout << "Student not found.\n\nResult: Failure\n";
    }

    return 0;
}