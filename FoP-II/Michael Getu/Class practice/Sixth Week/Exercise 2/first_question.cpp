#include<iostream>
#include<string>
using namespace std;
int c = 3;

struct phone {

    int area_code;
    int exchange;
    int number;
};

struct person_info {
    string name;
    phone phone_info;
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

void input_data(person_info& person) {
    cout << "Enter your name: ";
    cin >> person.name;
    cout << "Enter your area code: ";
    cin >> person.phone_info.area_code;
    cout << "Enter your exchange code: ";
    cin >> person.phone_info.exchange;
    cout << "Enter your number: ";
    cin >> person.phone_info.number;

}

void output_data(person_info& person) {
    cout << "Good, "<<person.name;
    cout << "Your phone number is: ("<< person.phone_info.area_code<<") "<<person.phone_info.exchange<<"-"<<person.phone_info.number<<endl;
}

int main() {
    person_info person[c];
    int num_times = calc_times();
    for(int i=0; i<num_times; i++) {
        input_data(person[i]);
        output_data(person[i]);
    }
}
