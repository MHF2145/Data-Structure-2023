#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

void insert(struct Node **root, int value) {
    if (*root == NULL) {
        *root = newNode(value);
        return;
    }
    if (value < (*root)->data) {
        insert(&((*root)->left), value);
    }
    else if (value > (*root)->data) {
        insert(&((*root)->right), value);
    }
    else {
        return;
    }
}

struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data > n1 && root->data > n2) {
        return LCA(root->left, n1, n2);
    }

    if (root->data < n1 && root->data < n2) {
        return LCA(root->right, n1, n2);
    }

    return root;
}

int main() {
    struct Node *root = NULL;
    int k, n, a, b;

    scanf("%d", &k);
    while(k--){
        scanf("%d", &n);
        insert(&root, n);
    }

    scanf("%d %d", &a, &b);
    struct Node* ancestor = LCA(root, a, b);
    printf("%d\n", ancestor->data);
    return 0;
}
