#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ll long long

struct BST
{
    ll data;
    struct BST *left;
    struct BST *right;
};

int check[105][105] = {0}, p = 0;

typedef struct BST node;

node *createNode(ll n)
{
    node *newnode;
    newnode = malloc(sizeof(node));
    newnode->data = n;
    newnode->left = newnode->right = NULL;
    return newnode;
}

node *insert(node *root, ll n, int a, int b)
{
    if (root == NULL)
    {
        // printf("%d %d\n", a, b);
        check[a][b]++;
        if (a > p)
        {
            p = a;
        }

        root = createNode(n);
    }
    else if (n <= root->data)
    {
        a++;
        root->left = insert(root->left, n, a, b);
    }
    else
    {
        a++;
        b++;
        root->right = insert(root->right, n, a, b);
    }
    return root;
}

int main()
{
    ll t, inp;
    node *root = NULL;
    // memset(check, 0, sizeof(check));
    while (1)
    {
        scanf("%lld", &t);
        if (t == -1)
        {
            break;
        }
        else if (t == 1)
        {
            scanf("%lld", &inp);
            root = insert(root, inp, 0, 0);
        }
        else if (t == 2)
        {
            scanf("%lld", &inp);
            int cek = 0;
            if (inp > p)
            {
                printf("kedalaman maksimumnya %d oi\n", p);
            }
            else
            {
                for (int i = 0; i < 105; i++)
                {
                    // printf("%d \n", check[inp][i]);
                    if (check[inp][i] >= 2)
                    {
                        // printf("%d \n", check[inp][i]);
                        cek++;
                    }
                }
                printf("%d\n", cek);
            }
        }
    }
}