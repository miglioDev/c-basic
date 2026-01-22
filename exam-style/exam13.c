/*
EXAM 13 - Programming in C 

Implement the following functions and a main program.


### 1. File Loading and Row Swap Function

Write a function that:

* Takes as input:

  * a square matrix of integers,
  * the name of a text file.
* Reads integers from the file and stores them into the matrix (The file contains exactly enough values to fill the matrix).
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
#include <stdlib.h>
#define R 4
#define C 4

void load_matrix(int m[][C], char *file_name)
{
  FILE *fp;
  fp = fopen(file_name, "r");

  if(fp == NULL) {
    printf("Error - file\n");
    return; }
  
  else {
    int r,c,k;
    char x[31];
    for(r = 0; r < R; r++)
    {
      for(c = 0; c < C; c++)
      {
        fscanf(fp,"%s",x);
        m[r][c] = atoi(x);
      }
    }
    fclose(fp);

    for(c = 0; c < C; c++)
    {
      k = m[0][c];
      m[0][c] = m[1][c];
      m[1][c] = k;
    }
  }
}

void print_matrix(int m[][C])
{
  int r,c;

  printf("\n\t\t");
  for(r = 0; r < R; r++)
  {
    printf("%d\t",r);
  }
  printf("\n\t\t");
  for(r = 0; r < R; r++)
  {
    printf("-\t");
  }

  printf("\n");
  for(r = 0; r < R; r++)
  {
    printf("%d\t|\t",r);
    for(c = 0; c < C; c++)
    {
      printf("%d\t",m[r][c]);
    }
    printf("\n");
  }
}

void max_and_min(int m[][C], int *p1, int *p2)
{
  *p1 = m[0][0];
  *p2 = m[0][0];
  int r,c;

  for(r = 0; r < R; r++)
  {
    for(c = 0; c < C; c++)
    {
      if(*p1 > *(*(m+r)+c) ) {
        *p1 = *(*(m+r)+c); }

      if(*p2 < *(*(m+r)+c)) {
        *p2 = *(*(m+r)+c); }
    }
  }
}

int search_matrix(int m[][C], int z)
{
  int present = 0,r,c;

  for(r = 0; r < R; r++)
  {
    for(c = 0; c < C; c++)
    {
      if(m[r][c] == z) {
        present = 1; }
    }
  }

  return present; 
}

int main (int arc, char *argv[]) //file name and value for m 
{
  if(arc != 3) {
    printf("ERROR: invalid number of parameters");
    exit(1); }
  
  int m[R][C],min,max,z;
  
  load_matrix(m,argv[1]);
  print_matrix(m);
  max_and_min(m,&min,&max);

  printf("\nMin = %d",min);
  printf("\nMax = %d",max);

  z = search_matrix(m,atoi(argv[2]));
  if(z) {
  printf("\nThe value is present in the matrix\n"); }
    else {
      printf("\nValue not found"); }

    return 0;
}