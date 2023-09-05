#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct snode_t {
    int data;
    struct snode_t *next;
} SListNode;

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

void slist_init(SinglyList *list) 
{
    list->_head = NULL;
    list->_size = 0;
}


bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

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

int slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

int main(){

    SinglyList kpop;
    slist_init(&kpop);
    float n,w,p,data,ans = 0;
    scanf("%f %f %f", &n, &w, &p);

    for (int i = 0; i < n; i++)
    {
        scanf("%f",&data);
        slist_pushBack(&kpop,data);
    }

    while (kpop._head != NULL)
    {
        ans = ans + slist_front(&kpop);
        slist_popFront(&kpop);
    }
    ans = (ans - (p*w))/60;

    printf("%.2f",ans);
    
    
}

