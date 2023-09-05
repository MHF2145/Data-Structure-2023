#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ll long long

int modal, terdekat;

struct BST
{
    int harga, data;
    struct BST *left;
    struct BST *right;
    struct BST *parent;
};

typedef struct BST node;

node *createnode(int n, int harga)
{
    node *newnode;
    newnode = malloc(sizeof(node));
    newnode->data = n;
    newnode->harga = harga;
    newnode->left = newnode->right = NULL;
    newnode->parent = NULL;
    return newnode;
}

void inorder(node *root, int lvl)
{
    lvl++;
    if (root == NULL)
        return;
    inorder(root->left, lvl);
    // printf("%d [%d] (%d) {%d}\n", root->data, lvl, root->harga, root->parent);
    inorder(root->right, lvl);
}

node *insert(node *root, int n, int harga)
{
    if (root == NULL)
    {
        root = createnode(n, harga);
    }
    else if (n <= root->data)
    {
        node *lchild = insert(root->left, n, harga);
        root->left = lchild;
        lchild->parent = root;
    }
    else
    {
        node *rchild = insert(root->right, n, harga);
        root->right = rchild;
        rchild->parent = root;
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

node *search(node *root, int n)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (n == root->data)
    {
        return root;
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

node *cari_jalan_terdekat_baby(node *root, node *start, int n)
{
    if (root->left == NULL && root->right == NULL)
    {
        if (terdekat > n)
        {
            terdekat = n;
        }
    }
    else if (root != NULL && n < terdekat)
    {
        if (root->left != NULL && root->left != start)
        {
            cari_jalan_terdekat_baby(root->left, root, n + root->left->harga);
        }
        if (root->right != NULL && root->right != start)
        {
            cari_jalan_terdekat_baby(root->right, root, n + root->right->harga);
        }
        if (root->parent != NULL && root->parent != start)
        {
            cari_jalan_terdekat_baby(root->parent, root, n + root->harga);
        }
    }
}

bool cari_jalan(node *root, int n)
{
    node *asal = search(root, n);
    if (asal == NULL)
    {
        printf("bruhh -_-\n");
        return false;
    }
    else if (asal->data == n)
    {
        terdekat = 999999;
        cari_jalan_terdekat_baby(asal, NULL, 0);
        if (modal - terdekat >= 0)
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

int main()
{
    node *root = NULL;
    int inp, n, harga;

    scanf("%d", &modal);
    scanf("%d %d", &inp, &n);
    // printf("%d %d\n", inp, n);
    root = insert(root, n, 0);
    inp--;
    for (int i = 0; i < inp; i++)
    {
        // printf("%d\n", inp);
        scanf("%d %d", &n, &harga);
        root = insert(root, n, harga);
    }
    // inorder(root, 0);
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d", &n);
        cari_jalan(root, n);
    }

    return 0;
}