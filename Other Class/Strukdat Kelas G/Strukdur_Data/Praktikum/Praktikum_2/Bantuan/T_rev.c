#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int shortest = 9999999, uang;

typedef struct bstnode_t
{
    int data, jarak;
    struct bstnode_t *left, *right, *parent;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode *__bst__createNode(BSTNode *proot, int value, int jarak)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    if (jarak == -1)
        newNode->jarak = 0;
    else
    newNode->jarak = jarak;
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    newNode->parent = proot;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, BSTNode *proot, int value, int jarak)
{
    if (root == NULL)
        return __bst__createNode(proot, value, jarak);
    if (value < root->data)
        root->left = __bst__insert(root->left, root, value, jarak);
    else if (value > root->data)
        root->right = __bst__insert(root->right, root, value, jarak);
    return root;
}

BSTNode *__bst__search(BSTNode *root, int value)
{
    while (root != NULL)
    {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode *__bst__findMinNode(BSTNode *node)
{
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}

BSTNode *__bst__remove(BSTNode *root, int value)
{
    if (root == NULL)
        return NULL;
    if (value > root->data)
        root->right = __bst__remove(root->right, value);
    else if (value < root->data)
        root->left = __bst__remove(root->left, value);
    else
    {
        if (root->left == NULL)
        {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL)
        {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }
        BSTNode *temp = __bst__findMinNode(root->right);
        root->data = temp->data;
        root->right = __bst__remove(root->right, temp->data);
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

BSTNode *bst_short(BSTNode *root, BSTNode *lroot, int value)
{
    if (root->left == NULL && root->right == NULL)
    {
        if (shortest > value)
        {
            shortest = value;
        }
    }
    else if (root != NULL && value < shortest)
    {
        if (root->left != NULL && root->left != lroot)
        {
            bst_short(root->left, root, value + root->left->jarak);
        }
        if (root->right != NULL && root->right != lroot)
        {
            bst_short(root->right, root, value + root->right->jarak);
        }
        if (root->parent != NULL && root->parent != lroot)
        {
            bst_short(root->parent, root, value + root->jarak);
        }
    }
}

bool bst_find_2(BST *bst, int value)
{
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
    {
        return false;
    }
    if (temp->data == value)
    {
        shortest = 9999999;
        bst_short(temp, NULL, 0);
        if (uang - shortest >= 0)
        {
            printf("yey, bisa refreshing :)\n");
        }
        else
        {
            printf("bruhh -_-\n");
        }
    }
    else
    {
        return false;
    }
}

bool bst_find(BST *bst, int value)
{
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
    {
        return false;
    }
    if (temp->data == value)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void bst_insert(BST *bst, int value, int jarak)
{
    if (!bst_find(bst, value))
    {
        bst->_root = __bst__insert(bst->_root, bst->_root, value, jarak);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value)
{
    if (bst_find(bst, value))
    {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

int main()
{
    BST kota;
    bst_init(&kota);
    int loop, value, jarak;

    scanf("%d", &uang);
    scanf("%d %d", &loop, &value);
    bst_insert(&kota, value, -1);
    loop --;
    while (loop--)
    {
        scanf("%d %d", &value, &jarak);
        bst_insert(&kota, value, jarak);
    }
    scanf("%d", &loop);
    while (loop--)
    {
        scanf("%d", &value);
        bst_find_2(&kota, value);
    }

    return 0;
}
