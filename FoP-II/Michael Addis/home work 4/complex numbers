#include <iostream>
#include <math.h>
using namespace std;

struct complexNum{
    float realPart;
    float imaginaryPart;
};
complexNum sum(complexNum, complexNum);
complexNum substract(complexNum, complexNum);
complexNum multiply(complexNum, complexNum);
complexNum divide(complexNum, complexNum);
int main(){
    complexNum num1,num2,resultant;
    cout << "enter the real value of variable 'A': ";
    cin >> num1.realPart;
    cout << "enter the imaginary value of variable 'A': ";
    cin >> num1.imaginaryPart;
    cout << "enter the real value of variable 'B': ";
    cin >> num2.realPart;
    cout << "enter the imaginary value of variable 'B': ";
    cin >> num2.imaginaryPart;
    resultant = sum(num1, num2);
    cout << "A + B = "<<resultant.realPart<<" + "<<resultant.imaginaryPart<<"i"<<endl;
    resultant = substract(num1, num2);
    cout << "A - B = "<<resultant.realPart<<" + "<<resultant.imaginaryPart<<"i"<<endl;
    resultant = multiply(num1, num2);
    cout << "A * B = "<<resultant.realPart<<" + "<<resultant.imaginaryPart<<"i"<<endl;
    resultant = divide(num1, num2);
    cout << "A / B = "<<resultant.realPart<<" + "<<resultant.imaginaryPart<<"i"<<endl;
}

complexNum sum(complexNum value1, complexNum value2){
    complexNum sum;
    sum.realPart = value1.realPart + value2.realPart;
    sum.imaginaryPart = value1.imaginaryPart + value2.imaginaryPart;
    return sum;
}

complexNum substract(complexNum value1, complexNum value2){
    complexNum substract;
    substract.realPart = value1.realPart - value2.realPart;
    substract.imaginaryPart = value1.imaginaryPart - value2.imaginaryPart;
    return substract;
}

complexNum multiply(complexNum value1, complexNum value2){
    complexNum multiply;
    multiply.realPart = (value1.realPart*value2.realPart) - (value1.imaginaryPart*value2.imaginaryPart);
    multiply.imaginaryPart = (value1.realPart*value2.imaginaryPart) + (value1.imaginaryPart*value2.realPart);
    return multiply;
}

complexNum divide(complexNum value1, complexNum value2){
    complexNum divide;
    divide.realPart = ((value1.realPart*value2.realPart) + (value1.imaginaryPart*value2.imaginaryPart))/(pow(value2.realPart,2)+pow(value2.imaginaryPart,2));
    divide.imaginaryPart = ((value1.imaginaryPart*value2.realPart) - (value1.realPart*value2.imaginaryPart))/(pow(value2.realPart,2)+pow(value2.imaginaryPart,2));
    return divide;
}
