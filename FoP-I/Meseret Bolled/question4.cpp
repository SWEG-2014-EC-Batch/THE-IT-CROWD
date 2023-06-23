#include<iostream>
#include<math.h>
using namespace std;
double getProduct(int num1,double num2);
int main()
{
    int firstNum;
    double secondNum;
    double product= getProduct(firstNum,secondNum);
    cout<<"enter your first number";
    cin>>firstNum;
    cout<<"enter your second number";
    cin>>secondNum;
cout<<"the product is:"<<product<<endl;
return 0;
}
double getProduct(int num1,double num2)
{
    num1*num2;
    return num1*num2;
}
