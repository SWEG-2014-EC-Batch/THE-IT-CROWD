#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    ifstream file("files/file8.txt");

    if (!file.is_open()) {
        cout << "File could not be opened." << endl;
        return 0;
    }

    unordered_map<char, int> charCounts;
    char ch;

    while (file.get(ch)) {
        if (islower(ch)) {
            charCounts[ch]++;
        }
    }

    file.close();

    cout << "CHARACTER OCCURRENCES" << endl;
    for (char c = 'a'; c <= 'z'; c++) {
        int count = charCounts[c];
        cout << c << "\t\t" << count << endl;
    }

    return 0;
}
