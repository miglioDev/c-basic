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
    char buffer[C];

    FILE *fp;
    fp = fopen(file_name, "r");

    if(fp == NULL) {
        res = 0; }

    else {
        r = 0;

        while(fscanf(fp, "%s", buffer) != EOF && r < R)
        {
            len = strlen(buffer);
            cond1 = ();
            cond2 = ();

            if(cond1 && cond2) {
                strcpy(m[r],buffer);
                r++; }
        }

    }

    return  res;
}

int print_matrix(char m[][C])
{
    //if file empty r

    //else print
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
    int n,x,lf;
    char m[R][C];

    if(argc != 2) {
        printf("Error 1: wrong number of argument\n");
        exit(1); }
    
    lf = load_from_file(m,argv[1]);

    return 0;
}