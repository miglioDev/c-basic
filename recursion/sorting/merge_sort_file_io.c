// generate 100 random integers save them to a text file, load them into an array, 
// sort the array using Merge Sort, and print the sorted result
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 100

void load_file(FILE *fp);
void load_arr(FILE *fp, int arr[]);
void print_arr(int a[]);
void MergeSort(int a[], int p, int r);
void merge(int a[], int p, int q, int r);

int main ()
{
	srand(time(NULL));
	int arr[DIM];
	
	FILE *fp = fopen("text.txt","w+");
	if(fp == NULL) {
		printf("Error file\n");
		exit(EXIT_FAILURE);
	}
	
	load_file(fp);
	rewind(fp);
	load_arr(fp, arr);
	print_arr(arr);

	MergeSort(arr,0,DIM-1);
	printf("\nSorted Array:\n");
	print_arr(arr);
	
	fclose(fp);

	return 0;
} 

void load_file(FILE *fp)
{
	int i,x;
	
	i = 0;
	
	while(i < DIM)
	{
		x = rand()%1000;
		fprintf(fp,"%d\t",x);
		i++;
	}
}

void load_arr(FILE *fp, int arr[])
{
	for(int i = 0; i < DIM ; i++)
	{
		fscanf(fp,"%d",&arr[i]);
	}
}

void print_arr(int a[])
{
	printf("Array:\n");
	for(int i = 0; i < DIM; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void MergeSort(int a[], int p, int r)
{
	int q;
	
	if(p < r) {
		q = (p + r)/2;
		
		MergeSort(a,p,q);
		MergeSort(a,q+1,r);
		
		merge(a,p,q,r);
	}

}

void merge(int a[], int p, int q, int r)
{
	int i,j,k;
	
	int *B;
	B = malloc((r+1) * sizeof(int));
	if(B == NULL) {
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	
	i = p;
	j = q+1;
	k = p;
	
	while(i <= q && j <= r)
	{
		if(a[i] < a[j]) {
			B[k++] = a[i++];
		}
		else 
			B[k++] = a[j++];
	}

	while(i <= q)
		B[k++] = a[i++];

	while(j <= r)
		B[k++] = a[j++];
		
	for(k = p; k <= r; k++)
	{
		a[k] = B[k];
	}
	
	free(B);
}
