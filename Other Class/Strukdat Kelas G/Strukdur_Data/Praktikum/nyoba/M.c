#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};

typedef struct BST node;

int paling_dalam = -999, dicari = -999;

node *createNode(int n)
{
    node *newnode;
    newnode = malloc(sizeof(node));
    newnode->data = n;
    newnode->left = newnode->right = NULL;
    return newnode;
}

int search(node *root, int n, int a)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (n == root->data)
    {
        if (dicari < a)
        {
            dicari = a;
        }
        return 1;
    }
    else if (n <= root->data)
    {
        a++;
        return search(root->left, n, a);
    }
    else
    {
        a++;
        return search(root->right, n, a);
    }
}

node *insert(node *root, int n, int a)
{
    if (root == NULL)
    {
        if (paling_dalam < a)
        {
            paling_dalam = a;
        }
        
        root = createNode(n);
    }
    else if (n <= root->data)
    {
        a++;
        root->left = insert(root->left, n, a);
    }
    else
    {
        a++;
        root->right = insert(root->right, n, a);
    }
    return root;
}

int main()
{
    node *root = NULL;
    int inp, n, cari;
    scanf("%d", &inp);
    while (inp--)
    {
        scanf("%d", &n);
        root = insert(root, n, 0);
    }
    scanf("%d", &cari);
    search(root, cari, 0);
    int b = paling_dalam - dicari;
    int c =b * b * 10000;
    printf("%d\n", c);
}