#include<iostream>
using namespace std;

int fibo(int count = 10) {
    int num1 = 0; int num2 = 1, th_term=0;
    cout << num1<< " "<< num2<<" ";
    for (int i =3; i<=count;i++) {
        th_term = num1 + num2;
        cout << th_term<<" ";
        num1 = num2;
        num2 = th_term;
    }

    cout << endl;
    return 0;
}

int main() {
    int count;
    cout << "Enter the amount of numbers you want to calculate for(default 10): ";
    cin >> count;
    fibo(count);
    cout << "Default Fabi Sequence: "<<endl;
    fibo();

    return 0;
}


