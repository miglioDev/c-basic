/*
EXAM 04 - Programming in C 

Implement the following functions and a main program 


Function 1

Write a function that:

Receives as input a square matrix of integers (initially undefined) and the matrix size (dim).

Asks the user to enter an integer value (x) that must be strictly positive and made of exactly one digit.
Example: 4

As long as x does not satisfy these requirements, it displays the message
“ERROR: the value is not correct” and asks again for the value.

Fills the matrix with multiples of x, inserting them row by row, until the matrix is completely filled.

Example:

dim: 3   x: 4
-->
4   16  28
8   20  32
12  24  36


The function does not return any value.

Function 2

Write a function that:

Receives as input a square matrix of integers and its dimension.

Displays the values stored in the matrix together with their corresponding indices, as shown in the example.

Example:

    0   1   2
  * * *
0 4  16  28 *
1 8  20  32 *
2 12 24  36 *


The function does not return any value.

Function 3 (using pointer arithmetic)

Write a function that:

Receives as input a square matrix of integers, the matrix dimension, and two parameters (p1, p2).

Stores in p1 the sum of the values located on the first row and the first column.

Stores in p2 the arithmetic mean of the values located on the first row and the first column.

Example:

4   16  28
8   20  32
12  24  36
-->
p1: 68
p2: 13.600000


The function does not return any value.

Function 4

Write a function that:

Receives as input a square matrix of integers, the matrix dimension, the name of a text file, and the number (q) of rows to copy into the file.

Returns 0 if the given quantity is not compatible with the matrix dimension.

Otherwise, copies the first q rows of the matrix into the file, then closes the file and returns 1.

Example:

q: 2
matrix:
4   16  28
8   20  32
12  24  36
-->
file:
4   16
8   20
12  24

Main Function

Write the main function that:

Must receive exactly two command-line parameters:

The dimension of the square matrix

The name of a text file
Otherwise, it displays the message
“ERROR: incorrect number of parameters” and terminates returning 1.

Declares a square matrix using the dimension received as input.

Calls the function that fills the matrix.

Calls the function that displays the matrix values.

Calls the function that computes sum and average, and prints the results:

"the sum of row ... and column ... is ..."

"the average of row ... and column ... is ..."

Asks the user for the number of rows to copy into the file and calls the dedicated function.

If the copy operation fails, it displays
“ERROR: file copy failed” and terminates returning 2.

Otherwise, it displays
“file copy completed successfully” and returns 0.
*/

#include <stdlib.h>
#include <stdio.h>

void load_matrix( int dim, int m[dim][dim])
{
    int x,ok,i,j;
    do 
    {
    printf("\nEnter number (x) for matrix loading: "); 
    scanf("%d",&x);
    ok = (x > 0 && x < 10);
    if(!ok) printf("\nError: not correct value");
    }
    while(!ok);

    int counter = 1;
    for(i = 0; i < dim; i++)
    {
        for(j = 0; j < dim; j++)
        {
            m[i][j] = counter*x;
            counter++;
        }
    }
}

void printf_matrix( int dim, int m[dim][dim])
{
    int i,j;

    printf("\n\t");
    for(i = 0; i < dim; i++)
    {
        printf("\t%d",i);
    }
    printf("\n\t");
    for(i = 0; i < dim; i++)
    {
        printf("\t*");
    }
    
    printf("\n");
    for(i = 0; i < dim; i ++)
    {
        printf("%d\t*",i);
        for(j = 0; j < dim; j++)
        {
            printf("\t%d",m[i][j]);
        }
        printf("\n");
    }
}

void stats_matrix(int dim, int (*m)[dim], float *p1, float *p2)
{
    int i,j;

    for(j = 0; j < dim;j++)
    {
        *p1 = *p1 + *((*m)+j);
    }
    for(i = 1; i < dim; i++)
        {
             *p1 = *p1 + *(*(m+i)); 
        }

    *p2  = *p1/(dim*2-1);
}

int file_copy(int dim, int m[][dim], int row_copy, char *argv[])
{
    int result,i,j;
    if(row_copy > dim) {
        result = 0;
        exit(0); }
    
    FILE *fp;
    fp = fopen(argv[2], "w");

    for(i = 0; i < row_copy; i++)
    {
        for(j = 0; j < dim; j++)
        {
        fprintf(fp, "\t%d", m[i][j]);
        }
        fprintf(fp, "\n");
    }
    result = 1;
    fclose(fp);
    
    return result;
}

int main (int argc, char *argv[]) 
{
    if(argc != 3) {
        printf("Error: number of input incorrect\n"); 
        exit(1); }
    
    int c = atoi(argv[1]);

    int m[c][c],row_copy,res;
    float average,sum = 0;

    load_matrix(c,m);
    printf_matrix(c,m);
    stats_matrix(c,m,&sum,&average);
        
    printf("\nThe sum of the row 0 and column 0 is: %f",sum);
    printf("\nThe average of the elements is: %f",average);

    printf("\nEnter the number of row you need to copy: ");
    scanf("%d",&row_copy);

    res = file_copy(c,m,row_copy,argv);
    if(res == 0) {
        printf("\nError: copy on file failed\n"); }
        else {
            printf("File copied successfully\n");}

    return 0;
}