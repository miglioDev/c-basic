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

  1. the name of a text file.
     If the number of parameters is incorrect, display
     `"ERROR 1: wrong number of parameters"`
     and terminate returning `1`.
* Declare an integer array of fixed size `10`.
* Call the function that loads the array from the file. If it fails, display
  `"ERROR 2: loading failed"`
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
#define C 30
#define R 10

int load_from_file(char m[][C], char *file_name)
{
  FILE *fp;
  fp = fopen(file_name, "r");
  int outcome,copied,len;

  if(fp == NULL) {
    outcome = 0; }

    else {
      copied = 0;
      char buffer[C];
      int cond1,cond2;


      while(fscanf(fp, "%s", buffer) != EOF && copied < R)
      {
        len = strlen(buffer);
        cond1 = 0;
        cond2 = 0;

        if(buffer[0] == 'A' || buffer[0] == 'E' || buffer[0] == 'I' || buffer[0] == 'O' || buffer[0] == 'U') {
          cond1 = 1; }
        if(buffer[len-1] == 'a' || buffer[len-1] == 'e' || buffer[len-1] == 'i' || buffer[len-1] == 'o' || buffer[len-1] == 'u') {
          cond2 = 1; }

        if(cond1 && cond2) {
          strcpy(m[copied],buffer);
          copied++; }

        fclose(fp);

        while(copied < R) 
        {
          m[copied][0] = '\0';
          copied++;
        }
      }

      outcome = 1;
    }

    return outcome;
}

int main(int argc, char *argv[])
{
  if(argc != 2) {
    printf("ERROR 1: wrong number of parameters\n");
    exit(1); }

  char m[R][C];
  int loaded;

  loaded = load_from_file(m,argv[1]);
  if(!loaded) {
    printf("ERROR 2: loading failed");
    exit(2); }

  return 0;
}

