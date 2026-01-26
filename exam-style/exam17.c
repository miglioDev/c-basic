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

#include <stdio.h>
#include <stdlib.h>
#define R 5
#define C 4

int load_matrix(int m[][C], char *file_name)
{
  FILE *fp;
  fp = fopen(file_name, "r");

  if(fp == NULL) {
    return 0; }

  else {
    int r,c;

    for(r = 0; r < R; r++) 
    {
      fscanf(fp,"%d" ,&m[r][0]); 
    }

    fclose(fp);

    for(r = 0; r < R; r++)
    {
      for(c = 1; c < C; c++)
      {
        m[r][c] = m[r][c-1]+1; 
      }
    }

    return 1;
  }
}

void print_matrix(int m[][C])
{
  int r,c;
  
  printf("\n\t\t");
  for(c = 0; c < C; c++)
  {
    printf("%d\t",c);
  }

  printf("\n\t\t");
  for(c = 0; c < C; c++)
  {
    printf("*\t");
  }
  printf("\n");

  for(r = 0; r < R; r++)
  {
    printf("%d\t*\t",r);
    for(c = 0; c < C; c++)
    {
      printf("%d\t",m[r][c]);
    }
    printf("\n");
  }
  printf("\n");
}

void search_on_matrix(int m[][C], int x, int *p1, int *p2)
{
  int r,c;
  *p1 = -1;
  *p2 = -1;

  for(c = 0; c < C; c++) 
  {
    for(r = 0; r < R; r++)
    {
      if(*p1 == -1 && m[r][c] == x) {
        *p1 = r;
        *p2 = c;
      }
    }
  }
}

int row_product(int m[][C], int row)
{
  int p = 1,c;

  if(0 <= row && row < R) {
    for(c = 0; c < C; c++)
    {
      p = p*m[row][c]; 
    } 
      return p; }

  else {
    return 1; }
}

int main(int argc, char *argv[])
{
  if(argc != 2) {
    printf("Error - file missing as argument\n");
    exit(1); }

  int m[R][C],res,x,i,j,row;

  res = load_matrix(m,argv[1]);
  if(res == 0) {
    printf("Error - file not found matrix not loaded\n");
    exit(2); }

  print_matrix(m);

  printf("Enter a number to search: ");
  scanf("%d",&x);

  search_on_matrix(m,x,&i,&j);
  if(i == -1) {
  printf("Value, not found\n"); }
    else {
      printf("Value found in:\n row: %d\n column: %d\n\n",i,j); }

  printf("Enter a row: ");
  scanf("%d",&row);

  res = row_product(m,row);
  if(res == 0) {
  printf("Error invalid row\n"); }
    else {
      printf("Row value: %d\n",res); }

  return 0;
}