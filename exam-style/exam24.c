/*
EXAM 24 – Programming in C

Implement the following functions and a main program.


A function that
receives as input an empty array of strings, its size, and the name of a text file.

The function copies from the file into the array only the words that start with an uppercase consonant and end with a lowercase vowel, making sure that there is still available space in the array.

Example: file content → *Paolo Irene Dario Elena George Marta*
resulting array → *Paolo Dario George*

If necessary, the remaining positions of the array must be filled with empty strings.

The function returns **0** if the file exists and at least one word has been copied, otherwise it returns **0**.

---

A function that
receives as input an array of strings.

The function prints the non-empty strings using the format **index: string**, one per line.

Example:

```
0: Paul
1: Bob
2: Georg
```

The function returns the number of printed strings.

---

A function that, using **pointer arithmetic**,
receives as input an array of strings, a character **ch**, and two parameters (**first**, **last**).

The function assigns to **first** the index of the first string containing the character **ch** (in any position).
It assigns to **last** the index of the last string containing the character **ch**.

If the character does not appear in any string, both parameters must be set to **–1**.

The function does not return any value.

---

A function that
receives as input an array of strings.

For every non-empty string, the function replaces all lowercase vowels with the character `#` or another char like *.

Example:
*Paul → P##l
*Bob → B*B

The function does not return any value.

---

The **main** function must:

* Receive **exactly one** command-line argument: the name of a text file.
  Otherwise, print
  **"ERROR 1: wrong number of parameters"**
  and terminate returning **1**.

* Declare an array of **15** strings, each with a maximum length of **30** characters (defined as constants).

* Call the function that loads the array from the file.
  If it returns **1**, print
  **"ERROR 2: loading failed"**
  and terminate returning **2**.

* Call the function that prints the array and show the returned count.

* Ask the user to **enter a character**, then call the search function.
  Display either
  **"The character ... appears from index ... to index ..."**
  or
  **"The character ... does not appear in any string"**.

* Call the function that replaces lowercase vowels with `#`.

* Call again the function that prints the modified array.

* Return **0**.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define R 15
#define C 30

int load_from_file(char m[][C], char *file_name)
{
  int res = 0,r,len,cond1,cond2;
  char buffer[C];

  FILE *fp;
  fp = fopen(file_name, "r");

  if(fp == NULL) {
    res = 1;
    return res; }

  else {
    r = 0;

    while(fscanf(fp, "%s", buffer) != EOF && r < R)
    {
      len = strlen(buffer);

      cond1 = (isupper(buffer[0]) && (buffer[0] != 'A' && buffer[0] != 'E' && buffer[0] != 'I' && buffer[0] != 'O' && buffer[0] != 'U'));
      cond2 = (islower(buffer[len-1]) && (buffer[len-1] == 'a' || buffer[len-1] == 'e' || buffer[len-1] == 'i' || buffer[len-1] == 'o' || buffer[len-1] == 'u'));

      if(cond1 && cond2) {
        strcpy(m[r],buffer);
        r++;
        res = 1;
      }
    }
    fclose(fp);

    while(r < R) 
    {
      m[r][0] = '\0';
      r++;
    }
  }

  return res;
}

int print_string(char m[][C])
{
  int i; 

  for(i = 0; m[i][0] != '\0'; i++)
  {
    printf("\n%d)\t%s",i,m[i]);
  }

  return i;
}

void search_char(char (*m)[C],char c, int *p1, int *p2)
{
  int r,j,len;
  *p1 = -1;
  *p2 = -1; 

  for(r = 0; *(*(m+r)+0) != '\0'; r++)
  {
    len = strlen(*(m+r)); 

    for(j = 0; j < len; j++)
    {
      if(*(*(m+r)+j) == c) {
        if(*p1 == -1) {
        *p1 = r; 
        *p2 = r;}
          else {
            *p2 = r;}}
    }
  }
}

void remove_and_replace(char m[][C])
{
  int r,j,len;

  for(r = 0; m[r][0] != '\0'; r++)
  {
    len = strlen(m[r]);

    for(j = 0; j < len; j++)
    {
      if(m[r][j] == 'a' || m[r][j] == 'e' || m[r][j] == 'i' || m[r][j] == 'o' || m[r][j] == 'u') {
        m[r][j] = '*'; }
    }
  }
}

int main (int argc, char *argv[])
{
  if(argc != 2) {
    printf("ERROR 1: wrong number of parameters\n");
    exit(1); }

  int loaded,printed,a,b;
  char m[R][C],c;

  loaded = load_from_file(m,argv[1]);
  if(loaded == 0) {
    printf("ERROR 2: loading failed"); 
    exit(2); }
  
  printed = print_string(m);
  printf("\n%d - string have been printed\n",printed);
  
  printf("Enter a char: ");
  scanf(" %c", &c);

  search_char(m,c,&a,&b);
  if(a == -1) {
  printf("No result for char %c",c); }
    else {
    printf("First result in %d row, last in %d",a,b);}

  remove_and_replace(m);
  print_string(m);

  return 0;
}
