#include<iostream>
using namespace std;
void input(float &length,char &inputUnit,char &outputUnit);
void processing(float &length,char &inputUnit,char &outputUnit);
void output(float &length,char &confirm,char &outputUnit);
int main(){
    float length;
    char confirm='n',inputUnit,outputUnit;
    while(toupper(confirm)=='N'){
        input(length,inputUnit,outputUnit);
        processing(length,inputUnit,outputUnit);
        output(length,confirm,outputUnit);
    }
    return 0;
}

void input(float &length,char &inputUnit,char &outputUnit){
    int choice;
    cout<<"enter 1 to convert feets and inches to meters nd centimeters. Enter 2 to convert meters and centimeters to meters to inches and meters\n";
    cin>>choice;
    if(choice==1){
        cout<<"type 'f' to convert feet and type 'i' to convert \n";
        cin>>inputUnit;
        cout<<"type 'm' if you want the out put to be in meters and type 'c' if you want the out put to be in centimeters\n";
        cin>>outputUnit;
        cout<<"enter the length you want to convert ";
        cin>>length;
    }
    else if(choice==2){
        cout<<"type 'f' to convert feet and type 'i' to convert \n";
        cin>>inputUnit;
        cout<<"type 'm' if you want the out put to be in meters and type 'c' if you want the out put to be in centimeters\n";
        cin>>outputUnit;
        cout<<"enter the length you want to convert ";
        cin>>length;
    }
    else{
        cout<<"invalid output \n";
    }
}

void processing(float &length,char &inputUnit,char &outputUnit){
    if(toupper(inputUnit)=='F'){
        if(toupper(outputUnit)=='M'){
            length*=0.3048;
        }
        if(toupper(outputUnit)=='I'){
            length*=12;
        }
        if(toupper(outputUnit)=='C'){
            length*=30.48;
        }
    }
    if(toupper(inputUnit)=='I'){
        if(toupper(outputUnit)=='M'){
            length*=0.3048*(1/12);
        }
        if(toupper(outputUnit)=='F'){
            length/=12;
        }
        if(toupper(outputUnit)=='C'){
            length*=30.48*(1/12);
        }
    }
    if(toupper(inputUnit)=='M'){
        if(toupper(outputUnit)=='I'){
            length/=0.3048*(1/12);
        }
        if(toupper(outputUnit)=='F'){
            length/=0.3048;
        }
        if(toupper(outputUnit)=='C'){
            length*=100;
        }
    }
    if(toupper(inputUnit)=='C'){
        if(toupper(outputUnit)=='I'){
            length*=100/(0.3048*(1/12));
        }
        if(toupper(outputUnit)=='F'){
            length*=100/0.3048;
        }
        if(toupper(outputUnit)=='M'){
            length/=100;
        }
    }
    
}

void output(float &length,char &confirm,char &outputUnit){
    cout<<"the converted value is "<<length;
    if(toupper(outputUnit)=='M')
        cout<<"meters";
    if(toupper(outputUnit)=='c')
        cout<<"centimeters";
    cout<<endl<<"type 'y'if you want to continue and type 'n' to quit \n";
    cin>>confirm;
}