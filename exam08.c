//add exam08 text
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int d;
	struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
LINK build_list();
void print_list(LINK lis);
LINK find_precd(LINK lis, int x);
void insert_zero_before(LINK *lis, int val);

int main ()
{
	int value;
	LINK head = build_list();
	
	printf("\nList:\n");
	print_list(head);

	printf("\nChoose one value on the list: ");
	scanf("%d",&value);
	insert_zero_before(&head,value);
	
	printf("\nUpdated List:\n");
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

LINK build_list()
{
	LINK p = NULL;
	int x;
	
	printf("\nEnter node value: ");
	scanf("%d",&x);
	
	if(x < 0) return NULL;
	else {
		p = new_node();
		p->d = x;
		p->next = build_list();
		return p;
	}
	
	return p;
}

void print_list(LINK lis)
{
	while(lis != NULL)
	{
		printf("%d -> ",lis->d);
		lis = lis->next;
	}	
	
	printf("NULL\n");
}

LINK find_precd(LINK lis, int x)
{
	if(lis == NULL) return NULL;
	if(lis->next != NULL) {
		if(lis->next->d == x) {
			return  lis;
		}
		else 
			return find_precd(lis->next,x);
	}
	else 
		return NULL;
}

void insert_zero_before(LINK *lis, int val)
{
	LINK p;
	
	if((*lis)->d == val) {
		p = new_node();
		p->d = 0;
		p->next = *lis;
		*lis = p;
	}
	else {
		LINK prec = find_precd(*lis,val);
		p = new_node();
		p->d = 0;
		p->next = prec->next;
		prec->next = p;
	}
}
