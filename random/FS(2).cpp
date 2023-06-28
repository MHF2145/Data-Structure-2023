#include <iostream>
#include <queue>
using namespace std;

typedef struct bstnode
{
    int data;
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

Node *createNode(Node *parent, int data)
{
    Node *newnode = new Node;
    newnode->data = data;
    newnode->parent = parent;
    newnode->left = newnode->right = NULL;
    return newnode;
}

Node *insert(Node *root, Node *parent, int data)
{
    if (root == NULL)
    {
        return createNode(parent, data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, root, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, root, data);
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

void InsertTree(bst *tree, int data)
{
    if (bst_find(tree, data) == false)
    {
        tree->root = insert(tree->root, NULL, data);
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

int CariLevel(Node *root, int data, int &level)
{
    if (root)
    {
        if (root->data == data)
        {
            return level;
        }

        else if (root->data < data)
        {
            level++;
            return CariLevel(root->right, data, level);
        }
        else if (root->data > data)
        {
            level++;
            return CariLevel(root->left, data, level);
        }
    }
}

int main()
{
    queue<int> Ancestor;
    init(&pohon);
    int n, data;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        cin >> data;
        InsertTree(&pohon, data);
    }
    int query;
    cin >> query;
    Node *temp;
    for (int i = 0; i < query; i++)
    {
        int a, b;
        cin >> a;
        int level = 0;
        while (a--)
        {
            cin >> b;
            Ancestor.push(b);
        }
        while (!Ancestor.empty() && Ancestor.size() != 1)
        {
            int front, next;
            front = Ancestor.front();
            Ancestor.pop();
            next = Ancestor.front();
            Ancestor.pop();
            temp = findLCA(pohon.root, front, next);
            Ancestor.push(temp->data);
        }
        if (Ancestor.size() == 1)
        {
            CariLevel(pohon.root, Ancestor.front(), level);
            cout << Ancestor.front() << " " << level << endl;
            Ancestor.pop();
        }
    }
    cout << endl;
    return 0;
}
