#include <bits/stdc++.h>

typedef struct pqueueNode_t
{
	char data[105];
	int cap;
	struct pqueueNode_t *next;
} PQueueNode;

typedef struct pqueue_t
{
	PQueueNode *_top;
	unsigned _size;
} PriorityQueue;


void pqueue_init(PriorityQueue *pqueue)
{
	pqueue->_top = NULL;
	pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) { 
	return (pqueue->_top == NULL); 
}

void pqueue_push(PriorityQueue *pqueue, char *value)
{
	PQueueNode *temp = pqueue->_top;
	PQueueNode *newNode = (PQueueNode *)malloc(sizeof(PQueueNode));
	strcpy(newNode->data, value);
	newNode->cap = 1;
	newNode->next = NULL;

	if (pqueue_isEmpty(pqueue))
	{
		pqueue->_top = newNode;
		return;
	}
	if (value < pqueue->_top->data)
	{
		if (!strcmp(value, pqueue->_top->data))
			pqueue->_top->cap++;
		else if (strcmp(value, pqueue->_top->data) > 0)
		{
			newNode->next = pqueue->_top;
			pqueue->_top = newNode;
		}
		else
		{
			while (temp->next != NULL && (strcmp(temp->next->data, value) > 0))
				temp = temp->next;
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
}
void pqueue_pop(PriorityQueue *pqueue, char *value)
{
	if (!pqueue_isEmpty(pqueue))
	{
		PQueueNode *temp = pqueue->_top;
		if (!strcmp(temp->data, value))
		{
			pqueue->_top = pqueue->_top->next;
			free(temp);
		}
		else
		{
			PQueueNode *temp1 = temp->next;
			while (temp1 != NULL && strcmp(temp1->data, value) != 0)
			{
				temp = temp->next;
				temp1 = temp1->next;
			}
			if (temp1 == NULL)
				return;
			temp->next = temp1->next;
			free(temp1);
		}
	}
}

char *pqueue_top(PriorityQueue *pqueue)
{
	if (!pqueue_isEmpty(pqueue))
		return pqueue->_top->data;
	else
		return 0;
}

int main(){
	PriorityQueue myPque;
	pqueue_init(&myPque);
	int n;
	scanf("%d", &n);
	while (n--){
		int num;
		scanf("%d", &num);
		if (num == 1){
			char chizuru[105];
			scanf("%s", chizuru);
			pqueue_push(&myPque, chizuru);
		}
		else if (num == 2){
			char chizuru[105];
			scanf("%s", chizuru);
			pqueue_pop(&myPque, chizuru);
		}
		else{
			int weselia;
			scanf("%d", &weselia);
			PQueueNode *temp = myPque._top;
			
			 while (weselia > 0){
			 	if (weselia > temp->cap){
			 		for (int i = 0; i < temp->cap; i++){
			 			printf("%s\n", temp->data);
			 		}
			 		weselia -= temp->cap;
			 	}
			 	else{
			 		for ( int i = 0; i < weselia; i++){
			 			printf("%s\n", temp->data);
			 		}	
			 		weselia = 0;
			 	}
			 	temp = temp->next;
			 }
			printf("---\n");
		}
	}
	return 0;
}
