#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};

typedef struct BST node;

node *createNode(int n)
{
    node *newnode;
    newnode = malloc(sizeof(node));
    newnode->data = n;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int search(node *root, int n)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (n == root->data)
    {
        return 1;
    }
    else if (n <= root->data)
    {
        return search(root->left, n);
    }
    else
    {
        return search(root->right, n);
    }
}

node *insert(node *root, int n)
{
    if (root == NULL)
    {
        root = createNode(n);
    }
    else if (n <= root->data)
    {
        root->left = insert(root->left, n);
    }
    else
    {
        root->right = insert(root->right, n);
    }
    return root;
}

node *findMinNode(node *find)
{
    node *currNode = find;
    while (currNode && currNode->left != NULL)
    {
        currNode = currNode->left;
    }

    return currNode;
}

node *findMaxNode(node *find)
{
    node *currNode = find;
    while (currNode && currNode->right != NULL)
    {
        currNode = currNode->right;
    }
    return currNode;
}

int main()
{
    node *root = NULL;
    int t, p;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &p);
        root = insert(root, p);
    }

    printf("%d %d\n", findMaxNode(root)->data, findMinNode(root)->data);
}