// Reads up to R strings from a file into a matrix, sorts them with selection sort, and prints the result
// Practice: file I/O strings handling and basic sorting algorithms

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define R 8
#define C 16

int read_file(char m[][C],char *file_name);
void selection_sort(char m[][C]);
void print_string(char m[][C]);

int main()
{
    int copied;
    char m[R][C];
    
    copied = read_file(m,"text.txt");
    printf("%d string have been copied from the file\n",copied);

    selection_sort(m);
    print_string(m);

    return 0;
}

int read_file(char m[][C],char *file_name)
{
    int r,copied;
    char buffer[C];

    FILE *fp;
    fp = fopen(file_name, "r");
    if(fp == NULL) {
        printf("Error: unable to read file");
        exit(EXIT_FAILURE); }

    r = 0;
    copied = 0;

    while(fscanf(fp, "%s", buffer) != EOF && r < R)
    {
        strcpy(m[r],buffer);
        r++;
        copied++;
    }

    while(r < R)
    {
        m[r][0] = '\0';
        r++;
    }

    return copied;
}

void selection_sort(char m[][C])
{
    int r,j;
    char temp[C];

    for(r = 0; r < R; r++)
    {
        for(j = r+1; j < R; j++)
        {
            if(strcmp(m[r],m[j]) > 0) {
                    strcpy(temp,m[r]);
                    strcpy(m[r],m[j]);
                    strcpy(m[j],temp);
                }
        }
    }
}

void print_string(char m[][C])
{
    int r = 0;

    for(r = 0; r < R && m[r][0] != '\0'; r++)
    {
        printf("%d) %s\n",r,m[r]);
    }
}