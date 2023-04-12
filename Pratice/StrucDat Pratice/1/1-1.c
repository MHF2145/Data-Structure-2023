#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct stackNode_t {
    int data, min;
    struct stackNode_t *next;
} StackNode;
//next node
typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;
//stack
void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}
//inisiasi stack
bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}
//stack is empty 
void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack))
		{
			newNode->next = NULL;
			newNode->min = value;
		} 
        else
		{
			newNode->next = stack->_top;
			if(value < stack->_top->min) newNode->min = value;
			else newNode->min = stack->_top->min;
		} 

        stack->_top = newNode;
    }
}
// put in data
void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}
// remove the data from stack
int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}
// put data in the top
int stack_min(Stack *stack)
{
	if (!stack_isEmpty(stack)) 
        return stack->_top->min;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}
// size nya
int main()
{
    Stack st;
    stack_init(&st);
    
	stack_push(&st, 6);
    stack_push(&st, 1);
    stack_push(&st, 9);
    stack_push(&st, 2);
    
    printf("%d\n", stack_min(&st));
    
    puts("");
    return 0;
}