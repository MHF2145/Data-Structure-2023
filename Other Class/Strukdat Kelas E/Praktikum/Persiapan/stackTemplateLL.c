#include <stdio.h>
#include <stdlib.h>

typedef int StackData; // Change the type of data being stored in the stack as needed

typedef struct node
{
    StackData data;
    struct node *next;
} Node, *NodePtr;

typedef struct stackType
{
    NodePtr top;
    int size; // New variable to keep track of the size of the stack
} StackType, *Stack;

Stack initStack()
{
    Stack sp = (Stack)malloc(sizeof(StackType));
    sp->top = NULL;
    sp->size = 0; // Initialize the size of the stack to 0
    return sp;
}

int empty(Stack S)
{
    return (S->top == NULL);
}

void push(Stack S, StackData d)
{
    NodePtr np = (NodePtr)malloc(sizeof(Node));
    np->data = d;
    np->next = S->top;
    S->top = np;
    S->size++; // Increment the size of the stack
}

StackData pop(Stack S)
{
    if (empty(S))
    {
        printf("\nAttempt to pop an empty stack\n");
        exit(1);
    }
    StackData hold = S->top->data;
    NodePtr temp = S->top;
    S->top = S->top->next;
    free(temp);
    S->size--; // Decrement the size of the stack
    return hold;
}

StackData peek(Stack S)
{
    if (!empty(S))
        return S->top->data;
    printf("\nAttempt to peek at an empty stack\n");
    exit(1);
}

void clearStack(Stack S)
{
    while (!empty(S))
        pop(S);
}

void printStack(Stack S)
{
    if (empty(S))
    {
        printf("Stack is empty.\n");
        return;
    }
    NodePtr current = S->top;
    printf("Stack contents:\n");
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
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
    printf("Size of stack: %d\n", stack->size);
    printStack(stack);
    clearStack(stack);
    printf("Size of stack after clear: %d\n", stack->size);
    return 0;
}
