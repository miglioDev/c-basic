/*
EXAM 20 – Programming in C

Implement the following functions and a main program.


**Function 1 — Load matrix from file**

The function:

* Takes as input:

  * a matrix of integers,
  * two integer values `low` and `high`,
  * the name of a text file.
* If the file exists, it reads integers from the file and copies into the matrix, row by row, **only** the values that are:

  * positive, and
  * within the inclusive range `[low, high]`.
* Before inserting each value, it must check that there is still available space in the matrix.
* After reading, it closes the file.
* If the matrix is not completely filled, the remaining cells must be filled with `0`.
* Returns `1` if the file exists, otherwise returns `0`.

*Example*
`low = 15`, `high = 28`

File content (example):
`-10 15 14 22 18 29 16 27 30 21 19 8 25 26 17 31 20 23 ...`

Resulting matrix (example):

```
15 22 18 16 27
21 19 25 26 17
20 23 0  0  0
0  0  0  0  0
0  0  0  0  0
```

---

**Function 2 — Display matrix**

The function:

* Takes as input a matrix of integers.
* Displays row and column indices together with the matrix values, arranged as shown in the example.
* Does not return any value.

*Example output format*:

```
    0   1   2   3   4
0 |  -  15  22  18  16
1 |  -  21  19  25  26
2 |  -  20  23   0   0
3 |  -   0   0   0   0
4 |  -   0   0   0   0
```

---

**Function 3 — Column sum and average (using pointers)**

The function:

* Takes as input:

  * a matrix of integers,
  * a column index `col`,
  * two pointer parameters `outSum` and `outAvg`.
* Using pointer arithmetic:

  * Stores in `outSum` the sum of the values in column `col`.
  * Stores in `outAvg` the average of the values in column `col`.
* If `col` is not compatible with the matrix dimensions, stores `-1` in both `outSum` and `outAvg`.
* Does not return any value.

*Example*
Given column `col = 1`:

```
outSum = 98
outAvg = 19.6
```

---

**Function 4 — Compare diagonals**

The function:

* Takes as input a square matrix of integers.
* Returns `1` if the main diagonal and the secondary diagonal contain exactly the same values in the same order.
* Otherwise, returns `0`.

*Example*
If both diagonals contain identical sequences of values → return `1`.

---

**`main` function**

The `main` function:

* Accepts **exactly three** command-line parameters:

  1. a first integer value,
  2. a second integer value,
  3. the name of a text file.
* If the number of parameters is incorrect, prints:
  `"ERROR 1: invalid number of parameters"`
  and terminates returning `1`.
* Checks that the first two parameters are valid integers and that the first is strictly less than the second.
  If not, prints:
  `"ERROR 2: parameters are not valid integers"`
  and terminates returning `2`.
* Declares a square matrix whose dimension is a fixed **odd constant** (for example, `7`).
* Calls the matrix-loading function using the input parameters.
  If the file does not exist, prints:
  `"ERROR 3: file <filename> not found"`
  and terminates returning `3`.
* Calls the function that displays the matrix.
* Prompts the user to enter a column index, then calls the function that computes sum and average.
  Displays either:

  * `"the sum of column X is Y and the average is Z"`, or
  * `"column X does not exist"`.
* Calls the function that compares the two diagonals and displays either:

  * `"the diagonals contain the same values"`, or
  * `"the diagonals contain different values"`.
* Terminates returning `0`.
*/

