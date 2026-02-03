/*
EXAM 21 – Programming in C

Implement the following functions and a main program.


**Function 1 – Load Strings from File**

* Receives a vector (array) of strings and a file name.
* Attempts to open the specified file.
* If the file does not exist, returns `-1`.
* If the file exists:

  * Copies into the vector all strings from the file that contain **at least 3 lowercase vowels** (`a`, `e`, `i`, `o`, `u`).
  * Example:

    * File contents:

      ```
      Berlin Madrid Oslo Paris Rome London
      ```
    * Vector after processing:

      ```
      Berlin Oslo Paris Rome London
      ```
* Closes the file.
* Returns the number of strings copied into the vector.

---

**Function 2 – Display Strings with Indices**

* Receives a vector of strings and the number of strings it contains.
* Prints the indices and strings in two separate rows, as in the example:

  ```
  Indices
  Strings
  0
  Berlin
  1
  Oslo
  2
  Paris
  3
  Rome
  4
  London
  ```
* Does not return any value.

---

**Function 3 – Find Words Ending with a Character**

* Receives a vector of strings, its size, a character, and two integer references (or pointers) `firstIndex` and `lastIndex`.
* Stores in `firstIndex` the index of the first string ending with the given character. If none exists, stores `-1`.
* Stores in `lastIndex` the index of the last string ending with the given character. If none exists, stores `-1`.
* Example:

  ```
  Vector: Berlin Oslo Paris Rome London
  Character: o
  -> firstIndex: 1, lastIndex: 1

  Character: n
  -> firstIndex: 0, lastIndex: 4

  Character: x
  -> firstIndex: -1, lastIndex: -1
  ```
* Does not return any value.

---

**Function 4 – Remove First String**

* Receives a vector of strings and its size.
* Removes the first string, shifting all remaining strings forward.
* Example:

  ```
  Before: Berlin Oslo Paris Rome London
  After:  Oslo Paris Rome London
  ```
* Returns the updated number of strings.

---

**Main Function Requirements**

* Receives **exactly one command-line argument**: the name of the input file.

  * If the number of arguments is incorrect, displays an error message and exits.
  * Example usage:

    ```
    ./program strings.txt
    ```
* Declares a vector capable of holding **30 strings of 30 characters each**.
* Calls the function to load strings from the file.

  * If the file does not exist, displays an error message and exits.
* Calls the function to display the vector.
* Prompts the user to enter a character.
* Calls the function to find the first and last words ending with that character and displays the results.
* Calls the function to remove the first string, then calls the display function again to show the updated vector.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30

int load_from_file(char m[][DIM], char *file_name)
{
  FILE *fp;
  fp = fopen(file_name, "r");
  int op;

  if(fp == NULL) {
    op = -1; }
  
  else {
    char buffer[DIM];
    int copied,vowel,i,len; 
    copied = 0;
    
    while(fscanf(fp, "%s", buffer) != EOF && copied < DIM)
    {
      vowel = 0;
      len = strlen(buffer);

      for(i = 0; i < len; i++)
      {
        if(buffer[i] == 'a' || buffer[i] == 'e' || buffer[i] == 'i' || buffer[i] == 'o' || buffer[i] == 'u') {
          vowel++; }
      }

      if(vowel >= 3) {
        strcpy(m[copied], buffer);
        copied++; }
    }
    fclose(fp);

    op = copied; }

  return op;
}

void print_matrix(char m[][DIM], int s_loaded)
{
  int i;

  printf("\nIndex:\t");
  for(i = 0; i < s_loaded; i++)
  {
    printf("\t\t%d",i);
  }

  printf("\nString:\t");
  for(i = 0; i < s_loaded; i++)
  {
    printf("\t\t%s",m[i]);
  }
}

void char_search(char m[][DIM], int s_loaded, char c, int *d1, int *d2)
{
  int i,j,len;
  *d1 = -1;
  *d2 = -1;

  for(i = 0; i < s_loaded; i++)
  {
    len = strlen(m[i]);

    for(j = 0; j < len; j++)
    {
      if(*(*(m+i)+j) == c) {
        if(*d1 == -1) {
          *d1 = i; }
        *d2 = i;
      }
    }
  }
}

int remove_string(char m[][DIM], int s_loaded)
{
  int i;

  for(i = 0; i < s_loaded; i++)
  {
    strcpy(m[i],m[i+1]);
  }
  s_loaded--;

  return s_loaded;
}

int main(int argc, char *argv[])
{
  if(argc != 2) {
    printf("Error 1: wrong number of argument\n");
    exit(1); }

  char m[DIM][DIM];
  int s_loaded,first,last,n;
  char c;
    
  s_loaded = load_from_file(m,argv[1]);
  if(s_loaded == -1) {
    printf("Error 2: file %s does not exist\n", argv[1]);
    exit(2); }

  print_matrix(m,s_loaded);
  
  printf("\nEnter a char: ");
  scanf("%c", &c);

  char_search(m,s_loaded,c,&first,&last);
  if(first == -1) {
  printf("\nChar not found\n"); }
    else {
    printf("\nChar found in %d and %d",first,last); }

  n = remove_string(m,s_loaded);
  printf("Updated number of string = %d\n",n);

  return 0;
}
