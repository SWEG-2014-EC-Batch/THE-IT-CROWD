#include<iostream>
#include"functions.h"
#include"monday.h"

using namespace std;

int main() {
    int firstNum;
    double secondNum;
    cout << "Enter the first number: ";
    cin >> firstNum;
    cout << "Enter the second number: ";
    cin >> secondNum;
    double product = getProduct(firstNum, secondNum);
    cout << "This is the Product: "<<product;
    message();
}
