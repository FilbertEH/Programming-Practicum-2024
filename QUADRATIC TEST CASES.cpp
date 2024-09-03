#include <cmath>
#include <iostream>
using namespace std;

double processing(double a, double b, double c){
    cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
    double discriminant = pow(b, 2) - ( 4 * a * c);
    cout << "Discriminant (∆) = " << discriminant << endl;
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
        cout << "There are no real roots (the roots are complex)." << endl;
    }
    return 0;
}

void testCases(){
    cout << "IF DISCRIMINANT (∆) > 0\n"
    << "------- CASE 1 --------\n";
    processing(1, -5, 6);
    cout << "------- CASE 2 --------\n";
    processing (1, -7, 10);

    cout << "---------------------------------\n"
    << "IF DISCRIMINANT (∆) = 0\n"
    << "------- CASE 1 --------\n";
    processing(1, -4, 4);
    cout << "------- CASE 2 --------\n";
    processing (1, -6, 9);

    cout << "---------------------------------\n"
    << "IF DISCRIMINANT (∆) < 0\n"
    << "------- CASE 1 --------\n";
    processing(1, 2, 7);
    cout << "------- CASE 2 --------\n";
    processing (1, 5, 13);
}

int main(){
    cout << "Solving a Quadratic Equation [ax^2 + bx + c = 0]\n" 
    << "---------- TEST CASES: ----------\n";
    testCases();
    return 0;
}