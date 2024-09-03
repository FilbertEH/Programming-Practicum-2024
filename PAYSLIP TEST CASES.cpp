#include <iostream>
#include <string>
using namespace std;

string format(long int value) {
    string original = to_string(value);
    string format;
    for (int i = 0; i < original.length(); i++) {
        format += original[i];
        if (i != original.length() - 1 && (original.length() - i - 1) % 3 == 0) {
            format += '.';
        }
    }
    return format + ",00"; 
}

void displayResult(string name, long int gross, long int installment, long int insurance){
    long int tax = gross * 0.2;
    long int net = gross - tax - installment - insurance;
    cout << "     Payslip for Employee\n"
    << "------------------------------\n" 
    << "Name: " << name << endl
    << "Gross Salary: Rp" << format(gross) << endl
    << "Tax (20%)   : Rp" << format(tax) << endl
    << "Installment : Rp" << format(installment) << endl
    << "Insurenace  : Rp" << format(insurance) << endl
    << "Net Salary  : Rp" << format(net) << endl;
}

void testCases(){
    string Name[4] = {
    "Carlot Ahint Danish",
    "Muhammad Sigma Reat",
    "Tomat Nanda Arwijaya",
    "Rian Daf Halim"};
    long int Data[4][3] = {
    {30000000, 2000000, 500000},
    {15000000, 1000000, 100000},
    {24000000, 750000, 1000000}, 
    {7000000, 350000, 200000}};
    
    for (int i = 0, j = 0; i < 4; i++) {
        cout << "----------- Case " << i+1 << " -----------\n";
        displayResult(Name[i], Data[i][j], Data[i][j+1], Data[i][j+2]);
        }
}

int main(){  
    cout << "------------------------------\n"
    << "       EMPLOYEE PAYSLIPS\n";
    testCases();
    return 0;
}
