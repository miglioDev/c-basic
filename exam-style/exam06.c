/*
EXAM 06 - Programming in C

Implement the following functions and a main program.


**Function 1 – Password input**

* Receives a character array `pwd` as input.
* Repeatedly asks the user to enter a password made of an **even number of characters**.
* Stores the entered password in `pwd`.
* As long as the password length is not even, it prints the message:
  `ERROR: the number of characters is not even`
  and asks for a new input.
* Returns nothing.

Example valid inputs (even length):

* `M2q#Azp!`
* `7bC@K9d(`
* `XyZ{QWER`

---

**Function 2 – Password strength check**

* Receives a character array `pwd`.
* Returns `1` (password considered *strong*) if the string contains:

  * at least one digit (`0–9`), and
  * at least one alphabetic character (uppercase or lowercase).
* Otherwise, returns `0` (password considered *weak*).

Examples:

* `M2q#Azp!` → `1`
* `7bC@K9d(` → `1`
* `XyZ{QWER` → `0`

---

**Function 3 – Encrypted save to file**

* Using pointers and pointer arithmetic, receives:

  * a character array `pwd`,
  * the name of a text file.
* Saves `pwd` to the file in an *encrypted* form by swapping characters in pairs:

  * first with second, third with fourth, fifth with sixth, and so on.
* Returns nothing.

Examples:

* `pwd: M2q#Azp!` → file content: `2M#qzA!p`
* `pwd: XyZ{QWER` → file content: `yX{ZQWRE`
* `pwd: 7bC@K9d(` → file content: `b7@C9Kd(`

---

**Function 4 – Password confirmation**

* Receives the name of a text file.
* Reads the encrypted password from the file and *decrypts* it to obtain the original password.
* Asks the user to re-enter the password for confirmation.
* Returns `1` (password correct) if the newly entered password matches the decrypted one.
* Otherwise, returns `0` (password incorrect).

---

**`main` function**

* Receives **exactly one command-line argument**, which is the name of a text file.

  * If the number of arguments is incorrect, prints:
    `ERROR: wrong number of parameters`
    and terminates returning `1`.
* Declares a character array of fixed size `30`.
* Calls the function to input and validate the password length.
* Calls the function that evaluates password strength and prints either:

  * `The password is strong` or
  * `The password is weak`.
* Calls the function that saves the password to the file in encrypted form.
* Calls the function that confirms the password and prints either:

  * `The password is correct` or
  * `The password is incorrect`.
* Terminates returning `0`.

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define DIM 30

void load_string(char s[])
{
    int len;

    do
    {
        printf("\nEnter a password: ");
        scanf(" %s",s);

        len = strlen(s);
        if(len %2 == 1) 
            printf("\nError: pw must be even (lengh)\n");
    }
    while( len %2 == 1 );
}

int strong_pw(char s[DIM])
{
    int i,len,res = 0,cond1 = 0,cond2 = 0;
    len = strlen(s);

    for(i = 0; i < len; i++)
    {
        if(isdigit(s[i])) {
             cond1 = 1; }
        if(isalpha(s[i])) {
            cond2 = 1; }
    }

    if(cond1 && cond2) {
        res = 1; }
        
    return res;
}

void load_pw_on_file(char s[DIM], char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1],"w"); 
    if(fp == NULL) {
        printf("Error: on file opening\n");}

    int i,len;
    len = strlen(s);
    char k;

    for(i = 1; i < len; i++) //while (i < len -1) i = i+2 
    {
        k = *(s+i-1);
        *(s+i-1) = *(s+i);
        *(s+i) = k;
        i++;
    }

    fprintf(fp, "%s",s);
    fclose(fp);
}

int comfirm_pw(char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    char s[DIM];
    fscanf(fp, "%s", s);

    int result = 0; 

    int i,len;
    len = strlen(s);
    char k;

    for(i = 1; i < len; i++)
    {
        k = s[i];
       s[i]= s[i-1];
        s[i-1] = k;
        i++;
    }

    char confirm[DIM];
    printf("\nConfirm the password: ");
    scanf(" %s",confirm);

    if(strcmp(s,confirm) == 0) { 
        result = 1; } 

    fclose(fp);
    return result;
}

int main (int argc, char *argv[])
{
    if(argc != 2) {
        printf("Error: invalid input\n");
        exit(1); }
    
    char s[DIM];
    int str,result;

    load_string(s);
    str = strong_pw(s);
    if(str) {
    printf("\nThe pw is strong"); }
        else 
        printf("\nThe pw is not strong");

    load_pw_on_file(s,argv);
    result = comfirm_pw(argv);
    
    if(result) {
    printf("\nPw is correct!"); }
        else {
            printf("Pw is incorrect\n");}

    return 0;
}