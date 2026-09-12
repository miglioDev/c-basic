/*
 * Exam 01 — Linked Lists: Conditional Counting and Removal
 *
 * Build a linked list of integers recursively and print the list, then implement:
 *
 * a) An iterative function:
 *    int count_multiples(LINK head, int k);
 *    that returns the number of nodes whose value is a multiple of k.
 *
 * b) The same function implemented recursively:
 *    int count_multiples_rec(LINK head, int k);
 *    that returns the number of nodes whose value is a multiple of k.
 *
 * c) A recursive function:
 *    LINK remove_multiples_rec(LINK head, int k);
 *    that removes all nodes whose value is a multiple of k,
 *    properly deallocates their memory, and returns the new head
 *    of the linked list, then print the updated list.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int d;
	struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
LINK build_list();
void print_list(LINK l);
int count_multiples(LINK head, int k);
int count_multiples_rec(LINK lis, int k);
LINK remove_multiples_rec(LINK lis, int k);

int main()
{	
	int k,res;
	LINK lis = build_list();
	print_list(lis);

	printf("Enter k: ");
	scanf("%d",&k);
	
	res = count_multiples(lis,k);
	printf("The multiples of number %d appears %d times (iterative)\n",k,res);
	
	res = count_multiples_rec(lis,k);
	printf("The multiples of number %d appears %d times (recursion)\n",k,res);
	
	printf("New list with multiples of %d removed:\n",k);
	remove_multiples_rec(lis,k);
	print_list(lis);
	
	return 0;
}

LINK new_node()
{
	LINK p = malloc(sizeof(*p));
	
	if(p == NULL){
		printf("Error memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	return p;
}

LINK build_list()
{
	LINK p;
	int x;
	
	printf("\nEnter new node value:");
	scanf("%d",&x);
	
	if(x < 0) {
		return NULL;
	}
	else {
		p = new_node();
		p->d = x;
		p->next = build_list();
		return p;
	}
	return p;
}

void print_list(LINK l)
{
	if(l == NULL) {
		printf("NULL\n");
		return;
	}
	else {
		printf("%d ->",l->d);
		print_list(l->next);
	}
}

int count_multiples(LINK head, int k)
{
	int counter = 0;
	LINK q = head;
	
	while(q != NULL)
	{	
		if(q->d%k == 0) counter++;
		q = q->next;
	}
	
	return counter;
}

int count_multiples_rec(LINK lis, int k)
{
	if(lis == NULL) return 0;
	
	else {
		if(lis->d%k == 0) return 1+count_multiples_rec(lis->next,k);
		else 
			return count_multiples_rec(lis->next,k);
	}
}

LINK remove_multiples_rec(LINK lis, int k)
{
	LINK tmp;
	
	if(lis == NULL) return NULL;
	
	lis->next = remove_multiples_rec(lis->next,k);
	
	if(lis->d%k == 0)
	{
		tmp = lis->next;
		free(lis);
		return tmp;	
	}
	else 
		return lis;
}
