// This program reads a valid time (hours 0-23, minutes 0-59, seconds 0-59) 
// and formats it as HH:MM:SS in a string,
// practicing input validation and string formatting with sprintf/strcat.

#include <stdio.h>
#include <string.h>
#define dim 16

void read_time(int *h, int *m, int *s);
void string_time(char time[], int ho, int mi, int se);

int main ()
{
    char time[dim];
    int ho,mi,se;
    int *h = &ho;
    int *m = &mi; 
    int *s = &se;

    read_time(&ho,&mi,&se);
    string_time(time,ho,mi,se);

    printf("The time is: %s\n", time);

    return 0;
}

void read_time(int *h, int *m, int *s)
{   
    int ok;
    do
    {
    printf("== Enter the time ==\nHour: ");
    scanf("%d", &(*h));
    printf("\nMin: ");
    scanf("%d", &(*m));
    printf("\nSec: ");
    scanf("%d", &(*s));

    ok = (*h <= 23 && *h >= 0 && *m <= 59 && *m >= 0 && *s <= 59 && *s >= 0);
    if(!ok) printf("\n-- Error --\n");

    }
    while(!ok);
}

void string_time(char time[], int ho, int mi, int se)
{   
    char sh[dim];
    char sm[dim];
    char ss[dim];

    if (ho <= 9)
        sprintf(sh, "0%d:", ho);
    else 
        sprintf(sh, "%d:", ho);

    if (mi <= 9)
        sprintf(sm, "0%d:", mi);
    else 
        sprintf(sm, "%d:", mi);


    if (ho <= 9)
        sprintf(ss, "0%d", ho);
    else 
        sprintf(ss, "%d", ho);


    strcpy(time,sh);
    strcat(time,sm);
    strcat(time,ss);
}