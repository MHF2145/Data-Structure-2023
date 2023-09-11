#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// function to add a node at the end of the list
void addNode(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int main() 
{
	int i, j, N, M;
    scanf("%d %d", &N, &M);

    int* pasukan = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) 
	{
        scanf("%d", &pasukan[i]);
    }

    Node* head = NULL;

   
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
    
    Node* curr = head;
    while (curr != NULL) 
	{
        printf("%d\n", curr->value);
        curr = curr->next;
    }

    return 0;
}
