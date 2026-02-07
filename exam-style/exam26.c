/*
EXAM 01 – Programming in C

Implement the following functions and a main program.


A function that
receives as input an (empty) array of strings, its size, and the name of a text file.

It copies from the file into the array the words that have **odd length** and contain **at least one uppercase vowel**, checking that there is still available space in the array.

Example:
file: `"Tree Apple PEAR banana Grape Mango"` → array:

* `"Tree"` (length 4, even → not valid)
* `"Apple"` (length 5, odd, but no uppercase vowel → not valid)
* `"PEAR"` (length 4, even → not valid)
* `"banana"` (length 6, even → not valid)
* `"Grape"` (length 5, odd, but no uppercase vowel → not valid)

So no string is copied.

For clarity, corrected example:
file: `"Tree Apple PEAR banana Grape Mango Orange"` → array:

* `"Grape"` (length 5, odd, contains uppercase vowel `'A'` → valid)
* `"Mango"` (length 5, odd, but no uppercase vowel → not valid)
* `"Orange"` (length 6, even → not valid)

Another corrected example with multiple valid strings:
file: `"Tree Apple PEAR banana Grape Mango Apricot"` → array:

* `"Grape"` (5, odd, contains uppercase vowel `'A'`)
* `"Apricot"` (7, odd, contains uppercase vowel `'A'`)

So the array contains: `"Grape"`, `"Apricot"`.

If necessary, the array is filled with empty strings.

The function returns the number of strings copied into the array.

---

A function that
receives as input an array of strings and its size.

It displays the non-empty strings using the format `[index] string`, one per line.

It returns the number of strings displayed.

---

A function that, using pointer arithmetic,
receives as input an array of strings, its size, a character (`c`), and two parameters (`p1`, `p2`).

It assigns to `p1` the index of the **first** string in which the character `c` appears at an **even position** (0, 2, 4, …).

It assigns to `p2` the index of the **last** string in which the character `c` appears at an **odd position** (1, 3, 5, …).

If no occurrences are found, it assigns `-1` to the corresponding parameters.

It does not return anything.

---

A function that
receives as input an array of strings and its size.

For each non-empty string, it replaces every numeric digit (`0–9`) with the character `'#'`.

Example:
`"Grape123"` → `"Grape###"`
`"Apricot"` remains `"Apricot"`.

It does not return anything.

---

The `main` function that
receives **exactly one** input parameter: the name of a text file.
Otherwise, it prints
`"ERROR 1: wrong number of parameters"`
and terminates returning `1`.

It declares an array of **20 strings**, each with a **maximum length of 30** (constants).

It calls the function to load the array from the file.
If the number of copied strings is `0`, it prints
`"ERROR 2: no valid strings"`
and terminates returning `2`.

It calls the function to display the array.

It asks the user to **"insert a character"** and calls the search function. Then it prints:

* `"The character ... appears at an even position in the string with index ..."`
* `"The character ... appears at an odd position in the string with index ..."`

or

* `"The character ... does not appear at even/odd positions"`
  if the corresponding parameter is `-1`.

It calls the function to replace digits with `'#'`.

It calls the display function again to show the modified array.

It returns `0`.
*/