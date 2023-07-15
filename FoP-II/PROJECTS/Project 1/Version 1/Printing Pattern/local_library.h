#ifndef LOCAL_LIB_H
#define LOCAL_LIB_H
#include<iostream>
using namespace std;

void printChars(char ch, int count);
void printFirstHalf(int n);
void printSecondHalf(int n);

//1
void printChars(char ch, int count) {
    for (int i = 0; i < count; i++) {
        cout << "  ";
    }
}

//2
void printFirstHalf(int n) {
    for (int i = n; i >= 1; i--) {
        printChars(' ', n - i);
        for (int j = i; j >= 1; j--) {
            cout << char('A' + j - 1) << ' ';
        }
        for (int j = 2; j <= i; j++) {
            cout << char('A' + j - 1) << ' ';
        }
        cout << endl;
    }
}

//3
void printSecondHalf(int n) {
    for (int i = 2; i <= n; i++) {
        printChars(' ', n - i);
        for (int j = i; j >= 1; j--) {
            cout << char('A' + j - 1) << ' ';
        }
        for (int j = 2; j <= i; j++) {
            cout << char('A' + j - 1) << ' ';
        }
        cout << endl;
    }
}
#endif

