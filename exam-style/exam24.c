/*
EXAM 24 – Programming in C

Implement the following functions and a main program.


A function that
receives as input an empty array of strings, its size, and the name of a text file.

The function copies from the file into the array only the words that start with an uppercase consonant and end with a lowercase vowel, making sure that there is still available space in the array.

Example: file content → *Paolo Irene Dario Elena Giorgio Marta*
resulting array → *Paolo Dario Giorgio*

If necessary, the remaining positions of the array must be filled with empty strings.

The function returns **1** if the file exists and at least one word has been copied, otherwise it returns **0**.

---

A function that
receives as input an array of strings and its size.

The function prints the non-empty strings using the format **index: string**, one per line.

Example:

```
0: Paul
1: Bob
2: Georg
```

The function returns the number of printed strings.

---

A function that, using **pointer arithmetic**,
receives as input an array of strings, its size, a character **ch**, and two parameters (**first**, **last**).

The function assigns to **first** the index of the first string containing the character **ch** (in any position).
It assigns to **last** the index of the last string containing the character **ch**.

If the character does not appear in any string, both parameters must be set to **–1**.

The function does not return any value.

---

A function that
receives as input an array of strings and its size.

For every non-empty string, the function replaces all lowercase vowels with the character `#` or another char like *.

Example:
*Paul → P##l
*Bob → B*B

The function does not return any value.

---

The **main** function must:

* Receive **exactly one** command-line argument: the name of a text file.
  Otherwise, print
  **"ERROR 1: wrong number of parameters"**
  and terminate returning **1**.

* Declare an array of **15** strings, each with a maximum length of **30** characters (defined as constants).

* Call the function that loads the array from the file.
  If it returns **0**, print
  **"ERROR 2: loading failed"**
  and terminate returning **2**.

* Call the function that prints the array and store the returned count.
  If the count is **0**, print
  **"ERROR 3: empty array"**
  and terminate returning **3**.

* Ask the user to **enter a character**, then call the search function.
  Display either
  **"The character ... appears from index ... to index ..."**
  or
  **"The character ... does not appear in any string"**.

* Call the function that replaces lowercase vowels with `#`.

* Call again the function that prints the modified array.

* Return **0**.


*/
