#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("files/file4.txt");
    if (!inputFile) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    int numItems;
    double number, sum;
    int totalNumbers = 0;
    double totalSum = 0.0;

    while (inputFile >> numItems) {
        sum = 0.0;

        for (int i = 0; i < numItems; i++) {
            inputFile >> number;
            sum += number;
            totalSum += number;
            totalNumbers++;
        }

        double average = sum / numItems;
        cout << "Group of " << numItems << " numbers, average: " << average << endl;
    }

    double overallAverage = totalSum / totalNumbers;
    cout << "Overall average: " << overallAverage << endl;

    inputFile.close();
    return 0;
}
