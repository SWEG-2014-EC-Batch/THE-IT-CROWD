#include <iostream>
#include <fstream>

using namespace std;
struct employe{
    char name[30];
    int hour;
    float rate;
    float regularPay;
    float overtimePay;
    float grossPay;
};
void readFile(employe[]);
void employeCalc(employe[]);
void print(employe[]);
int main(){
    employe people[10];
    readFile(people);
    return 0;
}

void readFile(employe person[]){
    fstream file;
    file.open ("files/file1.txt", ios::in|ios::out);
    if(!file.is_open()){
            cout<<"\afile did not open"<<endl;
            return;
    }
    cout<<"file is opened!"<<endl;
    int i =0;
    while(file.eof() == false){
        file>>person[i].name>>person[i].rate>> person[i].hour;
        i++;
    }
    file.close();
    employeCalc(person);
}

void employeCalc(employe person[]){
    for(int i=0; i<4; i++){
    (person[i].hour<=40)?person[i].regularPay=person[i].rate*person[i].hour:person[i].regularPay=person[i].rate*(-person[i].hour+80);
    (person[i].hour>40)?person[i].overtimePay=1.5*person[i].rate*(person[i].hour-40):person[i].overtimePay=0;
    person[i].grossPay=person[i].regularPay+person[i].overtimePay;
    }
    print(person);
}

void print(employe person[]){
    cout<<"Name"<<'\t'<<"Pay rate"<<'\t'<<"Hours"<<'\t'<<"Regular Pay"<<'\t'<<"Overtime pay"<<'\t'<<"Gross-pay"<<endl;
    for(int i=0; i<4; i++){
        cout<<person[i].name<<'\t'<<person[i].rate<<'\t'<<person[i].hour<<'\t'<<person[i].regularPay<<'\t'<<person[i].overtimePay<<'\t'<<person[i].grossPay<<endl;
    }
}
