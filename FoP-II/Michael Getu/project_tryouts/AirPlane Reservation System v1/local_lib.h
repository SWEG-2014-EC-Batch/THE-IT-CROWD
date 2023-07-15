#ifndef LOCAL_LIB_H
#define LOCAL_LIB_H
#include<iostream>
using namespace std;

const int MAX_FIRST_CLASS = 30;
const int MAX_ECONOMY = 100;

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

void showMenu() {
  cout << "*********************************************************************************************"
       << endl;
  cout << "*___________________________________________________________________________________________*"
       << endl;
  cout << "*                               Airline Reservation System                                  *"
       << endl;
  cout << "*___________________________________________________________________________________________*"
       << endl;
  cout << "*  Book a flight------------------------------------------------------------------------[1] *"
       << endl;
  cout << "*___________________________________________________________________________________________*"
       << endl;
  cout << "*  Search for attendance----------------------------------------------------------------[2] *"
       << endl;
  cout << "*___________________________________________________________________________________________*"
       << endl;
  cout << "*  List all passengers------------------------------------------------------------------[3] *"
       << endl;
  cout << "*___________________________________________________________________________________________*"
       << endl;
  cout << "*  Exit---------------------------------------------------------------------------------[4] *"
       << endl;
  cout << "*___________________________________________________________________________________________*"
       << endl;
}

int getChoice() {
  int choice;
  cin >> choice;
  return choice;
}

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

void searchPassport(Flight& flight) {
  cout << endl;
  // Prompt the user for the passport number to search
  string passportNumber;
  cout << "Enter passport number to search: ";
  cin >> passportNumber;

  // Search for the passenger
  Passenger* passenger = getPassenger(flight, passportNumber);
  if (passenger != nullptr) {
    cout << "\nPassport Found!\n" << endl;
    cout << "Name: " << passenger->name << endl;
    cout << "Sex: " << passenger->sex << endl;
    cout << "Age: " << passenger->age << endl;
    cout << "Passport Number: " << passenger->passportNumber << endl;
    cout << "Seat No: ";
    if (passenger >= flight.firstClass && passenger < flight.firstClass + MAX_FIRST_CLASS) {
      cout << (passenger - flight.firstClass) + 1 << " (First Class)" << endl;
    } else {
      cout << (passenger - flight.economyClass) + 1 << " (Economy Class)" << endl;
    }
  } else {
    cout << "\nPassport Not Found!" << endl;
  }
}

void printPassengerss(Flight& flight) {
  cout << endl;
  if (flight.firstClassCount == 0 && flight.economyClassCount == 0) {
    cout << "No passengers found." << endl;
    return;
  }

  cout << "List of Passengers:" << endl;
  printPassengers(flight);
}

#endif
