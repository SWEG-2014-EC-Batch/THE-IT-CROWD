#include <iostream>
#include <cstring>
using namespace std;
struct phone{
    int adderss;
    int exchange;
    int number;
};
void input(phone info[],int arraySize, int i);
void output(phone info[],phone initialized,int arraySize);
int main(){
    int num;
    cout<<"how many person do you want to work with?";
    cin>>num;
    phone person[num], person2={251,960,9887};
    for(int i=0;i<num;i++){
        input(person,num, i);
    }
    output(person, person2, num);
    return 0;
}

void input(phone info[],int arraySize, int i){
    cout<<"please enter the person"<<i+1<<"'s phone number: ";
    cin>> info[i].adderss>>info[i].exchange>>info[i].number;
}

void output(phone info[],phone initialized,int arraySize){
cout<<"other person: "<<initialized.adderss<<initialized.exchange<<initialized.number;
    for(int i=0;i<arraySize;i++){
        cout<<"person "<<i+1<<": "<<info[i].adderss<<"-"<<info[i].exchange<<"-"<<info[i].number<<endl;
    }
}
