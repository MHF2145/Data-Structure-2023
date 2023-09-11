#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct dnode_t {
    char data;
    struct dnode_t      \
        *next,
        *prev;
} DListNode;

typedef struct dlist_t {
    DListNode           \
        *_head, 
        *_tail;
    unsigned _size;
} List;


DListNode* __dlist_createNode(char value)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void dlist_init(List *list)
{
    list->_head = list->_tail = NULL;
    list->_size = (unsigned) 0;
}

bool dlist_isEmpty(List *list) {
    return (list->_head == NULL && \
            list->_tail == NULL);
}

void dlist_pushFront(List *list, char value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        list->_size++;
        if (dlist_isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }

        newNode->next = list->_head;
        list->_head->prev = newNode;
        list->_head = newNode;
    }
}

void dlist_pushBack(List *list, char value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        list->_size++;
        if (dlist_isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }

        list->_tail->next = newNode;
        newNode->prev = list->_tail;
        list->_tail = newNode;
    }
}

char dlist_front(List *list) {
    if (!dlist_isEmpty(list)) {
        return (list->_head->data);
    }
    return 0;
}

char dlist_back(List *list) {
    if (!dlist_isEmpty(list)) {
        return (list->_tail->data);
    }
    return 0;
}

void dlist_popFront(List *list)
{
    if (!dlist_isEmpty(list)) {
        DListNode *temp = list->_head;
        if (list->_head == list->_tail) {
            list->_head = NULL;
            list->_tail = NULL;
            free(temp);
        }
        else {
            list->_head = list->_head->next;
            list->_head->prev = NULL;
            free(temp);
        }
        list->_size--;
    }
}

void dlist_popBack(List *list)
{
    if (!dlist_isEmpty(list)) {
        DListNode *temp;
        if (list->_head == list->_tail) {
            temp = list->_head;
            list->_head = NULL;
            list->_tail = NULL;
            free(temp);
        }
        else {
            temp = list->_tail;
            list->_tail = list->_tail->prev;
            list->_tail->next = NULL;
            free(temp);
        }
        list->_size--;
    }
}

int main()
{
    List myList;
    dlist_init(&myList);
//	char c;
//	int len = 0;
//		
//	while ((c = getchar()) != '\n')
//	{
//       	
//	}

    dlist_pushBack(&myList, 'n');
    dlist_pushBack(&myList, 'i');
    dlist_pushBack(&myList, 'g');
    dlist_pushBack(&myList, 'g');
	dlist_pushBack(&myList, 'e');
	dlist_pushBack(&myList, 'r');

	while(1)
	{
		if(dlist_isEmpty(&myList))
		{
			printf("palindrom\n");
			return 0;
		} 
		
		if(dlist_front(&myList) == dlist_back(&myList))
		{
			dlist_popBack(&myList);
			dlist_popFront(&myList);
		}
		else
		{
			printf("bukan palindrom\n");
			return 0;
		}
	}
}