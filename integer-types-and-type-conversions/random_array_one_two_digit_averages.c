// Program that fills an integer array with random positive 1- or 2-digit numbers,
// prints indices and values, and computes the average of 1-digit and 2-digit elements.

#include <stdlib.h>
#include <stdio.h>
#define DIM 12

void load_vec(int v[DIM]);
void visual_vec(int v[DIM]);
void stats_vec(int v[DIM], float *p1, float *p2);

int main ()
{
    int v[DIM];
    float x,y;

    load_vec(v);
    visual_vec(v);
    stats_vec(v,&x,&y);

    if(x == 0) {
    printf("\nThe sum of one digit number cant be calculated\n"); }
        else {
        printf("\nThe sum of one digit number is %.4f\n",x);}  
    if(y == 0) {
    printf("\nThe sum of two digit number cant be calculated\n"); }
        else {
        printf("\nThe sum of two digit number is %.4f\n",y);}    
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

void visual_vec(int v[DIM])
{
    int i;

    printf("\nIndex:\t");
    for(i = 0; i < DIM; i++)
    {
        printf("%d\t",i);
    }

    printf("\nValue:\t");
    for(i = 0; i < DIM; i++)
    {
        printf("%d\t",v[i]);
    }
}

void stats_vec(int v[DIM], float *p1, float *p2)
{
    int i,sum1 = 0,sum2 = 0,c1 = 0,c2 = 0;

    for(i = 0; i < DIM; i++)
    {
        if(v[i] >= 0 && v[i] < 10) {
            sum1 = sum1+v[i];
            c1 ++;}

        if(v[i] >= 10 && v[i] < 100) {
            sum2 = sum2+v[i];
            c2++; }
    }
    if(c1 == 0) {
    *p1 = 0; }
        else {
        *p1 = (float) sum1/c1; }
    
    if(c2 == 0) {
    *p2 = 0;}
        else { 
        *p2 = (float) sum2/c2; }
}