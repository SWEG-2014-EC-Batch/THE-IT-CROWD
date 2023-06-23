
#include <iostream>
using namespace std;


void Myassert(double condition) {
    if (condition == 0) {
        cout << "Assersion failed!";
        exit(1);

    }
}
void scale(double factor, double& value1, double& value2) {
    Myassert(factor);
    value1 *= factor;
    value2 *= factor;
}

int main() {
    double value1 = 50.0;
    double value2 = 5.0;
    double scaleFactor = 5.0;

    cout << "Before scaling:" << std::endl;
    cout << "Value 1: " << value1 << std::endl;
    cout << "Value 2: " << value2 << std::endl;

    scale(scaleFactor, value1, value2);

    cout << "After scaling:" << endl;
    cout << "Value 1: " << value1 << endl;
    cout << "Value 2: " << value2 << endl;

    return 0;
}
