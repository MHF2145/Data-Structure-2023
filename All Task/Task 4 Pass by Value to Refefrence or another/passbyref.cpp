#include <stdio.h>
#include <stdlib.h>

typedef struct Mahasiswa
{
    int nim;
    struct Mahasiswa *next;
} Mahasiswa;

void init(Mahasiswa **P)
{
    *P = NULL;
}

Mahasiswa *alokasi(int nim)
{
    Mahasiswa *P;
    P = (Mahasiswa*) malloc(sizeof (Mahasiswa));
    if (P != NULL)
    {
        P -> next = NULL;
        P -> nim = nim;
    }
    return (P);
}

void Add(Mahasiswa **p, int nim)
{
    *p = alokasi(nim);
    printf("%d ", (*p) -> nim);  // print the data after adding a new node
}

int main()
{
    Mahasiswa *head;
    init(&head);
    int i, j;
    scanf("%d", &j);
    for (i = 1; i <= j; i++)
    {
        Add(&head, i);
    }

    printf("\n");

    return 0;
}
