#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} Node, *NodePtr;

NodePtr makeList();
NodePtr makeNode(int);
void printList(NodePtr);
NodePtr merge(NodePtr, NodePtr);