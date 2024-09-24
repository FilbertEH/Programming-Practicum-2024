#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::string format(long int value) {
    std::string original = std::to_string(value);
    std::string format;
    for (int i = 0; i < original.length(); i++) {
        format += original[i];
        if (i != original.length() - 1 && (original.length() - i - 1) % 3 == 0) {
            format += '.';
        }
    }
    return format + ",00"; 
}

std::vector<std::string> payslip(std::string name, long int gross, long int installment, long int insurance){
    std::vector<std::string> payslip;
    long int tax = gross * 0.2;
    long int net = gross - tax - installment - insurance;
    payslip.push_back("Payslip for Employee");
    payslip.push_back("--------------------");
    payslip.push_back("Name:" + name);
    payslip.push_back("Gross Salary: Rp" + format(gross));
    payslip.push_back("Tax (20%)   : Rp" + format(tax));
    payslip.push_back("Installment : Rp" + format(installment));
    payslip.push_back("Insurance   : Rp" + format(insurance));
    payslip.push_back("Net Salary  : Rp" + format(net));
    return payslip;
}

int main(){  
    std::cout << "EMPLOYEE PAYSLIPS\n";
    std::ifstream testFile("test.txt");
    std::string line;

    if (!testFile) {
        std::cerr << "Error: Could not open test.txt" << std::endl;
        return 1;
    }

    int i = 1;
    while (getline(testFile, line)) {
        std::string name;
        long int gross, installment, insurance;
        std::vector<std::string> expected_output, output;
        getline(testFile, line); 
        name = line.substr(line.find(":") + 1);
        getline(testFile, line); 
        gross = std::stol(line.substr(line.find(":") + 1));
        getline(testFile, line); 
        installment = std::stol(line.substr(line.find(":") + 1));
        getline(testFile, line); 
        insurance = std::stol(line.substr(line.find(":") + 1));
        getline(testFile, line); 
        output = payslip(name, gross, installment, insurance);
        
        for (int i = 1; i <= 8; i++){
            getline(testFile, line); 
            expected_output.push_back(line);
        }

        std::string genOutput = "Program Output:\n\n";
        for (int i = 0; i < output.size(); ++i) {
            genOutput += output[i] + '\n';
        }

        std::string genExpect = "Expected Output:\n\n";
        for (int i = 0; i < expected_output.size(); ++i) {
            genExpect += expected_output[i] + '\n';
        }

        if (output == expected_output) {
            std::cout << "\n----- TEST CASE " << i << " PASSED [OUTPUT MATCH] -----\n" <<
            "Input:\n\nName:" << name << "\nGross: " << gross << "\nInstallment: " << installment << "\nInsurance: " << insurance <<
            "\n____________________\n" << genExpect << "\n____________________\n" << genOutput;
        } else {
            std::cout << "\n----- TEST CASE " << i << " FAILED [IRREGULARITY FOUND] -----\n" << 
            "Input:\n\nName:" << name << "\nGross: " << gross << "\nInstallment: " << installment << "\nInsurance: " << insurance <<
            "\n____________________\n" << genExpect << "\n____________________\n" << genOutput;
        }
        i++;
    }

    testFile.close();
    return 0;
}
