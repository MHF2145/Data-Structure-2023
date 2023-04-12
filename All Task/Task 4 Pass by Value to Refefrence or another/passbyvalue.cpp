#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa
{
    char name[50];
    struct Mahasiswa *next;
} Mahasiswa;

void init(Mahasiswa **P)
{
    *P = NULL;
}

Mahasiswa *alokasi(char name[])
{
    Mahasiswa *P;
    P = (Mahasiswa*) malloc(sizeof (Mahasiswa));
    if (P != NULL)
    {
        P -> next = NULL;
        strcpy(P -> name, name);
    }
    return (P);
}

void Add(Mahasiswa **p, char name[])
{
    *p = alokasi(name);
    printf("%s ", (*p) -> name);  // print the data after adding a new node
}

int main()
{
    Mahasiswa *head = NULL;
    init(&head);
    char input[50];
    char choice;
    do {
        printf("Enter a name: ");
        scanf("%s", input);
        Add(&head, input);
        printf("\nDo you want to enter another name? (y/n): ");
        scanf(" %c", &choice);  // space before %c to consume any leftover newline character
    } while (choice == 'y' || choice == 'Y');

    printf("\n");

    return 0;
}
