/*
Exam 09 - Programming in C 

Implement the following functions and a main program

**Function 1 – String input and validation**

* Receives a character array as input.
* Prompts the user to *“enter a string”* that:

  * contains at least 3 characters,
  * starts with an **uppercase vowel**,
  * continues with **lowercase letters**,
  * ends with a **lowercase vowel**.
* Example valid strings:

  * *Irene*, *Olivia*, *Umberto*, *Alessia*, *Elena*
* Stores the entered string in the character array.
* Returns `1` if the string satisfies all requirements, `0` otherwise.

---

**Function 2 – Display indices and characters**

* Receives a string as input.

* Prints the indices and the corresponding characters on two separate lines, formatted as shown in the example.

* Example output for the string *Elisa*:

  ```
  indices:    0  1  2  3  4
  characters: E  l  i  s  a
  ```

* Does not return any value.

---

**Function 3 – Character search using pointer arithmetic**

* Using pointer arithmetic, receives:

  * a string,
  * a character to search,
  * two output parameters (`posFirst`, `posLast`).
* Stores in `posFirst` the index of the **first occurrence** of the character and in `posLast` the index of the **last occurrence**.
* If the character does not appear in the string, stores `-1` in both parameters.
* Example:

  * string: *Elissa*, character: `s` → `posFirst = 2`, `posLast = 3`
* Does not return any value.

---

**Function 4 – Circular right shift and file writing**

* Receives a string and a file name.
* Performs a **circular right shift** on the string.
* Writes the resulting string to the file, separating each character with a dash (`-`), then closes the file.
* Example:

  * original string: *Elisa* → shifted string: *aElis*
  * file content: `a-E-l-i-s`
* Returns the total number of characters written to the file (including separators).

---

**`main` function**

* Receives **exactly one command-line argument**, which is the name of a text file.

  * If the number of parameters is incorrect, prints
    *“ERROR: wrong number of parameters”*
    and terminates returning `1`.
* Declares a character array of fixed size **30**.
* Calls the string input function to load the string into the array.

  * If the loading fails, prints
    *“ERROR: invalid string”*
    and terminates returning `2`.
* Calls the function that displays the string with indices.
* Prompts the user to *“enter a character”*, calls the search function, and then prints either:

  * *“The character X appears at positions Y and Z”*, or
  * *“The character X is not present”*.
* Calls the function that performs the circular shift and writes to file, then prints
  *“N characters written to file”*.
* Returns `0`.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define DIM 30

int load_vec(char v[DIM])
{
    int len,cond1,cond2 = 1,i,cond3,ok;

    printf("Enter a string: ");
    scanf("%s", v);

    len = strlen(v);
    cond1 = (v[0] == 'A' || v[0] == 'E' || v[0] == 'I' || v[0] == 'O' || v[0] == 'U');
    
    for(i = 1; i < len; i++) {
        if(isupper(v[i])) cond2 = 0; }

    cond3 = (v[len-1] == 'a' || v[len-1] == 'e' || v[len-1] == 'i' || v[len-1] == 'o' || v[len-1] == 'u');

    ok = (len >= 3 && cond1 && cond2 && cond3);

    if(ok) {
        return 1; }
        else {
            return 0;}
}

void print_string(char v[DIM])
{
    int i,len;
    
    len = strlen(v);

    printf("\nIndex:\t");
    for(i = 0; i < len; i++) {
        printf("\t%d",i); }

    printf("\nChar:\t");
    for(i = 0; i < len; i++) {
        printf("\t%c",v[i]); }
    printf("\n");
}

void c_research(char v[DIM],char c, int *p1, int *p2)
{
    int i,len;
    *p1 = -1;
    *p2 = -1;
    len = strlen(v);

    for(i = 0; i < len; i++)
    {
        if(*p1 == -1 && v[i] == c) *p1 = i;
        if(*p1 != -1 && v[i] == c) *p2 = i;
    }
}

int shift_file_copy(char v[DIM], char *file_name)
{
    int i,len,counter = 0;
    char k;
    len = strlen(v);
    FILE *fp;

    k = v[len-1];
    for(i = len-1; i > 0; i--)
    {
        v[i] = v[i-1];
    }
    v[0] = k;

    fp = fopen(file_name, "w");

    for(i = 0; i < len; i++) 
    {
    fprintf(fp,"%c",v[i]);
    counter++;
    if(i < len-1) {
        fprintf(fp,"-"); }
    counter++; 
    }

    fclose(fp);

    return counter;
}

int main (int argc, char *argv[])
{
    if(argc != 2) {
        printf("ERROR: wrong number of parameters\n");
        exit(1); }

    char v[DIM],c;
    int s_loaded,pos1,pos2,counter;
    
    s_loaded = load_vec(v);
    if(s_loaded == 0) {
        printf("ERROR: invalid string\n");
        exit(2); }
    
    print_string(v);

    printf("Enter a char: ");
    scanf("%c", &c);
    scanf("%c", &c);

    c_research(v,c,&pos1,&pos2);
    if(pos2 != -1) {
    printf("Found in position %d and %d\n",pos1,pos2); }
        else if(pos1 != -1 && pos2 == -1) {
        printf("Char found in position: %d\n",pos1); }
            else {
                printf("Char not foud\n"); }

    counter = shift_file_copy(v,argv[1]);
    printf("Shift and print on file executed\n%d char copied on file\n",counter);

    return 0;
}