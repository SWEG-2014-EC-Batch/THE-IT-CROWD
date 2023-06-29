#include<iostream>

#include<cmath>

using namespace std;

double calcHyp(double f_side, double s_side);

int main() {

    double side1, side2;

    cout << "Enter the first side value: ";

    cin >> side1;

    cout << "Enter the second side value: ";

    cin >> side2;

    double hypotenuse = calcHyp(side1,side2);

    cout << "This is the Hypotenuse: "<<hypotenuse<<endl;

}

double calcHyp(double f_side, double s_side ) {

    double hyp = sqrt(pow(f_side, 2) + pow(s_side, 2));

    return hyp;

}
