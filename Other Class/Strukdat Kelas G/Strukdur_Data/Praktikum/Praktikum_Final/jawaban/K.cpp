#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Node structure */

bool check = false;

struct BSTNode
{
    BSTNode *left, *right, *parent;
    int key;
};

/* uniqueBST */

struct BST
{
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
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
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;

        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(BST *bst, int value)
    {
        if (!find(value))
        {
            bst->_root = __insert(bst->_root, bst->_root, value);
            bst->_size++;
        }
    }

    void remove(int value)
    {
        if (find(value))
        {
            _root = __remove(_root, value);
            _size++;
        }
    }

    void traverseInorder()
    {
        __inorder(_root);
    }

    void traversePreorder()
    {
        __preorder(_root);
    }

    void traversePostorder()
    {
        __postorder(_root);
    }

private:
    // Utility Function
    BSTNode *__createNode(BSTNode *root, int value)
    {
        BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        newNode->parent = root;
        return newNode;
    }

    BSTNode *__search(BSTNode *root, int value)
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

    BSTNode *__insert(BSTNode *root, BSTNode *node, int value)
    {
        if (node == NULL)
            return __createNode(root, value);
        if (value < node->key)
            node->left = __insert(node, node->left, value);

        else if (value > node->key)
            node->right = __insert(node, node->right, value);

        return node;
    }

    BSTNode *__findMinNode(BSTNode *node)
    {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;

        return currNode;
    }

    BSTNode *__remove(BSTNode *root, int value)
    {
        if (root == NULL)
            return NULL;

        if (value > root->key)
            root->right = __remove(root->right, value);
        else if (value < root->key)
            root->left = __remove(root->left, value);
        else
        {

            if (root->left == NULL)
            {
                BSTNode *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL)
            {
                BSTNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);
            root->key = temp->key;
            root->right = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root)
    {
        if (root)
        {
            __inorder(root->left);
            printf("%d ", root->key);
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root)
    {
        if (root)
        {
            __postorder(root->left);
            __postorder(root->right);
            printf("%d ", root->key);
        }
    }

    void __preorder(BSTNode *root)
    {
        if (root)
        {
            printf("%d ", root->key);
            __preorder(root->left);
            __preorder(root->right);
        }
    }
};

void finding_nemo(BSTNode *root, int dicari)
{
    BSTNode *temp = root;
    int jumlah;
    if (temp)
    {
        if (temp->parent)
        {
            if (temp->left)
            {
                jumlah = temp->key + temp->parent->key + temp->left->key;
                if ((jumlah == dicari))
                {
                    check = true;
                    return;
                }
            }
            if (temp->right)
            {
                jumlah = temp->key + temp->parent->key + temp->right->key;
                if ((jumlah == dicari))
                {
                    check = true;
                    return;
                }
            }
        }
        if (temp->left && temp->right)
        {
            jumlah = temp->key + temp->left->key + temp->right->key;
            if ((jumlah == dicari))
            {
                check = true;
                return;
            }
        }
        finding_nemo(temp->left, dicari);
        finding_nemo(temp->right, dicari);
    }
}

int main()
{
    BST set;
    set.init();

    int test, dicari, inp;
    cin >> test;

    while (test--)
    {
        cin >> inp;
        set.insert(&set, inp);
    }

    cin >> dicari;

    finding_nemo(set._root, dicari);

    if (!check)
    {
        cout << dicari << " Tidak ada kombinasi yang tepat! Bikin ulang." << endl;
    }
    else
    {
        cout << dicari << " Selamat! Kalian menemukan harta karunnya" << endl;
    }
}
