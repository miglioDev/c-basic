// build a singly linked list, remove a node by position (n)
// then remove either the head or the tail node
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
	int data;
	struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
void append_node(LINK *lis, int x);
void print_list(LINK lis);
void remove_node_in_pos(LINK *lis, int pos);
LINK find_pre(LINK lis, int pos);
void head_rm(LINK *lis);
void tail_rm(LINK *lis);

int main ()
{
	int i,x,n,option;
	srand(time(NULL));
	LINK head = NULL;
	
	for(i = 0; i < 10; i++)
	{
		x = rand()%10;
		append_node(&head,x);
	}
	
	printf("List:\n");	
	print_list(head);
	
	printf("Pick one node to remove (0-9):\n");
	scanf("%d",&n);
	
	remove_node_in_pos(&head,n);
	print_list(head);
	
	printf("\nNow choose one to remove:\n1) First node\n2) Last node\n");
	scanf("%d",&option);
	if(option == 1) {
		head_rm(&head);
	}
	else {
		tail_rm(&head);
	}
	
	printf("Updated list:\n");
	print_list(head);
	
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

void append_node(LINK *lis, int x)
{
	LINK p,q;
	p = new_node();
	p->data = x;
	p->next = NULL;
	
	q = *lis;
	
	if(q == NULL) {
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
		printf("%d ->",lis->data);
		lis = lis->next;
	}
	
	printf("NULL\n");
}

void remove_node_in_pos(LINK *lis, int pos)
{
	LINK p,target;
	
	if(pos == 0) {
		p = *lis;
		*lis = (*lis)->next;
		free(p);
	}
	
	else {
		LINK prev = find_pre(*lis,pos);
		target = prev->next;
		prev->next = target->next; 
		free(target);
	}
}

LINK find_pre(LINK lis, int pos)
{
	int i = 0;
	pos = pos-1;
	LINK p;
	
	while(lis->next != NULL && i < pos)
	{
		lis = lis->next;
		i++;
	}
	
	p = lis;
	return p;
}

void head_rm(LINK *lis)
{
	if(*lis == NULL) {
		return;
	}
	
	LINK p = *lis;
	*lis = (*lis)->next;
	free(p);
}

void tail_rm(LINK *lis)
{
	LINK q;
	q = *lis;
	
	if((*lis)->next == NULL) {
		free(*lis);
		*lis = NULL;
		return;
	}
	
	while(q->next->next != NULL)
	{
		q = q->next;
	}
	
	free(q->next);
	q->next = NULL;
}
