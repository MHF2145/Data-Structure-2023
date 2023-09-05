#include"header.h"

NodePtr makeNode(int n)
{
    NodePtr np = (NodePtr)malloc(sizeof(Node));
    np->num = n;
    np->next = NULL;
    return np;
} // end makeNode