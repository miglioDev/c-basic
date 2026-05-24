// Manage a music playlist using linked lists, including tail insertion, song removal by title,
// playlist printing, and total duration calculation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 20

typedef struct node{
    char title[DIM];
    int duration;
    struct node *next;
}node;

typedef struct node *LINK;

void append_song(LINK *list);
void head_remove_song(LINK *head, char title[DIM]);
void remove_song(LINK lis, char title[DIM]);
void print_playlist(LINK lis);
int total_time(LINK lis);

int main ()
{
    int i,n,tot_time;
    char s_remove[DIM];
    LINK head = NULL;

    printf("How many song will enter: ");
    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        append_song(&head);
    }

    printf("Enter the title of one song you will like to remove: ");
    scanf("%s",s_remove);
    
    head_remove_song(&head,s_remove);

    print_playlist(head);

    tot_time = total_time(head);

    printf("\nTotal time: %d",tot_time);

    return 0;
}

LINK new_node()
{
    LINK p = malloc(sizeof(*p));
    if(p == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE); }
    return p;
}

void append_song(LINK *list)
{
    LINK p;

    if(*list == NULL) {
        p = new_node();
        printf("\nEnter new song name (no space): ");
        scanf("%s",p->title);

        printf("\nEnter song duration (second): ");
        scanf("%d",&p->duration);

        p->next = NULL;
        *list = p;
        return; }

    LINK current = *list;
    while(current->next != NULL) 
    {
        current = current->next;
    }

    p = new_node();

    printf("\nEnter new song name: ");
    scanf("%s",p->title);

    printf("\nEnter song duration: ");
    scanf("%d",&p->duration);

    current->next = p;
    p->next = NULL;
}

void head_remove_song(LINK *head, char title[DIM])
{
    LINK p;

    if( strcmp((*head)->title, title) == 0) {
        p = *head;
        *head = (*head)->next;
        free(p);
        return; }
    else {
        remove_song(*head,title); }
}

void remove_song(LINK lis, char title[DIM])
{
    LINK t;
    while( strcmp(lis->next->title, title) != 0) 
    {
        lis = lis->next;
    }

    t = lis->next;
    lis->next = lis->next->next;
    free(t);
}

void print_playlist(LINK lis)
{
    int n = 1;
    while(lis != NULL)
    {
        printf("\n\n=== Song %d ===",n);
        printf("\nTitle: %s",lis->title);
        printf("\nDuration: %d",lis->duration);

        n++;
        lis = lis->next;
    }
}

int total_time(LINK lis)
{
    int time = 0; 

    while(lis != NULL) 
    {
        time = time + lis->duration;
        lis = lis->next;
    }

    return time;
}