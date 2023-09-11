#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100 // Change this value to set the maximum size of the stack
typedef int StackData; // Change the type of data being stored in the stack as needed

typedef struct stackType
{
    StackData data[STACK_SIZE];
    int top;
} StackType, *Stack;

Stack initStack()
{
    Stack sp = (Stack)malloc(sizeof(StackType));
    sp->top = -1; // Initialize the top index to -1 to indicate an empty stack
    return sp;
}

int empty(Stack S)
{
    return (S->top == -1);
}

int full(Stack S)
{
    return (S->top == STACK_SIZE - 1);
}

void push(Stack S, StackData d)
{
    if (full(S))
    {
        printf("\nAttempt to push onto a full stack\n");
        exit(1);
    }
    S->top++;
    S->data[S->top] = d;
}

StackData pop(Stack S)
{
    if (empty(S))
    {
        printf("\nAttempt to pop an empty stack\n");
        exit(1);
    }
    StackData hold = S->data[S->top];
    S->top--;
    return hold;
}

StackData peek(Stack S)
{
    if (!empty(S))
        return S->data[S->top];
    printf("\nAttempt to peek at an empty stack\n");
    exit(1);
}

void clearStack(Stack S)
{
    S->top = -1; // Reset the top index to -1 to indicate an empty stack
}

void printStack(Stack S)
{
    if (empty(S))
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = S->top; i >= 0; i--)
        printf("%d\n", S->data[i]);
}

int main()
{
    Stack stack = initStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printf("Top element: %d\n", peek(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("Top element: %d\n", peek(stack));
    printStack(stack);
    clearStack(stack);
    printf("Stack is now empty.\n");
    return 0;
}