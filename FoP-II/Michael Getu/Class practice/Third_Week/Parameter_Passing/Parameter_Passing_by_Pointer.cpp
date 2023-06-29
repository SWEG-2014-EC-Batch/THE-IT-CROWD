#include<iostream>
#include"quest.h"
using namespace std;


int calcQuotient(double n1, double n2, double *answer) {
    *answer = n1/n2;

}
    
int main() {
    double num1, num2;
    double quotiont;
    cout<< "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    calcQuotient(num1, num2, &quotiont);
    cout << "THis is the anaswer: "<< quotiont<<endl;
    
    return 0;
}
