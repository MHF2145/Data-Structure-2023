#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the queue

// Structure representing a queue
typedef struct {
    int front; // Index of the front of the queue
    int rear; // Index of the rear of the queue
    int size; // Current size of the queue
    int arr[MAX_SIZE]; // Array representing the queue
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full.\n");
        return;
    }
    else if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    }
    else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->arr[queue->rear] = value;
    queue->size++;
}

// Function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    int value;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    else if (queue->front == queue->rear) {
        value = queue->arr[queue->front];
        queue->front = -1;
        queue->rear = -1;
    }
    else {
        value = queue->arr[queue->front];
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    queue->size--;
    return value;
}

// Function to get the front element of the queue
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->arr[queue->front];
}

// Function to get the rear element of the queue
int rear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->arr[queue->rear];
}

int main() {
    Queue* queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));
    return 0;
}
