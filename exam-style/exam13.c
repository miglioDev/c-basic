/*
EXAM 13 - Programming in C 

Implement the following functions and a main program.


### 1. File Loading and Row Swap Function

Write a function that:

* Takes as input:

  * a square matrix of integers,
  * the name of a text file.
* Reads integers from the file and stores them into the matrix (the file contains exactly enough values to fill the matrix).
* Closes the file.
* After loading, swaps the contents of the first two rows of the matrix.
* Does not return any value.

**Example**

File content (one integer per line):

```
2
8
14
20
4
10
16
22
6
12
18
24
8
14
20
26
```

Resulting matrix after swapping the first two rows:

```
8   2   14  20
10  4   16  22
6   12  18  24
14  8   20  26
```

---

### 2. Matrix Display Function

Write a function that:

* Takes as input a square matrix of integers.
* Displays the matrix showing both row/column indices and values, arranged as in the example.
* Does not return any value.

**Example output format:**

```
    0   1   2   3
0 - 8   2   14  20
1 - 10  4   16  22
2 - 6   12  18  24
3 - 14  8   20  26
```

---

### 3. Minimum and Maximum Function (Using Pointers)

Write a function that, using pointers and pointer arithmetic:

* Takes as input:

  * a square matrix of integers,
  * two integer pointer parameters (`minVal`, `maxVal`).
* Stores in `minVal` the minimum value contained in the matrix.
* Stores in `maxVal` the maximum value contained in the matrix.
* Does not return any value.

**Example**

Given the matrix:

```
8   2   14  20
10  4   16  22
6   12  18  24
14  8   20  26
```

Result:

```
minVal = 2
maxVal = 26
```

---

### 4. Value Search Function

Write a function that:

* Takes as input:

  * a square matrix of integers,
  * an integer value to search.
* Returns `1` if the value is present in the matrix.
* Returns `0` otherwise.

**Example**

Search value `12` → returns `1`
Search value `5` → returns `0`

---

### 5. `main` Function

Write the `main` function that:

* Accepts **exactly two** command-line parameters:

  1. the name of the text file,
  2. the integer value to search in the matrix.
* If the number of parameters is incorrect, prints
  `"ERROR: invalid number of parameters"`
  and terminates returning `1`.
* Declares a square integer matrix with constant size.
* Calls the function that loads the matrix from the file and swaps the first two rows.
* Calls the function that displays the matrix.
* Calls the function that computes minimum and maximum values, then prints:
  `"maximum is ... minimum is ..."`
* Calls the function that searches for the value, then prints either:
  `"... is present in the matrix"`
  or
  `"... is not present in the matrix"`.
* Returns `0`.
*/

#include <stdio.h>

int main ()
{

    return 0;
}