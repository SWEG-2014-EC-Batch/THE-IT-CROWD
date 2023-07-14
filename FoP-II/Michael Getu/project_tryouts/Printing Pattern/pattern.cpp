#include <iostream>
#include"local_lib.h"
using namespace std;

int main() {
    char c;
    cout << "Enter an uppercase letter: ";
    cin >> c;

    printPattern(c);

    return 0;
}
