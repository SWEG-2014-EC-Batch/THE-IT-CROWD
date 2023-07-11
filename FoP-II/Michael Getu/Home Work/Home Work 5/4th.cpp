#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct employee {
    int id;
    char sex;
    float hourlyWage;
    int yearsWithCompany;
};

void sortEmployees(employee*, int);
void employeeInfoInput(employee*, int);
void writeToFile(employee*, int);
void updateFile(employee*, int);
void employeeCalc(employee*, int);

int main() {
    int arraySize = 3;
    employee employees[arraySize];
    int choice;

    employeeInfoInput(employees, arraySize);

    cout << "Type 1 to update the file or type 2 to calculate monthly pay: ";
    cin >> choice;

    if (choice == 1)
        updateFile(employees, arraySize);
    else
        employeeCalc(employees, arraySize);

    return 0;
}

void employeeInfoInput(employee* employees, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << "Enter employee's ID: ";
        cin >> employees[i].id;
        cout << "Enter employee's sex: ";
        cin >> employees[i].sex;
        cout << "Enter employee's hourly wage: ";
        cin >> employees[i].hourlyWage;
        cout << "Enter employee's years with the company: ";
        cin >> employees[i].yearsWithCompany;
    }

    sortEmployees(employees, arraySize);
    writeToFile(employees, arraySize);
}

void writeToFile(employee* employees, int arraySize) {
    fstream file;
    file.open("files/file4.txt", ios::out);

    if (!file.is_open()) {
        cout << "File did not open" << endl;
        return;
    }

    for (int i = 0; i < arraySize; i++) {
        file << employees[i].id << " " << employees[i].sex << " " << employees[i].hourlyWage << " " << employees[i].yearsWithCompany << endl;
    }

    file.close();
}

void updateFile(employee* employees, int arraySize) {
    int id;
    char choice;
    cout << "Enter the ID you want to update: ";
    cin >> id;

    for (int i = 0; i < arraySize; i++) {
        if (id == employees[i].id) {
            cout << "Type 'h' to change the hourly wage value and 'y' to change the years with the company value: ";
            cin >> choice;

            if (tolower(choice) == 'h') {
                cout << "Enter the new hourly wage: ";
                cin >> employees[i].hourlyWage;
                break;
            } else if (tolower(choice) == 'y') {
                cout << "Enter the new years with the company value: ";
                cin >> employees[i].yearsWithCompany;
                break;
            } else {
                cout << "Wrong input" << endl;
            }
        }
    }

    writeToFile(employees, arraySize);
}

void sortEmployees(employee* employees, int arraySize) {
    sort(employees, employees + arraySize, [](const employee& a, const employee& b) {
        return a.id < b.id;
    });
}

void employeeCalc(employee* employees, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        int hours;
        cout << "How many hours did employee " << employees[i].id << " work?" << endl;
        cin >> hours;
        cout << "Total pay is " << employees[i].hourlyWage * hours << endl;
    }
}
