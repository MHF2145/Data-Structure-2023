#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct stack {
    int arr[MAX_SIZE];
    int top;
};

void push(struct stack *s, int data) {
    if (s->top >= MAX_SIZE - 1) {
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

struct queue {
    struct stack s1;
    struct stack s2;
};

void enqueue(struct queue *q, int data) {
    push(&(q->s1), data);
}

int dequeue(struct queue *q) {
    if (q->s1.top == -1 && q->s2.top == -1) {
        printf("Queue underflow\n");
        return -1;
    }
    if (q->s2.top == -1) {
        while (q->s1.top != -1) {
            push(&(q->s2), pop(&(q->s1)));
        }
    }
    return pop(&(q->s2));
}

int main() {
    struct queue q;
    q.s1.top = -1;
    q.s2.top = -1;
    
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    enqueue(&q, 4);
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    
    return 0;
}
