#include<iostream>
using namespace std;

struct coordinates {
    int x_cor;
    int y_cor;
};

coordinates read() {
    coordinates read_cord;
    cout << "Enter the x coordinate: ";
    cin >> read_cord.x_cor;
    cout << "Enter the y coordinates: ";
    cin >> read_cord.y_cor;
    return read_cord;
}

void print_coordinates(coordinates& print) {
    cout << "The x,y coordinate is: "<<"("<<print.x_cor<<" , "<<print.y_cor<<")"<<endl;
}

int main() {
    coordinates cord = read();
    print_coordinates(cord);

}
