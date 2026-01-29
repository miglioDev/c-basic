// Copies the contents of a source text file into a destination file 
// handling file existence, empty file checks and argument count validation


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
    if(argc != 3) {
        printf("Error 3: wrong argument\n");
        exit(3); }

    if (strcmp(argv[1], argv[2]) == 0)
	{
		printf("Error - string have the same name\n");
		exit(EXIT_FAILURE);
	}

    
    FILE *fp1;
    fp1 = fopen(argv[1], "r");
    if(fp1 == NULL) {
        printf("Error 1: unable to read file\n");
        exit(EXIT_FAILURE); }

    else {
        char buffer[50];

        if(fscanf(fp1, "%s", buffer) == EOF) {
            printf("Error 2: file empty\n");
            exit(2); }
        rewind(fp1);

        FILE *fp2;
        fp2 = fopen(argv[2], "w");

        while(fscanf(fp1, "%s", buffer) != EOF) 
        {
            fprintf(fp2,buffer);
            fprintf(fp2,"\n");
        }
        fclose(fp1);
        fclose(fp2);

        exit(EXIT_SUCCESS);
    }
    
    return 0;
}