#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* newNode(int data){
    struct Node* pink = (struct Node*)malloc(sizeof(struct Node));
    pink->data = data;
    pink->next = NULL;
    return pink;
}

void makeLink(struct Node** pointerHead, int green){
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = green;
    temp1->next = NULL;

    struct Node* temp2 = *pointerHead;
    if(*pointerHead == NULL){
        *pointerHead = temp1;
    } else {
        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }
}

void mengPrint(struct Node* mengHead){
    struct Node* temp = mengHead;
    printf("Listnya = ");
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* mengReverse(struct Node* magenta){
    if(magenta == NULL || magenta->next == NULL) return magenta;
    struct Node* res = mengReverse(magenta->next);
    magenta->next->next = magenta;
    magenta->next = NULL;
    return res;
}

struct Node* sumTwoNode(struct Node* white, struct Node* black){
    struct Node* res = NULL;
    struct Node *temp, *prev = NULL;
    int carry = 0, tambah;

    while (white != NULL || black != NULL){
        tambah = carry + (white ? white->data : 0) + (black ? black->data : 0);
        carry = (tambah >= 10) ? 1 : 0;
        tambah %= 10;
        temp = newNode(tambah);

        if(res == NULL){
            res = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;

        if(white) white = white->next;
        if(black) black = black->next;
    }
    if(carry > 0) temp->next = newNode(carry);
    return res;
}

int main(){
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;
    struct Node* total = NULL;

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    while(n1 > 0){
        int mod = n1 % 10;
        makeLink(&num1, mod);    
        n1 = n1 / 10; 
    }

    while(n2 > 0){
        int mod = n2 % 10;
        makeLink(&num2, mod);    
        n2 = n2 / 10; 
    }

    total = sumTwoNode(num1, num2);

    printf("Total (reverse) -> ");
    mengPrint(total);

    total = mengReverse(total);
    printf("Total -> ");
    mengPrint(total);
    return 0;
}