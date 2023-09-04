
#include <iostream>
#include"local_library.h"
using namespace std;

int main() {
    char c;
    int n;
    cout << "Enter an uppercase letter: ";
    cin >> c;
    // Convert the entered letter to its corresponding integer value
    n = c - 'A' + 1;

    printFirstHalf(n);
    printSecondHalf(n);

    return 0;
}
