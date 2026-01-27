/*
EXAM 01 – Programming in C

Implement the following functions and a main program.


### Function 1 — Load filtered values from file

Write a function that:

* Takes as input:

  * an integer array `data`,
  * the maximum size of the array `size`,
  * an integer threshold `limit`,
  * a pointer to an open text file.
* Reads integers from the file and copies into the array only the values that are:

  * **positive**,
  * **strictly greater than `limit`**,
  * and only while there is still space available in the array.
* Appends the value `-1` as a **sentinel** to indicate the end of valid data.
* Returns:

  * `1` if the file contains no values,
  * `0` otherwise.

**Example**

* `limit = 12`
* File content:
  `18 5 9 25 -3 12 4 0 31 -8 18 -50 25`
* Resulting array:
  `18 25 31 18 25 -1`

---

### Function 2 — Display the array with sentinel

Write a function that:

* Takes as input an integer array terminated by the sentinel `-1`.
* If the array contains no valid values, prints:
  `"empty array"`.
* Otherwise, displays the content of the array by printing:

  * indices in one column,
  * corresponding values in another column,
    following the format shown in the example.
* Does not return any value.

**Example output**

indices:      values:
0             18
1             25
2             31
3             18
4             25

---

### Function 3 — Count matching values using pointers

Write a function that **uses pointers and pointer arithmetic** and:

* Takes as input:

  * an integer array terminated by `-1`,
  * an integer value `key`,
  * two integer parameters passed by reference (`countEq`, `countDiff`).
* Stores in:

  * `countEq` the number of elements in the array equal to `key`,
  * `countDiff` the number of elements different from `key`.
* Does not return any value.

**Example**

* `key = 25`
* Array: `18 25 31 18 25 -1`
* Result:
  `countEq = 2`, `countDiff = 3`

---

### Function 4 — Check array symmetry

Write a function that:

* Takes as input an integer array terminated by `-1`.
* Returns:

  * `1` if the array contains **at least two values** and is **symmetric**
    (the first half is equal to the second half),
  * `0` otherwise.

**Examples**

* `18 25 31 18 25 -1` → `1` (symmetric)
* `18 25 31 18 30 -1` → `0` (not symmetric)

---

### `main` function

Write a `main` function that:

* Receives **exactly two command-line arguments**:

  1. the name of a text file,
  2. an integer value.
* If the number of arguments is incorrect:

  * prints `"ERROR 1: invalid number of arguments"`
  * terminates returning `1`.
* Checks whether the file exists.

  * If not, prints `"ERROR 2: file <name> not found"`
  * terminates returning `2`.
* Checks whether the second argument represents a valid integer.

  * If not, prints `"ERROR 3: <value> is not a valid number"`
  * terminates returning `3`.
* Declares an integer array of size **40** (defined as a constant).
* Calls the function that loads data from the file.

  * Then prints `"the file is empty"` or `"the file is not empty"`.
  * Closes the file.
* Calls the function that displays the array.
* Asks the user to **enter an integer value**.

  * Calls the counting function and prints how many values are equal to and different from the entered value.
* Calls the function that checks whether the array is symmetric.

  * Prints `"the array is symmetric"` or `"the array is not symmetric"`.
* Terminates returning `0`.

  */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define DIM 40

int copy_from_file(int v[],int dim, int x, FILE *fp)
{
  int i = 0,value;

  while(fscanf(fp, "%d", &value) != EOF && i < DIM-1)
  {                                                    
    if(value > 0 && value > x) {
      v[i] = value;
      i++; }
  }

  if(i == 0) {
    v[0] = -1;
    return 1; }
  
  else {
    v[i] = -1;   // sentinel value
    return 0; }
}

void print_vector(int v[DIM])
{
  int i;

  if(v[0] == -1) {
    printf("Empty array\n");
    return; }

  else {
    printf("\nIndex:\tValue:\n");
    for(i = 0; v[i] != -1; i++)
    {
      printf("%d\t%d\n",i,v[i]);
    }
  }
}

void difference(int *v, int number, int *p1, int *p2)
{
  *p1 = 0;
  *p2 = 0;

  int i;

  for(i = 0; *(v+i) != -1; i++)
  {
    if(*(v+i) == number) {
    (*p1)++; }
      else {
      (*p2)++; }
  }
}

int simmetry(int v[DIM])
{
  int i,j = -1,sim = 1;

  for(i = 0; v[i] != -1; i++)
  { 
    j++;           //j last index 
  }

  if(j < 1) {
    sim = 0; }

  for(i = 0; i < j && sim; i++)
  {
    if(v[i] != v[j]) {
      sim = 0; }
    j--;
  }

  return sim;
}

int main(int argc, char *argv[])
{
  if(argc != 3) {
    printf("ERROR 1: invalid number of arguments");
    exit(1); }

  FILE *fp;
  fp = fopen(argv[1], "r");

  if(fp == NULL) {
    printf("ERROR 2: file %s not found",argv[1]);
    exit(2); }

  int const dim = 40;
  int x,res,number,equal,non_equal;
  x = atoi(argv[2]);

  if(x == 0) {
    printf("ERROR 3: %s is not a valid number",argv[2]);
    exit(3); }

  int v[dim];

  res = copy_from_file(v,dim,x,fp);
  if(res == 1) {
    printf("the file is empty\n"); }

  else {
    printf("the file is not empty\n"); }
  
  fclose(fp);

  print_vector(v);

  printf("Enter a number: ");
  scanf("%d",&number);

  difference(v,number,&equal,&non_equal);
  printf("\nEqual = %d",equal);
  printf("\nNon equal = %d",non_equal);

  res = simmetry(v);

  if(res == 0) {
  printf("\nNon simmetric"); }
    else {
      printf("\nSimmetric");}

  return 0;
}