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

// fungsi untuk menghapus node pada posisi tertentu
void deleteNodeAtPosition(Node *head, int position) {
    if(position < 1 || position > head->data) {
        printf("Invalid position!\n");
        return;
    }
    Node *current = head->next;
    int count = 1;
    while(count < position) {
        current = current->next;
        count++;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    head->data--;
}



// fungsi untuk mencetak isi dari linked list
void printList(Node *head) {
    Node *current = head->next;
    while(current != head) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n\n");
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

// fungsi untuk mencetak isi dari linked list secara terbalik
void printReverseList(Node *head) {
    Node *current = head->prev;
    while(current != head) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n\n");
}


int main() {
    Node *head = createNode(0);
    head->next = head;
    head->prev = head;

    int x, y;
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        scanf("%d", &y);
        addNode(head, y);
    }

    printf("\n\n");

    int position = 3;
    deleteNodeAtPosition(head, position);

    printList(head);

    printReverseList(head);

    return 0;
}
