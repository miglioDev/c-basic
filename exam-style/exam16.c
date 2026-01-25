/*
EXAM 16 - Programming in C

Implement the following functions and a main program


### Function 1 — Read and validate a string

Write a function that:

* Takes as input a character array `buffer`.
* Repeatedly asks the user to enter a string and stores it in `buffer`.
* The entered string must contain **at least two digits** (`0–9`), which may appear in **any positions**.
* If the requirement is not satisfied, prints an appropriate error message and asks again until a valid string is provided.
* Returns the **total number of digits** found in the string.

**Example**

* Input string: `Maven-3.8.6`
* Output: `3 digits`

---

### Function 2 — Display indices and characters

Write a function that:

* Takes as input a string.
* Displays:

  * the indices of the string characters on one line,
  * the corresponding characters on a second line,
* following the format shown in the example.
* Does not return any value.

**Example**

```
indices:    0 1 2 3 4 5 6 7 8 9
characters: M a v e n - 3 . 8 . 6
```

---

### Function 3 — Find digit positions

Write a function that:

* Takes as input:

  * a string,
  * two additional parameters `posA` and `posB`.
* Stores in:

  * `posA` the index of the **first digit** found in the string,
  * `posB` the index of the **second digit** found in the string.
* Does not return any value.

**Example**

* String: `Maven-3.8.6`
* Result: `posA = 6`, `posB = 8`

---

### Function 4 — Copy non-digit characters to file

Write a function that:

* Takes as input:

  * a string,
  * a file name.
* Opens the specified file.
* Writes into the file all characters of the string that are **not digits**, separating each character with the symbol `_`.
* Closes the file.
* Returns the **number of characters written to the file**, including the `_` separators.

**Example**

* String: `Maven-3.8.6`
* File content: `M_a_v_e_n_-_._.`
* Return value: `15 characters`

---

### `main` function

Write a `main` function that:

* Receives **exactly one command-line argument**, which is the name of a file.

  * If the number of parameters is incorrect, prints an appropriate error message and terminates.
* Calls the function that reads and validates the string, then prints the number of digits found.
* Calls the function that displays the indices and characters of the string.
* Calls the function that searches for digit positions and prints the results.
* Calls the function that copies non-digit characters to the file and prints the number of characters written. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DIM 20

int visual_string(char v[DIM])
{
  int len,i,counter;

  do
  {
    counter = 0;

    printf("Enter a string: ");
    scanf("%s",v);

    len = strlen(v);

    for(i = 0; i < len; i++)
    {
      if(isdigit(v[i])) {
        counter++; }
    }

  }
  while(counter < 2);

  return counter;
}

void print_string(char v[DIM])
{
  int i,len;
  len = strlen(v);

  printf("\nIndex:\t");
  for(i = 0; i < len; i++)
  {
    printf("\t%d",i);
  }

  printf("\nChar:\t");
  for(i = 0; i < len; i++)
  {
    printf("\t%c",v[i]);
  }
}

int main (int argc, char *argv[])
{
  if(argc != 2) {
    printf("Error - wrong number of argument\n");
    exit(1); }

  char v[DIM];
  int n_of_digit;

  n_of_digit = visual_string(v);
  printf("There are %d digit\n",n_of_digit);
  
  print_string(v);
    
  


}