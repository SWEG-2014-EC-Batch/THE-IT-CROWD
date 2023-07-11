#include <iostream>
#include <fstream>

using namespace std;

struct employee {
    char name[30];
    int hour;
    float rate;
    float regularPay;
    float overtimePay;
    float grossPay;
};

void readFile(employee[]);
void calculatePay(employee[]);
void print(employee[]);

int main() {
    employee people[10];
    readFile(people);
    return 0;
}

void readFile(employee person[]) {
    fstream file;
    file.open("files/file1.txt", ios::in | ios::out);

    if (!file.is_open()) {
        cout << "File did not open" << endl;
        return;
    }

    cout << "File is opened!" << endl;

    int i = 0;
    while (!file.eof() && i < 10) {
        file >> person[i].name >> person[i].rate >> person[i].hour;
        i++;
    }

    file.close();
    calculatePay(person);
}

void calculatePay(employee person[]) {
    for (int i = 0; i < 4; i++) {
        (person[i].hour <= 40) ? person[i].regularPay = person[i].rate * person[i].hour : person[i].regularPay = person[i].rate * (-person[i].hour + 80);
        (person[i].hour > 40) ? person[i].overtimePay = 1.5 * person[i].rate * (person[i].hour - 40) : person[i].overtimePay = 0;
        person[i].grossPay = person[i].regularPay + person[i].overtimePay;
    }

    print(person);
}

void print(employee person[]) {
    cout << "Name" << '\t' << "Pay rate" << '\t' << "Hours" << '\t' << "Regular Pay" << '\t' << "Overtime pay" << '\t' << "Gross-pay" << endl;
    for (int i = 0; i < 4; i++) {
        cout << person[i].name << '\t' << person[i].rate << '\t' << person[i].hour << '\t' << person[i].regularPay << '\t' << person[i].overtimePay << '\t' << person[i].grossPay << endl;
    }
}
