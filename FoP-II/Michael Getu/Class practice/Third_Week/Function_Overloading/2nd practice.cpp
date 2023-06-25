#include<iostream>
using namespace std;

double max(double num1, double num2, double num3) {
    double biggest = num1;
    if (biggest<num2) {
        biggest = num2;
    }
    if (biggest < num3) {
        biggest = num3;
    }
    return biggest;
}

double max(double num1, double num2) {
    double biggest = num1;
    if (biggest<num2) {
        biggest = num2;
    }
    return biggest;
}

int main() {
    double num1, num2, num3;
    char ans;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Do you want to enter a third number(y or n): ";
    cin >> ans;
    if ("y" || "Y") {
        cout << "Enter a third number: ";
        cin >> num3;
        cout << "The biggest Number from the three is: "<<max(num1, num2, num3)<<endl;
    } else {
        cout <<"The biggest number from the two is: "<< max(num1, num2)<<endl;
    }

    
}


