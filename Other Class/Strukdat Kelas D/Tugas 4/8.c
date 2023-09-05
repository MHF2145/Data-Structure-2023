#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct stack {
    int arr[MAX_SIZE];
    int top;
};

void push(struct stack *s, int data) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++(s->top)] = data;
}

int pop(struct stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

void sort_stack(struct stack *s) {
    struct stack s2;
    s2.top = -1;
    
    while (s->top != -1) {
        int temp = pop(s);
        while (s2.top != -1 && s2.arr[s2.top] > temp) {
            push(s, pop(&s2));
        }
        push(&s2, temp);
    }
    
    // Copy the sorted elements back to the original stack
    while (s2.top != -1) {
        push(s, pop(&s2));
    }
}

int main() {
    struct stack s;
    s.top = -1;
    
    push(&s, 3);
    push(&s, 1);
    push(&s, 4);
    push(&s, 2);
    
    sort_stack(&s);
    
    while (s.top != -1) {
        printf("%d ", pop(&s));
    }
    
    return 0;
}