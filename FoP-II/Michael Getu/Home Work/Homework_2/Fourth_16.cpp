#include <iostream>
using namespace std;

void convertTo12Hour(int& hour, int& minute, char& am_pm) {
    if (hour == 0) {
        hour = 12;
        am_pm = 'A';
    } else if (hour < 12) {
        am_pm = 'A';
    } else {
        hour -= 12;
        am_pm = 'P';
    }
}

void displayTime(int hour, int minute, char ampm) {
    cout << "Converted Time: " << hour << ":" << minute << " " << ampm << "M" << endl;
}

int main() {
    int hour, minute;
    char ampm;

    char choice;
    do {
        cout << "Enter time in 24-hour notation (HH:MM): ";
        std::cin >> hour >> minute;

        convertTo12Hour(hour, minute, ampm);
        displayTime(hour, minute, ampm);

        cout << "Do you want to convert another time? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
