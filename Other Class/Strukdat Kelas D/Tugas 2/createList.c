#include "header.h"

Node *createList(int n)
{
    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 1; i <= n; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = i;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    tail->next = head;
    return head;
}