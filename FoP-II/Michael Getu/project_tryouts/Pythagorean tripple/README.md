

## Airline Reservation System Refactored Code

### Overview

The Airline Reservation System is a program designed to facilitate flight bookings, search for passengers by passport number, and view a list of all passengers. The code has been refactored to enhance its structure, readability, and efficiency. The improvements include the use of structures, improved function parameters, enhanced error handling, and optimized code flow.

### Code Improvements

1. **Structures:** The code now utilizes structures instead of classes to represent passengers and flights. Structures provide a lightweight way to hold related data without the need for encapsulation and member functions, making the code more straightforward and efficient.

2. **Improved Function Parameters:** The `addPassenger()` function now takes an additional parameter `isFirstClass` to determine whether the passenger should be added to the first class or the economy class. This enhancement allows for better control and flexibility when booking passengers.

3. **Enhanced Error Handling:** The `addPassenger()` function now includes error handling for invalid input. If the `isFirstClass` parameter is neither 1 (for first class) nor 2 (for economy class), an error message is displayed.

4. **Optimized Code Flow:** The `printPassengerss()` function has been renamed to `printPassengers` to maintain consistency. Additionally, the function now checks whether there are any passengers before displaying the list, avoiding unnecessary iterations when the flight has no passengers.

### Functions and their Purpose

The refactored code includes several functions, each serving a specific purpose to enhance code organization and maintainability. Here is a detailed description of each function:

1. **`addPassenger()` Function:**
   - Purpose: Adds a passenger to the flight data.
   - Parameters:
     - `Flight& flight`: Reference to the `Flight` structure representing the flight data.
     - `const Passenger& passenger`: Reference to the `Passenger` structure representing the passenger to be added.
     - `int isFirstClass`: Indicates whether the passenger should be added to the first class (`1`) or the economy class (`2`).
   - Returns: None.
   - Details: The function checks if there is availability in the specified class and adds the passenger accordingly. If the class is full, the user is prompted to book in the other class or informed about the next available flight.

2. **`getPassenger()` Function:**
   - Purpose: Searches for a passenger by passport number within the flight data.
   - Parameters:
     - `Flight& flight`: Reference to the `Flight` structure representing the flight data.
     - `const std::string& passportNumber`: Reference to the string containing the passport number to be searched.
   - Returns: Pointer to the found `Passenger` structure or `nullptr` if the passenger is not found.
   - Details: The function iterates over the passenger data in both the first class and economy class arrays to find a matching passport number. It returns the pointer to the found passenger or `nullptr` if no match is found.

3. **`printPassengers()` Function:**
   - Purpose: Prints the details of all passengers in the flight data.
   - Parameters:
     - `const Flight& flight`: Reference to the constant `Flight` structure representing the flight data.
   - Returns: None.
   - Details: The function iterates over the passenger data in both the first class and economy class arrays, printing the details of each passenger.

4. **`showMenu()` Function:**
   - Purpose: Displays the main menu options for the user.
   - Parameters: None.
   - Returns: None.
   - Details: The function clears the console screen and prints the main menu options, allowing the user to select an action.

5. **`getChoice()` Function:**
   - Purpose: Reads and retrieves the user's menu choice.
   - Parameters: None.
   - Returns: Integer representing the user's menu choice.
   - Details: The function reads the user's input from the standard input and returns the selected menu choice.

6. **`bookFlight()` Function:**
   - Purpose: Handles the process of booking a flight by interacting with the user.
   - Parameters:
     - `Flight& flight`: Reference to the `Flight` structure representing the flight data.
   - Returns: None.
   - Details: The function prompts the user to enter passenger details such as name, sex, age, and passport number. It then creates a passenger object and calls the `addPassenger()` function to add the passenger to the appropriate class within the flight data.

7. **`searchPassport()` Function:**
   - Purpose: Allows the user to search for a passenger by passport number and displays their details if found.
   - Parameters:
     - `Flight& flight`: Reference to the `Flight` structure representing the flight data.
   - Returns: None.
   - Details: The function prompts the user to enter a passport number and calls the `getPassenger()` function to search for the passenger within the flight data. If a match is found, it displays the passenger's details along with their seat number.

### Program Flow

1. The program starts by declaring the `Flight` structure to hold the flight data, including arrays for first class and economy class passengers.
2. The `main()` function initializes the `Flight` object and enters a continuous loop for the menu-driven program.
3. Inside the loop, the `showMenu()` function is called to display the main menu options for the user to choose from.
4. The user's choice is obtained using the `getChoice()` function.
5. Depending on the selected menu choice, the corresponding function is called:
   - Choice 1: The `bookFlight()` function handles the flight booking process.
   - Choice 2: The `searchPassport()` function allows the user to search for a passenger by passport number.
   - Choice 3: The `printPassengers()` function displays the list of all passengers.
   - Choice 4: The program exits.
6. The loop continues until the user chooses to exit the program.

### Conclusion

The refactored Airline Reservation System code demonstrates significant improvements in code organization, readability, and efficiency. The utilization of structures, improved function parameters, enhanced error handling, and optimized code flow contribute to a more effective and user-friendly program. The refactored code provides a structured and efficient approach to handle flight bookings, passenger searches, and passenger list display.
