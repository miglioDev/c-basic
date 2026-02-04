/*
EXAM 22 – Programming in C

Implement the following functions and a main program.


**Function 1**

This function:

* Receives as input:

  * an array of integers,
  * an integer value `n`,
  * the name of a text file.
* Reads integers from the file and copies into the array only the *positive divisors* of `n`, checking that there is still available space in the array.
* Closes the file.
* Appends the value `-1` as a sentinel (array terminator).
* Returns:

  * `0` if the file cannot be opened or if no values were copied into the array,
  * `1` otherwise.

*Example*
If `n = 18` and the file contains:
`7 9 4 -2 1 6 5 3 12 18 -9`
the resulting array will contain:
`9 1 6 3 18`

---

**Function 2**

This function:

* Receives as input an array of integers terminated by `-1`.
* Displays indices and corresponding values arranged in two columns, as shown in the example.
* Does not return any value.

*Example output format*:

```
index   value
0       9
1       1
2       6
3       3
4       18
```

---

**Function 3**

This function, implemented using *pointer arithmetic*:

* Receives as input:

  * an array of integers terminated by `-1`,
  * two parameters `outOdd` and `outEven` (passed by reference).
* Assigns to:

  * `outOdd` the product of all odd values in the array, or `-1` if no odd values are present;
  * `outEven` the product of all even values in the array, or `-1` if no even values are present.
* Does not return any value.

*Example*
Array: `9 1 6 3 18`
Results:
`outOdd = 27`
`outEven = 108`

---

**Function 4**

This function:

* Receives as input:

  * an array of integers terminated by `-1`,
  * an integer value `n`.
* If `n` appears *exactly once* in the array and there is still space available, duplicates that value by inserting an additional occurrence immediately after it.
* Returns:

  * `1` if the array content was modified,
  * `0` otherwise.

*Examples*

* `n = 6`, array: `9 1 6 3 18` → array becomes: `9 1 6 6 3 18`
* `n = 4`, array: `9 1 6 3 18` → array unchanged

---

**`main` Function**

The `main` function must:

* Receive *exactly two* command-line arguments:

  1. an integer value,
  2. the name of a text file.
     If the number of parameters is incorrect, display
     `"ERROR 1: wrong number of parameters"`
     and terminate returning `1`.
* Verify that the first parameter is a valid integer. If not, display
  `"ERROR 2: <parameter> is not a number"`
  and terminate returning `2`.
* Declare an integer array of fixed size `10`.
* Call the function that loads the array from the file. If it fails, display
  `"ERROR 3: loading failed"`
  and terminate returning `3`.
* Call the function that displays the array.
* Call the function that computes the products, then display:

  * `"the product of odd values is ..."` or `"there are no odd values"`,
  * `"the product of even values is ..."` or `"there are no even values"`.
* Ask the user to *“enter a value”*, then call the duplication function.
* If the array was modified, display the array again.
* Return `0`.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SENTINEL -1
#define DIM 10

int load_from_file(int v[DIM], int x, char *file_name)
{
  FILE *fp;
  fp = fopen(file_name, "r");
  int outcome,temp,copied;

  if(fp == NULL) {
    outcome = 0; }

    else {
      copied = 0;

      while(fscanf(fp, "%d", &temp) != EOF && copied < DIM-1)
      {
        if(temp > 0 && (temp%x) == 0) {
          v[copied] = temp;
          copied++; 
          outcome = 1;
        }
      }
        
      fclose(fp);

      v[copied] = SENTINEL;
    }

    return outcome;
}

void visual_vector(int v[DIM])
{
  int i;

  printf("\nIndex:\tValues:\n");
  for(i = 0; v[i] != SENTINEL; i++)
  {
    printf("%d\t%d\n",i,v[i]);
  }
}

void even_and_odd(int v[DIM], int *p1, int *p2)
{
  int i;
  *p1 = -1;
  *p2 = -1;

  for(i = 0; v[i] != SENTINEL; i++)
  {
    if(v[i]%2 == 0) {
      if(*p1 == -1) 
        *p1 = *(v+i); 
        else 
        *p1 = (*p1) * (*(v+i)); }

    else {
      if(*p2 == -1) 
      *p2 = *(v+i); 
        else 
        *p2 = (*p2) * (*(v+i)); }
  }
}

int value_duplication(int v[DIM], int x)
{
  int i,pres,pos,last_index,outcome;
  pres = 0;
  outcome = 0;

  for(i = 0; v[i] != SENTINEL; i++)
  {
    if(v[i] == x) {
      pres++;
      pos = i; }
    last_index = i;
  }

  if(last_index < DIM-1 && pres == 1) {
    for(i = last_index += 2; i > pos; i--) 
    {
      v[i] = v[i-1];
    }
    outcome = 1;
  }

  return outcome;
}

int main(int argc, char *argv[])
{
  if(argc != 3) {
    printf("ERROR 1: wrong number of parameters\n");
    exit(1); }

  int x = atoi(argv[1]); 
  if(x == 0) {
    printf("ERROR 2: %s is not a number\n",argv[1]);
    exit(2); }

  int v[DIM],loaded,m_even,m_odd,y,mod;

  loaded = load_from_file(v,x,argv[2]);
  if(!loaded) {
    printf("ERROR 3: loading failed\n");
    exit(3); }
  
  visual_vector(v);
  
  even_and_odd(v,&m_even,&m_odd);

  if(m_even == -1) {
  printf("There are no even values\n"); }
    else {
    printf("The result is: %d (even)\n",m_even); }

  if(m_odd == -1) {
  printf("There are no even values\n"); }
    else {
    printf("The result is: %d (odd)\n",m_odd); }

  printf("Enter a value: ");
  scanf("%d", &y);

  mod = value_duplication(v,y);
  if(mod) {
  visual_vector(v); }

  return 0;
}

