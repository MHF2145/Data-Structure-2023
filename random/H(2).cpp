#include <iostream>
#include <stdlib.h>

using namespace std;

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
            _size--;
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

    int getLevel(BSTNode *node, int data)
    {
        return __getLevel(node, data, 1);
    }

    int rk(BSTNode *node, int x, int &count)
    {
        if (node == NULL)
            return count;

        count = rk(node->left, x, count);
        count++;

        if (count == x)
        {
            cout << node->key << endl;
            return count;
        }

        return rk(node->right, x, count);

        // if (count <= x) {
        //     rk(node->left, x, count);
        //     count++;

        //     if (count == x) {
        //         cout << node->key << endl;
        //         return;
        //     }
        //     rk(node->right, x, count);
        // }
    }

    void ph(BSTNode *node, int x)
    {
        if (!node)
            return;

        if (x < node->key)
        {
            cout << "L";
            ph(node->left, x);
        }
        else if (x > node->key)
        {
            cout << "R";
            ph(node->right, x);
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

    int __getLevel(BSTNode *node, int data, int lvl)
    {
        if (node == NULL)
            return 0;

        if (node->key == data)
            return lvl;

        int increaseLevel = __getLevel(node->left, data, lvl + 1);
        if (increaseLevel != 0)
            return increaseLevel;

        increaseLevel = __getLevel(node->right, data, lvl + 1);
        return increaseLevel;
    }
};

int main()
{
    BST bst;
    bst.init();
    string command;
    int x;

    cin >> command;
    while (command != "STOP")
    {
        if (command == "IN")
        {
            cin >> x;
            if (!bst.find(x))
                bst.insert(x);
        }
        else if (command == "FD")
        {
            cin >> x;
            if (bst.find(x))
            {
                int level = bst.getLevel(bst._root, x);
                cout << "on level " << level << endl;
            }
            else
                cout << "no " << x << endl;
        }
        else if (command == "RK")
        {
            cin >> x;
            if (x == 0)
                cout << -1 << endl;
            else if (x <= (int)bst._size)
            {
                int count = 0;
                count = bst.rk(bst._root, x, count);
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (command == "PH")
        {
            cin >> x;
            if (bst.find(x))
            {
                bst.ph(bst._root, x);
                cout << "S" << endl;
            }
            else
                cout << "no " << x << endl;
        }

        cin >> command;
    }
    cout << "done" << endl;

    return 0;
}