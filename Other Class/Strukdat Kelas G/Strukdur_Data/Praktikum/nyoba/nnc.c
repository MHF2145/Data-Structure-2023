/**
 * Dimodifikasi dari kode yang dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode_t {
    int key;
    struct bstnode_t 
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

void cari(BSTNode *root, int quarry, int *flag) {
    if(root) {
        int sum;
        if(root->parent) {
            if(root->left) {
                sum = root->key + root->parent->key + root->left->key;
                if(sum == quarry && !(*flag)) {
                    printf("%d | | Pintu terbuka! Lanjut eksplorasi.\n", quarry);
                    *flag = 1;
                }
            }
            if(root->right) {
                sum = root->key + root->parent->key + root->right->key;
                if(sum == quarry && !(*flag)) {
                    printf("%d | | Pintu terbuka! Lanjut eksplorasi.\n", quarry);
                    *flag = 1;
                }
            }
        }
        if(root->left && root->right) {
            sum = root->key + root->left->key + root->right->key;
            if(sum == quarry && !(*flag)) {
                printf("%d | | Pintu terbuka! Lanjut eksplorasi.\n", quarry);
                *flag = 1;
            }
        }
        cari(root->left, quarry, flag);
        cari(root->right, quarry, flag);
    }
}

void carijumlah(BST *bst, int quarry) {
    int flag = 0;
    cari(bst->_root, quarry, &flag);
    if(!flag)
        printf("%d >< Tidak ditemukan kombinasi yang tepat! Retreat.\n", quarry);
}

int main()
{
    BST set;
    bst_init(&set);
    int n, t, i;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        bst_insert(&set, x);
    }
    scanf("%d", &t);
    carijumlah(&set, t);

    return 0;
}