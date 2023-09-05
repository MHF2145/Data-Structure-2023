#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bstnode_t
{
    int key;
    struct bstnode_t *left, *right, *parent;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode *__bst__createNode(BSTNode *parent, int value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->parent = parent;
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *parent, BSTNode *root, int value)
{
    if (root == NULL)
        return __bst__createNode(parent, value);

    if (value < root->key)
    {
        root->left = __bst__insert(root, root->left, value);
    }

    else if (value > root->key)
    {
        root->right = __bst__insert(root, root->right, value);
    }

    return root;
}

BSTNode *__bst__search(BSTNode *root, int value)
{
    while (root != NULL)
    {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst)
{
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value)
{
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value)
{
    if (!bst_find(bst, value))
    {
        bst->_root = __bst__insert(bst->_root, bst->_root, value);
        bst->_size++;
    }
}

bool flag = 0;
void brute(BSTNode *root, int value)
{
    BSTNode *temp = root;
    long long total = 0;
    if (temp)
    {
        if (temp->left && temp->right)
        {
            if (temp->key + temp->left->key + temp->right->key == value)
            {
                // puts("c");
                flag = 1;
                return;
            }
        }
        brute(temp->left, value);
        brute(temp->right, value);
    }
}

int main()
{
    BST set;
    bst_init(&set);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a;
        scanf("%d", &a);
        bst_insert(&set, a);
    }
    // printf("%d %d\n", set._root->left->parent->key, set._root->left->left->parent->key);
    int b;
    scanf("%d", &b);
    brute(set._root, b);
    if (flag)
        printf("Yey, ketemu :D\n");
    else
        printf("Yah, bukan :(\n");
    return 0;
}