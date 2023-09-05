#include"header.h"

NodePtr makeList()
{
    NodePtr makeNode(int), np, top, last, temp;
    int n;
    top = NULL;
    if (scanf("%d", &n) != 1)
        n = 0;
    while (n != 0)
    {
        np = makeNode(n); // create a new node containing n
        if (top == NULL)
            top = np; // set top if first node
        else
        {
            // insert node in sorted order
            temp = top;
            while (temp != NULL)
            {
                if (np->num < temp->num)
                {
                    np->next = temp;
                    if (temp == top)
                        top = np;
                    else
                        last->next = np;
                    break;
                }
                last = temp;
                temp = temp->next;
            }
            if (temp == NULL)
            {
                last->next = np; // insert at the end of the list
            }
        }
        if (scanf("%d", &n) != 1)
            n = 0;
    }
    return top;
} // end makeList