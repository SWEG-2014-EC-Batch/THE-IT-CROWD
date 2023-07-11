#include <iostream>
#include <cstring>
using namespace std;
struct phone{
    int adderss;
    int exchange;
    int number;
};
struct person{
    char name[90];
    phone phoneNum;
};
int main(){
    person people[10];/*can ask for ten people's phone and name*/
    for(int i=0;i<10;i++){
        cout<<"please enter the person"<<i+1<<"'s name: ";
        cin.ignore();
        cin.getline(people[i].name,90);
        cout<<"please enter "<<people[i].name<<"'s phone number like this: ooo ooo oooo\n";
        cin>>people[i].phoneNum.adderss>>people[i].phoneNum.exchange>>people[i].phoneNum.number;
    }
    for(int i=0;i<10;i++){
        cout<<"------------------------------------------------\n";
        cout<<"\n name: "<<people[i].name<<endl<<"phone: "<<people[i].phoneNum.adderss<<" "<<people[i].phoneNum.exchange<<" "<<people[i].phoneNum.number<<endl;
        cout<<"\n------------------------------------------------\n";
    }

    return 0;
}

