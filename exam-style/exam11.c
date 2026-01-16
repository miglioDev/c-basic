/*
EXAM 11 - Programming in C

Implement the following functions and a main program


**Function 1**

A function that:

* takes as input an array of integers, its maximum capacity, and the name of a text file;
* asks the user to “enter an integer value” (`n`);
* reads integers from the file and copies into the array only the *strictly positive* numbers that are divisors of `n`, checking that there is still available space in the array;
* places the value `-1` as a sentinel at the end of the array and closes the file;
* returns `0` if the file cannot be opened, otherwise returns `1`.

Example:
`n = 84`
File contents: `6 11 14 -3 4 0 21 -8 7 28 5`
Resulting array: `6 14 4 21 7 28 -1`

---

**Function 2**

A function that:

* takes as input an integer array terminated by a sentinel (`-1`);
* returns `0` if the array is empty;
* otherwise prints the indices and the corresponding values on two separate lines (as shown in the example) and returns `1`.

Example output:

```
indices:
0 1 2 3 4
values:
6 14 4 21 7
```

---

**Function 3**

A function that, using pointers and pointer arithmetic:

* takes as input an integer array with sentinel and two parameters (`minVal`, `maxVal`);
* stores in `minVal` the minimum value contained in the array;
* stores in `maxVal` the maximum value contained in the array.

Example:
Array: `6 14 4 21 7 -1` → `minVal = 4`, `maxVal = 21`

The function does not return any value.

---

**Function 4**

A function that:

* takes as input an integer array with sentinel;
* if the array has odd length, removes the element in the middle of the array.

Example:
`6 14 4 21 7 -1` → `6 14 21 7 -1`

The function does not return any value.

---

**`main` Function**

The `main` function:

* must receive exactly one command-line argument: the name of the text file. Otherwise, it prints
  `"ERROR 1: invalid number of parameters"`
  and terminates returning `1`;
* declares an integer array of fixed size 10;
* calls the function that loads the array. If the file does not exist, it prints
  `"ERROR 2: file not found"`
  and terminates returning `2`;
* calls the function that prints the array. If the array is empty, it prints
  `"ERROR 3: empty array"`
  and terminates returning `3`;
* calls the function that computes the minimum and maximum values, then prints
  `"minimum is ...; maximum is ..."` ;
* calls the function that removes the central element (if applicable);
* calls again the function that prints the array. If the array is empty, it prints
  `"ERROR 3: empty array"`
  and terminates returning `3`;
* returns `0`.
*/

#include <stdlib.h>
#include <stdio.h>
#define DIM 10

int file_loading(int v[DIM], char *file_name)
{
  int x,y,copied = 0;

  printf("Enter a value x: ");
  scanf("%d", &x);

  FILE *fp;
  fp = fopen(file_name, "r");

  if(fp == NULL) {
    return 0; }

  else {
    while(fscanf(fp, "%d", &y) != EOF && copied < DIM-1)
    {
      if(y > 0 && y%x == 0)
      {
        v[copied] = y;
        copied++;
      }
    }
    v[copied] = -1;
    return 1;
  }
}

int print_vec(int v[DIM])
{
  int i;
  if(v[0] == -1) {
    return 0; }
      else {
        printf("\nIndex: ");
        for(i = 0; i < DIM; i++)
        {
          printf("\t%d",i); 
        }
        printf("\nValue: ");
        for(i = 0; i < DIM; i++)
        {
          printf("\t%d",v[i]);
        }
        return 1;
      }
}

int main (int argc, char *argv[])
{
  if(argc != 2) {
    printf("ERROR 1: invalid number of parameters\n");
    exit(1); }

  int v[DIM],res;

  res = file_loading(v,argv[1]);
  if(res == 0) {
  printf("ERROR 2: file not found");
  exit(2); }
  
  res = print_vec(v);
  if(res == 0) {
    printf("ERROR 3: empty array\n");
    exit(3); }

    return 0;
}