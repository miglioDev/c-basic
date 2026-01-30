/*
EXAM 01 – Programming in C

Implement the following functions and a main program.


A function that:

* receives as input a character array;
* asks the user to *“enter a string”* and stores the input into the array;
* the string must:

  * contain at least 3 characters;
  * consist only of uppercase letters (A–Z);
  * start and end with a vowel.
* If the string does not satisfy the requirements, it prints
  **“ERROR: the string does not meet the constraints”**.
* The request is repeated until the string is valid, with a maximum of **3 attempts**.
* The function returns **1** if a valid string is eventually entered, otherwise **0**.

Example of valid strings:
`EVA`, `ANA`, `ELENA`, `OTTORE`, `ULISSE`

---

A function that:

* receives a string as input;
* prints the indices and the corresponding characters of the string, formatted as shown in the example below;
* returns the total number of characters in the string.

Example output:

```
0: A  1: L  2: E  3: S  4: S  5: I  6: O
```

Example:

```
string: ALESSIO
-->
7 characters
```

---

A function that, using pointers and pointer arithmetic:

* receives a string and two output parameters (`minChar`, `maxChar`);
* stores in `minChar` the alphabetically smallest character in the string;
* stores in `maxChar` the alphabetically largest character in the string;
* does not return any value.

Examples:

```
string: ALESSIO  -->  minChar: A   maxChar: S
string: ULISSE   -->  minChar: E   maxChar: U
```

---

A function that:

* receives a string and a file name;
* writes all the vowels found in the string to the file, separated by commas;
* closes the file;
* returns the total number of characters written to the file (commas included).

Example:

```
string: ALESSIO
-->
file content: A,E,I,O
-->
7 characters
```

---

The `main` function:

* receives **exactly one** command-line argument: the name of a text file.
  If not, it prints
  **“ERROR 1: invalid number of parameters”**
  and terminates returning **1**.
* declares a character array of fixed size **30**.
* calls the function that reads and validates the string.
  If the function returns 0, it prints
  **“ERROR 2: maximum number of attempts reached”**
  and terminates returning **2**.
* calls the function that displays the string and then prints
  **“the string … contains … characters”**.
* calls the function that determines the alphabetically first and last characters and then prints
  **“the first character is …, the last character is …”**.
* calls the function that writes the vowels to the file and then prints
  **“… characters written to file …”**.
* terminates returning **0**.
  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DIM 30

int load_string_on_vector(char s[DIM])
{
  char string[DIM];
  int attempt,len,all_upper,i,vowel,cond1,cond2,f;

  attempt = 0;
  do
  {
    printf("Enter a string: ");
    scanf("%s",string);
    strcpy(s,string);

    len = strlen(string);
    all_upper = 1;

    for(i = 0; i < len; i++)
    {
      if(!isupper(string[i])) {  
        all_upper = 0; }
    }

    cond1 = (string[0] == 'A' || string[0] == 'E' || string[0] == 'I' || string[0] == 'O' || string[0] == 'U');
    cond2 = (string[len-1] == 'A' || string[len-1] == 'E' || string[len-1] == 'I' || string[len-1] == 'O' || string[len-1] == 'U');
    vowel = (cond1 && cond2);

    f = (len >= 3 && vowel && all_upper); 
    
    if(!f) {
      printf("ERROR: the string does not meet the constraints\n");
      attempt++; }

  }
  while(!f && attempt < 3);

  if(f) return 1;

  else {
    return 0; }
}

int string_visual(char s[DIM])
{
  int i,len;
  len = strlen(s);

  for(i = 0; i < len; i++)
  {
    printf("%d: %c\t",i,s[i]);
  }

  return len;
}

void first_and_last(char s[DIM], char *c1, char *c2)
{
  int len,i;

  len = strlen(s);

  for(i = 0; i < len; i++)
  {
    if(i == 0) {
      *c1 = *(s+i);
      *c2 = *(s+i); }

      else {
        if(*(s+i) < *c1 ) {
          *c1 = *(s+i); }

        if(*(s+i) > *c2) {
          *c2 = *(s+i); }
      }
  }
}

int main(int argc, char *argv[])
{
  if(argc != 2) {
    printf("ERROR 1: invalid number of parameters\n");
    exit(EXIT_FAILURE); }

  int loaded,characters;
  char a,b;
  char s[DIM];

  loaded = load_string_on_vector(s);

  if(loaded == 0) {
  printf("ERROR 2: maximum number of attempts reached\n");
  exit(2); }

  characters = string_visual(s);
    printf("\nThe string contains %d characters\n",characters);

  first_and_last(s,&a,&b);
    printf("First char = %c, last char %c (alphabetical)\n",a,b);

  return 0;
}