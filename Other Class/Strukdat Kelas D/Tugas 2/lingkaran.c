#include "header.h"

int main()
{
    int T, n, k;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &n, &k);

        Node *head = createList(n);

        int classLeader = selectClassLeader(head, k);
        printf("%d\n", classLeader);

        Node* currentNode = head;
        Node* nextNode = NULL;
        do {
            nextNode = currentNode->next;
            free(currentNode);
            currentNode = nextNode;
        } while (currentNode != head);
    }
    return 0;
}