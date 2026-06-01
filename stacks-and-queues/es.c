//
#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

#define MAXLEN 100
#define EMPTY  -1
#define FULL MAXLEN-1;

typedef struct Stack{
    DATA a[MAXLEN];
    int top;
} stack;

void clear(stack *stk);
int is_empty(stack *stk);
int is_full(stack *stk);

int main()
{
    stack s;
    
    clear(&s);


    return 0;
}

void clear(stack *stk) {
    stk->top = EMPTY;
}

int is_empty(stack *stk) {
    return(stk->top == EMPTY);
}

int is_full(stack *stk) {
    return(stk->top == FULL);
}