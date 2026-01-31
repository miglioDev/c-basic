// Program that checks whether a given word is already present in a file and appends it if missing, 
// practicing file I/O, command-line arguments, and string comparison

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
    if(argc != 3) {
        printf("Argument incorrect\n");
        exit(2); }

    FILE *fp;
    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("File does not exits\n");
        exit(3); }

    else {
        int pres = 0;
        char s[30];
        while(fscanf(fp, "%s", s) != EOF && !pres) {
        if(strcmp(argv[2], s) == 0) { 
            pres = 1; }
    
    if(pres) {
        exit(EXIT_FAILURE); }}
        fclose(fp); }

    fp = fopen(argv[1] , "a");
    fprintf(fp, "%s\n" ,argv[2]);
    fclose(fp);
    
    exit(EXIT_SUCCESS);
}