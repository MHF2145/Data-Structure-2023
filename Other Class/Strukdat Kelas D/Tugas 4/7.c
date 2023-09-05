#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct queue {
    int arr[MAX_SIZE];
    int front, rear;
};

void enqueue(struct queue *q, int data) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    q->arr[++(q->rear)] = data;
}

int dequeue(struct queue *q) {
    if (q->front > q->rear) {
        printf("Queue underflow\n");
        return -1;
    }
    return q->arr[(q->front)++];
}

struct stack {
    struct queue q1;
    struct queue q2;
};

void push(struct stack *s, int data) {
    if (s->q1.rear == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    enqueue(&(s->q1), data);
}

int pop(struct stack *s) {
    if (s->q1.front > s->q1.rear) {
        printf("Stack underflow\n");
        return -1;
    }
    while (s->q1.front != s->q1.rear) {
        enqueue(&(s->q2), dequeue(&(s->q1)));
    }
    int data = dequeue(&(s->q1));
    while (s->q2.front <= s->q2.rear) {
        enqueue(&(s->q1), dequeue(&(s->q2)));
    }
    return data;
}

int main() {
    struct stack s;
    s.q1.front = s.q1.rear = -1;
    s.q2.front = s.q2.rear = -1;
    
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d ", pop(&s));
    printf("%d ", pop(&s));
    push(&s, 4);
    printf("%d ", pop(&s));
    printf("%d ", pop(&s));
    
    return 0;
}
