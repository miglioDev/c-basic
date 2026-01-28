// Checks whether the first input string is contained within the second one using strstr,
// practicing string and argument validation

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 3) {
        printf("Error - enter 2 string\n");}

    if(strstr(argv[1], argv[2]) == NULL) {
        exit(EXIT_FAILURE); }

    else {
        printf("%s contain %s!\n",argv[1],argv[2]);
        exit(EXIT_SUCCESS); }

    return 0;
}