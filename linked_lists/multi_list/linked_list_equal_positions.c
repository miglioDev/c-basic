// build a new linked list containing the elements that are equal at the corresponding positions of two input linked lists.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
	int d;
	struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
void append_node(LINK *lis, int x);
void print_list(LINK lis);
LINK build_list_of_equal(LINK l1, LINK l2);

int main ()
{
	srand(time(NULL));
	int i,x;
	LINK lis1,lis2,lis3;
	
	lis1 = NULL;
	lis2 = NULL;
	
	for(i = 0; i < 25; i++)
	{
		x = rand()%21;
		append_node(&lis1,x);
	}
	
	for(i = 0; i < 20; i++)
	{
		x = rand()%21;
		append_node(&lis2,x);
	}
	
	printf("\nList 1:\n");
	print_list(lis1);
	printf("\nList 2:\n");
	print_list(lis2);

	lis3 = build_list_of_equal(lis1,lis2);
	printf("\nList 3: (equal node)\n");
	print_list(lis3);
	
	return 0;
}

LINK new_node()
{
	LINK p = malloc(sizeof(*p));
	if(p == NULL) {
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	return p;
}

void append_node(LINK *lis, int x)
{
	LINK p,q;
	
	q = *lis;
	p = new_node();
	p->d = x;
	p->next = NULL;
	
	if(*lis == NULL) {
		*lis = p;
		return;
	}
	else {
		while(q->next != NULL)
		{
			q = q->next;
		}	
		
		q->next = p;
	}
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

LINK build_list_of_equal(LINK l1, LINK l2)
{
	LINK p,head, tail;
	head = NULL;

	while(l1 != NULL && l2 != NULL)
	{
		if(l1->d == l2->d)
		{	
			p = new_node();
			p->d = l1->d;
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
		l1 = l1->next;
		l2 = l2->next;
	 }
	 
	 return head;
}
