#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
//node next data
typedef struct snode_t {
    int data;
    struct snode_t *next;
} SListNode;
//stuct agar jadi singly linked list
typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;
// singly linked list variable
SinglyList myList;
// inisiasi singly linked list 
void slist_init(SinglyList *list) 
{
    list->_head = NULL;
    list->_size = 0;
}
// memeriksa apakah empty
bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}
// untuk mengepush data ke list
void slist_pushFront(SinglyList *list, int value) 
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;

        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        list->_head = newNode;
    }
}
// untuk mengeluarkan data dari singly linked list
void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}
// memasukkan data ke belakang singly linked list
void slist_pushBack(SinglyList *list, int value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (slist_isEmpty(list)) 
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = newNode;
        }
    }
}
// mengeluarkan data dari belakang singly linked list
void slist_popBack(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL) {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}
// memasukkan data pada tempat yg ditentukan
void slist_insertAt(SinglyList *list, int index, int value)
{
    /* Kasus apabila posisinya melebihi batas */
    if (slist_isEmpty(list) || index >= list->_size) {
        slist_pushBack(list, value);
        return;
    }
    else if (index == 0 || index < 0) {
        slist_pushFront(list, value);
        return;
    }
    
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}
// mengeluarkan data pada tempat yang ditentukan
void slist_removeAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list)) {
        
        /* Kasus apabila posisinya melebihi batas */
        if (index >= list->_size) {
            slist_popBack(list);
            return;    
        }
        else if (index == 0 || index < 0) {
            slist_popFront(list);
            return;
        }
        
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        SListNode *nextTo = temp->next->next;
        free(temp->next);
        temp->next = nextTo;
        list->_size--;
    }
}

void slist_remove(SinglyList *list, int value)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp, *prev;
        temp = list->_head;

        if (temp->data == value) {
            slist_popFront(list);
            return;
        }
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        list->_size--;
    }
}

int slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

int slist_back(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        while (temp->next != NULL) 
            temp = temp->next;
        return temp->data;
    }
    return 0;
}

int slist_getAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index) {
            temp = temp->next;
            _i++;
        }
        return temp->data;
    }
    return 0;
}
// ngeprint isi singly linked list
void printElement(SinglyList *list) 
{
	printf("%d ", list->_head->data);
}
// kuadrat
void multiply2(SinglyList *list)
{
	list->_head->data *= 2;
}
// membalikkan
void reverseEach(SinglyList *list)
{
    int num = list->_head->data;
    int rev = 0;
    while(num != 0) {
    	rev = rev * 10 + num % 10;
    	num /= 10;
	}
	list->_head->data = rev;
}
// modulus
void sumDigit(SinglyList *list)
{
	int num = list->_head->data;
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    list->_head->data = sum;
}
// mengimplementasi singly linked list
void forEachElement(SinglyList *list, void function())
{
	SListNode *temp = list->_head;
	while(list->_head != NULL)
	{
		function(list);
		list->_head = list->_head->next;
	}
	list->_head = temp;
}

int main()
{
	slist_init(&myList);

    // Di isi List => [12, 23, 34, 45, 56]
    slist_pushBack(&myList, 12);
    slist_pushBack(&myList, 23);
    slist_pushBack(&myList, 34);
    slist_pushBack(&myList, 45);
	slist_pushBack(&myList, 56);
	//Mengeprint dari linked list
	forEachElement(&myList, printElement);
	puts("");
	//memasukkan isi dari hasil sumdigit ke singly linked list "myList", lalu di print element
	forEachElement(&myList, sumDigit);
	forEachElement(&myList, printElement);
	puts("");
	//memasukkan isi dari hasil multiply2, reverseEach ke singly linked list "myList", lalu di print element
	forEachElement(&myList, multiply2);
	forEachElement(&myList, reverseEach);
	forEachElement(&myList, printElement);
	puts("");
    
    return 0;
}