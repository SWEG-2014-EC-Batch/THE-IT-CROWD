#include<iostream>
using namespace std;
int c = 3;

struct phone {

    int area_code;
    int exchange;
    int number;
};


int main() {
    phone phone1[c];
    int calc_times;
    cout << "Good sir, how many times do you want to \nput in your phone number(10 must be max): ";
    cin >> calc_times;
    if (calc_times > c) {
        return 0;
    }
    for (int i=0; i< calc_times; i++) {
    //for phone 1
    cout << "Enter your area code: ";
    cin >> phone1[i].area_code;
    cout << "Enter your exchange code: ";
    cin >> phone1[i].exchange;
    cout << "Enter your number: ";
    cin >> phone1[i].number;

    cout << "The first number is: ("<< phone1[i].area_code<<") "<<phone1[i].exchange<<"-"<<phone1[i].number<<endl;

    
    }
}
