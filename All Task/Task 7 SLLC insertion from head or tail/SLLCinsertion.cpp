#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct TNode
{
    int data;
    TNode *next;
};

TNode *head, *tail;
void tampil();

void init()
{
    head = NULL;
    tail = NULL;
}

int isEmpty()
{
    if (tail == NULL)
    {
        return 1;
    }
    else return 0;
}

void insertDepan(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru -> data = databaru;
    baru -> next = baru;
    if(isEmpty() == 1)
    {
        head = baru;
        tail = baru;
        head -> next = head;
        tail -> next = tail;   
    }
    else
    {
        baru -> next = head;
        head = baru;
        tail -> next = head;
    }
    printf("Data masuk\n\n");
}

void insertBelakang(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru -> data = databaru;
    baru -> next = baru;
    if(isEmpty() == 1)
    {
        head = baru;
        tail = baru;
        head -> next = head;
        tail -> next = tail;   
    }
    else
    {
        tail -> next = baru;
        tail = baru;
        tail -> next = head;
    }
    printf("Data masuk\n\n");
}

void tampil()
{
    TNode *b;
    b = head;
    if (isEmpty() == 0)
    {
        do
        {
            printf("%d", b -> data);
            b = b -> next;
            printf(" ");
        } while (b != head);
        printf("\n\n");
    }
    else
    {
        printf("Masih kosong\n");
    }
}

int main()
{
    insertDepan(10);
    insertDepan(20);
    insertDepan(30);
    insertBelakang(50);
    insertBelakang(60);
    insertBelakang(70);
    tampil();
    getch();
}