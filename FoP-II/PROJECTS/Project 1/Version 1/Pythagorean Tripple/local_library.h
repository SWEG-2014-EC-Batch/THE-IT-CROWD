#ifndef LOCAL_LIB_H
#define LOCAL_LIB_H
#include<iostream>
using namespace std;
// Triangle structure
struct Triangle {
  int side1;
  int side2;
  int hypotenuse;
};

//2

//3

//4


// Print triangle sides
void printTriangle(Triangle t) {
  cout << "Side 1: " << t.side1 << endl;
  cout << "Side 2: " << t.side2 << endl;
  cout << "Hypotenuse: " << t.hypotenuse << endl;
}

// Check Pythagorean triangle property
bool isPythagorean(Triangle t) {
  return t.side1 * t.side1 + t.side2 * t.side2 == t.hypotenuse * t.hypotenuse;
}
#endif
