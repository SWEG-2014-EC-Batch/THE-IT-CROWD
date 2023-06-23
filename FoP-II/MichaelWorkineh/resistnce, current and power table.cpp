#include <iostream>
#include <math.h>
using namespace std;
void currentReciver(double current[], int arraySize);
void powerCalculator(double power[],double resistance[],double current[], int arraySize);
double total(double inputArray[], int arraySize);
void spacing(double input);
void display(double current[], double power[], double resistance[], int arraySize);
int main(){
    double resistance[]={16,27,39,56,81}, current[5], power[5];
    int arraySize = 5;
    currentReciver(current,arraySize);
    powerCalculator(power,resistance,current,arraySize);
    display(current, power, resistance, arraySize);
    return 0;
}

void currentReciver(double current[], int arraySize){
    for(int i=0;i<arraySize;i++){
        cout<<"Please enter current "<<i+1<<": ";
        cin>>current[i];
    }
}

void powerCalculator(double power[],double resistance[],double current[], int arraySize){
    for(int i=0;i<arraySize;i++){
        power[i]= resistance[i]*pow(current[i],2);
    }
}

double total(double inputArray[], int arraySize){
    double sum=0;
    for(int i=0;i<arraySize-1;i++){
        sum+=inputArray[i];
    }
    return sum;
}

void spacing(double input){
         if(input<10)
            cout<<"         ";
        else if(input>=10&&input<100)
            cout<<"        ";
        else if(input>=100&&input<1000)
            cout<<"       ";
}
void display(double current[], double power[], double resistance[], int arraySize){
    cout<<"-------------------------------------------"<<endl;
    cout<<"| Resistance|     current    |    power   |"<<endl;
    cout<<"-------------------------------------------"<<endl;
    for(int i=0;i<arraySize;i++){
        cout<<"  "<<resistance[i];
        spacing(resistance[i]);
        cout<<"|      "<<current[i];
        spacing(current[i]);
        cout<<"|      "<<power[i]<<endl;
        cout<<"-------------------------------------------"<<endl;
    }
    cout<<"  "<<total(resistance,arraySize);
    spacing(total(resistance,arraySize));
    cout<<"|      "<<total(current,arraySize);
    spacing(total(current,arraySize));
    cout<<"|      "<<total(power,arraySize)<<endl;
    cout<<"-------------------------------------------"<<endl;
}
