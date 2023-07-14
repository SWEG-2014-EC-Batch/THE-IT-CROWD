#include<iostream>
using namespace std;
int c = 3;

struct phone {

    int area_code;
    int exchange;
    int number;
};


int calc_times() {
    int times;
    cout << "Good sir, how many times do you want to put in your phone number(max is 3): ";
    cin >> times;
    if (times > c) {
        return 0;
    } else {
        return times;
    }
}

void input_data(phone& phone1) {
    cout << "Enter your area code: ";
    cin >> phone1.area_code;
    cout << "Enter your exchange code: ";
    cin >> phone1.exchange;
    cout << "Enter your number: ";
    cin >> phone1.number;

}

void output_data(phone& phone1) {
    cout << "The first number is: ("<< phone1.area_code<<") "<<phone1.exchange<<"-"<<phone1.number<<endl;
}

int main() {
    phone phone1[c];
    int num_times = calc_times();
    for(int i=0; i<num_times; i++) {
        input_data(phone1[i]);
        output_data(phone1[i]);
    }
}
