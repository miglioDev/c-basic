//
#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

#define MAXLEN 100
#define EMPTY  -1
#define FULL MAXLEN-1

typedef struct Stack{
    DATA a[MAXLEN];
    int top;
} stack;

void clear(stack *stk);
int is_empty(stack *stk);
int is_full(stack *stk);
int push(DATA i, stack *stk);

int main()
{
    stack s;
    int a = 19;

    clear(&s);
    push(a,&s);

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

int push(DATA i, stack *stk)
{
    if(!is_full(stk)) {
        (stk->top)++;
        stk->a[stk->top] = i;
        return 1; 
    }
    
    return 0;
}