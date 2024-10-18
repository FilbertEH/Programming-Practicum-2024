#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

struct studentData {
    std::string nim;
    int uts, uas, avg;
    bool testPassed;
};

int main() {
    std::cout << "Student Exam Data Averager\n";
    const int maxStudents = 50; 
    std::string filename = "test.txt";
    std::ifstream testFile(filename);

    if (!testFile) {
        std::cerr << "Error: Could not open " << filename << "\n";
        return 1;
    }

    std::string label, line;
    char comma;

    std::getline(testFile, line);
    std::istringstream iss(line);
    int totalStudents;
    iss >> label >> totalStudents;

    if (totalStudents > maxStudents) {
        std::cerr << "Error: The number of students exceeds the maximum limit (" << maxStudents << ").\n";
        return 1;
    }

    std::vector<studentData> students;
    students.reserve(maxStudents);

    std::getline(testFile, line);
    
    while (std::getline(testFile, line) && line != "Output:") {
        std::istringstream iss(line);
        studentData student;
        iss >> label >> student.nim >> comma
            >> label >> student.uts >> comma
            >> label >> student.uas;

        student.avg = (student.uts + student.uas) / 2;
        students.push_back(student);
    }

    std::cout << "\nNumber of Students: " << students.size() << "\n\n";
    bool allTestsPassed = true;

    for (size_t i = 0; i < students.size(); ++i) {
        std::getline(testFile, line);
        std::istringstream iss(line);

        std::string expectedNIM;
        int expectedAvg;
        iss >> label >> expectedNIM >> comma >> label >> expectedAvg;

        students[i].testPassed = (expectedAvg == students[i].avg);
        allTestsPassed &= students[i].testPassed;

        std::cout << "----- Student " << i + 1 << " -----\n"
                  << "Input:\n"
                  << "  NIM = " << students[i].nim << "\n"
                  << "  UTS Score = " << students[i].uts << "\n"
                  << "  UAS Score = " << students[i].uas << "\n"
                  << "Program Output:\n"
                  << "  NIM = " << students[i].nim << "\n"
                  << "  Average Score = " << students[i].avg << "\n"
                  << "Expected Output:\n"
                  << "  NIM = " << expectedNIM << "\n"
                  << "  Average Score = " << expectedAvg << "\n"
                  << "[Test Case " << i + 1 << ": " << (students[i].testPassed ? "Passed]" : "Failed]") << "\n\n";
    }
    return 0;
}
