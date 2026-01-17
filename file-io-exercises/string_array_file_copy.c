// Reads strings from a file into a string array, fills missing entries with empty strings,
// then writes all non-empty strings to another file to replicate the original content

#include <stdio.h>
#include <string.h>
#define R 5
#define C 25

void read_and_load(char v[][C], char *file_name);
void write_string_2file(char v[][C], char *file_name);

int main ()
{
    char v[R][C];

    read_and_load(v,"text.txt");
    write_string_2file(v,"second_file_text.txt");

    return 0;
}

void read_and_load(char v[][C], char *file_name)
{
    FILE *fp;
    fp = fopen(file_name,"r");

    if(fp == NULL) {
        printf("Error -"); 
        return; }
    
    char buffer[C];
    int r = 0;
    while(fscanf(fp,"%s",buffer) != EOF && r < R) //fgets
    {
        strcpy(v[r], buffer);
        r++;
    }
    fclose(fp);

    while(r < R)
    {
        v[r][0] = '\n';
        r++;
    }
}

void write_string_2file(char v[][C], char *file_name)
{
    FILE *fp;
    fp = fopen(file_name, "w");

    int r = 0;
    while(strlen(v[r]) > 0)
    {
        fprintf(fp,"%s\n",v[r]); //fputs
        r++;
    }

    fclose(fp);
}