/*
EXAM 15 – Programming in C

Implement the following functions and a main program.


### Function 1 — Load words from file

Write a function that:

* Takes as input:

  * an array of strings `words`,
  * the maximum capacity of the array `capacity`,
  * the name of a text file `filename`.
* If the file exists, opens it and copies into the array all words that:

  * start with an **uppercase vowel** (`A, E, I, O, U`),
  * end with a **lowercase consonant**,
  * and only while there is still space available in the array.
* After processing, closes the file.
* Fills any unused positions in the array with empty strings.
* Returns:

  * `1` if the file exists and was processed,
  * `0` if the file does not exist.

**Example**

* File content:
  `Paul Alice Otto Ivan Alan Ethan eva Mark olga Ulrich`
* Resulting array:
  `Alice Ivan Alan Ethan Ulrich`

---

### Function 2 — Display the array

Write a function that:

* Takes as input:

  * an array of strings `words`,
  * its dimension `capacity`.
* Prints the content of the array using the format:
  `index: value`
* Skips empty strings.
* Returns:

  * `1` if all positions in the array are occupied by non-empty strings,
  * `0` otherwise.

**Example output**

```
0: Alice 1: Ivan 2: Alan 3: Ethan 4: Ulrich
```

---

### Function 3 — Character search using pointers

Write a function that **uses pointers and pointer arithmetic** and:

* Takes as input:

  * an array of strings `words`,
  * its dimension `capacity`,
  * a character `ch`,
  * two integer pointer parameters `firstPos` and `lastPos`.
* Stores in:

  * `firstPos` the index of the **first** string containing `ch`,
  * `lastPos` the index of the **last** string containing `ch`.
* If no string contains the character, both values must be set to `-1`.
* Does not return any value.

**Example**

* `ch`: `l`
* `words`: `Alice Ivan Alan Ethan Ulrich`
* Result:
  `firstPos = 0`, `lastPos = 4`

---

### Function 4 — Check string lengths

Write a function that:

* Takes as input:

  * an array of strings `words`,
  * its dimension `capacity`.
* Returns:

  * `1` if all non-empty strings have the **same length**,
  * `0` otherwise.

**Examples**

* `Alice Ivan Alan Ethan Ulrich` → `1` (same length)
* `Alice Ivan Alan Ethan Isabella Ulrich` → `0` (different lengths)

---

### `main` function

Write a `main` function that:

* Receives **exactly one command-line argument**, which is the name of the text file.

  * If the number of arguments is incorrect, prints:
    `"ERROR 1: invalid number of arguments"`
    and terminates returning `1`.
* Declares an array of **20 strings**, each with a **maximum length of 29 characters**.
* Calls the function that loads data from the file.

  * If the file does not exist, prints:
    `"ERROR 2: file <filename> not found"`
    and terminates returning `2`.
  * If no strings were loaded, prints:
    `"ERROR 3: the array is empty"`
    and terminates returning `3`.
* Calls the function that displays the array, then prints:

  * `"the array is fully used"` or
  * `"the array is partially used"`.
* Asks the user to **enter a character**, then calls the search function and prints:

  * `"no string contains <ch>"`, or
  * `"the first string containing <ch> has index <firstPos>, the last has index <lastPos>"`.
* Calls the function that checks string lengths and prints:

  * `"all strings have the same length"` or
  * `"strings have different lengths"`.
* Terminates returning `0`.
*/
