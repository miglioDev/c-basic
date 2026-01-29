// Validates two numeric operands and an arithmetic operator from command-line arguments, 
// practicing input checking and operator validation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc != 4) {
        printf("Error 1: number of argument incorrect\n");
        exit(EXIT_FAILURE); }

    if(atoi(argv[1]) == 0 || atoi(argv[2]) == 0) {
        printf("Error 2: one or more input is not a number\n");
        exit(2); }

    char op[1];
    strcpy(op, argv[3]); 
    int res;

    if(strcmp(op,"+") != 0 && strcmp(op,"-") != 0 && strcmp(op,"*") != 0 && strcmp(op,"/") != 0 ) {
        printf("Error 3: incorrect operator\n");
        exit(3); }

    switch (argv[3][0])
    {
    case '/':
        res = atoi(argv[1])/atoi(argv[2]);
        break;
    case '*':
        res = atoi(argv[1])*atoi(argv[2]);
        break;
    case '+':
        res = atoi(argv[1])+atoi(argv[2]);
        break;
    case '-':
        res = atoi(argv[1])-atoi(argv[2]);
        break;
    }

    printf("Result = %d\n",res);

    return 0;
}