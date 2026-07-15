/*
 * Exam 06 — Arrays: Generation, File I/O, Recursive Search, and QuickSort
 *
 * a) Write a function:
 *    void load(int *arr);
 *    that generates an array of random integers by using pointer dereferencing.
 *
 * b) Write a recursive function:
 *    void print_arr(int i, int arr[], int r);
 *    that prints the array to the terminal.
 *
 * c) Write a function:
 *    void save_on_file(char filename[], int arr[]);
 *    that saves the array to a text file whose name is provided as a command-line argument.
 *
 * d) Write a recursive function:
 *    int find_min_rec(int arr[], int n);
 *    that returns the minimum value contained in the array.
 *
 * e) Write a recursive function:
 *    int countx_rn(int arr[], int n, int x);
 *    that returns the number of occurrences of a value x entered by the user.
 *
 * f) Implement the QuickSort algorithm through the following functions:
 *    void swap(int i, int j, int A[]);
 *    int partition(int arr[], int p, int r);
 *    void QuickSort(int arr[], int p, int r);
 *    then print the sorted array.
 *
 * g) Write a main function that:
 *    - checks that the output filename is provided as a command-line argument;
 *    - generates the array and prints it recursively;
 *    - saves the unsorted array to the file;
 *    - finds and prints the minimum value;
 *    - asks the user for a value x and prints its number of occurrences;
 *    - sorts the array using QuickSort;
 *    - prints the sorted array.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 100

void load(int *arr);
void print_arr(int i, int arr[], int r);
void save_on_file(char filename[], int arr[]);
int min(int a, int b);
int find_min_rec(int arr[], int n);
int countx_rn(int arr[], int n, int x);
void swap(int i, int j, int A[]);
int partition(int arr[], int p, int r);
void QuickSort(int arr[], int p, int r);

int main(int argc, char *argv[])
{
	if(argc != 2) {
		printf("Missing output filename\n");
		exit(EXIT_FAILURE);
	}
	
	int p,r,Min,x,occ;
	int arr[DIM];
	
	srand(time(NULL));
	p = 0;
	r = DIM-1;
	
	load(&arr[0]);
	printf("\nArray:\n");
	print_arr(p,arr,r);
	
	save_on_file(argv[1],arr);
	Min = find_min_rec(arr,r);
	printf("\n\nMin = %d\n",Min);
	
	printf("\nEnter a number x: ");
	scanf("%d",&x);
	
	occ = countx_rn(arr,r,x);
	printf("\nThe number %d was found %d times\n",x,occ);
	
	QuickSort(arr,p,r);
	printf("\nSorted Array:\n");
	print_arr(p,arr,r);
	printf("\n");
}

void load(int *arr)
{
	for(int i = 0; i < DIM; i++)
	{
		*(arr+i) = rand()%100;
	}
}

void print_arr(int i, int arr[], int r)
{	
	if(i <= r) {
		printf("%d ",arr[i]);
		i++;
		print_arr(i,arr,r);
	}
}

void save_on_file(char filename[], int arr[])
{
	FILE *fp = fopen(filename, "w");
	if(fp == NULL) {
		printf("Error on file opening\n");
		exit(EXIT_FAILURE);
	}
	
	for(int i = 0; i < DIM; i++)
	{
		fprintf(fp,"%d ",arr[i]);
	}
	
	fclose(fp);
}

int min(int a, int b)
{
	if(a < b) return a;
	else 
		return b;
}

int find_min_rec(int arr[], int n)
{
	if(n == 0) return arr[n];
	else {
		return min(arr[n], find_min_rec(arr,n-1));
	}
}

int countx_rn(int arr[], int n, int x)
{
	if(n == 0) return (arr[n] == x);
	else {
		if(arr[n] == x) return 1+countx_rn(arr,n-1,x);
		else 
			return countx_rn(arr,n-1,x);
	}
}

void swap(int i, int j, int A[])
{
	int k = A[i];
	A[i] = A[j];
	A[j] = k;
}

int partition(int arr[], int p, int r)
{
	int i,pivot,pivopos;
	
	swap(p,(p+r)/2,arr);
	
	pivot = arr[p];
	pivopos = p;
	
	for(i = p+1; i <= r; i++)
	{
		if(arr[i] < pivot) {
			pivopos++;
			swap(i,pivopos,arr);
		}
	}
	
	swap(p,pivopos,arr);

	return pivopos;
}

void QuickSort(int arr[], int p, int r)
{
	int q;
	
	if(p < r) {
		
		q = partition(arr,p,r);
		
		QuickSort(arr,p,q-1);
		QuickSort(arr,q+1,r);
	}
}





