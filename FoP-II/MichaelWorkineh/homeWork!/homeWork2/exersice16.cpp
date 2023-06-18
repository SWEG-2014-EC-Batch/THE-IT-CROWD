#include <iostream>

using namespace std;

void input(int *hour, int *minute);
void processing(int *hour, int *minute, char &am_pm);
void output(int *hour, int *minute, char &am_pm,char *quit);

int main (){
    int hour, minute;
    char am_pm,quit;
    while (toupper(quit)=='N')
    {
        input(&hour, &minute);
        processing(&hour, &minute, am_pm);
        output(&hour, &minute, am_pm, &quit);
    }
    return 0;
}

void input(int *hour, int *minute){
    int x;
    cout<<"enter the hour ";
    cin>>*hour;
    cout<<"enter the minute ";
    cin>>*minute;
}
void processing(int *hour, int *minute, char &am_pm){
    if(*hour>12){
        *hour-=12;
        am_pm='P';
    }
    else{
        am_pm='A';
    }
}
void output(int *hour, int *minute, char &am_pm,char *quit){
    cout<<"the converted time is "<<*hour<<":"<<*minute;
    (am_pm=='P')?cout<<"PM":cout<<"AM";
    cout<<"enter to 'y' to quit and 'n' to quit\n";
    cin>>*quit;
}