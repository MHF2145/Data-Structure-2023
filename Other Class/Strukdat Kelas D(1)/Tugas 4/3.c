#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int job_num;
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

void enqueue(PriorityQueue* pq, int job_num, int priority) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->job_num = job_num;
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
    int job_num = pq->head->job_num;
    Node* temp = pq->head;
    pq->head = pq->head->next;
    free(temp);
    return job_num;
}

void remove_job(PriorityQueue* pq, int job_num) {
    Node* curr = pq->head;
    Node* prev = NULL;
    while (curr != NULL && curr->job_num != job_num) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Job not found in queue\n");
        return;
    }
    if (prev == NULL) {
        pq->head = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
}
