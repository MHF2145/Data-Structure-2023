#include "header.h"

int selectClassLeader(Node *head, int k)
{
    Node *currentNode = head;
    int count = 0;

    while (currentNode->next != currentNode)
    {
        count++;
        if (count == k)
        {
            printf("%d ", currentNode->next->data);
            currentNode = deleteNode(currentNode, k);
            count = 0;
        }
        else
        {
            currentNode = currentNode->next;
        }
    }

    printf("@\n");
    return currentNode->data;
}