//1

//2


//3


//4




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
