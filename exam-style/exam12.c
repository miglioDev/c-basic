/*
EXAM 12 - Programming in C

Implement the following functions and  main program 


### Function 1 – Input and validation of a string

A function that:

* Receives as input a character array.
* Prompts the user with the message: *“Enter a string:”* and stores the input in the array.
* The string must satisfy **both** of the following conditions:

  * It contains at least **4 characters**.
  * It is composed **only of lowercase alphabetic letters** (`a`–`z`).
* If the string does not satisfy both conditions, the function prints:
  *“ERROR: invalid string”*
  and repeats the request until a valid string is provided.
* The function does **not** return any value.

---

### Function 2 – Alphabetical order check

A function that:

* Receives a string as input.
* Returns `1` if the characters in the string are ordered in **non-decreasing alphabetical order**.
* Returns `0` otherwise.

Examples of strings considered ordered:
`ball`, `cello`, `door`, `loop`, `moon`, `zoo`

---

### Function 3 – Search for vowels using pointers

A function that uses **pointers and pointer arithmetic** and:

* Receives a string and two integer parameters (`idxStart`, `idxEnd`) passed by reference.
* Stores in `idxStart` the index of the **first vowel** found in the string.
* Stores in `idxEnd` the index of the **last vowel** found in the string.
* If the string contains **no vowels**, it stores `-1` in both `idxStart` and `idxEnd`.
* The function does **not** return any value.

Example:
String: `area` → `idxStart = 0`, `idxEnd = 3`

(Vowels are `a`, `e`, `i`, `o`, `u`)

---

### Function 4 – Writing vowels to a file

A function that:

* Receives a string and a file name.
* Opens the specified text file.
* Writes **all vowels** found in the string to the file, separated by semicolons (`;`).
* Closes the file.
* Returns the **total number of characters written** to the file (including separators).

Example:
String: `area` → File content: `a;e;a` → 5 characters written

---

### `main` function

The `main` function must:

* Accept **exactly one command-line argument**, which is the name of a text file.

  * If the number of parameters is incorrect, print:
    *“ERROR 1: wrong number of parameters”*
    and terminate returning `1`.
* Declare a character array of size **25** (defined as a constant).
* Call the string input function, then print:
  *“The string is: …”*
* Call the alphabetical order check function, then print either:
  *“The string is alphabetically ordered”*
  or
  *“The string is not alphabetically ordered”*
* Call the vowel search function, then:

  * If vowels are found, print:
    *“First vowel index: …, last vowel index: …”*
  * Otherwise, print:
    *“ERROR 2: no vowels found in the string”*
    and terminate returning `2`.
* Call the file-writing function, then print:
  *“… characters written to file …”*
* Terminate returning `0`.
*/

#include <stdio.h>

int main()
{
    
    return 0;
}