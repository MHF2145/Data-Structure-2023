#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct queueNode_t {
	char _nama[31], _alamat[51], _kelurahan[51];
    int _usia;
    struct queueNode_t *next;
} QueueNode;

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, char nama[], int usia, char alamat[], char kelurahan[])
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->_usia = usia;
        strcpy(newNode->_nama, nama);
        strcpy(newNode->_alamat, alamat);
        strcpy(newNode->_kelurahan, kelurahan);
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

void queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        printf("%s %d %s %s\n", queue->_front->_nama, queue->_front->_usia, queue->_front->_alamat, queue->_front->_kelurahan);
		return;
    }
    return;
}

int queue_size(Queue *queue) {
    return queue->_size;
}

int main()
{
    Queue q, temp;
    queue_init(&q);
    queue_init(&temp);
    
    int n, b;
    char a[31], c[51], d[51];
    while(scanf("%d", &n))
    {
    	if(n == 1)
    	{
    		scanf("%s %d %s %s", a, &b, c, d);
    		queue_push(&q, a, b, c, d);
		}
		else if(n == 2)
		{
			queue_front(&q);
			queue_pop(&q);
		}
		else if(n == 3)
		{
			while(!queue_isEmpty(&q))
			{
				queue_push(&temp, q._front->_nama, q._front->_usia, q._front->_alamat, q._front->_kelurahan);
				queue_front(&q);
				queue_pop(&q);
			}
			while(!queue_isEmpty(&temp))
			{
				queue_push(&q, temp._front->_nama, temp._front->_usia, temp._front->_alamat, temp._front->_kelurahan);
				queue_pop(&temp);
			}
		}
		else
		{
			while(!queue_isEmpty(&q)) queue_pop(&q);
			return 0;
		}
	}
}