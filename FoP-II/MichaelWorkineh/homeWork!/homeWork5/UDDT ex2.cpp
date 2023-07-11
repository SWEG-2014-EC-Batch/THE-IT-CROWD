#include <iostream>
#include <math.h>

using namespace std;
struct complexNum{
    double real;
    double imaginary;
};
complexNum add(complexNum x, complexNum y), multiply(complexNum x, complexNum y), substarct(complexNum x, complexNum y), divide(complexNum x, complexNum y);
int main(){
    complexNum num1, num2, num3;
    char operation;
    cout<<"please enter the fist complex number like this: \"real imaginary\""<<endl<<"num1: ";
    cin>>num1.real>>num1.imaginary;
    cout<<"now please enter the second complex number like this: \"real imaginary\""<<endl<<"num2: ";
    cin>>num2.real>>num2.imaginary;
    cout<<"enter +,-,* or /"<<endl;
    cin>>operation;
    switch(operation){
        case '+':
            num3 = add(num1,num2);
            break;
        case '-':
            num3 = substarct(num1,num2);
            break;
        case '*':
            num3 = multiply(num1,num2);
            break;
        case '/':
            num3 = divide(num1,num2);
            break;
        default:
            cout<<"wrong input"<<endl;
            return 0;
    }
    cout<<"result = ("<<num3.real<<") + ("<<num3.imaginary<<")i"<<endl;
    return 0;
}

complexNum add(complexNum x, complexNum y){
    complexNum z;
    z.real = x.real + y.real;
    z.imaginary = x.imaginary + y.imaginary;
    return z;
}

complexNum substarct(complexNum x, complexNum y){
    complexNum z;
    z.real = x.real - y.real;
    z.imaginary = x.imaginary - y.imaginary;
    return z;
}

complexNum multiply(complexNum x, complexNum y){
    complexNum z;
    z.real = (x.real * y.real) - (x.imaginary * y.imaginary);
    z.imaginary = (x.real * y.imaginary) + (x.imaginary * y.real);
    return z;
}

complexNum divide(complexNum x, complexNum y){
    complexNum z;
    z.real = ((x.real * y.real) + (x.imaginary * y.imaginary))/(pow(y.real,2) + pow(y.imaginary,2));
    z.imaginary = (-1/(pow(y.real,2) + pow(y.imaginary,2)))*((x.real * y.imaginary) + (x.imaginary * y.real));
    return z;
}


