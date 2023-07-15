#ifndef LOCAL_LIB_H
#define LOCAL_LIB_H
#include<iostream>
using namespace std;

const int MAX_FIRST_CLASS = 30;
const int MAX_ECONOMY = 100;


//2

//3



void bookFlight(Flight& flight) {
  cout << endl;
  // Prompt the user for passenger details
  string name, passportNumber;
  char sex;
  int age;
  cout << "Enter passenger name: ";
  cin.ignore();
  getline(cin, name);
  cout << "Enter passenger sex (m/f): ";
  cin >> sex;
  cout << "Enter passenger age: ";
  cin >> age;
  cout << "Enter passport number: ";
  cin >> passportNumber;
  cout << "Select class (1 - First Class, 2 - Economy): ";
  int classChoice;
  cin >> classChoice;

  // Create the passenger object
  Passenger passenger{name, sex, age, passportNumber};

  // Add the passenger to the flight
  addPassenger(flight, passenger, classChoice);
}

//4




#endif
