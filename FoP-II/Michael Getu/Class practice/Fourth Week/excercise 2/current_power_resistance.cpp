#include<iostream>
#include <math.h>
using namespace std;
const int x= 5;
void calc_power(double current[], double resistance [], double power[], int size) {
    for(int i=0;i<size;i++){
        power[i]=pow(current[i],2)*resistance[i];
    }
}

void currentCal(double current[],int size){
    for(int i=0;i<size;i++){
        cout<<"current "<<i+1<<": ";
        cin>>current[i];
    }
}

double total(double array[], int size){
    double sum=0;
    for (int i=0;i<size;i++){
        sum+=array[i];   
    }
    return sum;
}

void display(double current[], double resistance [], double power[], int size) {
    cout<<"Resistance\t\t|\t\t\tcurrent\t\t\t|\t\t\tpower"<<endl;
    for(int i=0;i<size;i++){
        cout<<resistance[i]<<"\t\t\t|\t\t\t"<<current[i]<<"\t\t\t|\t\t\t"<<power[i]<<endl;
    }
    cout<<"total: "<<total(resistance,size)<<"\t\t|\t\t"<<"total: "<<total(current,size)<<"\t\t|\t\t\t"<<"total: "<<total(power,size)<<endl;
}



int main() {
    double resisttance[] = {16, 27, 39, 56, 81};
    double current [x];
    double power [x];
    currentCal(current,x);
    calc_power(current,resisttance,power,x);
    display(current,resisttance,power,x);

  return 0;
}
