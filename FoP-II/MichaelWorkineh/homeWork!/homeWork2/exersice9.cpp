#include <iostream>

using namespace std;

void function(int &num1,int &num2,int&num3);
int main(){
    int number1,number2,number3;
    cout<<"enter number1: ";
    cin>>number1;
    cout<<"enter number2: ";
    cin>>number2;
    cout<<"enter number3: ";
    cin>>number3;
    function(number1,number2,number3);
    return 0;
}

void function(int &num1,int &num2,int&num3){
    int max = num1, int min = num3; int sum = num1+num2+num3;
    if(max<num2)
        max=num2;
    if(max<num3)
        max=num3;
    if(num1<min)
        min=num1;
    if(num2<min)
        min=num2;
    num1=max;
    num2=sum-max-min;
    num3=min;
}