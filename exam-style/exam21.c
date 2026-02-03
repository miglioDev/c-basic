/*
EXAM 21 – Programming in C

Implement the following functions and a main program.


**Function 1 – Load Strings from File**

* Receives a vector (array) of strings and a file name.
* Attempts to open the specified file.
* If the file does not exist, returns `-1`.
* If the file exists:

  * Copies into the vector all strings from the file that contain **at least 3 lowercase vowels** (`a`, `e`, `i`, `o`, `u`).
  * Example:

    * File contents:

      ```
      Berlin Madrid Oslo Paris Rome London
      ```
    * Vector after processing:

      ```
      Berlin Oslo Paris Rome London
      ```
* Closes the file.
* Returns the number of strings copied into the vector.

---

**Function 2 – Display Strings with Indices**

* Receives a vector of strings and the number of strings it contains.
* Prints the indices and strings in two separate rows, as in the example:

  ```
  Indices
  Strings
  0
  Berlin
  1
  Oslo
  2
  Paris
  3
  Rome
  4
  London
  ```
* Does not return any value.

---

**Function 3 – Find Words Ending with a Character**

* Receives a vector of strings, its size, a character, and two integer references (or pointers) `firstIndex` and `lastIndex`.
* Stores in `firstIndex` the index of the first string ending with the given character. If none exists, stores `-1`.
* Stores in `lastIndex` the index of the last string ending with the given character. If none exists, stores `-1`.
* Example:

  ```
  Vector: Berlin Oslo Paris Rome London
  Character: o
  -> firstIndex: 1, lastIndex: 1

  Character: n
  -> firstIndex: 0, lastIndex: 4

  Character: x
  -> firstIndex: -1, lastIndex: -1
  ```
* Does not return any value.

---

**Function 4 – Remove First String**

* Receives a vector of strings and its size.
* Removes the first string, shifting all remaining strings forward.
* Example:

  ```
  Before: Berlin Oslo Paris Rome London
  After:  Oslo Paris Rome London
  ```
* Returns the updated number of strings.

---

**Main Function Requirements**

* Receives **exactly one command-line argument**: the name of the input file.

  * If the number of arguments is incorrect, displays an error message and exits.
  * Example usage:

    ```
    ./program strings.txt
    ```
* Declares a vector capable of holding **30 strings of 30 characters each**.
* Calls the function to load strings from the file.

  * If the file does not exist, displays an error message and exits.
* Calls the function to display the vector.
* Prompts the user to enter a character.
* Calls the function to find the first and last words ending with that character and displays the results.
* Calls the function to remove the first string, then calls the display function again to show the updated vector.
*/
