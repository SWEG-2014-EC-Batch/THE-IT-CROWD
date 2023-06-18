#include <iostream>
#include <cmath>
using namespace std;
double hypo(double side1, double side2) {
    double hypo;
    hypo = sqrt(pow(side1, 2) + pow(side2, 2));
    return hypo;
}
int main()
{
        double side1, side2;
    cout << "Enter the first side: ";
    cin >> side1;
    cout << "Enter the second side: ";
    cin >> side2;
    cout << "The hypotenuse is " << hypo(side1, side2) << endl;
    return 0;
}


