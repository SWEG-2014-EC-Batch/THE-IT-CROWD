#include <iostream>
using namespace std;
void swapValues(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void modifyValues(int& a, int& b, int& c) {
    cout << "Original Values: " << a << " " << b << " " << c << endl;
    if (a < b) {
        swapValues(a, b);
    }
    if (a < c) {
        swapValues(a, c);
    }
    if (b < c) {
        swapValues(b, c);
    }
    cout << "Modified Values: " << a << " " << b << " " << c << endl;
}
int main() {
    int x , y, z;
    cin>>x>>y>>z;
    modifyValues(x, y, z);
    return 0;
}
