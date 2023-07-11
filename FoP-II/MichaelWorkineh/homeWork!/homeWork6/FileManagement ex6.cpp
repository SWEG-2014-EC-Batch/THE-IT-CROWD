#include <iostream>
#include<fstream>

using namespace std;

struct studeInfo{
    char name [90];
    float exam1, exam2, homework, finalExam;
    char grade;
};
void writeToFile(studeInfo [], int);
void gradeCal(studeInfo &);
void input(studeInfo [], int);
int main(){
    int arraySize = 2;
    studeInfo students[arraySize];
    input(students,arraySize);
    for(int i=0; i<arraySize; i++){
        gradeCal(students[i]);
    }
    writeToFile(students,arraySize);
    return 0;
}
void input(studeInfo students[], int arraySize){
    for(int i = 0; i < arraySize; i++){
        cout<<"enter name: ";
        cin.ignore();
        cin.getline(students[i].name,90);
        cout<<"enter exam1: ";
        cin>>students[i].exam1;
        cout<<"enter exam2: ";
        cin>>students[i].exam2;
        cout<<"enter homework: ";
        cin>>students[i].homework;
        cout<<"enter finalexam: ";
        cin>>students[i].finalExam;
    }
}
void writeToFile(studeInfo students[], int arraySize){
        fstream file;
    file.open ("files/file6.txt", ios::in|ios::out);
    if(!file.is_open()){
            cout<<"\afile did not open"<<endl;
            return;
    }
    for(int i = 0; i<arraySize; i++){
        file<<students[i].name<<" "<<students[i].exam1<<" "<<students[i].exam2<<" "<<students[i].homework<<" "<<students[i].finalExam<<" "<<students[i].grade<<endl;
    }
    file.close();
}

void gradeCal(studeInfo &students){
    float finalGrade = 0.2*(students.exam1+students.exam2)+0.35*(students.homework)+0.25*(students.finalExam);
    if(finalGrade<=100&&finalGrade>=90)
        students.grade='A';
    else if(finalGrade<=89&&finalGrade>=80)
        students.grade = 'B';
    else if(finalGrade<=79&&finalGrade>=70)
        students.grade = 'C';
    else if(finalGrade<=69&&finalGrade>=60)
        students.grade = 'D';
    else if(finalGrade<60)
        students.grade = 'F';
    else
        students.grade = '?';
}
