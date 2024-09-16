#include <cmath>
#include <iostream>
using namespace std;

double getInput(string prompt){
    double value;
    cout << prompt;
    cin >> value;
    return value;
}

int main(){
    char again = 'y';
    cout << "Finding the largest number between three numbers:\n";
    do{
        double a = getInput("Input number 1: ");
        double b = getInput("Input number 2: ");
        double c = getInput("Input number 3: ");
        int large = a;
        if (large < b){
            large = b;
        }
        if (large < c){
            large = c;
        }
        cout << "The largest number is: " << large << endl;
        cout << "\nTry again? [y/n]: ";
        cin >> again;
    }while (again == 'y');
    return 0;
}
