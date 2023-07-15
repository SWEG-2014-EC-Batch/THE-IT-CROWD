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
// Function prototypes
void printMenu();
int getChoice();
void printPythagoreanTable();
void inputAndPrintTriangle();

void printTriangle(Triangle); // Print triangle
bool isPythagorean(Triangle); // Check property


// Print menu options
void printMenu() {
  cout << "================================================" << endl;
  cout << " WELCOME TO OUR PROGRAM                         " << endl;
  cout << "________________________________________________" << endl;
  cout << " 1) Print Pythagorean triples" << endl;
  cout << " 2) Check and print a triangle" << endl;
  cout << " 3) Exit" << endl;
  cout << "================================================" << endl;
}

// Get user's choice
int getChoice() {
  int choice;
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}


//3

void printPassengers(const Flight& flight) {
  for (int i = 0; i < flight.firstClassCount; i++) {
    cout << "Passenger " << i + 1 << " (First Class)" << endl;
    cout << "Name: " << flight.firstClass[i].name << endl;
    cout << "Sex: " << flight.firstClass[i].sex << endl;
    cout << "Age: " << flight.firstClass[i].age << endl;
    cout << "Passport number: " << flight.firstClass[i].passportNumber << endl;
    cout << "-------------------------------------------" << endl;
  }
  for (int i = 0; i < flight.economyClassCount; i++) {
    cout << "Passenger " << i + 1 << " (Economy Class)" << endl;
    cout << "Name: " << flight.economyClass[i].name << endl;
    cout << "Sex: " << flight.economyClass[i].sex << endl;
    cout << "Age: " << flight.economyClass[i].age << endl;
    cout << "Passport number: " << flight.economyClass[i].passportNumber << endl;
    cout << "-------------------------------------------" << endl;
  }
}


// Print Pythagorean triples table
void printPythagoreanTable() {
  cout << "\nPythagorean triples table:\n" << endl;
  cout << "Side 1\tSide 2\tHypotenuse" << endl;
  cout << "______________________________" << endl;

  for (int side1 = 1; side1 <= 100; side1++) {
    for (int side2 = 1; side2 <= 100; side2++) {
      for (int hypotenuse = 1; hypotenuse <= 100; hypotenuse++) {
        int side1Square = side1 * side1;
        int side2Square = side2 * side2;
        int hypotenuseSquare = hypotenuse * hypotenuse;

        if (side1Square + side2Square == hypotenuseSquare) {
          cout << side1 << "\t" << side2 << "\t" << hypotenuse << endl;
        }
      }
    }
  }

  cout << endl;
}


// Input and print a triangle
void inputAndPrintTriangle() {
  Triangle triangle;

  cout << "\nEnter the sides of the triangle:" << endl;
  cout << "Side 1: ";
  cin >> triangle.side1;
  cout << "Side 2: ";
  cin >> triangle.side2;
  cout << "Hypotenuse: ";
  cin >> triangle.hypotenuse;

  cout << "\nTriangle information:" << endl;
  printTriangle(triangle);

  if (isPythagorean(triangle)) {
    cout << "This triangle is a Pythagorean triangle." << endl;
  } else {
    cout << "This triangle is not a Pythagorean triangle." << endl;
  }

  cout << endl;
}

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
