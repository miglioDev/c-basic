/*
EXAM 04 - Programming in C 

Implement the following functions and a main program 


Function 1

Write a function that:

Receives as input a square matrix of integers (initially undefined) and the matrix size (dim).

Asks the user to enter an integer value (x) that must be strictly positive and made of exactly one digit.
Example: 4

As long as x does not satisfy these requirements, it displays the message
“ERROR: the value is not correct” and asks again for the value.

Fills the matrix with multiples of x, inserting them row by row, until the matrix is completely filled.

Example:

dim: 3   x: 4
-->
4   16  28
8   20  32
12  24  36


The function does not return any value.

Function 2

Write a function that:

Receives as input a square matrix of integers and its dimension.

Displays the values stored in the matrix together with their corresponding indices, as shown in the example.

Example:

    0   1   2
  * * *
0 4  16  28 *
1 8  20  32 *
2 12 24  36 *


The function does not return any value.

Function 3 (using pointer arithmetic)

Write a function that:

Receives as input a square matrix of integers, the matrix dimension, and two parameters (p1, p2).

Stores in p1 the sum of the values located on the first row and the first column.

Stores in p2 the arithmetic mean of the values located on the first row and the first column.

Example:

4   16  28
8   20  32
12  24  36
-->
p1: 68
p2: 13.600000


The function does not return any value.

Function 4

Write a function that:

Receives as input a square matrix of integers, the matrix dimension, the name of a text file, and the number (q) of rows to copy into the file.

Returns 0 if the given quantity is not compatible with the matrix dimension.

Otherwise, copies the first q rows of the matrix into the file, then closes the file and returns 1.

Example:

q: 2
matrix:
4   16  28
8   20  32
12  24  36
-->
file:
4   16
8   20
12  24

Main Function

Write the main function that:

Must receive exactly two command-line parameters:

The dimension of the square matrix

The name of a text file
Otherwise, it displays the message
“ERROR: incorrect number of parameters” and terminates returning 1.

Declares a square matrix using the dimension received as input.

Calls the function that fills the matrix.

Calls the function that displays the matrix values.

Calls the function that computes sum and average, and prints the results:

"the sum of row ... and column ... is ..."

"the average of row ... and column ... is ..."

Asks the user for the number of rows to copy into the file and calls the dedicated function.

If the copy operation fails, it displays
“ERROR: file copy failed” and terminates returning 2.

Otherwise, it displays
“file copy completed successfully” and returns 0.
*/

#include <stdio.h>

int main ()
{


    return 0;
}