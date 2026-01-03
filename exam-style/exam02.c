/*
EXAM 02 -Programming in C

Implement the following functions and a main program

**A function that:**

* Receives a character array as input.
* Asks the user to enter a string and stores it in the array.
* The string must start with **two uppercase letters** (the remaining characters can be of any type); moreover, the string must contain **at least 5 characters**.
* Examples of valid strings:
  `ESame`, `ESAme1`, `ESAME`, `ESaME`, ...
* If the requirements are not met, it displays an appropriate error message and repeats the request until the conditions are satisfied.
* Does not return any value.

---

**A function that:**

* Receives a string and two parameters (`q1`, `q2`) as input.
* Stores in `q1` the number of **uppercase letters** present in the string.
* Stores in `q2` the number of **other types of characters**.
* Example:

  * string: `ESAme1` → `q1 = 3`, `q2 = 3`
* Does not return any value.

---

**A function that, using pointer arithmetic:**

* Receives a string as input.
* Returns `1` if the string contains **at least two consecutive identical characters**.
* Otherwise, it returns `0`.
* Examples:

  * `ESaME...` → `1`
  * `ESame` → `0`

---

**A function that:**

* Receives a string and a file name as input.
* Opens the file with the given name.
* Writes into the file the **indices and the characters of the string arranged vertically**.

* Closes the file.
* Does not return any value.

---

**The `main` function:**

* Must receive **exactly one command-line argument**, which is the file name.
  If this condition is not satisfied, it displays an appropriate error message and terminates by returning `1`.
* Declares a character array of size **30** (constant).
* Calls the function to read and store the string, then displays the resulting string.
* Calls the function that counts the characters and displays the results with an appropriate message.
* Calls the function that checks for consecutive equal characters and displays the result with an appropriate message.
* Calls the function that writes the string to the file.
* Returns `0`.
*/

int main ()
{

    return 0;
}