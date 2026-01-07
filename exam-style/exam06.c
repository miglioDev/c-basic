/*
EXAM 06 - Programming in C

Implement the following functions and a main program.


**Function 1 – Password input**

* Receives a character array `pwd` as input.
* Repeatedly asks the user to enter a password made of an **even number of characters**.
* Stores the entered password in `pwd`.
* As long as the password length is not even, it prints the message:
  `ERROR: the number of characters is not even`
  and asks for a new input.
* Returns nothing.

Example valid inputs (even length):

* `M2q#Azp!`
* `7bC@K9d(`
* `XyZ{QWER`

---

**Function 2 – Password strength check**

* Receives a character array `pwd`.
* Returns `1` (password considered *strong*) if the string contains:

  * at least one digit (`0–9`), and
  * at least one alphabetic character (uppercase or lowercase).
* Otherwise, returns `0` (password considered *weak*).

Examples:

* `M2q#Azp!` → `1`
* `7bC@K9d(` → `1`
* `XyZ{QWER` → `0`

---

**Function 3 – Encrypted save to file**

* Using pointers and pointer arithmetic, receives:

  * a character array `pwd`,
  * the name of a text file.
* Saves `pwd` to the file in an *encrypted* form by swapping characters in pairs:

  * first with second, third with fourth, fifth with sixth, and so on.
* Returns nothing.

Examples:

* `pwd: M2q#Azp!` → file content: `2M#qzA!p`
* `pwd: XyZ{QWER` → file content: `yX{ZQWRE`
* `pwd: 7bC@K9d(` → file content: `b7@C9Kd(`

---

**Function 4 – Password confirmation**

* Receives the name of a text file.
* Reads the encrypted password from the file and *decrypts* it to obtain the original password.
* Asks the user to re-enter the password for confirmation.
* Returns `1` (password correct) if the newly entered password matches the decrypted one.
* Otherwise, returns `0` (password incorrect).

---

**`main` function**

* Receives **exactly one command-line argument**, which is the name of a text file.

  * If the number of arguments is incorrect, prints:
    `ERROR: wrong number of parameters`
    and terminates returning `1`.
* Declares a character array of fixed size `30`.
* Calls the function to input and validate the password length.
* Calls the function that evaluates password strength and prints either:

  * `The password is strong` or
  * `The password is weak`.
* Calls the function that saves the password to the file in encrypted form.
* Calls the function that confirms the password and prints either:

  * `The password is correct` or
  * `The password is incorrect`.
* Terminates returning `0`.

*/

#include <stdio.h>

int main ()
{


    return 0;
}