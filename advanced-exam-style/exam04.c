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
void append_node(LINK *head, int x);
LINK read_list_from_file(FILE *fp);
void print_list(LINK lis);
int fibonacci_smallest(LINK lis);

int main()
{
	FILE *fp = fopen("input.txt", "r");
	if(fp == NULL) {
		printf("Error file\n");
		exit(EXIT_FAILURE);
	}
	
	LINK head = read_list_from_file(fp);
	print_list(head);

	int fib = fibonacci_smallest(head);
	printf("\nFibonacci = %d\n",fib);
	
	return 0;
}

LINK new_node()
{
	LINK p = malloc(sizeof(*p));
	
	if(p == NULL) {
		printf("Error: memory allocation failed\n");
		exit(EXIT_FAILURE);
		return p;
	}
	return p;
} 
 
void append_node(LINK *head, int x)
{
	LINK p = new_node();
	p->next = NULL;
	p->d = x;
	
	if(*head == NULL) {
		*head = p;
		return;
	}
	else {
		LINK q = *head;
		while(q->next != NULL) 
		{
			q = q->next;
		}
		q->next = p;
	}
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

//work in progress
