#include <stdio.h>
#include <stdlib.h>

typedef struct Deque {
    int* values;
    int front;
    int rear;
} Deque;

// create a new deque
Deque* createDeque(int capacity) {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->values = (int*)malloc(capacity * sizeof(int));
    deque->front = -1;
    deque->rear = -1;
    return deque;
}

// check if the deque is empty
int isDequeEmpty(Deque* deque) {
    return deque->front == -1;
}

// check if the deque is full
int isDequeFull(Deque* deque, int capacity) {
    return (deque->rear + 1) % capacity == deque->front;
}

// add an element to the rear of the deque
void addToDequeRear(Deque* deque, int value, int capacity) {
    if (isDequeFull(deque, capacity)) {
        printf("Deque is full.\n");
        return;
    }
    if (isDequeEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % capacity;
    }
    deque->values[deque->rear] = value;
}

// remove an element from the front of the deque
void removeFromDequeFront(Deque* deque, int capacity) {
    if (isDequeEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % capacity;
    }
}

// get the element at the front of the deque
int getDequeFront(Deque* deque) {
    if (isDequeEmpty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }
    return deque->values[deque->front];
}

int main() {
    int i, j, N, M;
    scanf("%d%d", &N, &M);

    int* pasukan = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        scanf("%d", &pasukan[i]);
    }

    Deque* deque = createDeque(M);
    for (i = 0; i < M; i++) {
        while (!isDequeEmpty(deque) && pasukan[i] <= pasukan[getDequeFront(deque)]) {
            removeFromDequeFront(deque, M);
        }
        addToDequeRear(deque, i, M);
    }
    printf("%d\n", pasukan[getDequeFront(deque)]);

    for (i = M; i < N; i++) {
        while (!isDequeEmpty(deque) && getDequeFront(deque) <= i - M) {
            removeFromDequeFront(deque, M);
        }
        while (!isDequeEmpty(deque) && pasukan[i] <= pasukan[getDequeFront(deque)]) {
            removeFromDequeFront(deque)

