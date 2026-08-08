/*
 * Exam 09 — Linked Lists: Custom Data Structures and File Processing
 *
 * Define a linked list whose nodes store a custom data structure
 * representing a person. Each person is described by a name and an age.
 *
 * The required data structure is:
 *
 *    typedef struct {
 *        char name[DIM];
 *        int age;
 *    } Element;
 *
 *    typedef struct node {
 *        Element d;
 *        struct node *next;
 *    } Node;
 *
 *    typedef struct node *LINK;
 *
 * a) Write a function:
 *    LINK create_listfrom_file(char filename[]);
 *    that reads the people from the specified text file and creates
 *    the corresponding linked list, preserving the order in which
 *    the records appear in the file.
 *
 * b) Write a recursive function:
 *    void print_list(LINK lis);
 *    that prints the name and age of every person in the linked list.
 *
 * c) Write a recursive function:
 *    int count_greater_thr(LINK lis, int k);
 *    that returns the number of people whose age is strictly greater
 *    than the given threshold k.
 *
 * d) Write a main function that:
 *    - loads the linked list from a file named "text.txt";
 *    - prints the loaded list;
 *    - asks the user to enter an age threshold;
 *    - calculates and prints the number of people older than the
 *      specified threshold.
 *
 * Function prototypes:
 *    LINK new_node();
 *    LINK create_listfrom_file(char filename[]);
 *    void print_list(LINK lis);
 *    int count_greater_thr(LINK lis, int k);
 *
 * Example input file (text.txt): Mario 24 Bob 79 Mirko 12 Lucas 34 - You can assume that the input file is always valid
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 20

typedef struct {
	char name[DIM];
	int age;
} Element;

typedef struct node{
	Element d;
	struct node *next;
} Node;

typedef struct node *LINK;

LINK new_node();
LINK create_listfrom_file(char filename[]);
void print_list(LINK lis);
int count_greater_thr(LINK lis, int k);

int main()
{
	int thr,n;
	
	LINK head = create_listfrom_file("text.txt");
	
	printf("Loaded list:\n");
	print_list(head);
	
	printf("\n\nPick a threshold value: ");
	scanf("%d",&thr);
	
	n = count_greater_thr(head, thr);	
	printf("\nThere are %d people older than %d years\n",n,thr);
	
	return 0;
}

LINK new_node()
{
	LINK n = malloc(sizeof(*n));
	if(n == NULL) {
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	return n;
}

LINK create_listfrom_file(char filename[])
{
	LINK p,head,tail;
	char buffer[DIM];
	int x;
	
	FILE *fp = fopen(filename, "r");
	if(fp == NULL) {
		printf("Error on file opening\n");
		exit(EXIT_FAILURE);
	}
	
	head = NULL;
	while(fscanf(fp,"%19s",buffer) == 1)
	{
		p = new_node();
		strcpy(p->d.name,buffer);
		
		fscanf(fp,"%d",&x);
		p->d.age = x;
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
	fclose(fp);
	
	return head;
}

void print_list(LINK lis)
{
	if(lis == NULL) {
		printf("\n\n");
		return;
	}
	else {
		printf("\n\nName: %s",lis->d.name);
		printf("\nAge: %d",lis->d.age);
		print_list(lis->next);
	}
}

int count_greater_thr(LINK lis, int k)
{
	if(lis == NULL) return 0;
	
	if(lis->d.age > k) 
		return 1+count_greater_thr(lis->next,k);
	
	else return count_greater_thr(lis->next,k);
}
