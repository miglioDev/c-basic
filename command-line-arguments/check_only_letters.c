// Checks whether exactly one command-line string is provided 
// then verifies that it contains only alphabetic characters

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char *argv[])
{
    if(argc == 1) {
        printf("Error 2: string not found\n");
        exit(2); }

    if(argc > 2) {
        printf("Error 3: too many argument\n");
        exit(3); }

    int len,i;
    len = strlen(argv[1]);

    for(i = 0; i < len-1; i++) 
    {
        if(!isalpha(argv[1][i])) {
            printf("The string does NOT contain only alpha\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("The string contain only alpha\n");
    exit(EXIT_SUCCESS);

    return 0;
}