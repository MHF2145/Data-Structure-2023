#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char data;
    struct Node* next;
};

void makeLink(struct Node** pointerHead,char blue){
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = blue;
    temp1->next = NULL;

    struct Node* temp2 = *pointerHead;
    if(*pointerHead == NULL){
        *pointerHead = temp1;
    } else{
        while (temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }
}

void mengPrint(struct Node* mengHead){
    struct Node* temp = mengHead;
    printf("Listnya = ");
    while (temp != NULL)
    {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");    
}

void deleteFront(struct Node** gray){
    struct Node* temp = *gray;
    *gray = temp->next;
    free(temp);
}

void sortedInsert(struct Node** newNode, struct Node** sorted){
    if(*sorted == NULL || (*sorted)->data > (*newNode)->data){
        (*newNode)->next = *sorted;
        *sorted = *newNode;
    } else {
        struct Node* curr = *sorted;
        while(curr->next != NULL && curr->next->data < (*newNode)->data){
            curr = curr->next;
        }
        (*newNode)->next = curr->next;
        curr->next = *newNode;
    }
}

void insertionSort(struct Node** green, struct Node** red){
    struct Node* current = *green;
    while(current != NULL){
        struct Node* temp2 = current->next;
        sortedInsert(&current, &*red);
        current = temp2;
    }
    *green = *red;
}

int main(){
    struct Node* word1 = NULL;
    struct Node* word2 = NULL;
    struct Node* sort1 = NULL;
    struct Node* sort2 = NULL;

    char w1[30], w2[30];
    scanf("%s %s", w1, w2);

    if(strlen(w1) != strlen(w2)){
        printf("Bukan Anagram");
        exit(0);
    }

    for(int i = 0; i < strlen(w1); i++){
        makeLink(&word1, w1[i]);
        makeLink(&word2, w2[i]);
    }  

    printf("---Before---\n");
    printf("Word1 -> ");
    mengPrint(word1);
    printf("Word2 -> ");
    mengPrint(word2);

    insertionSort(&word1, &sort1);
    insertionSort(&word2, &sort2);

    printf("\n---After---\n");

    while(word1 != NULL){
        printf("Word1 -> ");
        mengPrint(word1);
        printf("Word2 -> ");
        mengPrint(word2);
        printf("\n");
        if(word1->data == word2->data){
            deleteFront(&word1);
            deleteFront(&word2);
        } else{
            printf("Bukan Anagram");
            exit(0);
        }
    }

    printf("Anagram Nih");
    return 0;
}