#include <iostream>
#include <cassert>

using namespace std;

void scale(double val, double& val1, double& val2) {
    assert(val != 0.0);
    val1 *= val;
    val2 *= val;
}

int main() {
    double val1 = 2.5;
    double val2 = 3.0;
    double scale_factor = 2.0;

    cout << "Before scaling:" << endl;
    cout << "val1 = " << val1 << endl;
    cout << "val2 = " << val2 << endl;

    scale(scale_factor, val1, val2);

    cout << "After scaling:" << endl;
    cout << "val1 = " << val1 << endl;
    cout << "val2 = " << val2 << endl;

    scale_factor = 0.5;

    cout << "Before scaling down:" << endl;
    cout << "val1 = " << val1 << endl;
    cout << "val2 = " << val2 << endl;

    scale(scale_factor, val1, val2);

    cout << "After scaling down:" << endl;
    cout << "val1 = " << val1 << endl;
    cout << "val2 = " << val2 << endl;

    return 0;
}
