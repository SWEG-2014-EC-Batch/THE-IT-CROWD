#include <iostream>
#include <math.h>
using namespace std;

double windChil(double windSpeed, double temp);

int main(){
    double windSpeed,temp;
    cout<<"enter the wind speed ";
    cin>>windSpeed;
    cout<<"enter the temperature ";
    cin>>temp;
    if(temp<=10){
        cout<<"the windchill index is "<<windChil(windSpeed,temp);
    }
    return 0;
}

double windChil(double windSpeed, double temp){
    return (13.12+pow(0.6215,temp)-11.37*pow(windSpeed,0.16)+0.3965*temp*pow(windSpeed,0.016));
}
