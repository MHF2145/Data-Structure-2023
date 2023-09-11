#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

int is_sorted(struct node* head) {
    if(head == NULL || head->next == NULL) return 1;

    if(head->val > head->next->val) return 0;
    else return is_sorted(head->next);
}

int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* node2 = (struct node*)malloc(sizeof(struct node));
    struct node* node3 = (struct node*)malloc(sizeof(struct node));
    struct node* node4 = (struct node*)malloc(sizeof(struct node));
    struct node* node5 = (struct node*)malloc(sizeof(struct node));
    
    head->val = 0;
    head->next = node2;
    
    node2->val = 2;
    node2->next = node3;
    
    node3->val = 4;
    node3->next = node4;
    
    node4->val = 6;
    node4->next = node5;
    
    node5->val = 9;
    node5->next = NULL;
    
    // linked list 
	// 0 -> 2 -> 4 -> 6 -> 9
    
	if(is_sorted(head)) printf("list terurut naik\n");
    else printf("list tidak terurut naik\n");
    
    free(head);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    
    return 0;
}