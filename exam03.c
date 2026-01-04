/*
EXAM 03 - Programming in C

Implement the following functions and a main program 


A function that:

Receives as input an array of strings (initially unspecified), the maximum number of strings the array can store, and the name of a text file.

Attempts to open the given text file.

If the file is successfully opened, it copies from the file into the array the strings that start with an uppercase vowel and end with a lowercase vowel, checking that there is still available space in the array.

Then closes the file.

Example:

File content:

Anna Jack Elisa Ethan ada Daniela Adele Demi Ariel Omero Enea AchillE


Array content after loading:

Anna  Elisa  Adele  Omero  Enea


Returns -1 if the file opening fails.

Otherwise, returns the number of strings copied into the array
(the array may remain empty if the file does not contain suitable strings).

A function that:

Receives as input an array of strings and the number of strings currently stored in the array.

Displays the contents of the array using the notation index: string, arranging 3 strings per line
(the last line may contain fewer than 3 strings).

Example output:

0: Anna     1: Elisa     2: Adele
3: Omero    4: Enea


Does not return any value.

A function that:

Receives as input an array of strings, the number of strings stored in the array, a character, and two parameters (p1, p2).

Assigns to p1 the index of the first string that contains the given character (assigns -1 if not found).

Assigns to p2 the index of the second string that contains the given character (assigns -1 if not found).

Examples:

Array:

0: Anna   1: Elisa   2: Adele   3: Omero   4: Enea

Character	p1	p2
a	0	1
e	2	4
o	3	-1
u	-1	-1

Does not return any value.

A function that, using pointer arithmetic:

Receives as input an array of strings and the number of strings stored in the array.

Performs a circular right shift: each string is moved one position to the right; the last string is moved to the first position.

Example:

0: Anna  1: Elisa  2: Adele  3: Omero  4: Enea
-->
0: Enea  1: Anna   2: Elisa  3: Adele  4: Omero


Does not return any value.

The main function:

Must receive exactly one command-line argument, which is the name of a text file.
Otherwise, it displays the message
“ERROR: missing text file name”
and terminates by returning 1.

Declares an array of 10 strings, each of length 30 (10 and 30 are constants).

Calls the function to load the array from the file.

If the file opening fails, it displays
“ERROR: the text file does not exist”
and terminates by returning 2.

If the array contains no strings, it displays
“ERROR: empty array”
and terminates by returning 3.

Calls the function to display the array.

Asks the user to input a character.

Calls the function that searches for the character in the array and displays one of the following messages:

“the character is present in the strings with indices ... and ...”

“the character is present only in the string with index ...”

“the character is not present”

Calls the function that performs the array shift.

Calls again the function to display the array.

Returns 0. */

#include <stdio.h>
#include <ctype.h>

int main ()
{


    return 0; 
}