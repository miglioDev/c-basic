/*
EXAM 26 – Programming in C

Implement the following functions and a main program.


## A function that

• receives as input a square matrix of integers of constant size C and the name of a file.

• Reads the integer values from the file and copies into the matrix only those that are **multiples of 3 and strictly greater than 10**, inserting them **row by row**. If the file ends before the matrix is completely filled, it fills the remaining cells with -1.

• Closes the file.

• Returns 1 if the file exists, 0 otherwise.

Example:
file: 12 5 9 15 21 0 18 6 30 33 27 24
4x4 matrix:

```
12 15 21 18
30 33 27 24
-1 -1 -1 -1
-1 -1 -1 -1
```

## A function that

• receives as input a square matrix of integers of size C.

• Displays the matrix with row and column indices, as in the example, omitting the -1 values (replacing them with a space).

Example:

```
    0   1   2   3
  +---------------
0 | 12 15 21 18
1 | 30 33 27 24
2 |
3 |
```

• Returns nothing.

## A function that, using pointer arithmetic,

• receives as input a square matrix of integers of size C, an integer value k, and two pointers p1 and p2.

• Scans the matrix **column by column** and stores in p1 the number of even values greater than k, and in p2 the number of odd values less than k.

• Returns nothing.

Example:
k = 20
matrix as above → p1: 3 (12, 18, 24)  p2: 1 (15)

## A function that

• receives as input a square matrix of integers of size C.

• Returns 1 if the sum of the elements of each row is increasing with respect to the row index, 0 otherwise.

Example:
row 0: sum = 66
row 1: sum = 114 → increasing → returns 1

## The main function that

• receives from the command line exactly two parameters:

1. the name of a text file;
2. an integer value k.

• Otherwise, it displays “ERROR 1: incorrect number of parameters” and terminates returning 1.

• Declares a square matrix of constant size 4.

• Calls the loading function: if it fails, it displays “ERROR 2: the file does not exist” and terminates returning 2.

• Calls the display function.

• Calls the function that, using pointers, counts the values based on k, and displays:
“Even greater than …: … – Odd less than …: …”.

• Calls the function that checks the trend of the row sums, and displays:
“The row sums are increasing” or “The row sums are not increasing”.

• Returns 0.
*/
#include <stdio.h>
#include <stdlib.h>
#define DIM 4

int load_from_file(int m[][DIM], char *file_name)
{
  FILE *fp;
  fp = fopen(file_name,"r");

  if(fp == NULL) {
    return 0; }

  else {
      int r,c,x;
      r = 0;
      c = 0;

      while(fscanf(fp, "%d", &x) != EOF && r < DIM)
      {
        if(x > 10 && x%3 == 0) {
          m[r][c] = x;
          c++; }

          if(c == DIM) {
            c = 0;
            r++; }
      }
      fclose(fp);

      while(r < DIM)
      {
        m[r][c] = -1;
          c++; 

        if(c == DIM) {
        c = 0;
        r++;}
      } 
    }
      
    return 1;
}

void print_matrix(int m[][DIM])
{
  int r,c;

  printf("\n\t");
  for(c = 0; c < DIM; c++)
  {
    printf("%d\t",c);
  }
  printf("\n  +-------------------------------\n");

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

void matrix_stats(int (*m)[DIM], int k, int *p1, int *p2)
{
  int r,c;
  *p1 = 0;
  *p2 = 0;

  for(r = 0; r < DIM; r++)
  {
    for(c = 0; c < DIM; c++)
    {
      if( *(*(m+r)+c) > k && *(*(m+r)+c)%2 == 0)
      {
        (*p1)++; }

      if(*(*(m+r)+c) < k && *(*(m+r)+c)%2 == 1) {
        (*p2)++; }
    }
  }
}

int sum_inc(int m[][DIM])
{
  int inc,r,c,sum1,sum2;
  inc = 1;
  sum1 = 0;
  sum2 = 0;

  for(r = 0; r < DIM-1 && inc; r++)
  {
    for(c = 0; c < DIM && inc; c++)
    {
      sum1 = sum1+m[r][c];
      sum2 = sum2+m[r+1][c];
    }

    if(sum1 > sum2) {
      inc = 0; }
    sum1 = 0;
    sum2 = 0;
  }

  return inc;
}

int main(int argc, char *argv[])
{
  if(argc != 3) {
    printf("ERROR 1: incorrect number of parameters");
    exit(1); }

  int m[DIM][DIM],res,a,b,k,incr;

  res = load_from_file(m,argv[1]);
  if(res == 0) {
    printf("ERROR 2: the file does not exist\n");
    exit(2); }

  print_matrix(m);

  k = atoi(argv[2]);
  matrix_stats(m,k,&a,&b);
  printf("\nGreater than %d and even = %d",k,a);
  printf("\nLess than %d and odd = %d",k,b);

  incr = sum_inc(m);
  if(incr) {
  printf("\nThe row sums are increasing"); }
    else {
    printf("\nThe row sums are NOT increasing"); }

  return 0;
}