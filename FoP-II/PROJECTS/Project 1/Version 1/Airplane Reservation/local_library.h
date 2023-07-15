#ifndef LOCAL_LIB_H
#define LOCAL_LIB_H
#include<iostream>
using namespace std;

const int MAX_FIRST_CLASS = 30;
const int MAX_ECONOMY = 100;


//2

struct Passenger {
  string name;
  char sex;
  int age;
  string passportNumber;
};

struct Flight {
  int firstClassCount;
  int economyClassCount;
  Passenger firstClass[MAX_FIRST_CLASS];
  Passenger economyClass[MAX_ECONOMY];
};

void addPassenger(Flight& flight, const Passenger& passenger, int isFirstClass) {
  if (isFirstClass==1) {
    if (flight.firstClassCount < MAX_FIRST_CLASS) {
      flight.firstClass[flight.firstClassCount++] = passenger;
      cout << "Booking confirmed. Seat number: " << flight.firstClassCount << " (First Class)" << endl;
    } else {
      cout << "First class is full. Do you want to book an economy class? (y/n): ";
      char choice;
      cin >> choice;
      if (choice == 'y' || choice == 'Y') {
        addPassenger(flight, passenger, false);
      } else {
        cout << "Next flight leaves in 3 hours." << endl;
      }
    }
  } else if (isFirstClass ==2) {
    if (flight.economyClassCount < MAX_ECONOMY) {
      flight.economyClass[flight.economyClassCount++] = passenger;
      cout << "Booking confirmed. Seat number: " << flight.economyClassCount << " (Economy Class)" << endl;
    } else {
      cout << "Economy class is full. Next flight leaves in 3 hours." << endl;
    }
  } else {
    cout << "Error input.";
  }
}

Passenger* getPassenger(Flight& flight, const string& passportNumber) {
  for (int i = 0; i < flight.firstClassCount; i++) {
    if (flight.firstClass[i].passportNumber == passportNumber) {
      return &flight.firstClass[i];
    }
  }
  for (int i = 0; i < flight.economyClassCount; i++) {
    if (flight.economyClass[i].passportNumber == passportNumber) {
      return &flight.economyClass[i];
    }
  }
  return nullptr;
}





//3





//1





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
