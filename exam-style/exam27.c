/*
EXAM 27 – Programming in C

Implement the following functions and a main program.

I will soon add the correct text
1) add exam 27 


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
        len = strlen((*m+r));

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