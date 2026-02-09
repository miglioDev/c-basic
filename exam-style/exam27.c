/*
EXAM 27 – Programming in C

Implement the following functions and a main program.


1) add exam 27 


*/

#include <stdio.h>
#include <stdlib.h>

int load_from_file()
{
    int res;

    return  res;
}

int main(int argc, char *argv[])
{
    int n,x,lf;

    if(argc != 3) {
        printf("Error 1: wrong number of argument\n");
        exit(1); }

    if(atoi(argv[3]) == 0) {
        printf("Error 2: non valid argument\n");
        exit(2); }
    
    
    
    lf = load_from_file();

    return 0;
}