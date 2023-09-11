#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

void swap(Stack *a, Stack *b)
{
	StackNode *tmp = a->_top;
	a->_top = b->_top;
	b->_top = tmp;
}

int main()
{
    Stack st1, st2;
    stack_init(&st1);
    stack_init(&st2);
    
    stack_push(&st1, 34);
    stack_push(&st1, 2);
    stack_push(&st1, 56);
    stack_push(&st1, 98);
    stack_push(&st1, 69);
    stack_push(&st1, 420);

 
    while(!stack_isEmpty(&st1))
    {
        int tmp = stack_top(&st1);
        stack_pop(&st1);
 
        while(!stack_isEmpty(&st2) && stack_top(&st2) < tmp)
        {
        	stack_push(&st1, stack_top(&st2));
            stack_pop(&st2);
        }
        stack_push(&st2, tmp);
    }
	
	swap(&st1, &st2);
	
    while (!stack_isEmpty(&st1))
    {
        printf("%d ", stack_top(&st1));
        stack_pop(&st1);
    }
}