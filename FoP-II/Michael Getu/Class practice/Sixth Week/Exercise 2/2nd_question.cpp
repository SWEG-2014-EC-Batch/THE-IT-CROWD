#include <iostream>
using namespace std;

struct ComplexNumber {
    double real;
    double imaginary;
};

ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2) {
    return {c1.real + c2.real, c1.imaginary + c2.imaginary};
}

ComplexNumber operator-(const ComplexNumber& c1, const ComplexNumber& c2) {
    return {c1.real - c2.real, c1.imaginary - c2.imaginary};
}

ComplexNumber operator*(const ComplexNumber& c1, const ComplexNumber& c2) {
    return {
        (c1.real * c2.real) - (c1.imaginary * c2.imaginary),
        (c1.real * c2.imaginary) + (c1.imaginary * c2.real)
    };
}

ComplexNumber operator/(const ComplexNumber& c1, const ComplexNumber& c2) {
    double denominator = (c2.real * c2.real) + (c2.imaginary * c2.imaginary);
    return {
        ((c1.real * c2.real) + (c1.imaginary * c2.imaginary)) / denominator,
        ((c1.imaginary * c2.real) - (c1.real * c2.imaginary)) / denominator
    };
}

int main() {

    ComplexNumber c1{2.0, 3.0};
    ComplexNumber c2{-1.0, 2.5};

    ComplexNumber addition = c1 + c2;
    ComplexNumber subtraction = c1 - c2;
    ComplexNumber multiplication = c1 * c2;
    ComplexNumber division = c1 / c2;

    cout << "Addition: " << addition.real << " + " << addition.imaginary << "i" << endl;
    cout << "Subtraction: " << subtraction.real << " + " << subtraction.imaginary << "i" << endl;
    cout << "Multiplication: " << multiplication.real << " + " << multiplication.imaginary << "i" << endl;
    cout << "Division: " << division.real << " + " << division.imaginary << "i" << endl;

    return 0;
}
