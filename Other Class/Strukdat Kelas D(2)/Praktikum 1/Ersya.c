#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

void enqueue(Queue *q, int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

int dequeue(Queue *q) {
    if (q->front == NULL) {
        return -1;
    }

    Node *temp = q->front;
    int data = temp->data;

    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
    }

    free(temp);
    q->size--;
    return data;
}

	bool queue_isEmpty(Queue *queue) 
	{
    	return (queue->front == NULL && queue->rear == NULL);
	}


int main() {
    int x, y, n, i, j;
    int data;
    Queue q;
    initQueue(&q);

    scanf("%d %d %d", &x, &y, &n);
    for (i = 0; i < x; i++) 
	{
        scanf("%d", &data);
        enqueue(&q, data);
    }
    
    		
	queue_isEmpty(&q);
	if (queue_isEmpty) printf("Kasian Ersya\n");
	
	else
	{
		for (i = 0; i < n; i++) 
		{
        	data = dequeue(&q);

       		 for (j = 0; j < y; j++) 
			{
        		nextData = dequeue(&q);
           		if (nextData == -1) 
				{
                	break;
            	}

            enqueue(&q, nextData);
        }

        if (data == -1) 
		{
            printf("Kasian Ersya\n");
            return 0;
        }
    }

    printf("%d\n", data);
    return 0;
	}
}

