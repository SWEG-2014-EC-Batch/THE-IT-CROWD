#include <iostream>
#include <fstream>

using namespace std;

struct account {
    char name[30];
    int accNum;
    double balance;
};

void readFile(account[]);
void searchAccount(account[]);

int main() {
    account people[5];
    readFile(people);
    return 0;
}

void readFile(account person[]) {
    fstream file;
    file.open("files/bankFiles.txt", ios::in | ios::out);

    if (!file.is_open()) {
        cout << "File did not open" << endl;
        return;
    }

    cout << "File is opened!" << endl;

    int i = 0;
    while (!file.eof() && i < 5) {
        file >> person[i].name >> person[i].accNum >> person[i].balance;
        i++;
    }

    file.close();
    searchAccount(person);
}

void searchAccount(account person[]) {
    int accountNumber;
    cout << "Enter the account number you want to search: ";
    cin >> accountNumber;

    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (person[i].accNum == accountNumber) {
            cout << "Account Number: " << person[i].accNum << '\t' << "Name: " << person[i].name << '\t' << "Balance: " << person[i].balance << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << accountNumber << " is not stored" << endl;
    }
}
