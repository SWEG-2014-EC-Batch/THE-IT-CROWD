#include<iostream>
#include<cmath>
using namespace std;
int c=3;
struct person {
    char name[20], gender;
    float height, weight;
    int age;
};

int calc_times() {
    int times;
    cout << "Good sir, how many times do you want to calculate the Bmi(max is 3): ";
    cin >> times;
    if (times > c) {
        return 0;
    } else {
        return times;
    }
}

void input_data(person& dude) {
    cout << "Enter your name dude: ";
    cin.ignore();
    cin.getline(dude.name, 20);
    cout << "Enter your gender: ";
    cin >> dude.gender;
    cout << "Enter your height and weight: ";
    cin >> dude.height >> dude.weight;
    cout << "Enter your age: ";
    cin >> dude.age;
}

int bmi_calc(person& dude) {
    int bmi = dude.weight/pow(dude.height, 2);
    return bmi;
}

void output_data(person& dude) {
    int bmi = bmi_calc(dude);
    if (bmi > 18 && bmi <24) {
            cout << "Your BMI is " << bmi<< " nice, bruv"<<endl;
        }   else  {
            cout << "Your BMI is " << bmi<< ", bruv, Something is not clicking my guy fix up"<<endl;
        }
}

int main() {
    person dude[c];
    int num_times = calc_times();
    for (int i=0; num_times; i++) {
        input_data(dude[i]);
        bmi_calc(dude[i]);
        output_data(dude[i]);
    }
}
