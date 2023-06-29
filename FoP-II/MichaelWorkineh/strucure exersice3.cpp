#include <iostream>
#include <cstring>
using namespace std;
struct phone{
    int adderss;
    int exchange;
    int number;
};
int main(){
    int num;
    cout<<"how many person do you want to work with?";
    cin>>num;
    phone person[num], person2={251,960,9887};
    for(int i=0;i<num;i++){
        cout<<"please enter the person"<<i+1<<"'s phone number: ";
        cin>> person[i].adderss>>person[i].exchange>>person[i].number;
    }
    cout<<"other person: "<<person2.adderss<<person2.exchange<<person2.number;
    for(int i=0;i<num;i++){
        cout<<"person "<<i+1<<": "<<person[i].adderss<<person[i].exchange<<person[i].number<<endl;
    }

    return 0;
}
