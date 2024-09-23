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

void displayResult(string name, long int gross, long int installment, long int insurance){
    long int tax = gross * 0.2;
    long int net = gross - tax - installment - insurance;
    cout << "\n     Payslip for Employee\n"
    << "------------------------------\n" 
    << "Name: " << name << endl
    << "Gross Salary: Rp" << format(gross) << endl
    << "Tax (20%)   : Rp" << format(tax) << endl
    << "Installment : Rp" << format(installment) << endl
    << "Insurenace  : Rp" << format(insurance) << endl
    << "Net Salary  : Rp" << format(net) << endl;
}

int task(string name){
    long int gross = getInput("Input Gross Salary: ");
    long int installment = getInput("Input Installment: ");
    long int insurance = getInput("Input Insurance: ");
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
