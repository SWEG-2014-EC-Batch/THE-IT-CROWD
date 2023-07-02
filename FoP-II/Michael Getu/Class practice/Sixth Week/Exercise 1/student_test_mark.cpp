#include<iostream>
using namespace std;

int count = 3;
struct students {
    char id[20];
    char name[20];
    int test_mark;
    int final_mark;
    int total_mark;
    
};


int main() {

    students student[count];
    int calc_times;
    cout << "Good sir, how many times do you want to calculate your mark(3 must be max): ";
    cin >> calc_times;
    if (calc_times > count) {
        return 0;
    }
    for (int i=0; i< calc_times; i++) {
    
    cout << "Enter your name: ";
    cin.getline(student[i].name, 20);
    cout << "Enter your ID: ";
    cin.getline(student[i].id, 20);
    cout << "Enter your test result: ";
    cin >> student[i].test_mark;
    cout << "Enter your final result: ";
    cin >> student[i].final_mark;

    student[i].total_mark = student[i].test_mark + student[i].final_mark;
    cout << "Student Info"<<endl;
    cout << student[i].name<< " "<< student[i].id<<" "<<student[i].total_mark<<endl;

    cout << "Good "<< student[i].name << ", Your total mark is \n"<< student[i].total_mark<<endl;
    }

    return 0;
}
