#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} PriorityQueue;

void init(PriorityQueue* pq) {
    pq->head = NULL;
}

int is_empty(PriorityQueue* pq) {
    return pq->head == NULL;
}

void enqueue(PriorityQueue* pq, int data, int priority) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;

    if (is_empty(pq) || priority > pq->head->priority) {
        new_node->next = pq->head;
        pq->head = new_node;
    } else {
        Node* curr = pq->head;
        while (curr->next != NULL && priority <= curr->next->priority) {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
}

int dequeue(PriorityQueue* pq) {
    if (is_empty(pq)) {
        printf("Priority queue is empty\n");
        return -1;
    }
    int data = pq->head->data;
    Node* temp = pq->head;
    pq->head = pq->head->next;
    free(temp);
    return data;
}

int peek(PriorityQueue* pq) {
    if (is_empty(pq)) {
        printf("Priority queue is empty\n");
        return -1;
    }
    return pq->head->data;
}

int main() {
    PriorityQueue pq;
    init(&pq);

    enqueue(&pq, 5, 2);
    enqueue(&pq, 3, 1);
    enqueue(&pq, 10, 3);

    printf("%d\n", dequeue(&pq)); // prints 10
    printf("%d\n", dequeue(&pq)); // prints 5
    printf("%d\n", dequeue(&pq)); // prints 3

    return 0;
}
