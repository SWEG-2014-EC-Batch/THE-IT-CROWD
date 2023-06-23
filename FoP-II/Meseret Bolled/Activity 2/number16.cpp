#include <iostream>

using namespace std;

void inputTime(int& hour, int& minute) {
    cout << "Enter the hour (0-23): ";
    cin >> hour;
    cout << "Enter the minute (0-59): ";
    cin >> minute;
}

void convertTime(int& hour, int& minute, char& am_pm) {
    if (hour >= 12) {
        am_pm = 'P';
    } else {
        am_pm = 'A';
    }
    if (hour == 0) {
        hour = 12;
    } else if (hour > 12) {
        hour -= 12;
    }
}

void outputTime(int hour, int minute, char am_pm) {
    cout << "The time is: " << hour << ":" << minute << " ";
    if (am_pm == 'A') {
        cout << "AM";
    } else {
        cout << "PM";
    }
    cout << endl;
}

int main() {
    int hour, minute;
    char am_pm;
    char repeat;

    do {
        inputTime(hour, minute);
        convertTime(hour, minute, am_pm);
        outputTime(hour, minute, am_pm);

        cout << "Do you want to convert another time? (Y/N): ";
        cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}
