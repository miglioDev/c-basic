// Program that practices arrays, file and functions: fills an integer array with random one- or two-digit values, 
// prints indices and values, and writes odd numbers first then even numbers to a file on separate lines

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define DIM 16

void load_string(int v[DIM]);
void visual_vect(int v[DIM]);
void load_vec_on_file(int v[DIM], char *file_name);

int main()
{
    int v[DIM];

    srand(time(NULL));

    load_string(v);
    visual_vect(v);
    load_vec_on_file(v,"text.txt");

    return 0;
}

void load_string(int v[DIM])
{
    int i;
    for(i = 0; i < DIM; i++)
    {
        v[i] = rand()%100;
    }
}

void visual_vect(int v[DIM])
{
    int i;

    printf("\nIndex: ");
    for(i = 0; i < DIM; i++)
    {
        printf("%d\t",i);
    }

    printf("\nValue: ");
    for(i = 0; i < DIM; i++)
    {
        printf("%d\t",v[i]);
    }
}

void load_vec_on_file(int v[DIM], char *file_name)
{
    FILE *fp;
    fp = fopen(file_name, "w");

    for(int i = 0; i < DIM; i++)
    {
        if(v[i]%2 == 0 ) {
        fprintf(fp, "%d\t",v[i]); }
    }

    fprintf(fp, "\n");

    for(int i = 0; i < DIM; i++)
    {
        if(v[i]%2 == 1 ) {
        fprintf(fp, "%d\t",v[i]); }
    }
}