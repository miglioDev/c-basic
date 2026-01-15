// This program loads an integer matrix from a file row by row,
// fills missing elements with zeros if needed, and prints indices and values

#include <stdio.h>
#define R 3
#define C 3

void load_file(int m[3][3], char *file_name);
void print_matrix(int m[R][C]);

int main()
{
    int m[R][C];

    load_file(m,"text.txt");
    print_matrix(m);

    return 0; 
}

void load_file(int m[3][3], char *file_name)
{
    int x,r = 0,c = 0;
    FILE *fp;
    fp = fopen(file_name, "r");

    if(fp == NULL) {
    printf("Error on file opening\n");
    return; }

        else {
        while(r < R && fscanf(fp, "%d", &x) != EOF)
        {
            m[r][c] = x;
            c++;

            if(c == C) {
                c = 0;
                r++; }
        }
        fclose(fp);
        }
            while(r < R)
            {
            m[r][c] = 0;
            c++;

            if(c == C) {
                c = 0;
                r++; }
            }
}

void print_matrix(int m[R][C])
{
    int r,c;

    printf("\t");
    for(c = 0; c < C; c++)
    {
        printf("%d\t",c);
    }
    printf("\n");

    for(r = 0; r < R; r++)
    {
        printf("%d |\t",r);
        for(c = 0; c < C; c++)
        {
            printf("%d\t",m[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}