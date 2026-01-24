/*
EXAM 15 – Programming in C

Implement the following functions and a main program.


### Function 1 — Load words from file

Write a function that:

* Takes as input:

  * an array of strings `words`,
  * the maximum capacity of the array `capacity`,
  * the name of a text file `filename`.
* If the file exists, opens it and copies into the array all words that:

  * start with an **uppercase vowel** (`A, E, I, O, U`),
  * end with a **lowercase consonant**,
  * and only while there is still space available in the array.
* After processing, closes the file.
* Fills any unused positions in the array with empty strings.
* Returns:

  * `1` if the file exists and was processed,
  * `0` if the file does not exist.

**Example**

* File content:
  `Paul Alice Otto Ivan Alan Ethan eva Mark olga Ulrich`
* Resulting array:
  `Alice Ivan Alan Ethan Ulrich`

---

### Function 2 — Display the array

Write a function that:

* Takes as input:

  * an array of strings `words`,
  * its dimension `capacity`.
* Prints the content of the array using the format:
  `index: value`
* Skips empty strings.
* Returns:

  * `1` if all positions in the array are occupied by non-empty strings,
  * `0` otherwise.

**Example output**

```
0: Alice 1: Ivan 2: Alan 3: Ethan 4: Ulrich
```

---

### Function 3 — Character search using pointers

Write a function that **uses pointers and pointer arithmetic** and:

* Takes as input:

  * an array of strings `words`,
  * its dimension `capacity`,
  * a character `ch`,
  * two integer pointer parameters `firstPos` and `lastPos`.
* Stores in:

  * `firstPos` the index of the **first** string containing `ch`,
  * `lastPos` the index of the **last** string containing `ch`.
* If no string contains the character, both values must be set to `-1`.
* Does not return any value.

**Example**

* `ch`: `l`
* `words`: `Alice Ivan Alan Ethan Ulrich`
* Result:
  `firstPos = 0`, `lastPos = 4`

---

### Function 4 — Check string lengths

Write a function that:

* Takes as input:

  * an array of strings `words`,
  * its dimension `capacity`.
* Returns:

  * `1` if all non-empty strings have the **same length**,
  * `0` otherwise.

**Examples**

* `Alice Ivan Alan Ethan Ulrich` → `1` (same length)
* `Alice Ivan Alan Ethan Isabella Ulrich` → `0` (different lengths)

---

### `main` function

Write a `main` function that:

* Receives **exactly one command-line argument**, which is the name of the text file.

  * If the number of arguments is incorrect, prints:
    `"ERROR 1: invalid number of arguments"`
    and terminates returning `1`.
* Declares an array of **20 strings**, each with a **maximum length of 29 characters**.
* Calls the function that loads data from the file.

  * If the file does not exist, prints:
    `"ERROR 2: file <filename> not found"`
    and terminates returning `2`.
  * If no strings were loaded, prints:
    `"ERROR 3: the array is empty"`
    and terminates returning `3`.
* Calls the function that displays the array, then prints:

  * `"the array is fully used"` or
  * `"the array is partially used"`.
* Asks the user to **enter a character**, then calls the search function and prints:

  * `"no string contains <ch>"`, or
  * `"the first string containing <ch> has index <firstPos>, the last has index <lastPos>"`.
* Calls the function that checks string lengths and prints:

  * `"all strings have the same length"` or
  * `"strings have different lengths"`.
* Terminates returning `0`.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define R 20
#define C 30

int matrix_loading_from_file(char m[][C], char *file_name)
{
  FILE *fp;
  fp = fopen(file_name, "r");

  if(fp == NULL) {
    return 0; }

  else {
    int copied = 0,cond1,cond2,f,len;
    char buffer[C];

    while(fscanf(fp,"%s", buffer) != EOF && copied < R)
    {
      f = 0;
      len = strlen(buffer);

      cond1 = (buffer[0] == 'A' || buffer[0] == 'E' || buffer[0] == 'I' || buffer[0] == 'O' || buffer[0] == 'U');
      cond2 = (islower(buffer[len-1]) && (buffer[len-1] != 'a' && buffer[len-1] != 'e' && buffer[len-1] != 'i' && buffer[len-1] != 'o' && buffer[len-1] != 'u'));
      
      if(cond1 && cond2) {
        f = 1; }

      if(f) {
        strcpy(m[copied], buffer);
        copied++; }
    }
    fclose(fp);

    while(copied < R)
    {
      m[copied][0] = '\0';
      copied++;
    }
    
    return 1;
  }
}

int show_matrix(char m[][C])
{
  int r;
  for(r = 0; m[r][0] != '\0' && r < R; r++)
  {
    printf("%d: %s\t",r,m[r]);
  }
  printf("\n");

  if(r == R) {
    return 1; }

    else {
      return 0; }
}

void char_finder(char (*m)[C],char c, int *p1, int *p2)
{
  int r,j,len;
  *p1 = -1;
  *p2 = -1;     

  for(r = 0; *(*(m+r)+0) != '\0'; r++)    //m[r][c]   *(*(m+r)+j)
  {
    len = strlen(m[r]);
    for(j = 0; j < len-1; j++)  //or use strchr()
    {
      if(*(*(m+r)+j) == c && *p1 == -1) {
        *p1 = r; }
      if(*(*(m+r)+j) == c) {
        *p2 = r; }
    }
  }
}

int string_len_check(char m[][C])
{
  int r,len,equal = 1;
  len = strlen(m[0]);

  for(r = 1; m[r][0] != '\0'; r++)
  {
    if(strlen(m[r]) != len) {
      equal = 0; }
  }

  return equal;
}

int main (int argc, char *argv[])
{
  if(argc != 2) {
    printf("ERROR 1: invalid number of arguments\n");
    exit(1); }

    char m[R][C],c;
    int r,first,last;

    r = matrix_loading_from_file(m,argv[1]);
    if(r == 0) {
    printf("ERROR 2: file %s not found\n",argv[1]);
    exit(2); }

      else if(r == 1 && m[0][0] == '\0') {
        printf("ERROR 3: the array is empty\n");
        exit(3); }

    r = show_matrix(m);
      if(r) {
      printf("the array is fully used\n"); }
        else {
        printf("the array is partially used\n"); }

  printf("Enter a char: ");
  scanf("%c",&c);

  char_finder(m,c,&first,&last);
    if(first == -1) {
    printf("no string contains %c\n",c); }
      else {
      printf("the first string containing %c has index %d, the last has index %d\n",c,first,last); }

  r = string_len_check(m);
  if(r) {
  printf("all strings have the same length\n"); }
    else {
      printf("strings have different lengths\n"); }

  return 0;
}
