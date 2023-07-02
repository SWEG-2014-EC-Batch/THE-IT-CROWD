#include<iostream>
#include<string>
using namespace std;
int c = 3;
struct student{
    char id[20];
    char name[20];    
    int test_mark;
    int final_mark;

};

int calc_times() {
    int times;
    cout << "Good sir, how many times do you want to calculate the grade(max is 3): ";
    cin >> times;
    if (times > c) {
        return 0;
    } else {
        return times;
    }
}

void input_data(student& stud) {
    cout << "Enter your name: ";
    cin.ignore();
    cin.getline(stud.name, 20);
    cout << "Enter your ID: ";
    cin.ignore();
    cin.getline(stud.id,20);
    cout << "Enter your test result: ";
    cin >> stud.test_mark;
    cout << "Enter your Final exam result: ";
    cin >> stud.final_mark;
}

void calc_result(student& stud) {
    int total_mark = stud.test_mark + stud.final_mark;
    cout << "Good, "<< stud.name << " Your total mark is: "<<total_mark<<endl;
}



int main() {
student stud[c];
int num_times = calc_times();
for (int i=0; i< num_times; i++) {
    input_data(stud[i]);
    calc_result(stud[i]);
}
}
