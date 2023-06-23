#include<iostream>
using namespace std;

void values(int &num1, int &num2, int &num3) {
    
    int largest;
    int sec_largest;
    int smallest;
    if ( num1 < num2) {
        swap(num1, num2);
    
    }
    if (num1 < num3) {
        swap (num1, num3);
    }
    if ( num2 < num3) {
        swap( num2, num3);
    }
    cout << "Checked- Order: "<< num1 << " "<< num2 << " "<< num3<<endl;


}
void swap(int &a, int &b) {
    int temp = a;
        a = b;
        b = temp;
}

int main() {
    int num1, num2, num3;
    cout << "Program to find Decending Order of Three numbers: "<<endl;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the Second number: ";
    cin >> num2;
    cout << "Enter the third number: ";
    cin >> num3;
    cout << "Pre- Order: "<< num1 << " "<< num2 << " "<< num3<<endl;
    values(num1, num2, num3);
    return 0;
}





