#include<stdio.h>

#define MAX_SIZE 100

typedef struct {
    double data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void init(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int is_empty(Queue *q) {
    return q->size == 0;
}

int is_full(Queue *q) {
    return q->size == MAX_SIZE;
}

void enqueue(Queue *q, double value) {
    if (is_full(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
    q->size++;
}

double dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return 0;
    }
    double value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return value;
}

int main() {
    Queue q;
    init(&q);

    enqueue(&q, 3.14);
    enqueue(&q, 2.71);

    double value = dequeue(&q);
    printf("%f\n", value);

    return 0;
}