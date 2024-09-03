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
        cout << "As the discriminant is greater than zero,\nThere are two distinct real roots, x1 = " 
        << x1 << " and x2 = " << x2 << endl;
    }
    else if (discriminant == 0){
        double x = -b / (2 * a);
        cout << "As the discriminant is equal to zero,\nThere is exactly one real root, x = " << x << endl;
    }
    else{
        cout << "As the discriminant is less than zero,\nThere are no real roots (the roots are complex)." << endl;
    }
    return 0;
}

void testCases(){
    double test[6][3] = {
    {1, -5, 6},
    {1, -7, 10},
    {1, -4, 4},
    {1, -6, 9},
    {1, 2, 7},
    {1, 5, 13},
    };
    for (int i = 0, j = 0; i < 6; i++) {
        cout << "----------- Case " << i+1 << " -----------\n";
        processing(test[i][j], test[i][j+1], test[i][j+2]);
        }
}

int main(){
    cout << "Solving a Quadratic Equation [ax^2 + bx + c = 0]\n" 
    << "---------- TEST CASES: ----------\n";
    testCases();
    return 0;
}
