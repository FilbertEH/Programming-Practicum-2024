#include <iostream>
#include <string>
using namespace std;

long getInput(string prompt){
    long value;
    cout << prompt;
    cin >> value;
    return value;
}

string format(long value) {
    string original = to_string(value); 
    string format;
    for (int i = 0; i < original.size(); i++) { 
        format += original[i];
        if (i != original.length() - 1 && (original.size() - i - 1) % 3 == 0) {
            format += '.';
        }
    }
    return "Rp" + format + ",00";
}

void displayResult(string name, long gross, long installment, long insurance){
    long tax = gross * 0.2;
    long net = gross - tax - installment - insurance;
    cout << "\n     Payslip for Employee\n"
    << "------------------------------\n" 
    << "Name: " << name << endl
    << "Gross Salary: " << format(gross) << endl
    << "Tax (20%)   : " << format(tax) << endl
    << "Installment : " << format(installment) << endl
    << "Insurenace  : " << format(insurance) << endl
    << "Net Salary  : " << format(net) << endl;
}

int task(string name){
    long gross = getInput("Input Gross Salary: ");
    long installment = getInput("Input Installment: ");
    long insurance = getInput("Input Insurance: ");
    displayResult(name, gross, installment, insurance);
    return 0;
}

int main(){
    char again = 'y';
    do {
        string name;
        cout << "------------------------------\nInput Name: ";
        while (name == "") {
            getline(cin, name);
        }
        task(name);
        cout << "\nWould you like to start again [y/n]: ";
        cin >> again;
    } while (again == 'y');
    return 0;
}
