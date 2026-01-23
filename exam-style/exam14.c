/*
EXAM 01 – Programming in C

Implement the following functions and a main program.


Write a C program composed of several functions that operate on an array of strings and a text file.

**Function 1 — File filtering and loading**

* Takes as input:

  * an initially empty array of strings;
  * a pointer to a text file already opened in read mode.
* Reads strings from the file and copies into the array only those strings that contain **two adjacent lowercase vowels**.
* Returns the number of strings copied into the array.

*Example*
Text file content:
`Andrea Bruno Emanuel Sofia Lucia Paolo Matteo Bob Mark`

Resulting array:
`Andrea Emanuel Sofia Lucia Bob Mark`

---

**Function 2 — Array display**

* Takes as input:

  * an array of strings;
  * the number of valid strings stored in the array.
* If the array contains no strings, prints:
  `empty array`
* Otherwise, prints indices and strings in two aligned columns, as shown below.
* Returns nothing.

*Example output*

Indices:    Strings:

```
0           Andrea
1           Emanuel
2           Sofia
3           .....
4           ...
5 

---

**Function 3 — String length analysis (using pointer arithmetic)**

* Takes as input:

  * an array of strings;
  * the number of strings in the array;
  * two output parameters (`oddCount`, `evenCount`).
* Assigns to:

  * `oddCount` the number of strings with odd length;
  * `evenCount` the number of strings with even length.
* Must use pointer arithmetic to access the array elements.
* Returns nothing.

*Example*

Array: `Andrea Emanuele Sofia Lucia Irene Marco`

Results:
`oddCount = 4`
`evenCount = 2`

---

**Function 4 — Circular left shift**

* Takes as input:

  * an array of strings;
  * the number of strings in the array.
* Performs a circular left shift:

  * each string is moved one position to the left;
  * the first string is moved to the last position.
* Returns nothing.

*Example*

Before:
`Andrea Emanuele Sofia Lucia Irene Marco`

After:
`Emanuele Sofia Lucia Irene Marco Andrea`

---

**`main` function**

* Declares an array of **50 strings**, each capable of holding up to **50 characters**.
* Accepts exactly **one command-line argument**, which is the name of a text file.

  * If the number of parameters is incorrect, prints:
    `ERROR 1: invalid number of parameters`
    and terminates returning `1`.
* Attempts to open the specified text file.

  * If the file cannot be opened, prints:
    `ERROR 2: text file not found`
    and terminates returning `2`.
* Calls the function that loads the array from the file, then closes the file.
* Calls the function that displays the array.
* Calls the function that counts odd- and even-length strings, then prints:
  `the array contains ... strings of odd length and ... strings of even length`
* Calls the function that performs the circular left shift.
* Calls again the function that displays the array.
* Terminates returning `0`.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define R 40
#define C 40

int load_m_from_file(char m[][C], FILE *fp)
{
  int len,i,counter = 0,cond;
  char buffer[C];

  while(fscanf(fp,"%s",buffer) != EOF && counter < R)
  {
    len = strlen(buffer);
    cond = 0;
    for(i = 0; i < len-1; i++)
    {
      if(islower(buffer[i]) && (buffer[i] == 'a' || buffer[i] == 'e' || buffer[i] == 'i' || buffer[i] == 'o' || buffer[i] == 'u') &&
       islower(buffer[i+1]) && (buffer[i+1] == 'a' || buffer[i+1] == 'e' || buffer[i+1] == 'i' || buffer[i+1] == 'o' || buffer[i+1] == 'u')) {
      cond = 1;
      }
    }
    if(cond) {
      strcpy(m[counter], buffer);
      counter++; }
  }

  return counter;
}

void print_matrix(char m[][C], int row)
{
  if(row == 0)  {
    printf("Empty array\n"); }

  else {
    int r;
    printf("Index:\tString:\n");
    for(r = 0; strlen(m[r]) > 0 && r < R; r++)
    {
      printf("%d\t%s\n",r,m[r]);
    }
  }
}

void even_and_odd(char (*m)[C], int *p1, int *p2)
{                     
  int r;
  *p1 = 0;
  *p2 = 0; 
  for(r = 0; strlen(*(m+r)) > 0; r++)    //*(m+r) == m[i]
  {
    if(strlen(*(m+r)) % 2 == 0) {
      (*p1) ++; }
      else {
        (*p2) ++; }
  }
}

int main (int argc, char *argv[])
{
  char m[R][C];

  if(argc != 2) {
    printf("ERROR 1: invalid number of parameters\n");
    exit(1); }

  FILE *fp;
  fp = fopen(argv[1], "r");

  if(fp == NULL ) {
    printf("ERROR 2: text file not found\n");
    exit(2); }

  int copied,even,odd;

  copied = load_m_from_file(m,fp);

  fclose(fp);

  print_matrix(m,copied);
  even_and_odd(m,&even,&odd);
    printf("Even lengh string: %d\n",even);
    printf("Odd lenght string: %d\n",odd);

  return 0;
}

