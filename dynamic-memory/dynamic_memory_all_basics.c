// dynamic memory management in C using malloc, calloc, realloc, and free
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
	srand(time(NULL));
	int i;
	
	int *p = malloc(sizeof(int));
	if(p == NULL) {
		printf("Error: memory allocation failed\n");
		exit(EXIT_FAILURE); }
	
	*p = 10;
	printf("p = %d\n",*p);
	free(p);
	
	
	int *arr = (int *)calloc(5,sizeof(int));
	if(arr == NULL) {
		printf("Error: arr memory allocation failed\n");
		exit(EXIT_FAILURE); }
	
	for(i = 0; i < 5; i++)
	{
		printf("\nEnter arr value in pos %d\n",i);
		scanf("%d",&arr[i]);
	}
	
	printf("\nArray:  ");
	for(i = 0; i < 5; i++)
	{
		printf("%d\t",arr[i]);
	}
	
	
	int *tmp = (int *)realloc(arr,10 * sizeof(int));
	if(tmp == NULL) {
		printf("Error: realloc tmp\n");
		free(arr);
		exit(EXIT_FAILURE); }
		
	for(; i < 10; i++)
	{
		tmp[i] = rand()%100;
	}
	
	printf("\nResized Array with 5 extra random value:  ");
	for(i = 0; i < 10; i++)
	{
		printf("%d\t",tmp[i]);
	}

	free(tmp);
}
