#include <iostream>
#include <string>
#include "local_library.h"

using namespace std;

int main() {
  Flight flight;
  while (true) {
    showMenu();
    cout << "Enter your choice: ";
    int choice = getChoice();

    switch (choice) {
      case 1:
        bookFlight(flight);
        break;
      case 2:
        searchPassport(flight);
        break;
      case 3:
        printPassengerss(flight);
        break;
      case 4:
        return 0;
      default:
        cout << "Invalid input. Please try again." << endl;
    }
  }

  return 0;
}
