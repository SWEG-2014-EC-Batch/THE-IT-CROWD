#include <iostream>
#include <cstring>
using namespace std;
struct student{
    char id[5], name[21];
    float testMark[5],finalMark,totalMark;
};
int main(){
    int num;
    cout<<"how many people are you going to work with: ";
    cin>>num;
    student student1[num];
    for(int i=0;i<num;i++){
    cin.ignore();
        cout<<"please enter the student's name: ";
        cin.getline(student1[i].name,21);
        cout<<"Please enter "<<student1[i].name<<"'s id: ";
        cin>>student1[i].id;
        student1[i].testMark[4]=0;
        for(int j=0;j<4;j++){
            cout<<"Please enter "<<student1[i].name<<"'s test"<<endl;
            cin>>student1[i].testMark[j];
            student1[i].testMark[4]+=student1[i].testMark[j];
        }

        cout<<" and final mark: ";
        cin>>student1[i].finalMark;
        student1[i].totalMark=student1[i].testMark[4]+student1[i].finalMark;
        cout<<"total mark "<<student1[i].totalMark<<endl;
        cout<<"student info:"<<endl;
        cout<<"name: "<<student1[i].name<<endl<<"id: "<<student1[i].id<<"total mark: "<<student1[i].totalMark;
    }
    return 0;
}


