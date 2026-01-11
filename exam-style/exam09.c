/*
Exam 09 - Programming in C 

Implement the following functions and a main program

**Function 1 – String input and validation**

* Receives a character array as input.
* Prompts the user to *“enter a string”* that:

  * contains at least 3 characters,
  * starts with an **uppercase vowel**,
  * continues with **lowercase letters**,
  * ends with a **lowercase vowel**.
* Example valid strings:

  * *Irene*, *Olivia*, *Umberto*, *Alessia*, *Elena*
* Stores the entered string in the character array.
* Returns `1` if the string satisfies all requirements, `0` otherwise.

---

**Function 2 – Display indices and characters**

* Receives a string as input.

* Prints the indices and the corresponding characters on two separate lines, formatted as shown in the example.

* Example output for the string *Elisa*:

  ```
  indices:    0  1  2  3  4
  characters: E  l  i  s  a
  ```

* Does not return any value.

---

**Function 3 – Character search using pointer arithmetic**

* Using pointer arithmetic, receives:

  * a string,
  * a character to search,
  * two output parameters (`posFirst`, `posLast`).
* Stores in `posFirst` the index of the **first occurrence** of the character and in `posLast` the index of the **last occurrence**.
* If the character does not appear in the string, stores `-1` in both parameters.
* Example:

  * string: *Elissa*, character: `s` → `posFirst = 2`, `posLast = 3`
* Does not return any value.

---

**Function 4 – Circular right shift and file writing**

* Receives a string and a file name.
* Performs a **circular right shift** on the string.
* Writes the resulting string to the file, separating each character with a dash (`-`), then closes the file.
* Example:

  * original string: *Elisa* → shifted string: *aElis*
  * file content: `a-E-l-i-s`
* Returns the total number of characters written to the file (including separators).

---

**`main` function**

* Receives **exactly one command-line argument**, which is the name of a text file.

  * If the number of parameters is incorrect, prints
    *“ERROR: wrong number of parameters”*
    and terminates returning `1`.
* Declares a character array of fixed size **30**.
* Calls the string input function to load the string into the array.

  * If the loading fails, prints
    *“ERROR: invalid string”*
    and terminates returning `2`.
* Calls the function that displays the string with indices.
* Prompts the user to *“enter a character”*, calls the search function, and then prints either:

  * *“The character X appears at positions Y and Z”*, or
  * *“The character X is not present”*.
* Calls the function that performs the circular shift and writes to file, then prints
  *“N characters written to file”*.
* Returns `0`.
*/

#include <stdio.h>

int main ()
{

    return 0;
}