// Reads strings from a file into an array, removes punctuation characters from each string,
// and writes the cleaned non-empty strings to a new file
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define R 5
#define C 25

void copy_from_file(char m[][C], char *file_name);
void remover(char m[][C]);
void write_on_new_file(char m[][C], char *file_name);

int main ()
{
    char m[R][C];

    copy_from_file(m,"text.txt");
    remover(m);
    write_on_new_file(m,"new_file.txt");

    return 0;
}

void copy_from_file(char m[][C], char *file_name)
{
    int copied = 0;

    FILE *fp;
    fp= fopen(file_name, "r");

    if(fp == NULL) {
        printf("Error file not found\n");
        return; }

    else {
        while(fscanf(fp,"%s",m[copied]) != EOF && copied < R) //fgets
        copied++ ;
    }

    while(copied < R) 
    {
        m[copied][0] = '\0';
        copied++;
    }
    fclose(fp);
}

void remover(char m[][C])
{
    int r,c = 0,k,len;

    for(r = 0; r < R; r++)
    {
        len = strlen(m[r]);
        for(c = 0; c < len; c++)
        {
            if(m[r][c] == '.' || m[r][c] == ';' || m[r][c] == ':' || m[r][c] == '?' || m[r][c] == '!') {
            for(k = c; m[r][k] != '\0'; k++) 
            { 
                m[r][k] = m[r][k+1]; 
            } }
        }
    }
}

void write_on_new_file(char m[][C], char *file_name)
{
    FILE *fp;
    fp = fopen(file_name, "w");

    int r;
    for(r = 0; m[r][0] != '\0'; r++)
    {
        fprintf(fp,"%s\n",m[r]);
    }
    fclose(fp);
}
