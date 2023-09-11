#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int value;
    struct Node* next;
} Node;

//Template bikin Node
Node* createNode(int value) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> value = value;
    newNode -> next = NULL;
    return newNode;
}

// Template add node di akhir list
void addNode(Node** head, int value) 
{
    Node* newNode = createNode(value);
    if (*head == NULL) 
	{
        *head = newNode;
    } 
	else 
	{
        Node* current = *head;
        while (current->next != NULL) 
		{
            current = current->next;
        }
        current->next = newNode;
    }
}

int main() 
{
	int i, j, N, M;
    scanf("%d%d", &N, &M);

    int* pasukan = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) 
	{
        scanf("%d", &pasukan[i]);
    }

    Node* head = NULL;

    // perform troop detection for each range and add the smallest detected troop to the list
    for (i = 0; i <= N - M; i++) 
	{
        int min = pasukan[i];
        for (j = i + 1; j < i + M; j++) 
		{
            if (pasukan[j] < min) 
			{
                min = pasukan[j];
            }
        }
        addNode(&head, min);
    }

    // print the smallest detected troops
    Node* current = head;
    while (current != NULL) 
	{
        printf("%d\n", current -> value);
        current = current -> next;
    }

    return 0;
}
