#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    int height;
};

Node *newNode(int val);

int height(Node *node);

int balanceFactor(Node *node);

void updateHeight(Node *node);

Node *rotateRight(Node *y);

Node *rotateLeft(Node *x);

Node *insert(Node *node, int val);

void sumVerticals(Node *node, int col, int colSums[]);

int main()
{
    Node *root = NULL;
    string input;
    while (cin >> input)
    {
        if (input == "MASUKKAN")
        {
            int x;
            cin >> x;
            root = insert(root, x);
        }
        else if (input == "HITUNG")
        {
            int colSums[2001] = {0};
            sumVerticals(root, 1000, colSums);
            int total = 0;
            for (int i = 0; i < 2001; i++)
            {
                total += colSums[i] * colSums[i];
            }
            cout << total << endl;
        }
    }
    return 0;
}

Node *newNode(int val)
{
    Node *node = new Node();
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int height(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int balanceFactor(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

void updateHeight(Node *node)
{
    node->height = max(height(node->left), height(node->right)) + 1;
}

Node *rotateRight(Node *y)
{
    Node *x = y->left;
    Node *t2 = x->right;
    x->right = y;
    y->left = t2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    Node *t2 = y->left;
    y->left = x;
    x->right = t2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

Node *insert(Node *node, int val)
{

    if (node == NULL)
    {
        return newNode(val);
    }
    if (val < node->val)
    {
        node->left = insert(node->left, val);
    }
    else
    {
        node->right = insert(node->right, val);
    }
    updateHeight(node);
    int bf = balanceFactor(node);
    if (bf > 1 && val < node->left->val)
    {
        return rotateRight(node);
    }
    if (bf < -1 && val > node->right->val)
    {
        return rotateLeft(node);
    }
    if (bf > 1 && val > node->left->val)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (bf < -1 && val < node->right->val)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

void sumVerticals(Node *node, int col, int colSums[])
{
    if (node == NULL)
    {
        return;
    }
    colSums[col] += node->val;
    sumVerticals(node->left, col - 1, colSums);
    sumVerticals(node->right, col + 1, colSums);
}