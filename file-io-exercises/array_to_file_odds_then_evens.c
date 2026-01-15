// Program that fills an integer array with random 1 or 2 digit numbers,
// prints indices and values, and writes odd numbers first and even numbers
// to a file on two separate lines

#include <stdlib.h>
#include <stdio.h>
#define DIM 10

void load_vec(int v[DIM]);
void visual(int v[DIM]);
void load_data_on_file(int v[DIM], char *file_name);

int main ()
{
    int v[DIM];

    load_vec(v);
    visual(v);
    load_data_on_file(v,"text.txt");

    return 0;
}

void load_vec(int v[DIM])
{
    int i;

    for(i = 0; i < DIM; i++)
    {
        v[i] = rand()%100;
    }
}

void visual(int v[DIM])
{
    int i;

    printf("\nIndex:\t");
    for(i = 0; i < DIM; i++)
    {
        printf("%d\t",i);
    }
    printf("\n");

    printf("\nValue:\t");
    for(i = 0; i < DIM; i++)
    {
        printf("%d\t",v[i]);
    }
    printf("\n");
}

void load_data_on_file(int v[DIM], char *file_name)
{
    int j;
    FILE *fp;

    fp = fopen(file_name, "w");

    for(j = 0; j < DIM; j++)
    {
        if(v[j]%2 == 1) {
            fprintf(fp,"%d\t",v[j]); }
    }
    fprintf(fp,"\n");

    for(j = 0; j < DIM; j++)
    {
        if(v[j]%2 == 0) {
            fprintf(fp,"%d\t",v[j]); }
    }

    fclose(fp);
}