// Program that loads strings from a text file into an array, fills missing slots with empty strings,
// and writes the non-empty strings to another file in reverse order to practice file I/O and string arrays.

#include <stdio.h>
#include <string.h>
#define R 5 
#define C 25

void load_vec_from_file(char m[][C], char *file_name); 
void copy_on_a_second_file(char m[][C], char *new_file_name);

int main ()
{
    char m[R][C];

    load_vec_from_file(m,"text.txt");
    copy_on_a_second_file(m, "new_text.txt");

    return 0;
}

void load_vec_from_file(char m[][C], char *file_name)
{
    FILE *fp;
    fp = fopen(file_name, "r");

    if(fp == NULL) {
        printf("Error - file missing\b");
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

void copy_on_a_second_file(char m[][C], char *new_file_name)
{
    int last = 0;
    while(m[last][0] != '\0') {last++; } printf("last = %d", last);

    FILE *fp;
    fp = fopen(new_file_name, "w");

    for(; last >= 0; last--)
    {
        fprintf(fp,"%s\n", m[last-1]);
    }

    fclose(fp);
}