/*
EXAM 02 -Programming in C

Implement the following functions and a main program

**A function that:**

* Receives a character array as input.
* Asks the user to enter a string and stores it in the array.
* The string must start with **two uppercase letters** (the remaining characters can be of any type); moreover, the string must contain **at least 5 characters**.
* Examples of valid strings:
  `ESame`, `ESAme1`, `ESAME`, `ESaME`, ...
* If the requirements are not met, it displays an appropriate error message and repeats the request until the conditions are satisfied.
* Does not return any value.

---

**A function that:**

* Receives a string and two parameters (`q1`, `q2`) as input.
* Stores in `q1` the number of **uppercase letters** present in the string.
* Stores in `q2` the number of **other types of characters**.
* Example:

  * string: `ESAme1` → `q1 = 3`, `q2 = 3`
* Does not return any value.

---

**A function that, using pointer arithmetic:**

* Receives a string as input.
* Returns `1` if the string contains **at least two consecutive identical characters**.
* Otherwise, it returns `0`.
* Examples:

  * `ESaME...` → `1`
  * `ESame` → `0`

---

**A function that:**

* Receives a string and a file name as input.
* Opens the file with the given name.
* Writes into the file the **indices and the characters of the string arranged vertically**.

* Closes the file.
* Does not return any value.

---

**The `main` function:**

* Must receive **exactly one command-line argument**, which is the file name.
  If this condition is not satisfied, it displays an appropriate error message and terminates by returning `1`.
* Declares a character array of size **30** (constant).
* Calls the function to read and store the string, then displays the resulting string.
* Calls the function that counts the characters and displays the results with an appropriate message.
* Calls the function that checks for consecutive equal characters and displays the result with an appropriate message.
* Calls the function that writes the string to the file.
* Returns `0`.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define DIM 30

void load_string(char v[])
{
    int cond1,cond2,len;

    do
    {
    printf("\nEnter a string: ");
    scanf("%s", v);
    
    cond1 = 0;
    cond2 = 0;
    len = strlen(v);
    cond2 = len >= 5;
    cond1 = (isupper(v[0])) && (isupper(v[1]));

    if(!cond1 || !cond2) printf("ERROR string must be at least 5 char && must start with two capital letters\n");
    }
    while(!cond1 || !cond2);
}

void letter_counter(char v[],int *cap_letter, int *other_counter)
{
    int i,len;
    len = strlen(v);

    for(i = 0; i < len; i++)
    {
        if(isalpha(v[i]) && isupper(v[i])) {
            (*cap_letter)++;
        }
        else 
            (*other_counter)++;
    }
}

int consecutive_char(char v[])
{
    int con = 0,i,len;
    len = strlen(v);

    for(i = 0; i < len-1; i++)
    {
        if(*(v+i) ==  *(v+i+1)) {
            con = 1; }    
    }

    return con;
}

void write_string_onfile(char v[], char text[])
{
    FILE *fp;
    int i,len;

    fp = fopen(text, "w");
    if(fp == NULL) {
        printf("ERROR opening file\n");
        return;
    }
    len = strlen(v);

    fprintf(fp, "Index\tletter\n");
    for(i = 0; i < len; i++)
    {
        fprintf(fp, "%d\t%c\n", i,v[i]);
    }

    fclose(fp);
}

int main (int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("ERROR - program need one parameter only (filename)\n");
        exit(1);
    }

    char v[DIM];
    int cap_letter = 0,other_letter = 0,equal_c;

    load_string(v);
    printf("\nString:\t%s",v);

    letter_counter(v,&cap_letter,&other_letter);
    printf("\n== String Stats ==\n");
    printf("Capital letter: %d\n", cap_letter);
    printf("Other letter: %d\n", other_letter);

    equal_c = consecutive_char(v);
    if(equal_c) {
        printf("There are two or more consecutive identical char\n"); }
        else
        printf("There are not two or more consecutive identical char\n");

    write_string_onfile(v,argv[1]);

    return 0;
}

