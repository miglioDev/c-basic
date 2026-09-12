/*
 * Exam 04 — Linked Lists: File Processing and Recursive Filtering
 *
 * Manage a linked list of integers using text files.
 *
 * a) Write an iterative function:
 *    LINK read_list_from_file(FILE *f);
 *    that reads a sequence of integers from a text file, 
 *    (terminated by the end of the file), builds the corresponding
 *    linked list while preserving the input order (by inserting nodes at
 *    the tail), and returns the head of the list.
 *
 * b) Write an iterative function that finds and print the smallest value stored
 *    in the linked list, computes its Fibonacci number, and returns it.
 *    The main function must print the Fibonacci number.
 *
 * c) Write a recursive function:
 *    LINK filter_even_rec(LINK head);
 *    that returns a new linked list containing only the even values from
 *    the original list. The new list must be built using newly allocated
 *    nodes, while the original list must remain unchanged.
 *
 * d) Write a function that properly deallocates the memory used by both
 *    linked lists.
 *
 * e) Write a main function that:
 *    - reads the linked list from a file named "input.txt";
 *    - prints the original list;
 *    - builds the filtered list by calling filter_even_rec();
 *    - writes the filtered list to a file named "output.txt";
 *    - deallocates both linked lists before terminating.
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int d;
	struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
LINK read_list_from_file(FILE *fp);
void print_list(LINK lis);
int fibonacci_smallest(LINK lis);
LINK filter_even_rec(LINK head);
void write_on_file(LINK lis);
void free_all_list(LINK *lis1, LINK *lis2);

int main()
{
	FILE *fp = fopen("input.txt", "r");
	if(fp == NULL) {
		printf("Error file\n");
		exit(EXIT_FAILURE);
	}
	
	LINK head = read_list_from_file(fp);
	fclose(fp);
	print_list(head);

	int fib = fibonacci_smallest(head);
	printf("\nFibonacci = %d\n",fib);
	
	printf("\nEven list:\n");
	LINK even_list = filter_even_rec(head);
	print_list(even_list);
	
	write_on_file(even_list);
	
	free_all_list(&head,&even_list);
	
	return 0;
}

LINK new_node()
{
	LINK p = malloc(sizeof(*p));
	
	if(p == NULL) {
		printf("Error: memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	return p;
} 
 
LINK read_list_from_file(FILE *fp)
{
	LINK head,tail,p;
	int x;
	head = NULL;
	
	while((fscanf(fp,"%d",&x)) == 1)
	{
		p = new_node();
		p->d = x;
		p->next = NULL;
		
		if(head == NULL) {
			head = p;
			tail = p;
		}
		else {
			tail->next = p;
			tail = p;
		}
	}
	
	return head;
}
 
void print_list(LINK lis)
{
	while(lis != NULL) 
	{
		printf("%d ->",lis->d);
		lis = lis->next;
	}
	printf("NULL\n");
}
 
int fibonacci_smallest(LINK lis)
{
	if(lis == NULL) return -1;
	int number = lis->d;
	
	while(lis != NULL)
	{
		if(lis->d < number)
			number = lis->d;
		
		lis = lis->next;
	}
	printf("Smallest number on the list = %d\n",number);
	
	if(number == 0 || number == 1) return number;
	else {
	int fib;
	int fib_minus1 = 1;
	int fib_minus2 = 0;
	
	for(int i = 2; i <= number; i++)
	{
		fib = fib_minus1 + fib_minus2;
		
		fib_minus2 = fib_minus1;
		fib_minus1 = fib;
	}
	
	return fib;
	}
}
 
LINK filter_even_rec(LINK head)
{
	LINK p;
	
	if(head == NULL) return NULL;
	if(head->d%2 == 0) {
		p = new_node();
		p->d = head->d;
		p->next = filter_even_rec(head->next);
		return p;
	}
	else {
		return filter_even_rec(head->next);
	}
}
 
void write_on_file(LINK lis)
{
	FILE *fp = fopen("output.txt","w");
	if(fp == NULL) {
		printf("Error on file\n");
		exit(EXIT_FAILURE);
	}
	
	while(lis != NULL)
	{
		fprintf(fp,"%d ->",lis->d);
		lis = lis->next;
	}
	fprintf(fp,"NULL\n");
	
	fclose(fp);
}


void free_all_list(LINK *lis1, LINK *lis2)
{
	LINK p;
	
	while(*lis1 != NULL)
	{
		p = *lis1;
		*lis1 = (*lis1)->next;
		free(p);
	}

	while(*lis2 != NULL)
	{
		p = *lis2;
		*lis2 = (*lis2)->next;
		free(p);
	}
}
