#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right, *parent;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(BSTNode *root, int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->parent = root;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, BSTNode *node, int value) {
    if (node == NULL)
        return __bst__createNode(root, value);
    root = node;
    if (value < node->key)
        node->left = __bst__insert(root, node->left, value);

    else if (value > node->key)
        node->right = __bst__insert(root, node->right, value);

    return node;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
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

BSTNode* bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return NULL;

    if (temp->key == value)
        return temp;
    else
        return NULL;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, bst->_root, value);
        bst->_size++;
    }
}

void __solve(BSTNode *root, int value, int *ada) {
    if(root) {
        int sum;
        if(root->parent) {
            if(root->left) {
                sum = root->key + root->parent->key + root->left->key;
                if(sum == value && !(*ada)) {
                    printf("%d Selamat! Kalian menemukan harta karunnya\n", value);
                    *ada = 1;
                }
            }
            if(root->right) {
                sum = root->key + root->parent->key + root->right->key;
                if(sum == value && !(*ada)) {
                    printf("%d Selamat! Kalian menemukan harta karunnya\n", value);
                    *ada = 1;
                }
            }
        }
        if(root->left && root->right) {
            sum = root->key + root->left->key + root->right->key;
            if(sum == value && !(*ada)) {
                printf("%d Selamat! Kalian menemukan harta karunnya\n", value);
                *ada = 1;
            }
        }
        __solve(root->left, value, ada);
        __solve(root->right, value, ada);
    }
}

void solve(BST *bst, int value) {
    int ada = 0;
    __solve(bst->_root, value, &ada);
    if(!ada)
        printf("%d Tidak ada kombinasi yang tepat! Bikin ulang.\n", value);
}

int main()
{
    BST set;
    bst_init(&set);
    int n, a;

    scanf("%d", &n);
    while(n--) {
        scanf("%d", &a);
        bst_insert(&set, a);
    }
    scanf("%d", &a);
    solve(&set, a);

    return 0;
}