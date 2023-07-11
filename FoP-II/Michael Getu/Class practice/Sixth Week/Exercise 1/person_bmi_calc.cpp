#include<iostream>
#include<cmath>
using namespace std;
int count=3;
struct person {
    char name[20], gender;
    float height, weight;
    int age;
};


int main() {
 
    person dude[count];
    int calc_times;
    cout << "Good sir, how many times do you want to \ncalculate your grade (3 must be max): ";
    cin >> calc_times;
    if (calc_times > count) {
        return 0;
    }
    for (int i=0; i< calc_times; i++) {
    
    cout << "Enter your name dude: ";
    cin.ignore();
    cin.getline(dude[i].name, 20);
    cout << "Enter your gender: ";
    cin >> dude[i].gender;
    cout << "Enter your height and weight: ";
    cin >> dude[i].height >> dude[i].weight;
    cout << "Enter your age: ";
    cin >> dude[i].age;
    int bmi = dude[i].weight/pow(dude[i].height, 2);
        if (bmi > 18 && bmi <24) {
            cout << "Your BMI is " << bmi<< " nice, bruv";
        }   else  {
            cout << "Your BMI is " << bmi<< ", bruv, Something is not clicking my guy fix up";
        }
    }
 }
