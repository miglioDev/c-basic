#include <stdio.h>
#include <string.h>
#define R 5
#define C 25

void load_m_from_file(char m[][C], char *file_name);

int main ()
{
    char m[R][C];

    load_m_from_file(m, "text.txt");
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

        while(copied < R) 
        {
            m[copied][0] = '\0';
            copied++;
        }
        fclose(fp);
    }
}