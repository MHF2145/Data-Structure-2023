#include <stdio.h>
#include <stdlib.h>

// struktur untuk node
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// fungsi untuk membuat node baru
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// fungsi untuk menambahkan node baru ke linked list
void addNode(Node *head, int data) {
    Node *newNode = createNode(data);
    newNode->prev = head;
    newNode->next = head->next;
    head->next->prev = newNode;
    head->next = newNode;
    head->data++;
}

// fungsi untuk menghapus node dari linked list
void deleteNode(Node *head, int data) {
    Node *current = head->next;
    while(current != head && current->data != data) {
        current = current->next;
    }
    if(current != head) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
        head->data--;
    }
}

// fungsi untuk mencetak isi dari linked list
void printList(Node *head) {
    Node *current = head->next;
    while(current != head) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// fungsi untuk mengubah nilai data pada node yang ditentukan
void editNode(Node *head, int data, int newData) {
    Node *current = head->next;
    while(current != head && current->data != data) {
        current = current->next;
    }
    if(current != head) {
        current->data = newData;
    }
}

int main() {
    Node *head = createNode(0);
    head->next = head;
    head->prev = head;

    addNode(head, 10);
    addNode(head, 20);
    addNode(head, 30);
    printList(head);

    deleteNode(head, 20);
    printList(head);

    editNode(head, 30, 40);
    printList(head);

    return 0;
}
