#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int angka;
    struct Node *next;
};

// Logika nambah angka
struct Node *nambah(struct Node *l1, struct Node *l2)
{
    struct Node *hasil = NULL;
    struct Node *temp = NULL;
    int tambahan = 0;

    while (l1 != NULL || l2 != NULL || tambahan != 0)
    {
        int sum = tambahan;
        if (l1 != NULL)
        {
            sum += l1->angka;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->angka;
            l2 = l2->next;
        }

        int digit = sum % 10;
        tambahan = sum / 10;

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->angka = digit;
        newNode->next = NULL;

        if (hasil == NULL)
        {
            hasil = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    return hasil;
}

// Buat node baru
struct Node *buatnode(int digit)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->angka = digit;
    newNode->next = NULL;
    return newNode;
}

// memasukkan digit dari belakang
void input(struct Node **head, int digit)
{
    struct Node *newNode = buatnode(digit);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

// outputnya
void Hasil(struct Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Hasil(head->next);
    printf("%d ", head->angka);
}

int main()
{
    // sebagai representasi dari 2 angka berbeda
    struct Node *l1 = NULL;
    struct Node *l2 = NULL;

    // contoh 128 + 324
    input(&l1, 8);
    input(&l1, 2);
    input(&l1, 1);

    input(&l2, 4);
    input(&l2, 2);
    input(&l2, 3);

    struct Node *sum = nambah(l1, l2);

    printf("Hasilnya: ");
    Hasil(sum);

    return 0;
}
