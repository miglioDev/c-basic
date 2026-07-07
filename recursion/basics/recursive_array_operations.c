// recursively load, print, search, and find the minimum value of an integer array
// all using separate functions and recursion
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void load_arr(int arr[], int i, int n);
void print_arr(int arr[], int i, int n);
int find_x_rc(int arr[], int x, int i, int n);
int min(int A, int B);
int find_min(int arr[], int n);

int main ()
{
	int x,i,n,pres,minimum;
	srand(time(NULL));
	n = 12;
	i = 0;
	int arr[n];
	

	load_arr(arr,i,n);
	i = 0;
	print_arr(arr,i,n);
	
	printf("\nEnter x: ");
	scanf("%d",&x);
	
	i = 0;
	pres = find_x_rc(arr,x,i,n);
	if(pres == -1) printf("Numer not present\n");
	else 
		printf("The number %d is present\n",x);
	
	minimum = find_min(arr,n-1);
	printf("\nMin = %d\n",minimum);
	
	return 0;
}

void load_arr(int arr[], int i, int n)
{
	if(i == n) return; 
	else {
		arr[i] = rand()%100;
		load_arr(arr,i+1,n);
	}
}

void print_arr(int arr[], int i, int n)
{
	if(i == n) return;
	else {
		printf("%d ",arr[i]);
		print_arr(arr,i+1,n);
	}
}

int find_x_rc(int arr[], int x, int i, int n)
{
	if(i == n) return -1;
	
	if(arr[i] == x) return 1; 
	else {
		return find_x_rc(arr,x,i+1,n);
	}
}

int min(int A, int B)
{
	return (A < B) ? A : B;
}

int find_min(int arr[], int n)
{
	if(n == 0) return arr[n];
	else {
		return min(arr[n], find_min(arr,n-1));
	}
}
