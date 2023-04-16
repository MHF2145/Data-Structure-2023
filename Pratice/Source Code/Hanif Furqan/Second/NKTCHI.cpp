#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct bstnode
{
    int data, jarak;
    bstnode *left, *right, *parent;
} Node;

typedef struct tree
{
    Node *root;
    unsigned int size;
} bst;

bst pohon;

void init(bst *bst)
{
    bst->root = NULL;
    bst->size = 0u;
}

Node *createNode(Node *parent, int data, int jarak)
{
    Node *newnode = new Node;
    newnode->data = data;
    newnode->jarak = jarak;
    newnode->parent = parent;
    newnode->left = newnode->right = NULL;
    return newnode;
}

Node *insert(Node *root, Node *parent, int data, int jarak)
{
    if (root == NULL)
    {
        return createNode(parent, data, jarak);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, root, data, jarak);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, root, data, jarak);
    }
    return root;
}

Node *search(Node *root, int data)
{
    while (root)
    {
        if (data < root->data)
        {
            root = root->left;
        }
        else if (data > root->data)
        {
            root = root->right;
        }
        else
            return root;
    }
    return root;
}

bool bst_find(bst *bst, int data)
{
    return search(bst->root, data) != NULL;
}

void InsertTree(bst *tree, int data, int jarak)
{
    if (bst_find(tree, data) == false)
    {
        tree->root = insert(tree->root, NULL, data, jarak);
        tree->size++;
    }
}

Node *findLCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data > n1 && root->data > n2)
        return findLCA(root->left, n1, n2);

    if (root->data < n1 && root->data < n2)
        return findLCA(root->right, n1, n2);

    return root;
}

int findDistance(Node *root, int k, int distance)
{
    if (root == NULL)
        return -1;

    if (root->data == k)
        return distance;

    int left = -1;
    if (root->left != NULL && root->data > k)
    {
        left = findDistance(root->left, k, distance + root->left->jarak);
    }

    if (left != -1)
        return left;

    int right = -1;
    if (root->right != NULL && root-> data < k)
    {
        right = findDistance(root->right, k, distance + root->right->jarak);
    }

    return right;
}

int findShortestPath(Node *root, int n1, int n2)
{
    Node *lca = findLCA(root, n1, n2);
    int d1 = findDistance(lca, n1, 0);
    int d2 = findDistance(lca, n2, 0);
    return d1 + d2;
}

void findLeaf(Node *root, vector<int> &leaf)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        leaf.push_back(root->data);
    }
    else
    {
        findLeaf(root->left, leaf);
        findLeaf(root->right, leaf);
    }
}

int main()
{
    vector<int> leaf;
    init(&pohon);
    int n, data, jarak;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            cin >> data;
            InsertTree(&pohon, data, 0);
        }
        else
        {
            cin >> data >> jarak;
            InsertTree(&pohon, data, jarak);
        }
    }
    findLeaf(pohon.root, leaf);
    int query;
    cin >> query;
    Node *temp;
    int shortestPath = 0;
    for (int i = 0; i < query; i++)
    {
        int angka;
        cin >> angka;
        temp = search(pohon.root, angka);
        int nilai_minimal = 1e9;
        for (int j = 0; j < leaf.size(); j++)
        {
            shortestPath = findShortestPath(pohon.root, leaf[j], temp->data);
            if (shortestPath < nilai_minimal)
            {
                nilai_minimal = shortestPath;
            }
        }
        cout << nilai_minimal;
        if (i != query - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
