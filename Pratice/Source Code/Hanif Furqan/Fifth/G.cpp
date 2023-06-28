#include <bits/stdc++.h>


typedef struct node_t
{
    int value;
    struct node_t *left, *right;
} Node;

typedef struct bintree_t
{
    Node *_root;
    unsigned int _size;
} bintree;

Node *createNode(int value);
Node *insertNode(Node *root, int value);
Node *searchNode(Node *root, int value);
Node *findMinNode(Node *node);
Node *removeNode(Node *root, int value);

void printNodesWithOneChild(Node *node, bool *found);
void bintreeInit(bintree *bintree);
bool bintreeIsEmpty(bintree *bintree);
bool bintreeFind(bintree *bintree, int value);
void bintreeInsert(bintree *bintree, int value);
void bintreeRemove(bintree *bintree, int value);
void printNodesWithOneChild(bintree *bintree);

int main()
{
    bintree set;
    bintreeInit(&set);

    int LN, XC;
    std::cin >> LN;

    for (int i = 0; i < LN; i++)
    {
        int order;
        std::cin >> order;
        if (order == 15)
        {
            std::cin >> XC;
            bintreeInsert(&set, XC);
        }
        else if (order == 4)
        {
            std::cin >> XC;
            bintreeRemove(&set, XC);
        }
        else if (order == 89)
        {
            printNodesWithOneChild(&set);
        }
    }
    return 0;
}

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->value)
        root->left = insertNode(root->left, value);
    else if (value > root->value)
        root->right = insertNode(root->right, value);

    return root;
}


Node *searchNode(Node *root, int value)
{
    while (root != NULL)
    {
        if (value < root->value)
            root = root->left;
        else if (value > root->value)
            root = root->right;
        else
            return root;
    }
    return root;
}

Node *findMinNode(Node *node)
{
    Node *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}

Node *removeNode(Node *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value > root->value)
        root->right = removeNode(root->right, value);
    else if (value < root->value)
        root->left = removeNode(root->left, value);
    else
    {

        if (root->left == NULL)
        {
            Node *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL)
        {
            Node *leftChild = root->left;
            free(root);
            return leftChild;
        }

        Node *temp = findMinNode(root->right);
        root->value = temp->value;
        root->right = removeNode(root->right, temp->value);
    }
    return root;
}

void printNodesWithOneChild(Node *node, bool *found)
{
    if (node == NULL)
        return;

    printNodesWithOneChild(node->left, found);

    if ((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL))
    {
        printf("%d ", node->value);
        *found = true;
    }

    printNodesWithOneChild(node->right, found);
}

void bintreeInit(bintree *bintree)
{
    bintree->_root = NULL;
    bintree->_size = 0;
}

bool bintreeIsEmpty(bintree *bintree)
{
    return bintree->_root == NULL;
}

bool bintreeFind(bintree *bintree, int value)
{
    Node *temp = searchNode(bintree->_root, value);
    if (temp == NULL)
        return false;

    if (temp->value == value)
        return true;
    else
        return false;
}

void bintreeInsert(bintree *bintree, int value)
{
    if (!bintreeFind(bintree, value))
    {
        bintree->_root = insertNode(bintree->_root, value);
        bintree->_size++;
    }
}

void bintreeRemove(bintree *bintree, int value)
{
    if (bintreeFind(bintree, value))
    {
        bintree->_root = removeNode(bintree->_root, value);
        bintree->_size--;
    }
}

void printNodesWithOneChild(bintree *bintree)
{
    bool found = false;
    printNodesWithOneChild(bintree->_root, &found);
    if (!found)
    {
        printf("Use whatever means you must to control our population. Just do it.\n");
    }
}