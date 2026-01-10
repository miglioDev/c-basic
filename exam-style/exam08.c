/*
EXAM 08 - Programming in C

Implement the following functions and a main program

### Function 1 — Load matrix from file

A function that:

* Takes as input:

  * a square matrix of integers with fixed size `N`,
  * the name of a text file.
* Reads integers from the file and copies **only strictly positive odd values** into the matrix, filling it **column by column**.
* Stops reading when the matrix is full or the file ends, then closes the file.
* If the read values are not enough to fill the matrix, completes the remaining cells with `0`.
* Returns:

  * `10` if the matrix has been successfully loaded,
  * `-5` if the file does not exist or cannot be opened.

**Example**

File contents:
`3 14 7 -2 11 8 5 0 19 4 9 -6 13`

Resulting matrix (filled column by column with positive odd values):

```
3   5   9
7   19  13
11  0   0
```

---

### Function 2 — Display matrix with indices

A function that:

* Takes as input a square matrix of integers of size `N`.
* Prints the matrix values along with row and column indices, formatted as shown in the example.
* Does not return any value.

**Example output format (conceptual):**

```
      0    1    2
   -----------------
0 |   3    5    9
1 |   7   19   13
2 |  11    0    0
```

---

### Function 3 — Search value using pointer arithmetic

A function that:

* Uses **pointer arithmetic** only.
* Takes as input:

  * a square matrix of integers of size `N`,
  * an integer value `target`,
  * two output parameters `rowPos` and `colPos`.
* Scans the matrix **column by column**.
* Assigns to `rowPos` and `colPos` the indices of the **first occurrence** of `target`.
* If `target` is not present, assigns `-2` to both `rowPos` and `colPos`.
* Does not return any value.

**Example**

Given `target = 11` and the matrix:

```
3   5   9
7   19  13
11  0   0
```

Result:
`rowPos = 2`, `colPos = 0`

---

### Function 4 — Column sum

A function that:

* Takes as input:

  * a square matrix of integers of size `N`,
  * a column index.
* Returns:

  * `-10` if the column index is out of range,
  * otherwise, the sum of all values in the specified column.

**Example**

Column index: `1`
Matrix:

```
3   5   9
7   19  13
11  0   0
```

Result:
Sum = `24`

---

### `main` function

The `main` function must:

* Receive **exactly one command-line argument**, the name of a text file.

  * If the number of parameters is incorrect, print
    `"ERROR: invalid parameter count"`
    and terminate returning `100`.
* Declare a square matrix of constant size `N`.
* Call the matrix-loading function.

  * If loading fails, print
    `"ERROR: unable to open input file"`
    and terminate returning `200`.
* Call the function that displays the matrix.
* Ask the user to *“enter an integer value”*, then call the search function.

  * Print either
    `"The value ... was found at row ... and column ..."`
    or
    `"The value ... does not appear in the matrix"`.
* Ask the user to *“enter a column index”*, then call the column-sum function.

  * Print either
    `"The sum of column ... equals ..."`
    or
    `"Column index ... is out of range"`.
* Terminate by returning `0`.
*/

#include <stdlib.h>
#include <stdio.h>
#define C 4

int load_matrix(int m[C][C], char *argv[1])
{
  int i,j,result,x;
  FILE *fp;
  fp = fopen(argv[1], "r");

  if(fp == NULL) {
    result = 0; }

  else {
  i = 0;
  j = 0;
  result = 1;
  while(fscanf(fp, "%d", &x) != EOF) {
  if(x > 0 && x%2 == 1) {
    m[i][j] = x;
    j++;
      if(j == C)
      {
        j = 0;
        i++;
      }
  } } }
  
  while(i < C)
  {
    m[i][j] = 0;
    j++;
      if(j == C)
      {
        j = 0;
        i++;
      }

    fclose(fp);
  }

  return result;
}

void print_matrix(int m[][C])
{
  int i,j;
  printf("\n\t\t");
  for(i = 0; i < C; i++)
  {
    printf("%d\t",i);
  }

  printf("\n\t\t");
    for(i = 0; i < C; i++)
  {
    printf("-\t");
  }
  printf("\n");

  for(i = 0; i < C; i++)
  {
    printf("%d\t|",i);
    for(j = 0; j < C; j++)
    {
      printf("\t%d", m[i][j]);
    }
    printf("\n");
  }
}

void finder_matrix(int m[][C], int v, int *p1, int *p2)
{
  *(p1) = -1;
  *(p2) = -1;

  int i,j;
  for(j = 0; j < C; j++)
  {
    for(i = 0; i < C; i++)
    {
      if(m[i][j] == v && *p1 == -1) { 
        *(p1) = i;
        *(p2) = j;}
    }
  }
}

int column_sum(int m[][C], int column)
{
  int res = 0;
  if(column > C || column < 1) {
    res = -1; }

  else {
    for(int r = 0; r < C; r++) {
      res = res+m[r][column-1];
    }
  }

  return res;
}


int main (int argc, char *argv[])
{
  if(argc != 2) {
    printf("Error: file text missing\n");
    exit(1); }
  
  int m[C][C],v,addr1,addr2,column,c_sum;

  load_matrix(m,argv);
  print_matrix(m);

  printf("Enter a value to find on the matrix: ");
  scanf("%d", &v);

  finder_matrix(m,v,&addr1,&addr2);

  if(addr1 == -1) {
    printf("\nValue not foud"); }
    else {
      printf("One result: \nrow %d \ncolumn %d\n",addr1,addr2); }

  printf("Enter column to sum matrix: ");
  scanf("%d", &column);

  c_sum = column_sum(m,column);
  if(c_sum == -1) {
    printf("Error- invalid index\n"); }
    else{
      printf("The sum is %d\n",c_sum); }

  return 0;
}