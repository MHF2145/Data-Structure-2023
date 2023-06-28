#include <iostream>

using namespace std;

struct POHON_AVL
{
    int data;
    int height;
    POHON_AVL *left;
    POHON_AVL *right;
};

int getHeight(POHON_AVL *node);

POHON_AVL *rotateLeft(POHON_AVL *node);

POHON_AVL *rotateRight(POHON_AVL *node);

POHON_AVL *rotateLeftRight(POHON_AVL *node);

POHON_AVL *rotateRightLeft(POHON_AVL *node);

int getBalanceFactor(POHON_AVL *node);

POHON_AVL *insertNode(POHON_AVL *node, int data);

POHON_AVL *searchNode(POHON_AVL *node, int data);

POHON_AVL *getortuNode(POHON_AVL *node, POHON_AVL *root);

POHON_AVL *getsdrortuNode(POHON_AVL *node, POHON_AVL *root);

int getDifference(POHON_AVL *node, POHON_AVL *root);

int main()
{
    int n, t, r;
    cin >> n >> t;
    POHON_AVL *root = NULL;

    while (n--)
    {
        cin >> r;
        root = insertNode(root, r);
    }

    while (t--)
    {
        int x;
        cin >> x;
        POHON_AVL *node = searchNode(root, x);
        cout << getDifference(node, root) << endl;
    }

    return 0;
}

POHON_AVL *rotateLeft(POHON_AVL *node)
{
    POHON_AVL *newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    return newRoot;
}

POHON_AVL *rotateRight(POHON_AVL *node)
{
    POHON_AVL *newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    return newRoot;
}

POHON_AVL *rotateLeftRight(POHON_AVL *node)
{
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

POHON_AVL *rotateRightLeft(POHON_AVL *node)
{
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

int getHeight(POHON_AVL *node)
{
    if (node == NULL)
        return -1;
    else
        return node->height;
}

int getBalanceFactor(POHON_AVL *node)
{
    if (node == NULL)
        return 0;
    else
        return getHeight(node->left) - getHeight(node->right);
}

POHON_AVL *insertNode(POHON_AVL *node, int data)
{
    if (node == NULL)
    {
        POHON_AVL *newNode = new POHON_AVL;
        newNode->data = data;
        newNode->height = 0;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if (data < node->data)
    {
        node->left = insertNode(node->left, data);
        if (getBalanceFactor(node) == 2)
        {
            if (data < node->left->data)
                node = rotateRight(node);
            else
                node = rotateLeftRight(node);
        }
    }
    else if (data > node->data)
    {
        node->right = insertNode(node->right, data);
        if (getBalanceFactor(node) == -2)
        {
            if (data > node->right->data)
                node = rotateLeft(node);
            else
                node = rotateRightLeft(node);
        }
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    return node;
}

POHON_AVL *searchNode(POHON_AVL *node, int data)
{
    if (node == NULL || node->data == data)
        return node;
    else if (data < node->data)
        return searchNode(node->left, data);
    else
        return searchNode(node->right, data);
}

POHON_AVL *getortuNode(POHON_AVL *node, POHON_AVL *root)
{
    if (node == NULL || root == NULL || root == node)
        return NULL;
    else if (root->left == node || root->right == node)
        return root;
    else if (node->data < root->data)
        return getortuNode(node, root->left);
    else
        return getortuNode(node, root->right);
}

POHON_AVL *getsdrortuNode(POHON_AVL *node, POHON_AVL *root)
{
    POHON_AVL *ortuNode = getortuNode(node, root);
    POHON_AVL *grandortuNode = getortuNode(ortuNode, root);
    if (grandortuNode == NULL)
        return NULL;
    else if (grandortuNode->left == ortuNode)
        return grandortuNode->right;
    else if (grandortuNode->right == ortuNode)
        return grandortuNode->left;
}

int getDifference(POHON_AVL *node, POHON_AVL *root)
{
    POHON_AVL *ortuNode = getortuNode(node, root);
    POHON_AVL *sdrortuNode = getsdrortuNode(node, root);
    if (sdrortuNode == NULL)
        return ortuNode->data;
    else
        return abs(ortuNode->data - sdrortuNode->data);
}