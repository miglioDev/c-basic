/*
EXAM 22 – Programming in C

Implement the following functions and a main program.


**1. File-to-array loading function**

A function that:

* Takes as input an array of strings and the name of a text file.
* Reads words from the file and copies into the array only those strings that:

  * start with an uppercase vowel, and
  * end with a lowercase vowel,
    checking that there is still free space in the array.
* Fills the remaining positions of the array with empty strings, if necessary.
* Closes the file.
* Returns `0` if the file could not be opened, `1` otherwise.

*Example*
File content:
`Irene Mark Elena Oscar eva Luca Adele Dino Ulisse Enrico AlexE`

Resulting array:
`Irene Elena Adele Ulisse Enrico`

---

**2. Display function**

A function that:

* Takes as input an array of strings.
* Displays all non-empty strings using the format
  `index: string`,
  arranging **3 strings per line** (the last line may contain fewer than 3 strings).

*Example output:*

```
0: Irene   1: Elena   2: Adele
3: Ulisse  4: Enrico
```

* Returns nothing.

---

**3. Character search function (using pointer arithmetic)**

A function that:

* Takes as input an array of strings, a character `ch`, and two integer parameters `posFirst` and `posLast`.
* Assigns to `posFirst` the index of the **first** string that starts with `ch` (`-1` if none exists).
* Assigns to `posLast` the index of the **last** string that starts with `ch` (`-1` if none exists).
* Uses pointer arithmetic to scan the array.
* Returns nothing.

*Example:*

```
Array: 0: Irene 1: Elena 2: Adele 3: Ulisse 4: Enrico

Character: E  -> posFirst = 1, posLast = 4
Character: U  -> posFirst = 3, posLast = 3
Character: B  -> posFirst = -1, posLast = -1
```

---

**4. Alphabetical order check function**

A function that:

* Takes as input an array of strings.
* Returns `1` if the non-empty strings are in alphabetical order, `0` otherwise.

*Examples:*

```
Irene Elena Adele Ulisse Enrico  -> 0
Adele Elena Enrico Irene Ulisse  -> 1
```

---

**5. `main` function**

The `main` function must:

* Receive **exactly one** command-line argument: the name of a text file.
  Otherwise, print
  `"ERROR 1: invalid number of parameters"`
  and terminate returning `1`.
* Declare an array of **8 strings**, each of maximum length **32** (both values are constants).
* Call the file-loading function.
  If the file cannot be opened, print
  `"ERROR 2: file <name> not found"`
  and terminate returning `2`.
* If the array contains only empty strings, print
  `"ERROR 3: the array is empty"`
  and terminate returning `3`.
* Call the display function to show the array contents.
* Ask the user to *“enter a character”*, then call the character search function.
  Finally, print either:

  * `"the first string starting with <c> is <...>, the last string starting with <c> is <...>"`, or
  * `"no string starts with <c>"`.
* Call the alphabetical order check function and print:

  * `"the strings are in alphabetical order"` or
  * `"the strings are not in alphabetical order"`.
* Terminate returning `0`.
*/
