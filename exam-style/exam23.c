/*
EXAM 23 – Programming in C

Implement the following functions and a main program.


**1. Matrix initialization function**

A function that:

* Takes as input a matrix of integers and an integer value `start`.
* Assigns `start` to the first element of the matrix.
* Fills the remaining elements with the next even numbers after `start`, proceeding row by row.

Example (with `start = 6`):

Matrix (5 × 5):

```
 6  16  26  36  46
 8  18  28  38  48
10  20  30  40  50
12  22  32  42  52
14  24  34  44  54
```

The function does not return any value.

---

**2. Matrix display function**

A function that:

* Takes as input a matrix of integers.
* Prints the indices and the values of the matrix arranged as shown in the example.

Example output format:

```
    0   1   2   3   4
  --------------------
0 |  6  16  26  36  46
1 |  8  18  28  38  48
2 | 10  20  30  40  50
3 | 12  22  32  42  52
4 | 14  24  34  44  54
```

The function does not return any value.

---

**3. Border and inner sum function (using pointers)**

A function that, using pointers and pointer arithmetic:

* Takes as input a matrix of integers and two integer parameters `outBorder` and `outInner`.
* Stores in `outBorder` the sum of the elements on the matrix border (first and last row, first and last column).
* Stores in `outInner` the sum of the elements inside the border.

Example (using the matrix above):

```
outBorder = 500
outInner  = 300
```

The function does not return any value.

---

**4. File writing function**

A function that:

* Takes as input a matrix of integers, two integer values `low` and `high`, and a file name.
* If `low` is less than `high`, writes to the file all matrix values between `low` and `high` (inclusive),
  ordered by column.
* Closes the file after writing.

Example:

Matrix as above
`low = 16`, `high = 30`

File content:

```
16 26 18 28 20 30 22 24 26
```

The function returns the number of values written to the file (9 in the example).

---

**5. `main` function**

The `main` function must:

* Receive exactly two command-line parameters:

  1. An integer value.
  2. A file name.
     If the number of parameters is incorrect, print
     `"ERROR 1: wrong number of parameters"`
     and terminate returning `1`.
* Check that the first parameter is strictly positive and even.
  Otherwise, print
  `"ERROR 2: value is not valid"`
  and terminate returning `2`.
* Declare a square matrix of fixed size 5 × 5.
* Call the matrix initialization function, passing the first parameter.
* Call the matrix display function.
* Call the sum calculation function, then print:
  `"border sum = ... , inner sum = ..."`
* Ask the user to input two integer values.
* Call the file writing function and then print:
  `"... values written to the file ..."`
* Terminate returning `0`.
*/

#include <stdio.h>
#include <stdlib.h>

#define DIM 5

void load_matrix(int m[][DIM], int x)
{
  int r,c,even;
  even = x;

  for(r = 0; r < DIM; r++)
  {
    for(c = 0; c < DIM; c++)
    {
      m[r][c] = even;
      even = even+2;
    }
  }
}

void print_matrix(int m[][DIM])
{
  int r,c;

  printf("\n");
  for(r = 0; r < DIM; r++)
  {
    printf("%d\t|",r);
    for(c = 0; c < DIM; c++)
    {
      printf("\t%d",m[r][c]);
    }
    printf("\n");
  }

  printf("\t\t");
  for(c = 0; c < DIM; c++)
  {
  printf("-\t");
  }

  printf("\n\t");
  for(c = 0; c < DIM; c++)
  {
  printf("\t%d",c);
  }
}

void sum_matrix(int m[][DIM], int *p1, int *p2)
{
  int r,c;

  *p1 = 0;
  *p2 = 0;

  for(r = 0; r < DIM; r++)
  {
    for(c = 0; c < DIM; c++)
    {
      if(r == 0 || r == DIM-1 || c == 0 || c == DIM-1) {
      *p1 = *p1 + *(*(m+r)+c); }
      
        else {
        *p2 = *p2 + *(*(m+r)+c); }
    }
  }
}

int write_on_file(int m[][DIM], int a, int b, char *file_name)
{
  int counter,c,r;

  FILE *fp;

  if(a < b) 
  {
    counter = 0;
    fp = fopen(file_name, "w");

    for(c = 0; c < DIM; c++)
    {
      for(r = 0; r < DIM; r++)
      {
        if(m[r][c] >= a && m[r][c] <= b) {
          fprintf(fp,"%d\t", m[r][c]);
          counter++;
        }
      }
    }
    fclose(fp);
  }

  return counter;
}

int main(int argc, char *argv[])
{
  if(argc != 3) {
    printf("ERROR 1: wrong number of parameters\n");
    exit(1); }

  int x,out_border,inner,a,b,copied;
  x = atoi(argv[1]);

  if(x <= 0 || x%2 == 1) {
    printf("ERROR 2: value is not valid\n");
    exit(2); }

  int m[DIM][DIM];

  load_matrix(m,x);
  print_matrix(m);

  sum_matrix(m,&out_border,&inner);
    printf("\n\nThe sum of the out border value is: %d\n",out_border);
    printf("The sum of the inner value of the matrix is: %d\n",inner);

  printf("Enter two values\n");
  printf("Value one: ");
  scanf("%d", &a);
  printf("\nValue two: ");
  scanf("%d", &b);

  copied = write_on_file(m,a,b,argv[2]);
    printf("\n%d values have benn copied on file %s\n",copied,argv[2]);

  return 0;
}
