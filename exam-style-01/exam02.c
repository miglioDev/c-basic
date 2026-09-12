/*
 * Exam 02 — Linked Lists: Merge of Sorted Lists
 *
 * Build two sorted linked lists of integers from user input, then implement:
 *
 * a) An iterative function:
 *    int count_common(LINK lis1, LINK lis2);
 *    that counts how many values appear in both original sorted lists.
 *    Matching duplicate values should be counted only once per
 *    corresponding pair of occurrences.
 *
 * b) A recursive function:
 *    LINK merge_list(LINK lis1, LINK lis2);
 *    that merges the two sorted linked lists into a single sorted list
 *    by reusing the existing nodes (without allocating new ones),
 *    exactly as in the merge step of Merge Sort.
 *
 * c) A main function that:
 *    - builds the two linked lists from user input (terminated by a
 *      sentinel value, e.g. -1), assuming the values are entered
 *      in ascending order;
 *    - prints the original lists;
 *    - prints the merged list;
 *    - prints the number of common elements.
 *
 * Function prototypes:
 *    LINK new_node();
 *    void append_node(LINK *lis, int x);
 *    void print_list(LINK lis);
 *    int count_common(LINK lis1, LINK lis2);
 *    LINK merge_list(LINK lis1, LINK lis2);
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int d;
	struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
void append_node(LINK *lis, int x);
void print_list(LINK lis);
int count_common(LINK lis1, LINK lis2);
LINK merge_list(LINK lis1, LINK lis2);

int main()
{
	LINK lis1,lis2;
	lis1 = NULL;
	lis2 = NULL;
	int x = 0;
	int y = 0;
	
	while(x >= 0)
	{
		printf("\nEnter new node lis1: ");
		scanf("%d",&x);
		if(x >= 0) append_node(&lis1,x);
	}
	
	while(y >= 0)
	{
		printf("\nEnter new node lis2: ");
		scanf("%d",&y);
		if(y >= 0) append_node(&lis2,y);
	}
	
	printf("\nList 1:\n");
	print_list(lis1);
	printf("\nList 2:\n");
	print_list(lis2);
	
	int element = count_common(lis1, lis2);
	printf("\n%d Element in common\n",element);
	
	printf("\nMerge list:\n");
	lis1 = merge_list(lis1,lis2);
	print_list(lis1);
	
	return 0;
}

LINK new_node()
{
	LINK p = malloc(sizeof(*p));
	if(p == NULL) {
		printf("Error memory allocation failedn\n");
		exit(EXIT_FAILURE);
	}
	
	return p;
}

void append_node(LINK *lis, int x)
{
	LINK p = new_node();
	p->next = NULL;
	p->d = x;
	
	if(*lis == NULL) {
		*lis = p;
		return;
	}
	
	LINK q = *lis;
	
	while(q->next != NULL) 
	{
		q = q->next;
	}

	q->next = p;
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

int count_common(LINK lis1, LINK lis2)
{	
	int counter = 0;
	
	while(lis1 != NULL && lis2 != NULL)
	{
		if(lis1->d == lis2->d) {
			counter++;
			lis1 = lis1->next;
			lis2 = lis2->next;
		} 
		else if(lis1->d > lis2->d) {
			lis2 = lis2->next;
		}
		else {
			lis1 = lis1->next;
		}
	}
	
	return counter;
}

LINK merge_list(LINK lis1, LINK lis2)
{
	if(lis1 == NULL) return lis2;
	if(lis2 == NULL) return lis1;
	
	if((lis1->d) <= (lis2->d)) {
		lis1->next = merge_list(lis1->next,lis2);
		return lis1;
	}
	else {
		lis2->next = merge_list(lis1,lis2->next);
		return lis2;
	}
}




