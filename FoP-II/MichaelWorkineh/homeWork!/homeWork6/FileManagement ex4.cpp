#include <iostream>
#include<fstream>
#include <algorithm>
using namespace std;
struct employe{
    int id;
    char sex;
    float hourlyWage;
    int yearsWithCompany;
};
void sortEmployees(employe*, int);
void employeInfoInput(employe*, int);
void writeToFile(employe*, int);
void updateFile(employe*, int);
void employeCalc(employe*, int);
int main(){
    int arraySize=3;
    employe employees[arraySize];
    int choice;
    employeInfoInput(employees,arraySize);
    cout<<"type 1 to update the file type 2 to calculate monthly pay \n";
    cin>>choice;
    if( choice == 1)
        updateFile(employees,arraySize);
    else
        employeCalc(employees,arraySize);
    return 0;
}

void employeInfoInput(employe* employees, int arraySize){
    for(int i = 0; i<arraySize;i++){
        cout<<"enter employee's ID: ";
        cin>>employees[i].id;
        cout<<"enter employee's sex: ";
        cin>>employees[i].sex;
        cout<<"enter employee's hourly-wage: ";
        cin>>employees[i].hourlyWage;
        cout<<"enter employee's years withe the company: ";
        cin>>employees[i].yearsWithCompany;
    }
    sortEmployees(employees,arraySize);
    writeToFile(employees,arraySize);
}

void writeToFile(employe* employees, int arraySize){
        fstream file;
    file.open ("files/file4.txt", ios::in|ios::out);
    if(!file.is_open()){
            cout<<"\afile did not open"<<endl;
            return;
    }
    for(int i = 0; i<arraySize; i++){
        file<<employees[i].id<<" "<<employees[i].sex<<" "<<employees[i].hourlyWage<<" "<<employees[i].yearsWithCompany<<endl;
    }
    file.close();
}

void updateFile(employe* employees, int arraySize){
    int id;
    char choice;
    cout<<"enter the id you want to update: ";
    cin>>id;
    for(int i=0; i<arraySize; i++){
        if(id==employees[i].id){
            cout<<"type \"y\" to change the year with the company value and type \"h\" to change the hourly wage value \n";
            cin>>choice;
                if (toupper(choice)=='H'){
                    cout<<"enter the new hourly wage: ";
                    cin>>employees[i].hourlyWage;
                    break;
                }
                else if(toupper(choice)=='Y'){
                    cout<<"enter the new year with company value: ";
                    cin>>employees[i].yearsWithCompany;
                    break;
                }
                else{
                    cout<<"wrong input"<<endl;
                }
            }
        }
        writeToFile(employees, arraySize);
}

void sortEmployees(employe* employees, int arraySize){
    sort(employees, employees + arraySize, [](const employe& a, const employe& b){
         return a.id < b.id;
         });
}

void employeCalc(employe* employees, int arraySize){
    for(int i = 0; i<arraySize; i++){
        int hours;
        cout<<"how much hours did employee "<<employees[i].id<<" work?"<<endl;
        cin>>hours;
        cout<<"total pay is "<<employees[i].hourlyWage*hours<<endl;
    }
}
