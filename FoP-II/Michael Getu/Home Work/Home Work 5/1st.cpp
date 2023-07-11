#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void readFile(int[], int, const char[]);
 
int main() {
    const int arraySize = 12;
    int inputArray[arraySize];
    char fileName[90];

    cout << "Enter the file name only: ";
    cin.getline(fileName, 90);

    readFile(inputArray, arraySize, fileName);

    for (int i = 0; i < arraySize; i++) {
        cout << inputArray[i] << " ";
    }

    return 0;
}

void readFile(int num[], int arraySize, const char fileName[]) {
    char location[100] = "files/";
    strcat(location, fileName);
    strcat(location, ".txt");

    fstream file;
    file.open(location, ios::in | ios::out);

    if (!file.is_open()) {
        cout << "File did not open" << endl;
        return;
    }

    cout << "File is opened!" << endl;

    int i = 0;
    while (!file.eof() && i < arraySize) {
        file >> num[i];
        i++;
    }

    file.close();
}
