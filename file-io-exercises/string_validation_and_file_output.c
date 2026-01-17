// Program that practices string handling: validates alphabetic-only strings, loads strings from user input,
// and writes to a file only those strings that meet specific formatting rules (length, case, alphabetic)
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define C 20
#define R 5

void load_string(char v[][C]);
void copy_on_file(char *file_name, char v[][C]);
int only(char s[]);

int main ()
{
    char v[R][C];

    load_string(v);
    copy_on_file("text.txt",v);

    return 0; 
}

void load_string(char v[][C])
{
    int r;
    
    for(r = 0; r < R; r++)
    {
        printf("\nEnter string n.%d:  ",r);
        scanf(" %s", &v[r][0]);
    }
}

void copy_on_file(char *file_name, char v[][C])
{
    int r,len;
    FILE *fp;
    fp = fopen(file_name, "w");
    
    for(r = 0; r < R; r++)
    {
        len = strlen(v[r]);

        if(len >= 3 && only(v[r]) && isupper(v[r][0]) && islower(v[r][len-1])) { 
        fprintf(fp,"%s\n",v[r]);
        }
    }
    fclose(fp);
}

int only(char s[])
{
    int i,len,cond = 1;

    len = strlen(s);

    for(i = 0; i < len; i++)
    {
        if(!isalpha(s[i])) {
            cond = 0; }
    }

    return cond;
}

