/*
EXAM 03 - Programming in C

Implement the following functions and a main program 


A function that:

Receives as input an array of strings (initially unspecified), the maximum number of strings the array can store, and the name of a text file.

Attempts to open the given text file.

If the file is successfully opened, it copies from the file into the array the strings that start with an uppercase vowel and end with a lowercase vowel, checking that there is still available space in the array.

Then closes the file.

Example:

File content:

Anna Jack Elisa Ethan ada Daniela Adele Demi Ariel Omero Enea AchillE


Array content after loading:

Anna  Elisa  Adele  Omero  Enea


Returns -1 if the file opening fails.

Otherwise, returns the number of strings copied into the array
(the array may remain empty if the file does not contain suitable strings).

A function that:

Receives as input an array of strings and the number of strings currently stored in the array.

Displays the contents of the array using the notation index: string, arranging 3 strings per line
(the last line may contain fewer than 3 strings).

Example output:

0: Anna     1: Elisa     2: Adele
3: Omero    4: Enea


Does not return any value.

A function that:

Receives as input an array of strings, the number of strings stored in the array, a character, and two parameters (p1, p2).

Assigns to p1 the index of the first string that contains the given character (assigns -1 if not found).

Assigns to p2 the index of the second string that contains the given character (assigns -1 if not found).

Examples:

Array:

0: Anna   1: Elisa   2: Adele   3: Omero   4: Enea

Character	p1	p2
a	0	1
e	2	4
o	3	-1
u	-1	-1

Does not return any value.

A function that, using pointer arithmetic:

Receives as input an array of strings and the number of strings stored in the array.

Performs a circular right shift: each string is moved one position to the right; the last string is moved to the first position.

Example:

0: Anna  1: Elisa  2: Adele  3: Omero  4: Enea
-->
0: Enea  1: Anna   2: Elisa  3: Adele  4: Omero


Does not return any value.

The main function:

Must receive exactly one command-line argument, which is the name of a text file.
Otherwise, it displays the message
“ERROR: missing text file name”
and terminates by returning 1.

Declares an array of 10 strings, each of length 30 (10 and 30 are constants).

Calls the function to load the array from the file.

If the file opening fails, it displays
“ERROR: the text file does not exist”
and terminates by returning 2.

If the array contains no strings, it displays
“ERROR: empty array”
and terminates by returning 3.

Calls the function to display the array.

Asks the user to input a character.

Calls the function that searches for the character in the array and displays one of the following messages:

“the character is present in the strings with indices ... and ...”

“the character is present only in the string with index ...”

“the character is not present”

Calls the function that performs the array shift.

Calls again the function to display the array.

Returns 0. */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define DIM 30
#define R 10

int load_string(char m[][DIM], char *argv[])
{
    int result,cond1,cond2,counter = 0,len; 
    char name[DIM];

    FILE *fp;
    fp = fopen(argv[1], "r");

    if(fp == NULL) {
        result = -1; }
    else{
    while(fscanf(fp ,"%s", name) != EOF )
    {
        len = strlen(name)-1; 

        cond1 = (name[0] == 'A' || name[0] == 'E' || name[0] == 'I' || name[0] == 'O' || name[0] == 'U');
        cond2 = (name[len] == 'a' || name[len] == 'e' || name[len] == 'i' || name[len] == 'o' || name[len] == 'u');

        if(cond1 && cond2 && counter < R) {
            strcpy(m[counter], name);
            counter++;
        }

        result = counter;
    }}

    fclose(fp);
    return result;
}

void visual_vector(char m[][DIM], int copied)
{
    int i;
    for(i = 0; i < copied; i++)
    {
        printf("%d:%s\t",i, m[i]);
        if(i > 0 && (i+1)%3 == 0) printf("\n");
    }
}

void char_finder(char m[][DIM],char c,int copied, int *p1, int *p2)
{
    int i;
    (*p1) = -1;
    (*p2) = -1;

    for(i = 0; i < copied && (*p1 == -1 || *p2 == -1); i++)
    {
        if(strchr(m[i], c) != NULL ) {
            if(*p1 == -1) *p1 = i;
                else 
                *p2 = i; }
    }
}

void shift_func(char (*m)[DIM], int *p_copied)
{
    int i;
    for(i = *(p_copied); i > 0; i--)
    {
        char name[DIM];

        strcpy(name,m[*(p_copied)-1]); //m[last]

        for(i = *(p_copied)-1; i > 0; i--)
        {
            strcpy(*(m+i), *(m+i-1));
            strcpy(*m, name);
        }
    }
}


int main (int argc, char *argv[])
{
    int copied, x,y;
    if(argc != 2) {
        printf("Error: file name missing\n");
        exit(1); }
    
    char m[R][DIM], c;

    copied = load_string(m,argv);
    if(copied == -1) {
        printf("Error: file does not exist\n");
        exit(2);}

    if(copied == 0) {
        printf("Error: file does not contain any string\n");
        exit(3);}

    visual_vector(m,copied);

    printf("\nEnter a char: ");
    scanf("%c", &c);
    char_finder(m,c,copied,&x,&y);

    if(x == y) 
        printf("\nThe char is present only at %d row\n", x);
    if(x != y)
        printf("\nThe char is present in row %d and row %d\n", x,y);
    if(x == -1)
        printf("\nThe char is not present\n");

    shift_func(m,&copied);
    visual_vector(m,copied);

    return 0; 
}