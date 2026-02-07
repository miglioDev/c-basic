/*
EXAM 25 – Programming in C

Implement the following functions and a main program.


A function that
receives as input a square matrix of integers with constant size **N** and the name of a file.

The function reads a sequence of integer values from the file and copies into the matrix, row by row, only the values that are **negative and even**, until the matrix is completely filled.

If there are not enough valid values, the remaining cells of the matrix must be filled with **0**.

The function returns **1** if the file exists, otherwise it returns **0**.

---

A function that
receives as input a square matrix of integers with constant size **N**.

The function displays the matrix including row and column indices, formatted as in the following example:

```
    0   1   2
  -----------
0 |  7  -6   4
1 | -8   0  10
2 |  1   2  -3
```

The function does not return any value.

---

A function that, using **pointer arithmetic**,
receives as input a square matrix of integers of size **N**, an integer value **k**, and two parameters (**count**, **sum**).

The function assigns to **count** the number of occurrences of **k** inside the matrix.
It assigns to **sum** the total of all matrix elements strictly greater than **k**.

The function does not return any value.

---

A function that
receives as input a square matrix of integers of size **N** and two integers (**rowA**, **rowB**).

If **rowA** and **rowB** are valid indices, the function swaps the contents of the two corresponding rows.

The function returns **1** if the swap is performed, otherwise **0**.

---

The **main** function must:

* Receive **exactly two** command-line arguments:

  1. the name of a text file
  2. an integer value
     Otherwise, print
     **"ERROR 1: invalid number of parameters"**
     and terminate returning **1**.

* Declare a square matrix with constant size **N = 4**.

* Call the function that loads the matrix from the file.
  If loading fails, print
  **"ERROR 2: file not found"**
  and terminate returning **2**.

* Call the function that displays the matrix.

* Call the pointer-based statistics function using the second command-line argument as value **k**, then display:

  * **"The value ... appears ... times in the matrix"**
  * **"The sum of values greater than ... is ..."**

* Ask the user to **enter two row indices**, then call the swap function.
  Display either **"Swap completed"** or **"Invalid indices"**.

* Call again the function that displays the matrix after the swap.

* Return **0**.
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 4

int load_from_file(int m[][DIM], char *file_name)
{
  FILE *fp;
  fp = fopen(file_name, "r");

  if(fp == NULL) {
    return 0; }
  
  else {
    int x,r,c;
    r = 0;
    c = 0;

    while(fscanf(fp, "%d", &x) != EOF && r < DIM)
    {
      if(x%2 == 0 && x < 0) { 
        m[r][c] = x;
        c++;

        if(c == DIM) {
          r++;
          c = 0; }
      }
    }
    fclose(fp);

    while(r < DIM)
    {
      m[r][c] = 0;
      c++;

      if(c == DIM) {
        r++;
        c = 0;
      }
    }
  }

  return 1;
}

void visual_matrix(int m[][DIM])
{
  int r,c;

  printf("\n\t");
  for(c = 0; c < DIM; c++)
  {
    printf("%d\t",c);
  }

  printf("\n   -------------------------------\n");
  for(r = 0; r < DIM; r++)
  {
    printf("%d |\t",r);
    for(c = 0; c < DIM; c++)
    {
      printf("%d\t",m[r][c]);
    }
    printf("\n");
  }
}

void matrix_stats(int (*m)[DIM], int x, int *p1, int *p2)
{
  int r,c;
  *p1 = 0;
  *p2 = 0;

  for(r = 0; r < DIM; r++)
  {
    for(c = 0; c < DIM; c++)
    {
      if( *(*(m+r)+c) == x) {
        (*p1)++; }
    }
  }

  for(r = 0; r < DIM; r++)
  {
    for(c = 0; c < DIM; c++)
    {
      if( *(*(m+r)+c) > x) {
        (*p2) = (*p2)+x; }
    }
  }

  printf("\n");
}

int row_swapper(int m[][DIM], int row1, int row2)
{
  int valid,k,c;
  valid = 1;

  if((row1 < 0 || row1 >= DIM) || (row2 < 0 || row2 >= DIM)) {
    valid = 0; }
  
  if(valid) {
    for(c = 0; c < DIM; c++)
    {
      k = m[row1][c]; 
      m[row1][c] = m[row2][c];
      m[row2][c] = k;
    }
  }

  return valid;
}

int main(int argc, char *argv[]) // ./a filename number
{
  if(argc != 3) {
    printf("ERROR 1: invalid number of parameters\n");
    exit(1); }

  int m[DIM][DIM],load_f,a,b,x,row1,row2,valid_row;

  load_f = load_from_file(m,argv[1]);
  if(load_f == 0) {
    printf("ERROR 2: file not found\n");
    exit(2); }

  visual_matrix(m);

  x = atoi(argv[2]);
  matrix_stats(m,x,&a,&b);
  printf("Number %d found %d times\n",x,a);
  printf("The sum of the values in the matrix greater than %d is %d\n",x,b);

  printf("Great now pick two row to swap:\n");
  printf("row 1 = ");
  scanf("%d", &row1);
  printf("row 2 = ");
  scanf("%d", &row2);
  valid_row = row_swapper(m,row1,row2);
  if(valid_row == 0) {
    printf("Swap not completed, invalid row\n");}

  visual_matrix(m);

  return 0;
}