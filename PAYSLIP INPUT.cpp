#include <iostream>
#include <string>
using namespace std;

long int getInput(string prompt){
    long int value;
    cout << prompt;
    cin >> value;
    return value;
}

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

void displayResult(string name, long int gross, long int tax, long int installment, long int insurance, long int net){
    cout << "Payslip for Employee" << endl
    << "---------------------" << endl 
    << "Name: " << name << endl
    << "Gross Salary: Rp" << format(gross) << endl
    << "Tax (20%)   : Rp" << format(tax) << endl
    << "Installment : Rp" << format(installment) << endl
    << "Insurenace  : Rp" << format(insurance) << endl
    << "Net Salary  : Rp" << format(net) << endl;
}

int main(){
    string name; cout << "Input Name: "; getline( cin, name);
    long int gross = getInput("Input Gross Salary: ");
    long int tax = gross * 0.2;
    long int installment = getInput("Input Installment: ");
    long int insurance = getInput("Input Insurance: ");
    long int net = gross - tax - installment - insurance;
    displayResult(name, gross, tax, installment, insurance, net);
    return 0;
}