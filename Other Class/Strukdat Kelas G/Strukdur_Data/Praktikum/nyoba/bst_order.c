#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};

typedef struct BST node;

node *createNode(char n)
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

void inorder(node *root, int lvl)
{
    lvl++;
    if (root == NULL)
    return;
    inorder(root->left, lvl);
    printf("%d [%d], ", root->data, lvl);
    inorder(root->right, lvl);
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

node *insert(node *root, char n)
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

int main()
{
    node *root = NULL;
    int choice, n;
    char ch;
    do
    {
        printf("\nPress 1 for insert:");
        printf("\nPress 2 for Preorder Transversal");
        printf("\nPress 3 for Inorder Transversal");
        printf("\nPress 4 for Postorder Transversal");
        printf("\nPress 5 for Search a data");
        printf("\nPlease enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter a number to be insert:");
            scanf("%d", &n);
            root = insert(root, n);
            break;

        case 2:
            printf("\nPreorder Tranversal:");
            preorder(root);
            printf("\n");
            break;

        case 3:
            printf("\nInorder Tranversal:");
            inorder(root, 0);
            printf("\n");
            break;

        case 4:
            printf("\nPostorder Tranversal:");
            postorder(root);
            printf("\n");
            break;

        case 5:
            printf("\nEnter a number to be search:");
            scanf("%d", &n);
            if (search(root, n) == 1)
            {
                printf("\nNumber found and search successful.");
            }
            else
            {
                printf("\nNumber not found and search unsuccessful.");
            }
            break;
            

        default:
            printf("\nWrong input.");
        }
        printf("\nDo you want to continue? (y/n)");
        ch = getche();
    } while (ch == 'y' || ch != 'n');
    return 0;
}