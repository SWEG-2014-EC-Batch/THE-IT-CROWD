#include<iostream>

#include<cmath>

using namespace std;

bool primeCheck(int num);

bool primeCheck(int num) {

    if (num < 1 || num > 1000) {

        return false;

    }

    if (num == 1) 

    {

        return false;

    }

        for (int i=2; i*i<=num; i++) {

            if (num%i==0) {

                return false;

            } 

        }

    return true;

    

} 

int main() {

    int newNum;

    cout << "Enter the number to be checked: ";

    cin >> newNum;

    

    if (primeCheck(newNum)) {

        cout << "It is a Prime Number";

    } else {

        cout << "Not a prime number";

    }

}


