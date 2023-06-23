
#include<iostream>
using namespace std;

    void result();
    bool leap_year();

int main() {
        result();
    }

bool leap_year() {
    int year;
    cout << "Enter the year: ";
    cin >> year;
    if (year%4 ==0 && year%100!=0) {
        return true;
    } else if (year%100 == 0 && year%400==0) {
        return true;
    } else {
        return false;
    }
}

void result() {
    if(leap_year()) {
        cout << "Leap Year";
    } else {
        cout << "Not leap Year";
    }
}
