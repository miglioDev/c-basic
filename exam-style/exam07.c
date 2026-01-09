/*
EXAM 07 - Programming in C 

Implement the following set of functions and a `main` program.


### Function 1: Read and filter strings from a file

This function:

* Receives as input an array of strings and a file path.
* Attempts to open the file with the given name.
* If the file cannot be opened, returns `-1`.
* If the file is opened successfully:

  * Reads strings from the file and stores in the array only those strings that:

    * begin with an **uppercase vowel** (`A, E, I, O, U`), and
    * end with a **lowercase vowel** (`a, e, i, o, u`).
  * Closes the file.
  * Returns the number of strings stored in the array.

**Example**
File content:
`Osaka Berlin Madrid amsterdam Vienna OrlandO Zurich Ankara Lima`

Array after processing:
`Osaka Vienna OrlandO Ankara Lima`

---

### Function 2: Print indices and strings

This function:

* Receives as input an array of strings and the number of valid strings stored.
* Prints the indices and the corresponding strings on two aligned rows, as shown in the example.
* Does not return any value.

**Example output:**

```
index     0        1         2         3        4
value   Osaka   Vienna   OrlandO   Ankara    Lima
```

---

### Function 3: Count uppercase and lowercase vowels

This function:

* Receives as input an array of strings, the number of strings it contains, and two output parameters (`countUpper`, `countLower`).
* Stores in `countUpper` the total number of **uppercase vowels** found in all strings.
* Stores in `countLower` the total number of **lowercase vowels** found in all strings.
* Does not return any value.

**Example**
Array: `Osaka Vienna OrlandO Ankara Lima`

Results:

* `countUpper = 5`
* `countLower = 8`

---

### Function 4: Circular left rotation

This function:

* Receives as input an array of strings and the number of strings it contains.
* Performs a circular left rotation:

  * Each string is shifted one position to the left.
  * The first string becomes the last one.
* Does not return any value.

**Example**
Before: `Osaka Vienna OrlandO Ankara Lima`
After:  `Vienna OrlandO Ankara Lima Osaka`

---

### `main` Function

The `main` function must:

* Accept **exactly one command-line argument**, representing the file path.

  * If the number of arguments is incorrect, print
    `"ERROR: invalid number of arguments"`
    and terminate returning `10`.
* Declare an array capable of storing **30 strings**, each with a maximum length of **30 characters**.
* Call the file-loading function.

  * If the file cannot be opened, print
    `"ERROR: unable to open file"`
    and terminate returning `20`.
  * If the file is opened but no strings are stored in the array, print
    `"ERROR: no valid strings found"`
    and terminate returning `30`.
* Call the function that prints the array.
* Call the vowel-counting function, then print a message in the form:
  `"uppercase vowels: ... , lowercase vowels: ..."`
* Call the circular rotation function, then call again the print function.
* Terminate returning `0`.

**Example command line:**

```
./program.out data.txt
```
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define DIM 30

int load_file(char s[][DIM], char *argv[])
{
    int cond1,cond2,len,copied_counter = 0;
    FILE *fp;
    fp = fopen(argv[1], "r"); 

    if(fp == NULL) {
        copied_counter = -1; }

    else {
        char buffer[DIM];
        while(fscanf(fp, "%s", buffer) != EOF && copied_counter < DIM)
        {
            len = 0;

            len = strlen(buffer);

            cond1 = (buffer[0] == 'A' || buffer[0] == 'E' || buffer[0] == 'I' || buffer[0] == 'O' || buffer[0] == 'U');

            cond2 = (buffer[len-1] == 'a' || buffer[len-1] == 'e' || buffer[len-1] == 'i' || buffer[len-1] == 'o' || buffer[len-1] == 'u');

            if(cond1 && cond2) {
            strcpy(s[copied_counter], buffer);
            copied_counter++; }
        }
        fclose(fp);

    }

    return copied_counter;
}

void visual_vect(char s[][DIM], int copied)
{
    int i;
    
    printf("\nIndex:\t");
    for(i = 0; i < copied; i++)
    {
        printf("%d\t",i);
    }

    printf("\nString:\t");
    for(i = 0; i < copied; i++)
    {
        printf("%s\t",s[i]);
    }
}

void string_stats(char s[][DIM],int copied, int *p1, int *p2)
{
    int i,j,len;
    *p1 = 0;
    *p2 = 0;

    for(i = 0; i < copied; i++)
    {
        len = strlen(s[i]);

        for(j = 0; j < len; j++)
        {
            if(s[i][j] == 'A' || s[i][j] == 'E' || s[i][j] == 'I' || s[i][j] == 'O' || s[i][j] == 'U') {
                (*p1)++; }

            if(s[i][j] == 'a' || s[i][j] == 'e' || s[i][j] == 'i' || s[i][j] == 'o' || s[i][j] == 'u') {
                (*p2)++; }
        }
    }
}

void shift_vec(char s[][DIM], int copied)
{
    int i;
    char temp[DIM]; 

    strcpy(temp, s[0]);
    for(i = 0; i < copied-1; i++)
    {
        strcpy(s[i], s[i+1]);
    }
    strcpy(s[copied-1], temp);
}

int main (int argc, char *argv[])
{
    if(argc != 2) {
        printf("Error: file missing in input\n");
        exit(1); }

    char s[DIM][DIM];
    int copied,capital,lower_case;

    copied = load_file(s,argv);
    if(copied == -1) {
        printf("Error: file missing\n");
        exit(2); }
    
    if(copied == 0) {
        printf("Error: file empty");
        exit(3); }
    
    visual_vect(s,copied);
    string_stats(s,copied,&capital,&lower_case);

    shift_vec(s,copied);
    visual_vect(s,copied);

    return 0;
}