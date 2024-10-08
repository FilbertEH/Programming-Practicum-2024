#include <cmath>
#include <iostream>
using namespace std;

double getInput(string prompt){
    double value;
    cout << prompt;
    cin >> value;
    return value;
}

int task(){
    double a = getInput("[a]: ");
    double b = getInput("[b]: ");
    double c = getInput("[c]: ");
    double discriminant = pow(b, 2) - ( 4 * a * c);
    if (discriminant > 0){
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "There are two distinct real roots, x1 = " << x1 << " and x2 = " << x2 << endl;
    }
    else if (discriminant == 0){
        double x = -b / (2 * a);
        cout << "There is exactly one real root, x = " << x << endl;
    }
    else{
        cout << "There are no real roots (the roots are complex).\n";
    }
    return 0;
}

int main(){
    char again = 'y';
    cout << "Solving a Quadratic Equation [ax^2 + bx + c = 0]\n" << "Input Values for:\n";
    do{
        task();
        cout << "\nWould you like to start again [y/n]: ";
        cin >> again;
    }while (again == 'y');
    return 0;
}
