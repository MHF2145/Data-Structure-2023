#include <stdio.h>
#include <stdlib.h>

struct Anak
{
    int ke;
    struct Anak *next;
};

int ngitung(int n, int m)
{
    // Logika untuk circular linked list
    struct Anak *head = (struct Anak *)malloc(sizeof(struct Anak));
    head->ke = 1;
    struct Anak *current = head;
    for (int i = 2; i <= n; i++)
    {
        struct Anak *newNode = (struct Anak *)malloc(sizeof(struct Anak));
        newNode->ke = i;
        current->next = newNode;
        current = current->next;
    }
    current->next = head;

    // Logika untuk eliminasi
    while (current->next != current)
    {
        for (int i = 1; i < m - 1; i++)
        {
            current = current->next;
        }
        struct Anak *eliminated = current->next;
        current->next = eliminated->next;
        free(eliminated);
        current = current->next;
    }

    int lastChild = current->ke;

    free(current);

    return lastChild;
}

int main()
{
    int n, m;
    printf("input n, m: ");
    scanf("%d %d", &n, &m);

    int lastChild = ngitung(n, m);

    printf("Anak terakhir adalah: %d\n", lastChild);

    return 0;
}
