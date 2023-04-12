#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
//next node
typedef struct pqueueNode_t {
    int data, id;
    struct pqueueNode_t *next;
} PQueueNode;
// deklar priority
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;
//inisiasi priority
void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}
// cek empty queue
bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}
// queu push
void pqueue_push(PriorityQueue *pqueue, int value, int _id)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->id = _id;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value > pqueue->_top->data) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && 
                temp->next->data > value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
// remove data from queue
void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}
//set the queu arrow to the top of the queu
int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->id;
    else return 0;
}

int main()
{
    PriorityQueue myPque;
    pqueue_init(&myPque);
    
    char cmd[11];
	int q;
    
    scanf("%d", &q);
    
    while(q--) 
	{
    	scanf("%s", cmd);
    	
    	if(strcmp(cmd, "MASUK") == 0)
		{
			int id, x;
			scanf("%d %d", &id, &x);
			pqueue_push(&myPque, x, id);
		}
		if(strcmp(cmd, "LAYANI") == 0)
		{
			printf("%d\n", pqueue_top(&myPque));
			pqueue_pop(&myPque);
		}
	}
	
    puts("");
    return 0;
}