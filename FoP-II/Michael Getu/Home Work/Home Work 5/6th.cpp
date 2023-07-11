#include <iostream>
#include <fstream>

using namespace std;

struct studeInfo {
    char name[90];
    float exam1, exam2, homework, finalExam;
    char grade;
};

void writeToFile(studeInfo[], int);
void gradeCal(studeInfo&);
void input(studeInfo[], int);

int main() {
    int arraySize = 2;
    studeInfo students[arraySize];
    input(students, arraySize);
    for (int i = 0; i < arraySize; i++) {
        gradeCal(students[i]);
    }
    writeToFile(students, arraySize);
    return 0;
}

void input(studeInfo students[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << "Enter name: ";
        cin.ignore();
        cin.getline(students[i].name, 90);
        cout << "Enter exam1: ";
        cin >> students[i].exam1;
        cout << "Enter exam2: ";
        cin >> students[i].exam2;
        cout << "Enter homework: ";
        cin >> students[i].homework;
        cout << "Enter final exam: ";
        cin >> students[i].finalExam;
    }
}

void writeToFile(studeInfo students[], int arraySize) {
    fstream file;
    file.open("files/file6.txt", ios::out);
    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return;
    }
    for (int i = 0; i < arraySize; i++) {
        file << students[i].name << " " << students[i].exam1 << " " << students[i].exam2 << " "
             << students[i].homework << " " << students[i].finalExam << " " << students[i].grade << endl;
    }
    file.close();
}

void gradeCal(studeInfo& students) {
    float finalGrade = 0.2 * (students.exam1 + students.exam2) + 0.35 * (students.homework) + 0.25 * (students.finalExam);
    if (finalGrade >= 90)
        students.grade = 'A';
    else if (finalGrade >= 80)
        students.grade = 'B';
    else if (finalGrade >= 70)
        students.grade = 'C';
    else if (finalGrade >= 60)
        students.grade = 'D';
    else
        students.grade = 'F';
}
