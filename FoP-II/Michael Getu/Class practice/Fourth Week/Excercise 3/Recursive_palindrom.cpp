#include <iostream>
#include <cstring>

using namespace std;

void reverseString(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

int main() {
    char str[90];
    cin.getline(str, 90);

    char reverseStr[90];
    strcpy(reverseStr, str);
    reverseString(reverseStr);

    if (strcmp(str, reverseStr) == 0) {
        cout << "It is a palindrome" << endl;
    } else {
        cout << "It isn't a palindrome" << endl;
    }

    return 0;
}
