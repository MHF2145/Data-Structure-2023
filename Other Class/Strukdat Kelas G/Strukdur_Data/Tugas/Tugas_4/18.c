#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int value;
    struct Stack *next;
};

struct Stack *createNode(int data)
{
    struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(struct Stack *root)
{
    return (root == NULL);
}

void push(struct Stack **root, int data)
{
    struct Stack *newNode = createNode(data);
    newNode->next = *root;
    *root = newNode;
}

int pop(struct Stack **root)
{
    if (isEmpty(*root))
    {
        return -1;
    }
    struct Stack *temp = *root;
    *root = (*root)->next;
    int popped = temp->value;
    free(temp);
    return popped;
}

int peek(struct Stack *root)
{
    if (isEmpty(root))
    {
        return -1;
    }
    return root->value;
}

void sortStack(struct Stack **S1)
{
    struct Stack *S2 = NULL;

    while (!isEmpty(*S1))
    {
        int temp = pop(S1);

        while (!isEmpty(S2) && peek(S2) > temp)
        {
            push(S1, pop(&S2));
        }

        push(&S2, temp);
    }

    while (!isEmpty(S2))
    {
        push(S1, pop(&S2));
    }
}

void Output(struct Stack *root)
{
    if (isEmpty(root))
    {
        return;
    }
    struct Stack *current = root;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Stack *S1 = NULL;

    push(&S1, 7);
    push(&S1, 3);
    push(&S1, 9);
    push(&S1, 2);
    push(&S1, 5);

    printf("Original stack: ");
    Output(S1);

    sortStack(&S1);

    printf("Sorted stack: ");
    Output(S1);

    return 0;
}
