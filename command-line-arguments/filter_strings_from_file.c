// Program that reads strings from a file and stores only those matching specific rules:
// alphabetic-only, minimum length, uppercase first letter, lowercase last letter
// Practice with strings, character checks, arrays of strings, file handling, and input validation.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define R 4
#define C 16

void load_v_string(FILE *fp, char m[][C]);
int all_alpha(char s[C]);
void visual(char m[][C]);

int main (int argc, char *argv[])
{
    FILE *fp;

    if(argc != 2) {
        printf("Error 1: number of argument incorrect\n");
        exit(1); }

    fp = fopen(argv[1],"r");
    if(fp == NULL) {
        printf("Error 2: non existing file\n");
        exit(2); }
    
    char m[R][C];
    load_v_string(fp,m);
    fclose(fp);

    visual(m);

    exit(EXIT_SUCCESS);
}

void load_v_string(FILE *fp, char m[][C])
{
    int r = 0,len,upper,lower,cond;
    char buffer[C];

    while(fscanf(fp, "%s", buffer) != EOF && r < C)
    {
        len = strlen(buffer);
        upper = 0;
        lower = 0;

        if(isupper(buffer[0])) {
            upper = 1; }
        if(islower(buffer[len-1])) {
            lower = 1; }

        cond = all_alpha(buffer);
        
        if(len > 3 && cond && upper && lower) {
            strcpy(m[r], buffer);
            r++; } 
    }   

    while(r < R)
    {
        m[r][0] = '\0';
        r++;
    }
}

int all_alpha(char s[C])
{
    int is = 1,len,i;
    len = strlen(s);

    for(i = 0; i < len; i++)
    {
       if(!isalpha(s[i])) {
        is = 0; } 
    }

    return is;
}

void visual(char m[][C])
{
    int r = 0;

    while(m[r][0] != '\0')
    {
        printf("%d|\t%s\n",r,m[r]);   
        r++;          
    }
}
