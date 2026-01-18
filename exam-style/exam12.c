/*
EXAM 12 - Programming in C

Implement the following functions and  main program 


### Function 1 – Input and validation of a string

A function that:

* Receives as input a character array.
* Prompts the user with the message: *“Enter a string:”* and stores the input in the array.
* The string must satisfy **both** of the following conditions:

  * It contains at least **4 characters**.
  * It is composed **only of lowercase alphabetic letters** (`a`–`z`).
* If the string does not satisfy both conditions, the function prints:
  *“ERROR: invalid string”*
  and repeats the request until a valid string is provided.
* The function does **not** return any value.

---

### Function 2 – Alphabetical order check

A function that:

* Receives a string as input.
* Returns `1` if the characters in the string are ordered in **non-decreasing alphabetical order**.
* Returns `0` otherwise.

Examples of strings considered ordered:
`ball`, `cello`, `door`, `loop`, `moon`, `zoo`

---

### Function 3 – Search for vowels using pointers

A function that uses **pointers and pointer arithmetic** and:

* Receives a string and two integer parameters (`idxStart`, `idxEnd`) passed by reference.
* Stores in `idxStart` the index of the **first vowel** found in the string.
* Stores in `idxEnd` the index of the **last vowel** found in the string.
* If the string contains **no vowels**, it stores `-1` in both `idxStart` and `idxEnd`.
* The function does **not** return any value.

Example:
String: `area` → `idxStart = 0`, `idxEnd = 3`

(Vowels are `a`, `e`, `i`, `o`, `u`)

---

### Function 4 – Writing vowels to a file

A function that:

* Receives a string and a file name.
* Opens the specified text file.
* Writes **all vowels** found in the string to the file, separated by semicolons (`;`).
* Closes the file.
* Returns the **total number of characters written** to the file (including separators).

Example:
String: `area` → File content: `a;e;a` → 5 characters written

---

### `main` function

The `main` function must:

* Accept **exactly one command-line argument**, which is the name of a text file.

  * If the number of parameters is incorrect, print:
    *“ERROR 1: wrong number of parameters”*
    and terminate returning `1`.
* Declare a character array of size **25** (defined as a constant).
* Call the string input function, then print:
  *“The string is: …”*
* Call the alphabetical order check function, then print either:
  *“The string is alphabetically ordered”*
  or
  *“The string is not alphabetically ordered”*
* Call the vowel search function, then:

  * If vowels are found, print:
    *“First vowel index: …, last vowel index: …”*
  * Otherwise, print:
    *“ERROR 2: no vowels found in the string”*
    and terminate returning `2`.
* Call the file-writing function, then print:
  *“… characters written to file …”*
* Terminate returning `0`.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define DIM 30

void load_string(char v[DIM])
{
  int i,len,cond,ok;
  do
  {
    cond = 1;

    printf("Enter the string: ");
    scanf("%s", v);

    len = strlen(v);
    for(i = 0; i < len; i++)
    {
      if(isupper(v[i]))
      cond = 0;
    }

    ok = (len >= 3 && cond);
    
    if(!ok) {
      printf("ERROR: invalid string\n");
    }
  } 
  while (!ok);
}

int is_sorted(char v[DIM])
{
  int i,len,cond = 1;
  len = strlen(v);

  for(i = 0; i < len-1 && cond; i++)
  {
    if((v[i] > v[i+1])) {
      cond = 0; }
  }

  return cond;
}

void occ_find(char *v, int *p1, int *p2)
{
  *p1 = -1;
  *p2 = -1;
  int len,i;
  
  len = strlen(v);

  for(i = 0; i < len; i++)
  {
    if(*(v+i) == 'a' ||*(v+i) == 'e' || *(v+i) == 'i' || *(v+i) == 'o' ||*(v+i) == 'u') {
      if(*p1 == -1) {
        *p1 = i;
        *p2 = i; }
          else if(*p1 != -1 && *p2 == *p1) {
            *p2 = i;
          }
    }
  }
}

int file_writing(char v[DIM], char *file_name)
{
  FILE *fp;
  int i,len,counter = 0;
  len = strlen(v);
  fp = fopen(file_name, "w");

  for(i = 0; i < len; i++)
  {
    if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
      
      if(counter == 0) {
      fprintf(fp,"%c",v[i]);
      counter++; }
        else {
          fprintf(fp,"%c,",v[i]);
          counter++;
          counter++; } }
  }
  fclose(fp);

  return counter;
}

int main(int argc, char *argv[])
{
    if(argc != 2) {
      printf("ERROR 1: wrong number of parameters\n");
      exit(1); }

    char v[DIM];
    int ord,a,b,f;

    load_string(v);
    ord = is_sorted(v);
    if(ord) {
    printf("The string is sorted\n"); }
      else {
      printf("The string is not sorted\n"); }

    occ_find(v,&a,&b);
    if(a == -1) {
    printf("There are not any vowel\n"); }
        else if(a == b) {
        printf("One in %d position\n",a); }
          else {
            printf("First in %d and second in %d",a,b); }

    f = file_writing(v,argv[1]);
    printf("%d char enter in the text file\n",f);

    return 0;
}