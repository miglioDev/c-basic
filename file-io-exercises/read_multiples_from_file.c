// Reads integers from a file, stores only the multiples of x into an array,
// fills remaining positions with zeros, and prints indices and values.

#include <stdio.h>
#include <stdlib.h>
#define DIM 15

void load_file(int v[DIM], char *file_name, int x);
void visual(int v[DIM]);

int main ()
{
    int x;
    int v[DIM] = {0, 2, 5, 3, 7, 8, 45, 22, 19};

    printf("Enter an integer: ");
    scanf("%d", &x);

    load_file(v,"text.txt",x);
    visual(v);

    return 0;
}

void load_file(int v[DIM], char *file_name, int x)
{
    int value,counter = 0;
    FILE *fp;
    fp = fopen(file_name, "r");
    if(fp == NULL) {
        printf("Error - file missing\n");
        return; }

    else 
    {
        while(counter < DIM && fscanf(fp,"%d",&value) == 1)
        {
            if(value % x == 0) {
                v[counter] = value;
                counter++;
            }
        }

        while(counter < DIM)
        {
            v[counter] = value;
            counter++;
        }

    fclose(fp);
    }
}

void visual(int v[DIM])
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