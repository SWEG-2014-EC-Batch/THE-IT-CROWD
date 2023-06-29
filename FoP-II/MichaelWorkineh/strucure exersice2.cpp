#include <iostream>
#include <cstring>
struct person{
    char name[21];
    float height,weight;
    int age;
    char gender;
    float bmi;
};
void bmiChecker(int age, char gender,float bmi);
using namespace std;
int main(){
    int num;

    cout<<"how many people are you going to work with: ";
    cin>>num;
    person person1[num];
    for(int i=0;i<num;i++){
    cout<<"enter name :";
    cin.ignore();
    cin.getline(person1[i].name,21);
    cout<<"enter age: ";
    cin.ignore();
    cin>>person1[i].age;
    cout<<"enter gender: ";
    cin.ignore();
    cin>>person1[i].gender;
    cout<<"enter height: ";
    cin>>person1[i].height;
    cout<<"enter weight: ";
    cin>>person1[i].weight;
    person1[i].bmi=person1[i].weight/(person1[i].height*person1[i].height);
    bmiChecker(person1[i].age,person1[i].gender,person1[i].bmi);
    cout<<endl;
    }
    return 0;
}

void bmiChecker(int age, char gender,float bmi){
    if(gender == 'F'||gender == 'f') //adderess both uppercase or lowercase inputs
        {
            if(bmi>=18.0 && bmi<=23.0)//normal range
                {
                    cout<<"Your BMI is "<<bmi<<" which is normal."<<endl;

                }
            else if(bmi<18.0)//under weight
                {
                    cout<<"Your BMI is "<<bmi<<" which is below the recommened weight."<<endl;
                }
            else
                {
                     cout<<"Your BMI is "<<bmi<<" which is above the recommened weight.";
                }

        }

    else if(gender == 'M'||gender == 'm') //adderess both uppercase or lowercase inputs
        {
            if(bmi>=20.0 && bmi<=25.0)//normal range
                {
                    cout<<"Your BMI is "<<bmi<<" which is normal.";
                }
            else if(bmi<20.0)//under weight
                {
                    cout<<"Your BMI is "<<bmi<<" which is below the recommened weight.";
                }
            else
                {
                     cout<<"Your BMI is "<<bmi<<" which is above the recommened weight.";
                }
        }

}
