// Program that reads integers from a file, stores only multiples of a given non-zero value into an array,
// fills remaining positions with zeros, and prints non-zero elements with their indices
// Practice with files, arrays, functions, pointers, and input validation

#include <stdio.h>
#include <stdlib.h>
#define DIM 16

void load_vector(int v[DIM], FILE *fp, int x);
void print_vector(int v[DIM]);

int main (int argc, char *argv[])
{
    if(argc != 3) {
        printf("Error 1: wrong argument number\n");
        exit(1); }

    FILE *fp;
    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Error 2: wrong argument number\n");
        exit(2); }

    int x;
    x = atoi(argv[2]);
    if(x == 0) {
        printf("Error 3: second argument is not a number\n");
        exit(3); }

    int v[DIM];
    load_vector(v,fp,x);

    if(v[0] == 0) {
        printf("Error 4: the vector is empty");
        exit(4); }
    
    print_vector(v);

    return 0;
}

void load_vector(int v[DIM], FILE *fp, int x)
{
    int y,copied = 0;

    while(fscanf(fp, "%d", &y) != EOF && copied < DIM)
    {
        if(y % x == 0) {
            v[copied] = y;
            copied++; }
    }

    while(copied < DIM)
    {
        v[copied] = 0;
        copied++;
    }
}

void print_vector(int v[DIM])
{
    int i;

    for(i = 0; v[i] != 0; i++)
    {
        printf("Index: %d\tValue: %d\n",i,v[i]);
    }
}