#include "header.h"

Node *deleteNode(Node *currentNode, int k)
{
    Node *removedNode = currentNode->next;
    currentNode->next = removedNode->next;
    free(removedNode);
    currentNode = currentNode->next;
    return currentNode;
}