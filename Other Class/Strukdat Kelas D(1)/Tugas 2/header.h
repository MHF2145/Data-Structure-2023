#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node *createList(int n);
Node *deleteNode(Node *currentNode, int k);
int selectClassLeader(Node *head, int k);