#include <iostream>
#include <cstring>
using namespace std;
struct student{
    char name[21];
    int id;
    float testMark[5],finalMark,totalMark;
};
void input(student person[], int arraySize, int i);
void calculations(student person[], int arraySize, int i);
void output(student person[], int arraySize, int i);
int main(){
    int num;
    cout<<"how many people are you going to work with: ";
    cin>>num;
    student student1[num];
    for(int i=0;i<num;i++){
        input(student1, num, i);
        calculations(student1, num, i);
        output(student1, num, i);
    }
    return 0;
}
void input(student person[], int arraySize, int i){
    cin.ignore();
    cout<<"please enter the student's name: ";
    cin.getline(person[i].name,21);
    cout<<"Please enter "<<person[i].name<<"'s id: ";
    cin>>person[i].id;
    person[i].testMark[4]=0;
    for(int j=0;j<4;j++){
        cout<<"Please enter "<<person[i].name<<"'s test "<<j+1 <<" grade: ";
        cin>>person[i].testMark[j];
        person[i].testMark[4]+=person[i].testMark[j];
    }
    cout<<"And final mark: ";
    cin>>person[i].finalMark;
}

void calculations(student person[], int arraySize, int i){
    person[i].totalMark=person[i].testMark[4]+person[i].finalMark;
}

void output(student person[], int arraySize, int i){
    cout<<"student info:"<<endl;
    cout<<"name: "<<person[i].name<<endl<<"id: "<<person[i].id<<endl<<"total mark: "<<person[i].totalMark<<endl;
}
