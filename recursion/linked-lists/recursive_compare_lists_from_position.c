// recursive comparison of two linked lists starting from a user-defined position n
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int d;
	struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
LINK build_list();
void print_list(LINK lis);
int check_equal_n(LINK l1, LINK l2, int n);

int main ()
{
	LINK lis1,lis2;
	int n,equal;
	
	printf("\nList 1:\n");
	lis1 = build_list();
	
	printf("\nList 2:\n");
	lis2 = build_list();
	
	printf("\nList one:\n");
	print_list(lis1);
	printf("\nList two:\n");
	print_list(lis2);
	
	printf("\nEnter n (check node from position n): ");
	scanf("%d",&n);
	
	equal = check_equal_n(lis1,lis2,n);
	if(equal)	
	printf("\nEqual\n");
		else 
		printf("\nNon equal\n");
		
	
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
	int x;
	LINK p; 
	
	printf("\nEnter new node value: ");
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
	if(lis == NULL) {
		printf("NULL\n");
		return; }
	else {
		printf(" %d ->",lis->d);
		print_list(lis->next);
	}
}

int check_equal_n(LINK l1, LINK l2, int n)
{
	if(n > 0) {
		if(l1->next == NULL || l2->next == NULL) return 0;
		else 
			return check_equal_n(l1->next,l2->next,n);
	}
	
	if(l1 == NULL && l2 == NULL) return 1;
	if(l1 == NULL || l2 == NULL) return 0;
	if(l1->d != l2->d) return 0;
	else 
		return check_equal_n(l1->next,l2->next,n);
}
