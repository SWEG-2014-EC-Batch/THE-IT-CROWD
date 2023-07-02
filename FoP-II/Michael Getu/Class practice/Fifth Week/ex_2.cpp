#include<iostream>
#include<cstring>
using namespace std;

int let_count = 100;
void vowel_check(char str[]);

int main() {
    char strr[let_count];
    cout << "Enter a string: ";
    cin.getline(strr, let_count);
    vowel_check(strr);
}

void vowel_check(char str[]) {
    for (int i=0; i<strlen(str); i++) {
        char h = (str[i]);
        if (toupper(h)=='A'||toupper(h)=='E'||toupper(h)=='I'||toupper(h)=='O'||toupper(h)=='U') {
            cout <<(h)<<" ";
        }
    }
}
