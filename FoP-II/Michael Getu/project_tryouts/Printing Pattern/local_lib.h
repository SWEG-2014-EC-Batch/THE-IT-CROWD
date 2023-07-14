#ifndef LOCAL_LIB_H
#define LOCAL_LIB_H
#include<iostream>
using namespace std;

void printPattern(char c) {
    int n = c - 'A' + 1;

    // First half loop
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            cout << "  ";
        }
        for (int j = i; j >= 1; j--) {
            cout << char('A' + j - 1) << " ";
        }
        for (int j = 2; j <= i; j++) {
            cout << char('A' + j - 1) << " ";
        }
        cout << endl;
    }

    // Second half loop
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << "  ";
        }
        for (int j = i; j >= 1; j--) {
            cout << char('A' + j - 1) << " ";
        }
        for (int j = 2; j <= i; j++) {
            cout << char('A' + j - 1) << " ";
        }
        cout << endl;
    }
}
#endif
