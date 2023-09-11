#include"header.h"

NodePtr merge(NodePtr A, NodePtr B)
{
    NodePtr C = NULL, last = NULL;
    // check if either A or B is empty
    if (A == NULL)
        return B;
    if (B == NULL)
        return A;
    // both lists are non-empty
    while (A != NULL && B != NULL)
    {
        if (A->num < B->num)
        {
            if (C == NULL)
                C = A;
            else
                last->next = A;
            last = A;
            A = A->next;
        }
        else
        {
            if (C == NULL)
                C = B;
            else
                last->next = B;
            last = B;
            B = B->next;
        }
    } // end while
    if (A == NULL)
        last->next = B;
    else
        last->next = A;
    return C;
} // end merge