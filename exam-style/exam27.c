/*
EXAM 27 – Programming in C

Implement the following functions and a main program.


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
        }

        res = 1;
    }

    return  res;
}

int print_matrix(char m[][C])
{
    int res,r,c,len;

    if(m[0][0] == '\0') {
        res = 1; }

    else {
        for(r = 0; m[r][0] != '\0'; r++)
        {
            len = strlen(m[r]);

            for(c = 0; c < len; c++)
            {
                printf("%d)\t%s\n",r,m[r]);
            }
        }
    }
}

void char_finder()
{
    //find first and second occ. of a user entered char
    //with pointer ar.
}

void right_circular_shift()
{
    //add circular shift
}

int main(int argc, char *argv[])
{
    int n,x,lf,pm;
    char m[R][C];

    if(argc != 2) {
        printf("Error 1: wrong number of argument\n");
        exit(1); }
    
    lf = load_from_file(m,argv[1]);
    if(lf == 0) {
        printf("Error 2: file not found\n");
        exit(2); }

    pm = print_matrix(m);
    if(pm == 0) {
        printf("Error 3: empty matrix\n");
        exit(3); }


    return 0;
}