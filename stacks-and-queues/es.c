#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

#define MAXLEN 100
#define FULL (MAXLEN-1)
#define EMPTY -1

typedef struct stack{
    DATA s[MAXLEN];
    int top;
} STACK;

void clear(STACK *stk);
int is_empty(STACK *stk);
int is_full(STACK *stk);
int push(DATA i, STACK *stk);

int main ()
{
    STACK s;
    DATA value;

    push(5, &s);
    push(10, &s);
    push(15, &s);
}

void clear(STACK *stk) {
    stk->top = EMPTY; }

int is_empty(STACK *stk) {
    return(stk->top == EMPTY);
}

int is_full(STACK *stk) {
    return(stk->top == FULL);
}

int push(DATA i, STACK *stk)
{
    if(!is_full(stk)) {
        (stk->top)++;
        stk->s[stk->top] = i;
        return 1;
    }
    return 0;
}