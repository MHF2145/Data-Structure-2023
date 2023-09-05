#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
/* Node structure */

struct BSTNode
{
    BSTNode *left, *right;
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

    void insert(int value)
    {
        if (!find(value))
        {
            _root = __insert(_root, value);
            _size++;
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

    void traverseInorder(int *cari)
    {
        __inorder(_root, cari);
    }

    void traversePreorder()
    {
        __preorder(_root);
    }

    void traversePostorder()
    {
        __postorder(_root);
    }

    void P_H(int cari)
    {
        queue<char> jalan;
        BSTNode *temp = __PHsearch(_root, &jalan, cari);
        if (!temp)
        {
            cout << "no " << cari << endl;
            return;
        }

        if (temp->key == cari)
        {
            while (jalan.size() > 0)
            {
                cout << jalan.front();
                jalan.pop();
            }
            cout << "S" << endl;
        }
        else
        {
            cout << "no " << cari << endl;
            return;
        }
    }

    void F_D(int cari)
    {
        int height = 0;
        BSTNode *temp = __search_height(_root, cari, &height);
        if (!temp)
        {
            cout << "no " << cari << endl;
            return;
        }

        if (temp->key == cari)
        {
            cout << "on level " << height + 1 << endl;
            return;
        }
        else
        {
            cout << "no " << cari << endl;
            return;
        }
    }

private:
    // Utility Function
    BSTNode *__createNode(int value)
    {
        BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
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

    BSTNode *__insert(BSTNode *root, int value)
    {
        if (root == NULL)
            return __createNode(value);

        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);

        return root;
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

    void __inorder(BSTNode *root, int *cari)
    {
        if (root)
        {
            __inorder(root->left, cari);
            if (*cari == 1)
            {
                cout << root->key << endl;
            }
            *cari -= 1;
            __inorder(root->right, cari);
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

    BSTNode *__PHsearch(BSTNode *root, queue<char> *jalan, int value)
    {
        while (root != NULL)
        {
            if (value < root->key)
            {
                jalan->push('L');
                root = root->left;
            }
            else if (value > root->key)
            {
                jalan->push('R');
                root = root->right;
            }
            else
                return root;
        }
        return root;
    }

    BSTNode *__search_height(BSTNode *root, int value, int *height)
    {
        while (root != NULL)
        {
            if (value < root->key)
            {
                root = root->left;
                *height += 1;
            }
            else if (value > root->key)
            {
                root = root->right;
                *height += 1;
            }
            else
                return root;
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
    BST set;
    string test;
    int inp;
    set.init();

    while (cin >> test)
    {
        if (test == "STOP")
        {
            cout << "done" << endl;
            break;
        }
        else if (test == "IN")
        {
            cin >> inp;
            set.insert(inp);
        }
        else if (test == "PH")
        {
            cin >> inp;
            set.P_H(inp);
        }
        else if (test == "RK")
        {
            cin >> inp;
            if (set._size < inp)
            {
                cout << "-1" << endl;
                continue;
            }
            set.traverseInorder(&inp);
        }
        else if (test == "FD")
        {
            inp;
            cin >> inp;
            set.F_D(inp);
        }
    }
    return 0;
}