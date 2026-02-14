/*
EXAM 27 – Programming in C

Implement the following functions and a main program.


## **Function 1**

A function that:

* takes as input a matrix of characters, its fixed dimensions, and the name of a text file;
* reads words from the file and copies into the matrix only the words that:

  * start with an uppercase alphabetic character;
  * end with the lowercase version of the first character;
* stops when the matrix is full or the file ends;
* fills the remaining rows with an empty string (`'\0'` as first character);
* closes the file;
* returns `0` if the file cannot be opened, otherwise returns `1`.

Example:

File contents: Anna Otto Level Test Ada Bob Civic

Resulting matrix:

```
Anna
Otto
Ada
Bob
Civic
```

## **Function 2**

A function that:

* takes as input a matrix of strings terminated by an empty string;
* returns `1` if the matrix is empty;
* otherwise prints each row index and the corresponding string (as shown in the example) and returns `0`.

Example output:

```
0)   Anna
1)   Otto
2)   Ada
```

---

## **Function 3**

A function that, using pointers and pointer arithmetic:

* takes as input a matrix of strings, a character `c`, and two integer pointers (`p1`, `p2`);
* searches for the first two rows that contain the character `c`;
* stores in `p1` the index of the first row where `c` is found;
* stores in `p2` the index of the second row where `c` is found;
* if the character is not found, both values remain `-1`;

The function does not return any value.

Example:

Matrix:

```
Anna
Otto
Ada
```

Search `c = 'a'` → `p1 = 0`, `p2 = 2`

---

## **Function 4**

A function that:

* takes as input a matrix of strings terminated by an empty string;
* performs a right circular shift of the rows. (moving the last string to the first position and shifting all others down by one position).

Example:

```
Anna
Otto
Ada
```

After shift:

```
Ada
Anna
Otto
```

The function does not return any value.

---

## **`main` Function**

The `main` function:

* must receive exactly one command-line argument: the name of the text file. Otherwise, it prints

  `"Error 1: wrong number of argument"`

  and terminates returning `1`;

* declares a matrix of characters with fixed size;

* calls the function that loads the matrix. If the file does not exist, it prints

  `"Error 2: file not found"`

  and terminates returning `2`;

* calls the function that prints the matrix. If the matrix is empty, it prints

  `"Error 3: empty matrix"`

  and terminates returning `3`;

* asks the user to enter a character;

* calls the function that searches for the character and:

  * prints `"Char X not found"` if not found;
  * prints `"One result in row ..."` if found once;
  * prints `"Found X in row ... and row ..."` if found twice;

* calls the function that performs the right circular shift;

* calls again the function that prints the matrix;

* returns `0`.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define R 5
#define C 30

int load_from_file(char m[][C], char *file_name)
{
    int res,r,len,cond1,cond2;
    char buffer[C],c;

    FILE *fp;
    fp = fopen(file_name, "r");

    if(fp == NULL) {
        res = 0; }

    else {
        r = 0;

        while(fscanf(fp, "%s", buffer) != EOF && r < R)
        {
            len = strlen(buffer);
            cond1 = (isupper(buffer[0]) && isalpha(buffer[0]));
            c = tolower(buffer[0]);
            cond2 = (buffer[len-1] == c);

            if(cond1 && cond2) {
                strcpy(m[r],buffer);
                r++; }
        }
        fclose(fp);

        while(r < R)
        {
            m[r][0] = '\0';
            r++;
        }

        res = 1;
    }

    return  res;
}

int print_matrix(char m[][C])
{
    int res,r;

    if(m[0][0] == '\0') {
        res = 1; }

    else {
        for(r = 0; m[r][0] != '\0'; r++)
        {
            printf("%d)\t%s\n",r,m[r]);
        }

        res = 0;
    }

    return res;
}

void char_finder(char (*m)[C], char c, int *p1, int *p2)
{
    int r,j,len;
    *p1 = -1;
    *p2 = -1;
    j = 0;

    for(r = 0; *(*(m+r)+0) != '\0' && *p2 == -1; r++)
    {
        len = strlen(*(m+r));

        for(j = 0; j < len && *p2 == -1; j++)
        {
            if( *(*(m+r)+j) == c) {
                if( *p1 == -1) {
                *p1 = r; }
                    else if( *p1 != -1 && *p2 == -1 ) {
                    *p2 = r; }
            }
        }
    }
}

void right_circular_shift(char m[][C])
{
    int r = 0;
    char buffer[C];

    while(m[r][0] != '\0')
    {
        r++; 
    }
    r--;

    strcpy(buffer,m[r]);

    for(; r > 0; r--)
    {
        strcpy(m[r],m[r-1]);
    }
    strcpy(m[0],buffer);
}

int main(int argc, char *argv[])
{
    int lf,pm,first,second;
    char m[R][C],cr;

    if(argc != 2) {
        printf("Error 1: wrong number of argument\n");
        exit(1); }
    
    lf = load_from_file(m,argv[1]);
    if(lf == 0) {
        printf("Error 2: file not found\n");
        exit(2); }

    pm = print_matrix(m);
    if(pm == 1) {
        printf("Error 3: empty matrix\n");
        exit(3); }

    printf("Enter a char: ");
    scanf(" %c", &cr);

    char_finder(m,cr,&first,&second);
    if(first == -1 && second == -1) {
    printf("Char %c not found\n",cr); }
        else if(first != -1 && second == -1) {
        printf("One result int row %d\n",first); }
            else if(first != -1 && second != -1) {
                printf("Found %c in row: %d and row: %d\n",cr,first,second); }

    right_circular_shift(m);
    print_matrix(m);

    return 0;
}
