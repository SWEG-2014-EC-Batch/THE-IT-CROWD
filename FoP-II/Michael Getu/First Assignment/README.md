# FOP2 Assignment
## Table of Contents
- [Question 4](#Question4)
- [Question 5](#Question5)
- [Question 6](#Question6)
- [Question 7](#Question7)
- [Question 8](#Question8)

## Question 4 <a name="Question4"></a>
This question involves creating a simple number multiplier program.

### The main function
- Prompts the user to enter values.
- Declares and initializes `firstNum` as an integer to store the first input value.
- Declares and initializes `secondNum` as a double to store the second input value.

### The getProduct function
- Performs the multiplication of the values entered in the main function.
- Takes two parameters:
  - `num1`, which receives the value stored in `firstNum` in the main function.
  - `num2`, which receives the value stored in `secondNum` in the main function.

## Question 5 <a name="Question5"></a>
This question involves adding the cube of one number to the square root of another number.

### The main function
- Accepts two numbers for the calculations (`firstNum` and `secondNum`).
- Computes the result and stores it in the variable `answer`.
- Finally, displays the result.

### The calculations function
- Receives the user's input via its parameters (`num1` and `num2`).
- Calculates the sum of `num1` cubed and the square root of `num2`.

## Question 6 <a name="Question6"></a>
This question involves using the Pythagorean theorem to find the hypotenuse of a triangle.

### The main function
- Receives the lengths of the two sides of the triangle from the user (stored in variables `side1` and `side2`).
- Calls the `hypotenuse` function to calculate and display the hypotenuse.

### The hypotenuse function
- Returns the square root of the sum of the squares of `side1` and `side2`.

## Question 7 <a name="Question7"></a>
This question involves calculating the product of different series of numbers using variable-length arguments.

### The main function
- Prints the product for different series of numbers.

### The calculateProduct function
- Returns a double data type.
- Is a recursive function that calculates the product of a variable number of arguments (the number of arguments can vary with each function call).

## Question 8 <a name="Question8"></a>
This question involves checking if an integer is a prime number or not.

### The main function
- Receives an integer from the user.
- Calls the `isPrime` function to determine if the number is prime.
- Prints "is a prime number" if `isPrime` returns true, indicating the number is prime.
- Prints "is not a prime number" if `isPrime` returns false, indicating the number is not prime.

### The isPrime function
- Takes one parameter that receives the integer entered by the user.
- Uses a variable `tester` to check if any factors are found.
- Uses a for loop to iterate through integers less than or equal to the square root of the user-entered value.
- Returns:
  - true if `tester` remains zero (no factors found).
  - false if `tester` has a different value (a factor was found).

