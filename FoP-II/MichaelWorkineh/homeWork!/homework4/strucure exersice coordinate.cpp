#include <iostream>
using namespace std;

struct coordinate{
    float x, y;
};

coordinate read();
void print (coordinate);

int main(){
    coordinate str = read();
    print(str);
    return 0;
}

coordinate read(){
    coordinate position;
    cout<<"enter the x coordinate: ";
    cin>>position.x;
    cout<<"enter the y coordinate: ";
    cin>>position.y;
    return position;
}

void print(coordinate value){
    cout<<"the position read: ("<<value.x<<", "<<value.y<<")"<<endl;
}
