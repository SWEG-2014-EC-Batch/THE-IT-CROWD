#include <iostream>
struct point{
    float x;
    float y;
};
point read();
void print(point p);
using namespace std;
int main(){
    point p = read();
    print(p);
    return 0;
}

point read(){
    point p;
    cout<<"enter the x and y coordinates like this: \"x y\""<<endl<<"point: ";
    cin>>p.x>>p.y;
    return p;
}

void print(point p){
    cout<<"The coordinate you have entered is: ("<<p.x<<", "<<p.y<<")"<<endl;
}
