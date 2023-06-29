#include <iostream>
#include <cstring>
struct person{
    char name[21];
    float height,weight;
    int age;
    char gender;
    float bmi;
};
void input(person info[],int arraySize, int i);
void bmiCalculator(person info[],int arraySize, int i);
void output(int age, char gender,float bmi);
using namespace std;
int main(){
    int num;
    cout<<"how many people are you going to work with: ";
    cin>>num;
    person person1[num];
    for(int i=0;i<num;i++){
    input(person1, num, i);
    bmiCalculator(person1, num, i);
    output(person1[i].age,person1[i].gender,person1[i].bmi);
    cout<<endl;
    }
    return 0;
}

void input(person info[],int arraySize, int i){
    cout<<"enter name :";
    cin.ignore();
    cin.getline(info[i].name,21);
    cout<<"enter age: ";
    cin.ignore();
    cin>>info[i].age;
    cout<<"enter gender: ";
    cin.ignore();
    cin>>info[i].gender;
    cout<<"enter height: ";
    cin>>info[i].height;
    cout<<"enter weight: ";
    cin>>info[i].weight;
}

void bmiCalculator(person info[],int arraySize, int i){
    info[i].bmi=info[i].weight/(info[i].height*info[i].height);
}

void output(int age, char gender,float bmi){
    if(gender == 'F'||gender == 'f') {
        if(bmi>=18.0 && bmi<=23.0){
            cout<<"Your BMI is "<<bmi<<" which is normal."<<endl;
        }

        else if(bmi<18.0){
            cout<<"Your BMI is "<<bmi<<" which is below the recommened weight."<<endl;
        }
        else{
            cout<<"Your BMI is "<<bmi<<" which is above the recommened weight.";
        }
    }
    else if(gender == 'M'||gender == 'm'){
        if(bmi>=20.0 && bmi<=25.0){
            cout<<"Your BMI is "<<bmi<<" which is normal.";
        }
        else if(bmi<20.0){
            cout<<"Your BMI is "<<bmi<<" which is below the recommened weight.";
        }
        else{
            cout<<"Your BMI is "<<bmi<<" which is above the recommened weight.";
        }
    }
}

