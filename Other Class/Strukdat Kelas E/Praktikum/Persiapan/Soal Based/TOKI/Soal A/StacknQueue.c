#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        return -2;
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

int main(){
    Queue* queue = createQueue();
    int n, temp;

    scanf("%d", &n);

    for (int i = n; i > 0; i--)
    {
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "push_front") == 0)
        {
            scanf("%d", &temp);
            enqueueFront(queue, temp);
        } else if (strcmp(command, "push_back") == 0)
        {
            scanf("%d", &temp);
            enqueueRear(queue, temp);
        } else if (strcmp(command, "pop_front") == 0)
        {
            dequeue(queue);
        } else if (strcmp(command, "pop_back") == 0)
        {
            poprear(queue);
        }
    }

    while (!isEmpty(queue)) {
        printf("%d\n", dequeue(queue));
    }
}