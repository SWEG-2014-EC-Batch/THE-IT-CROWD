#include <iostream>
#include "function.h"
#include "Header.h"
using namespace std;
string name="tom";
string *ptr = &name;
int main()
{
    int firstNum;
    double secondNum;
    cout << "enter the fist number: ";
    cin >> firstNum;
    cout << "enter the second number: ";
    cin >> secondNum;
    double product = getProduct(firstNum, secondNum);
    cout << firstNum << " * " << secondNum << " = " << product << endl;
    Frankenstine (*ptr);
    return 0;
}
