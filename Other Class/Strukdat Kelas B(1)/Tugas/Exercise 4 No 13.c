#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* newNode(int data)
{
    Node* new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
 
void push(Node** head_ref, int new_data)
{
    Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
Node* addTwoLists(Node* first, Node* second)
{
    Node* res = NULL;
    Node *temp, *prev = NULL;
    int carry = 0, sum;
 
    while (first != NULL || second != NULL) {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = newNode(sum);
        
        if (res == NULL)
            res = temp;
        else
            prev->next = temp;
       
        prev = temp;
 
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (carry > 0)
        temp->next = newNode(carry);
        
    return res;
}
 
Node* reverse(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;
        
    Node* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return rest;
}
 
void printList(Node* node)
{
    while (node != NULL) {
        printf("%d",node->data);
        node = node->next;
    }
}
 
int main(void)
{
    Node* resint = NULL;
    Node* resdec = NULL;
    Node* int1 = NULL;
    Node* dec1 = NULL;
    Node* int2 = NULL;
    Node* dec2 = NULL;
 	
    push(&int1, 6);
    push(&int1, 4);
    push(&dec1, 9);
    push(&dec1, 5);
    push(&dec1, 7);
    printf("First num is ");
    printList(int1);
    printf(".");
    printList(dec1);
    puts("");
 
    push(&int2, 4);
    push(&int2, 8);
    push(&dec2, 6);
    push(&dec2, 9);
    printf("Second num is ");
    printList(int2);
    printf(".");
    printList(dec2);
    puts("");
 
    int1 = reverse(int1);
    dec1 = reverse(dec1);
    int2 = reverse(int2);
    dec2 = reverse(dec2);
    
    resint = addTwoLists(int1, int2);
 	resdec = addTwoLists(dec1, dec2);

    resint = reverse(resint);
    resdec = reverse(resdec);
    
    printf("Resultant num is ");
    printList(resint);
    printf(".");
    printList(resdec);
    puts("");
    
	return 0;
}