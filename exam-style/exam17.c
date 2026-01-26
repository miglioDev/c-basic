/*
EXAM 17 – Programming in C

Implement the following functions and a main program.


### Function 1 — Load and initialize the matrix

Write a function that:

* Takes as input:

  * a two-dimensional integer matrix,
  * the name of a text file.
* If the file with the given name **does not exist**, returns `0`.
* If the file **exists**:

  * opens the file,
  * reads integer values from the file and stores them in the **first column** of the matrix (up to the number of rows),
  * closes the file,
  * automatically fills the remaining columns such that:

    * each element in a column is equal to the value in the **previous column plus one**.
* Returns `1` when the matrix has been successfully filled.

**Example (5 rows, 4 columns)**

```
2   3   4   5
3   4   5   6
6   7   8   9
10  11  12  13
14  15  16  17
```

---

### Function 2 — Display the matrix with indices

Write a function that:

* Takes as input a matrix of integers.
* Displays the matrix values together with their **row and column indices**, following the layout shown in the example.
* Does not return any value.

**Example output**

```
        0   1   2   3
      ****************
0  *    2   3   4   5
1  *    3   4   5   6
2  *    6   7   8   9
3  *   10  11  12  13
4  *   14  15  16  17
```

---

### Function 3 — Search for a value in the matrix

Write a function that:

* Takes as input:

  * a matrix of integers,
  * an integer value `target`,
  * two integer parameters passed by reference (`rowIndex`, `colIndex`).
* Searches for `target` in the matrix **column by column**.
* If the value is found:

  * stores in `rowIndex` and `colIndex` the position (row, column) of the **first occurrence**.
* If the value is not found:

  * stores `-1` in both `rowIndex` and `colIndex`.
* Does not return any value.

**Example**

* Target value: `5`
* Result: `rowIndex = 1`, `colIndex = 2`

---

### Function 4 — Compute the product of a matrix row

Write a function that:

* Takes as input:

  * a matrix of integers,
  * the index of a row.
* If the row index is **valid** with respect to the matrix dimensions:

  * returns the **product of all values** in that row.
* If the row index is **invalid**:

  * returns `-1`.

**Example**

* Row index: `1`
* Resulting product: `360`

---

### `main` function

Write a `main` function that:

* Receives **exactly one command-line argument**, representing the name of the input file.

  * If the number of arguments is incorrect, prints an appropriate error message and terminates.
* Declares a matrix with **5 rows and 4 columns**, whose dimensions are defined using constants.
* Calls the matrix loading function.

  * If the matrix cannot be loaded, prints an error message and terminates.
* Calls the function that displays the matrix.
* Asks the user to enter an integer value to search in the matrix.

  * Calls the search function and prints the result.
* Asks the user to enter a row index.

  * Calls the function that computes the product of the row and prints the result.
*/
