#include"header.h"

int main()
{
    void printList(NodePtr);
    NodePtr makeList(void);
    NodePtr merge(NodePtr, NodePtr);
    NodePtr A, B;
    printf("Enter numbers for the first list (0 to end)\n");
    A = makeList();
    printf("Enter numbers for the second list (0 to end)\n");
    B = makeList();
    printf("\nThe merged list is\n");
    printList(merge(A, B));
} // end main