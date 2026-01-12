/*
EXAM 10 - Programming in C

Implement the following function 


A function that:

* Takes as input an array of strings and its size.
* Prompts the user to “enter the first string”. This string must:

  * contain only lowercase letters,
  * have its characters in non-decreasing alphabetical order.
    Examples: `ace`, `ball`, `moon`.
* If the first string does not meet these requirements, the function returns `0`.
* Otherwise, it fills the array with strings obtained by replacing the **last character** of the previous string with the next letter in the alphabet.

  Example:
  first string: `ball`, size: `4`
  → array: `ball balm baln balo`
* Finally, the function returns `1`.

A function that:

* Takes as input an array of strings and its size.
* Prints indices and strings on two separate lines, following the format shown in the example.
* Does not return any value.

Example output:

```
indices:
strings:
0 1 2 3
ball balm baln balo
```

A function that, using pointers and pointer arithmetic:

* Takes as input an array of strings, its size, and two parameters (`c1`, `c2`).
* Stores in `c1` the number of strings that start with a lowercase vowel.
* Stores in `c2` the number of strings that end with a lowercase vowel.

Example:
array: `ball balm baln balo` → `c1 = 4`, `c2 = 1`

* Does not return any value.

A function that:

* Takes as input an array of strings, its size, and the name of a file.
* Writes to the file all lowercase vowels found in the array, separated by commas.

Example:
array: `ball balm baln balo` → file content: `a,a,a,o`

* Closes the file.
* Does not return any value.

The `main` function must:

* Receive exactly two command-line parameters:

  1. the number of strings,
  2. the name of a text file.
     If the number of parameters is incorrect, print
     `ERROR 1: wrong number of parameters`
     and terminate returning `1`.
* Check that the number of strings is at least 1. Otherwise, print
  `ERROR 2: invalid number of strings`
  and terminate returning `2`.
* Declare an array of strings based on the given size, where the maximum length of each string is 30 characters (defined as a constant).
* Call the function that loads the array. If loading fails, print
  `ERROR 3: loading failed`
  and terminate returning `3`.
* Call the function that displays the array.
* Call the function that counts strings, then print
  `... strings start with a vowel; ... strings end with a vowel`.
* Call the function that writes vowels to the text file.
* Return `0`.
*/

int main ()
{

    return 0;
}