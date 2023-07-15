//1


//2
void read(Flight& flight){
    fstream file;
    file.open("files/firstClassList.txt",ios::in|ios::out);
    int i =0;
    if(!file.is_open()){
        cout<<"\acould not be opened"<<endl;
    }
    else{
        while(file.eof() == false){
            file>>flight.firstClass[i].passportNumber>>flight.firstClass[i].name>> flight.firstClass[i].age>>flight.firstClass[i].sex;
            cout<<flight.firstClass[i].passportNumber<<flight.firstClass[i].name<< flight.firstClass[i].age<<flight.firstClass[i].sex<<endl;
            if(flight.firstClass[i].age != 0){
                    i++;
            }
            else{
                break;
            }
        }
    }
    flight.firstClassCount = i;
    file.close();

    i =0;
    file.open("files/economicClassList.txt",ios::in|ios::out);
    if(!file.is_open()){
        cout<<"\acould not be opened"<<endl;
    }
    else{
        while(file.eof() == false){
            file>>flight.economyClass[i].passportNumber>>flight.economyClass[i].name>> flight.economyClass[i].age>>flight.economyClass[i].sex;
            if(flight.economyClass[i].age !=0){
                i++;
            }
            else{
                break;
            }
        }
    }
    flight.economyClassCount = i;
    file.close();
}

void addPassenger(Flight flight, Passenger& passenger, char isFirstClass) {
  if (isFirstClass=='F') {
    if (flight.firstClassCount < MAX_FIRST_CLASS) {
      flight.firstClass[flight.firstClassCount++] = passenger;
      cout << "Booking confirmed. Seat number: " << flight.firstClassCount << " (First Class)" << endl;
      write(passenger);
    } else {
      cout << "First class is full. Do you want to book an economy class? (y/n): ";
      char choice;
      cin >> choice;
      if (choice == 'y' || choice == 'Y') {
        passenger.classChoice = 'E';
        addPassenger(flight, passenger, passenger.classChoice);
      } else {
        cout << "Next flight leaves in 3 hours." << endl;
      }
    }
  } else if (isFirstClass == 'E') {
    if (flight.economyClassCount < MAX_ECONOMY) {
      flight.economyClass[flight.economyClassCount++] = passenger;
      cout << "Booking confirmed. Seat number: " << flight.economyClassCount << " (Economy Class)" << endl;
      write(passenger);
    } else {
      cout << "Economy class is full. Next flight leaves in 3 hours." << endl;
    }
  } else {
    cout << "Error input.";
  }
}




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
