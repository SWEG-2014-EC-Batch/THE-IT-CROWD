#include <iostream>
#include"local_lib2.h"
using namespace std;

int main() {
    char c;
    cout << "Enter an uppercase letter: ";
    cin >> c;

    printPattern(c);

    return 0;
}
