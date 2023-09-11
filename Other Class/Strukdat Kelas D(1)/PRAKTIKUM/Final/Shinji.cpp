#include <bits/stdc++.h>
using namespace std;

int all = 0;

struct BSTNode
{
    BSTNode *left, *right;
    int key;
};

struct BST
{
    BSTNode *_root;
    int _size;

    void init()
    {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty()
    {
        return _root == NULL;
    }

    bool find(int value)
    {
        BSTNode *temp = search(_root, value);
        if (!temp)
            return false;

        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value)
    {
        if (!find(value))
        {
            _root = insertNode(_root, value);
            _size++;
        }
    }

private:
    BSTNode *createNode(int value)
    {
        BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    BSTNode *search(BSTNode *root, int value)
    {
        while (root != NULL)
        {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode *insertNode(BSTNode *root, int value)
    {
        if (root == NULL)
            return createNode(value);

        if (value < root->key)
            root->left = insertNode(root->left, value);
        else if (value > root->key)
            root->right = insertNode(root->right, value);

        return root;
    }
};

void rightnode(BSTNode *root, int level, vector<int> &arr)
{
    if (root)
    {
        int idx = level;
        arr[idx] = max(root->key, arr[idx]);
        all = max(all, level);
        rightnode(root->left, level + 1, arr);
        rightnode(root->right, level + 1, arr);
    }
}

int main()
{
    BST bst;
    bst.init();

    int count = 0;
    int a;
    while (cin >> a)
    {
        bst.insert(a);
        count++;
    }

    vector<int> arr(count, 0);
    rightnode(bst._root, 1, arr);

    for (int i = 1; i <= all; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
