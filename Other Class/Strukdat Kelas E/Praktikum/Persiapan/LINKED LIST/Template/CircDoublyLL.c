#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to print the linked list in forward direction
void printForward(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("null\n");
}

// Function to print the linked list in reverse direction
void printReverse(struct Node* tail) {
    while (tail != NULL) {
        printf("%d <-> ", tail->data);
        tail = tail->prev;
    }
    printf("null\n");
}

// Main function
int main() {
    // Creating nodes
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Adding data to nodes
    head->data = 1;
    head->prev = NULL;
    head->next = second;

    second->data = 2;
    second->prev = head;
    second->next = third;

    third->data = 3;
    third->prev = second;
    third->next = NULL;

    // Printing the linked list in forward and reverse direction
    printf("Linked List in Forward Direction: ");
    printForward(head);

    printf("Linked List in Reverse Direction: ");
    printReverse(third);

    return 0;
}
