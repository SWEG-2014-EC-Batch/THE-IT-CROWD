## Pythagorean Triangle Program

### Overview
The Pythagorean Triangle Program is a program that allows users to explore Pythagorean triples and check the properties of triangles. The code has been refactored to improve modularity, readability, and functionality. It includes separate functions for each functionality, such as printing Pythagorean triples and checking and printing triangle properties.

### Code Improvements
1. **Modularity:** The code has been divided into several functions, each responsible for a specific task. This improves modularity, making the code easier to read, understand, and maintain.
2. **Readability:** Meaningful function names, proper indentation, and consistent formatting have been used to enhance code readability.
3. **Separation of Concerns:** Each function has a clearly defined purpose and handles a specific functionality, improving code organization and separation of concerns.
4. **User Interaction:** The program interacts with the user by displaying a menu of options and obtaining their choice. This improves usability and provides a clear interface for users to navigate through the program.

### Functions and Their Purpose
The refactored code includes the following functions:

1. **`printMenu()` Function:**
   - Purpose: This function displays the main menu options for the user to choose from.
   - Parameters: None.
   - Returns: None.

2. **`getChoice()` Function:**
   - Purpose: This function reads and retrieves the user's menu choice.
   - Parameters: None.
   - Returns: Integer representing the user's menu choice.

3. **`printPythagoreanTable()` Function:**
   - Purpose: This function prints a table of Pythagorean triples for side 1, side 2, and hypotenuse, all no larger than 100.
   - Parameters: None.
   - Returns: None.

4. **`inputAndPrintTriangle()` Function:**
   - Purpose: This function allows the user to input the sides of a triangle and prints the triangle's information.
   - Parameters: None.
   - Returns: None.

5. **`printTriangle()` Function:**
   - Purpose: This function prints the sides of a triangle.
   - Parameters:
     - `Triangle t`: A `Triangle` structure representing the sides of the triangle.
   - Returns: None.

6. **`isPythagorean()` Function:**
   - Purpose: This function checks if a triangle satisfies the Pythagorean property.
   - Parameters:
     - `Triangle t`: A `Triangle` structure representing the sides of the triangle.
   - Returns: Boolean value (`true` if the triangle is a Pythagorean triangle, `false` otherwise).

### Program Flow
1. The program starts by displaying the main menu options using the `printMenu()` function.
2. The user's choice is obtained using the `getChoice()` function.
3. Based on the user's choice, the corresponding functionality is executed:
   - Choice 1: The `printPythagoreanTable()` function is called to print a table of Pythagorean triples.
   - Choice 2: The `inputAndPrintTriangle()` function is called to allow the user to input a triangle and print its information.
   - Choice 3: The program exits.
4. The program continues to display the main menu until the user chooses to exit.

### Conclusion
The refactored Pythagorean Triangle Program demonstrates improvements in code organization, modularity, and readability. The separation of concerns into separate functions allows for better code maintenance and readability. The program offers users the ability to explore Pythagorean triples and check the properties of triangles in an interactive and user-friendly manner.
