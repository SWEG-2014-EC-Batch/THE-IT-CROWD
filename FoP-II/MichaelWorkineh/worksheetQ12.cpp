#include <iostream>
using namespace std;

//12
double calculator(double n1,double n2,double &answer);//via address
double calculator(double n1,double n2,double *answer);//via pointer

//13
double maxi(double i,double j,double k);
double maxi(double i,double j);

//14
int fibbi(int i=1);

int main(){
    double num1, num2,quotient,num3;
    int counter;

    //Q.12:
    ///*
    cout<<"enter the first number ";
    cin>>num1;
    cout<<"enter the second number ";
    cin>>num2;

    //function via address
    calculator(num1,num2,quotient);
    cout<<"the result is "<<quotient<<endl;

    //function via pointer
    calculator(num1,num2,&quotient);
    cout<<"the result is "<<quotient<<endl;
    //*/

    //Q.13:
    ///*
    cout<<"num1: ";
    cin>>num1;
    cout<<"num2: ";
    cin>>num2;
    cout<<"num3: ";
    cin>>num3;
    cout<<"the greater number between "<<num1<<" and "<<num2<<" is "<<maxi(num1,num2)<<endl;
    cout<<"the greater number between "<<num1<<", "<<num2<<" and "<<num3<<" is "<<maxi(num1,num2,num3)<<endl<<"nth value: ";
    //*/

    //Q.14:
    ///*
    cout<<"nth value: "
    cin >> counter;
    cout << fibbi(counter)<<endl;
    cout << fibbi()<<endl;
    //*/

    return 0;
}

double calculator(double n1,double n2,double &answer){
    answer=n1/n2;
}//return not necessary

double calculator(double n1,double n2,double *answer){
    *answer=n1/n2;
}//return not necessary

double maxi(double i,double j,double k){
    double biggest = i;
    if(biggest<j){
        biggest=j;
    }
    if(biggest<k){
        biggest=k;
    }
    return biggest;
}

double maxi(double i,double j){
    double biggest = i;
    if(biggest<j){
        biggest=j;
    }
    return biggest;
}

int fibbi(int i){
    int a =0,sum = 0,b=1;
    if(i==1){
        return 1;
    }
    else{
        for(int checker=1;checker<=i-1;checker++){
            sum=b+a;
            a=b;
            b=sum;
        }
    }
    return sum;
}

