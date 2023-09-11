#include "Stack.h"

void st_init(Stack* stack) {
    stack->size = 0;
}

void st_push(Stack* stack, int data) {
    stack->data[stack->size++] = data; 
}

int st_pop(Stack* stack) {
    return stack->data[--stack->size];
}

int st_top(Stack* stack) {
    return stack->data[stack->size-1];
}

int st_empty(Stack* stack) {
    return stack->size == 0;
}