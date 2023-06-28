#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct node_t {
    int value;
    struct node_t *left, *right;
} Node;

typedef struct bst_t {
    Node *_root;
    unsigned int _size;
} BST;

Node* createNode(int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->value)
        root->left = insertNode(root->left, value);
    else if (value > root->value)
        root->right = insertNode(root->right, value);

    return root;
}

Node* searchNode(Node *root, int value) {
    while (root != NULL) {
        if (value < root->value)
            root = root->left;
        else if (value > root->value)
            root = root->right;
        else
            return root;
    }
    return root;
}

Node* findMinNode(Node *node) {
    Node *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}

Node* removeNode(Node *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->value)
        root->right = removeNode(root->right, value);
    else if (value < root->value)
        root->left = removeNode(root->left, value);
    else {

        if (root->left == NULL) {
            Node *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            Node *leftChild = root->left;
            free(root);
            return leftChild;
        }

        Node *temp = findMinNode(root->right);
        root->value = temp->value;
        root->right = removeNode(root->right, temp->value);
    }
    return root;
}

void printNodesWithOneChild(Node *node, bool *found){
    if(node == NULL) return;

    printNodesWithOneChild(node->left, found);

    if((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL)){
        printf("%d ", node->value);
        *found = true;
    }

    printNodesWithOneChild(node->right, found);
}

void bstInit(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0;
}

bool bstIsEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bstFind(BST *bst, int value) {
    Node *temp = searchNode(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->value == value)
        return true;
    else
        return false;
}

void bstInsert(BST *bst, int value) {
    if (!bstFind(bst, value)) {
        bst->_root = insertNode(bst->_root, value);
        bst->_size++;
    }
}

void bstRemove(BST *bst, int value) {
    if (bstFind(bst, value)) {
        bst->_root = removeNode(bst->_root, value);
        bst->_size--;
    }
}

void printNodesWithOneChild(BST *bst){
    bool found = false;
    printNodesWithOneChild(bst->_root, &found);
    if(!found){
        printf("Use whatever means you must to control our population. Just do it.\n");
    }
}

int main(){
    BST set;
    bstInit(&set);

    int N, X;
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        int order;
        scanf("%d", &order);
        if(order == 15){
            scanf("%d", &X);
            bstInsert(&set, X);
        }
        else if(order == 4){
            scanf("%d", &X);
            bstRemove(&set, X);
        }
        else if(order == 89){
            printNodesWithOneChild(&set);
        }
    }
    return 0;
}
