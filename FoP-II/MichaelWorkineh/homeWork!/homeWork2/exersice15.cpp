#include <iostream>
using namespace std;

void scale (double num1=1, double &num2, double &num3);
bool scalechecker = 0;
int main(){
    double num1, num2, num3;
    cout<<"enter the number1: ";
    cin>>num1;
    cout<<"enter the number2: ";
    cin>>num2;
    cout<<"enter the number3: ";
    cin>>num3;
    if(num1!=0){
        scale(num1,num2,num3);
        cout<<"the old value of number 2 is "<<num3<<endl;
        cout<<"the new  value number2 is "<<num2<<endl;
        cout<<"the old value of number 3 is "<<num3<<endl;
        cout<<"the new  value number3 is "<<num3<<endl;
        (scalechecker==0)?cout<<"they have been scaled down"<<endl:cout<<"they have been scaled up"<<endl;
    }
    return 0;
}

void scale(double num1, double &num2, double &num3){
    (num1>1)?scalechecker=1:scalechecker=0;
    num2*=num1;
    num3*=num1;
}

