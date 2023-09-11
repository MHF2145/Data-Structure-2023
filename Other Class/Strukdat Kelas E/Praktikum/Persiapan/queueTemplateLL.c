#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

int isEmpty(Queue* queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

void enqueueFront(Queue* queue, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    if (isEmpty(queue)) {
        newNode->next = NULL;
        queue->rear = newNode;
    }
    else {
        newNode->next = queue->front;
    }
    queue->front = newNode;
    queue->size++;
}

void enqueueRear(Queue* queue, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
    }
    else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->size++;
}

int dequeue(Queue* queue) {
    int value;
    Node* temp;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    else if (queue->front == queue->rear) {
        temp = queue->front;
        value = temp->data;
        queue->front = NULL;
        queue->rear = NULL;
    }
    else {
        temp = queue->front;
        value = temp->data;
        queue->front = queue->front->next;
    }
    free(temp);
    queue->size--;
    return value;
}

int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->front->data;
}

int rear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->rear->data;
}

int poprear(Queue* queue) {
    int value;
    Node* temp;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    else if (queue->front == queue->rear) {
        temp = queue->rear;
        value = temp->data;
        queue->front = NULL;
        queue->rear = NULL;
    }
    else {
        Node* prev = queue->front;
        Node* curr = queue->front->next;
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        temp = curr;
        value = temp->data;
        prev->next = NULL;
        queue->rear = prev;
    }
    free(temp);
    queue->size--;
    return value;
}

int main() {
    Queue* queue = createQueue();
    enqueueRear(queue, 1);
    enqueueRear(queue, 2);
    enqueueRear(queue, 3);
    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));
    printf("Popped rear element: %d\n", poprear(queue));
    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));
    return 0;
}

