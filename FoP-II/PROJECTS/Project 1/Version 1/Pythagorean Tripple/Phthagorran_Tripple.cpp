#include <iostream>
#include <cmath>
#include"local_lib.h"
using namespace std;
int main() {
  int choice;

  do {
    printMenu();
    choice = getChoice();

    if (choice == 1) {
      printPythagoreanTable();
    } else if (choice == 2) {
      inputAndPrintTriangle();
    }

  } while (choice != 3);

  return 0;
}

