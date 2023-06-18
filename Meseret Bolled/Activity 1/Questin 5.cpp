#include<iostream>
#include <cmath>

using namespace std;
double calculateAnswer(double num1,double num2)
{
  double answer=pow(num1,3) +sqrt(num2);
  return answer;

}
int main()
{

    double num1,num2,answer;
    cout<<"enter the first number";
    cin>>num1;
    cout<<"enter the first number";
    cin>>num2;
    answer=calculateAnswer( num1,num2);
    cout<<"the answer is:"<<answer<<endl;
    return 0;

}

