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
    cout << "Solving a Quadratic Equation (ax^2 + bx + c = 0)" << endl << "Input Values for: " << endl;
    double a = getInput("[a]: ");
    double b = getInput("[b]: ");
    double c = getInput("[c]: ");
    double discriminant = pow(b, 2) - ( 4 * a * c);
    cout << "Discriminant (∆) = " << discriminant << endl;
    if (discriminant > 0){
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "There are two distinct real roots, " << x1 << " and " << x2 << endl;
    }
    else if (discriminant == 0){
        double x = -b / (2 * a);
        cout << "There is exactly one real root, " << x << endl;
    }
    else{
        cout << "There are no real roots (the roots are complex)." << endl;
    }
    return 0;
}

