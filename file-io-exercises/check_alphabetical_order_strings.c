// Program that loads strings from a text file into an array, fills missing elements with empty strings,
// and checks whether the non-empty strings are in alphabetical order using strcmp

#include <stdio.h>
#include <string.h>
#define R 5
#define C 25

void load_m_from_file(char m[][C], char *file_name);
int compare(char m[][C]);

int main ()
{
    int alpha;
    char m[R][C];

    load_m_from_file(m,"text.txt");
    alpha = compare(m);
    if(alpha) {
    printf("The string are ordered\n"); }
        else {
            printf("The string are not ordered\n"); }

    return 0;
}

void load_m_from_file(char m[][C], char *file_name)
{
    FILE *fp;
    fp = fopen(file_name, "r");

    if(fp == NULL) {
        printf("Error - file missing\n");
        return; }
    
    else {
        int copied = 0;
        while(fscanf(fp,"%s",m[copied]) != EOF && copied < R)
        {
            copied ++;
        }
        fclose(fp);

        while(copied < R) 
        {
            m[copied][0] = '\0';
            copied++;
        }
    }
}

int compare(char m[][C])
{
    int r,t = 1;

    for(r = 0; r < R-1; r++)
    {
        if(strlen(m[r]) > 0 && strlen(m[r+1]) > 0) {
            if(strcmp(m[r],m[r+1]) > 0) {
                t = 0;
            }
        }
    }

    return t;
}