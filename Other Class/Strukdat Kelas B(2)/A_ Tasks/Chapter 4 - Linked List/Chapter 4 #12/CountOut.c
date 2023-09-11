#include <malloc.h>
#include <stdio.h>

#include "CountOut.h"

Child* createList(int n) {
    // Create a circular linked list of n nodes
    Child* head = (Child*)malloc(sizeof(Child));
    head->value = 1;
    Child* prev = head;
    for (int i = 2; i <= n; i++) {
        Child* node = (Child*)malloc(sizeof(Child));
        node->value = i;
        prev->next = node;
        prev = node;
    }
    prev->next = head;
    return head;
}

int countOut(Child* head, int m) {
    // Eliminate children one by one until one child is left
    Child* current = head;
    while (current->next != current) {
        // Count to the mth child and eliminate them
        for (int i = 1; i < m; i++) {
            current = current->next;
        }
        Child* eliminated = current->next;
        current->next = eliminated->next;
        printf("Eliminated child %d\n", eliminated->value);
        free(eliminated);
        // Move to the next child after the one just eliminated
        current = current->next;
    }
    // Return the number of the last remaining child
    int last_child = current->value;
    free(current);
    return last_child;
}