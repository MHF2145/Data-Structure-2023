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

int main() {
    Node *head = createNode(0); // head digunakan untuk menyimpan jumlah seluruh elemen dalam linked list
    head->next = head; // set next dari head ke head sendiri untuk membuat linked list circular
    head->prev = head; // set prev dari head ke head sendiri untuk membuat linked list circular

    // menambahkan beberapa node baru ke linked list
    Node *node1 = createNode(10);
    Node *node2 = createNode(20);
    Node *node3 = createNode(30);

    // menghubungkan node-node tersebut dengan linked list
    node1->prev = head;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = head;

    // menambahkan jumlah seluruh elemen pada linked list
    head->data = 3;

    // mencetak elemen pada linked list
    Node *current = head->next;
    while(current != head) {
        printf("%d ", current->data);
        current = current->next;
    }

    // menghapus node-node pada linked list
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
