#include"header.h"

void printList(NodePtr np)
{
    while (np != NULL)
    { // as long as there's a node
        printf("%d ", np->num);
        np = np->next; // go on to the next node
    }
    printf("\n\n");
} // end printList