#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bstnode_t
{
    int key;
    struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL){
        return __bst__createNode(value);
    } if (value < root->key) {
        root->left = __bst__insert(root->left, value);
    } else if (value > root->key){
        root->right = __bst__insert(root->right, value);
    }

    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key){
            root = root->left;
        } else if (value > root->key){
            root = root->right;
        } else{
            return root;
        }
    }
    return root;
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

int leftLeaves(BSTNode* root) {
    if (root == NULL) {
        return 0;
    }

    int total = 0;

    if (root->left != NULL) {
        if (root->left->left == NULL && root->left->right == NULL) {
            total += root->left->key;
        } else {
            total += leftLeaves(root->left);
        }
    }

    total += leftLeaves(root->right);

    return total;
}


int rightLeaves(BSTNode* root) {
    if (root == NULL) {
        return 0;
    }

    int total = 0;

    if (root->right != NULL) {
        if (root->right->left == NULL && root->right->right == NULL) {
            total += root->right->key;
        } else {
            total += rightLeaves(root->right);
        }
    }

    total += rightLeaves(root->left);

    return total;
}

bool cek(BSTNode *root) {
    if (root == NULL)   // empty tree
        return false;
    if (root->left == NULL && root->right == NULL)   // single node tree
        return true;
    else return false;
}

int main(){
    BST set;
    bst_init(&set);

    int value;
    while (scanf("%d", &value) == 1 && value != -1) {
        bst_insert(&set, value);
    }

    char direction;
    scanf(" %c", &direction);

    if (direction == 'L') {
        if (cek(set._root) || !leftLeaves(set._root)) {
            printf("gaada pak!");
        } else {
            printf("%d", leftLeaves(set._root));
        }
    } else if (direction == 'R') {
        if (cek(set._root) || !rightLeaves(set._root)) {
            printf("gaada pak!");
        } else {
            printf("%d", rightLeaves(set._root));
        }
    }

    return 0;
}
