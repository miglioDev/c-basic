// Program that loads strings from a text file into an array, sorts the non-empty strings alphabetically
// using selection sort, and writes the ordered strings to a second text file

#include <stdio.h>
#include <string.h>
#define R 5
#define C 25

void load_m_from_file(char m[][C], char *file_name);
void order_string(char m[][C]);
void copy_on_second_file(char m[][C], char *file_name);

int main ()
{
    char m[R][C];

    load_m_from_file(m,"text.txt");
    order_string(m);
    copy_on_second_file(m,"second_file.txt");

    return 0;
}

void load_m_from_file(char m[][C], char *file_name)
{
    FILE *fp;
    fp = fopen(file_name, "r");

    if(fp == NULL) {
        printf("Error -- file\n");
        return; }
    
    else {
        int i = 0;
        while(fscanf(fp,"%s",m[i]) != EOF && i < R)
        {
            i++;
        }

        while(i < R) 
        {
            m[i][0] = '\0';
            i++;
        }
        fclose(fp);
    }
}

void order_string(char m[][C])
{
    int i,p;
    char buffer[C];

    for(i = 0; i < R && strlen(m[i]) > 0; i++)
    {
        for(p = i+1; p < R && strlen(m[p]); p++)
        {
        if(strcmp(m[i],m[p]) > 0) {
            strcpy(buffer,m[i]);
            strcpy(m[i],m[p]);
            strcpy(m[p],buffer); }
        }
    }
}

void copy_on_second_file(char m[][C], char *file_name)
{
    FILE *fp;
    fp = fopen(file_name, "w");

    int i;
    for(i = 0; i < R && strlen(m[i]) > 0; i++)
    {
        fprintf(fp,"%s\n",m[i]);
    }
     
    fclose(fp);
}