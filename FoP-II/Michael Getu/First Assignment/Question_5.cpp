#include<iostream>

#include<cmath>

using namespace std;

double addNum(double num1, double num2);

int main() {

    double Num1, Num2;

    cout << "Hello, Can you please Enter two Numbers: ";

    cin >> Num1 >> Num2;

    double answer = addNum(Num1, Num2);

    cout << "This is the answer: "<< answer<<endl;

}

double addNum(double num1, double num2) {

    double cube = pow(num1, 3);

    double square_rt = sqrt(num2);

    double result = cube + square_rt;

    return result;

}
