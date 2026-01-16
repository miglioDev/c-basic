// Reads strings from a file and stores only those composed of alphabetic characters,
// with length >= 3, starting with an uppercase letter and ending with a lowercase letter;
// then fills the string array and prints it.

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define R 5
#define C 25

void load_from_file(char *file_name,char m[R][C]);
void print_all_string(char m[][C]);
int alpha(char s[C]);

int main()
{
    char m[R][C];

    load_from_file("text.txt",m);
    print_all_string(m);

    return 0;
}

void load_from_file(char *file_name,char m[R][C])
{
    FILE *fp;
    fp = fopen(file_name,"r");
    if(fp == NULL) { 
        return; }
    
    else {
    int copied = 0;
    int len;
    char buffer[C];
        while(fscanf(fp, "%s", buffer) != EOF && copied < R)
        {
            len = strlen(buffer);
            printf("buffer: %s string: copied %d\n",buffer,copied);

            if(alpha(buffer) && len >= 3 && isupper(buffer[0]) && islower(buffer[len-1])) {
                strcpy(m[copied],buffer);
                copied++;}
            }
            fclose(fp);
        
        while(copied < R)
        {
            m[copied][0] = '\0';
            copied++;
        }
    }
}

int alpha(char s[C])
{
    int c = 1,len,i;
    len = strlen(s);

    for(i = 0; i < len; i++)
    {
        if(!isalpha(s[i])) {
            c = 0; }
    }

    return c;
}

void print_all_string(char m[][C])
{
    int i;
    
    for(i = 0; i < R; i++)
    {
        printf("\n%d | %s",i,m[i]);
    }
}