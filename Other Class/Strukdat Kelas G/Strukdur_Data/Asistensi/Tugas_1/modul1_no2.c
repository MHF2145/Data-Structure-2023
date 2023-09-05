#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node
{
    int data;
    int id;
    struct node *next;
} node;

typedef struct squeue
{
    unsigned size;
    node *top;
} squeue;

void squeue_init(squeue *squeue)
{
    squeue->top = NULL;
    squeue->size = 0;
}

bool squeue_isEmpty(squeue *squeue)
{
    return (squeue->top == NULL);
}

void squeue_push(squeue *squeue, int value, int id)
{
    node *temp = squeue->top;
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->id = id;
    newNode->next = NULL;

    if (squeue_isEmpty(squeue))
    {
        squeue->top = newNode;
        return;
    }

    if (value > squeue->top->data)
    {
        newNode->next = squeue->top;
        squeue->top = newNode;
    }
    else
    {
        while (temp->next != NULL &&
               temp->next->data > value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void squeue_pop(squeue *squeue)
{
    if (!squeue_isEmpty(squeue))
    {
        node *temp = squeue->top;
        squeue->top = squeue->top->next;
        free(temp);
    }
}

int squeue_top(squeue *squeue)
{
    if (!squeue_isEmpty(squeue))
        return squeue->top->id;
    else
        return 0;
}

int main()
{
    squeue urutan;
    squeue_init(&urutan);
    int total, id, utama;
    char msk[20];
    scanf("%d", &total);
    while (total--)
    {
        scanf("%s", msk);
        if (!strcmp(msk, "MASUK"))
        {
            scanf("%d %d", &id, &utama);
            squeue_push(&urutan, utama, id);
        }

        else if (!strcmp(msk, "LAYANI"))
        {
            if (squeue_isEmpty(&urutan))
            {
                printf("HORE");
            }
            else
            {
                printf("%d \n", squeue_top(&urutan));
                squeue_pop(&urutan);
            }
        }
    }
}
