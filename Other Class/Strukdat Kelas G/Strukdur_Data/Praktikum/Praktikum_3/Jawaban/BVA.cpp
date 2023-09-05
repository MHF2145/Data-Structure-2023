// ========[AVL & BS Tree]======== //
/*
    Dibuat dan ditulis oleh ABDUR ROCHMAN
    C++ conversion oleh BAYU LAKSANA
    28-03-2020
    Struktur Data 2020
    For C++
*/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

queue<string> pre_avl_p, in_avl_p, post_avl_p, pre_bst_p, in_bst_p, post_bst_p;

string pre_avl, in_avl, post_avl, pre_bst, in_bst, post_bst;

struct AVLNode
{
    int data;
    AVLNode *left, *right;
    int height;
};

struct AVL
{
private:
    AVLNode *_root;
    unsigned _size;

    AVLNode *_avl_createNode(int value)
    {
        AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->height = 1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    AVLNode *_search(AVLNode *root, int value)
    {
        while (root != NULL)
        {
            if (value < root->data)
                root = root->left;
            else if (value > root->data)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    int _getHeight(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int _max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    AVLNode *_rightRotate(AVLNode *pivotNode)
    {
        AVLNode *newParrent = pivotNode->left;
        pivotNode->left = newParrent->right;
        newParrent->right = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left),
                                 _getHeight(pivotNode->right)) +
                            1;
        newParrent->height = _max(_getHeight(newParrent->left),
                                  _getHeight(newParrent->right)) +
                             1;

        return newParrent;
    }

    AVLNode *_leftRotate(AVLNode *pivotNode)
    {
        AVLNode *newParrent = pivotNode->right;
        pivotNode->right = newParrent->left;
        newParrent->left = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left),
                                 _getHeight(pivotNode->right)) +
                            1;
        newParrent->height = _max(_getHeight(newParrent->left),
                                  _getHeight(newParrent->right)) +
                             1;

        return newParrent;
    }

    AVLNode *_leftCaseRotate(AVLNode *node)
    {
        return _rightRotate(node);
    }

    AVLNode *_rightCaseRotate(AVLNode *node)
    {
        return _leftRotate(node);
    }

    AVLNode *_leftRightCaseRotate(AVLNode *node)
    {
        node->left = _leftRotate(node->left);
        return _rightRotate(node);
    }

    AVLNode *_rightLeftCaseRotate(AVLNode *node)
    {
        node->right = _rightRotate(node->right);
        return _leftRotate(node);
    }

    int _getBalanceFactor(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return _getHeight(node->left) - _getHeight(node->right);
    }

    AVLNode *_insert_AVL(AVLNode *node, int value)
    {

        if (node == NULL)
            return _avl_createNode(value);
        if (value < node->data)
            node->left = _insert_AVL(node->left, value);
        else if (value > node->data)
            node->right = _insert_AVL(node->right, value);

        node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

        int balanceFactor = _getBalanceFactor(node);

        if (balanceFactor > 1 && value < node->left->data)
            return _leftCaseRotate(node);
        if (balanceFactor > 1 && value > node->left->data)
            return _leftRightCaseRotate(node);
        if (balanceFactor < -1 && value > node->right->data)
            return _rightCaseRotate(node);
        if (balanceFactor < -1 && value < node->right->data)
            return _rightLeftCaseRotate(node);

        return node;
    }

    AVLNode *_findMinNode(AVLNode *node)
    {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }

    AVLNode *_remove_AVL(AVLNode *node, int value)
    {
        if (node == NULL)
            return node;
        if (value > node->data)
            node->right = _remove_AVL(node->right, value);
        else if (value < node->data)
            node->left = _remove_AVL(node->left, value);
        else
        {
            AVLNode *temp;
            if ((node->left == NULL) || (node->right == NULL))
            {
                temp = NULL;
                if (node->left == NULL)
                    temp = node->right;
                else if (node->right == NULL)
                    temp = node->left;

                if (temp == NULL)
                {
                    temp = node;
                    node = NULL;
                }
                else
                    *node = *temp;

                free(temp);
            }
            else
            {
                temp = _findMinNode(node->right);
                node->data = temp->data;
                node->right = _remove_AVL(node->right, temp->data);
            }
        }

        if (node == NULL)
            return node;

        node->height = _max(_getHeight(node->left), _getHeight(node->right)) + 1;

        int balanceFactor = _getBalanceFactor(node);

        if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
            return _leftCaseRotate(node);

        if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
            return _leftRightCaseRotate(node);

        if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
            return _rightCaseRotate(node);

        if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
            return _rightLeftCaseRotate(node);

        return node;
    }

    void _inorder(AVLNode *node, int a, int b)
    {
        a++;
        if (node)
        {
            _inorder(node->left, a, b - 1);
            string c = to_string(node->data), d = to_string(a), e = to_string(b);
            in_avl = c + "[lvl:" + d + " row:" + e + "]";
            in_avl_p.push(in_avl);
            // printf("%d ", node->data, a, b);
            _inorder(node->right, a, b + 1);
        }
    }

    void _preorder(AVLNode *node, int a, int b)
    {
        a++;
        if (node)
        {
            string c = to_string(node->data), d = to_string(a), e = to_string(b);
            pre_avl = c + "[lvl:" + d + " row:" + e + "]";
            pre_avl_p.push(pre_avl);
            // printf("%d ", node->data);
            _preorder(node->left, a, b - 1);
            _preorder(node->right, a, b + 1);
        }
    }

    void _postorder(AVLNode *node, int a, int b)
    {
        a++;
        if (node)
        {
            _postorder(node->left, a, b - 1);
            _postorder(node->right, a, b + 1);
            // printf("%d ", node->data);
            string c = to_string(node->data), d = to_string(a), e = to_string(b);
            post_avl = c + "[lvl:" + d + " row:" + e + "]";
            post_avl_p.push(post_avl);
        }
    }

public:
    void init()
    {
        _root = NULL;
        _size = 0U;
    }

    bool isEmpty()
    {
        return _root == NULL;
    }

    bool find(int value)
    {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;

        if (temp->data == value)
            return true;
        else
            return false;
    }

    void avl_insert(int value)
    {
        if (!find(value))
        {
            _root = _insert_AVL(_root, value);
            _size++;
        }
    }

    void remove(int value)
    {
        if (find(value))
        {
            _root = _remove_AVL(_root, value);
            _size--;
        }
    }

    void inorder(int a, int b)
    {
        this->_inorder(_root, a, b);
    }

    void preorder(int a, int b)
    {
        this->_preorder(_root, a, b);
    }

    void postorder(int a, int b)
    {
        this->_postorder(_root, a, b);
    }
};

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

    void bst_insert(int value)
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

    void traverseInorder(int a, int b)
    {
        __inorder(_root, a, b);
    }

    void traversePreorder(int a, int b)
    {
        __preorder(_root, a, b);
    }

    void traversePostorder(int a, int b)
    {
        __postorder(_root, a, b);
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

    void __inorder(BSTNode *root, int a, int b)
    {
        a++;
        if (root)
        {
            __inorder(root->left, a, b - 1);
            string c = to_string(root->key), d = to_string(a), e = to_string(b);
            in_bst = c + "[lvl:" + d + " row:" + e + "]";
            in_bst_p.push(in_bst);
            // printf("%d ", root->key);
            __inorder(root->right, a, b + 1);
        }
    }

    // "0" -> ascii

    void __postorder(BSTNode *root, int a, int b)
    {
        a++;
        if (root)
        {
            __postorder(root->left, a, b - 1);
            __postorder(root->right, a, b + 1);
            string c = to_string(root->key), d = to_string(a), e = to_string(b);
            post_bst = c + "[lvl:" + d + " row:" + e + "]";
            post_bst_p.push(post_bst);
            // printf("%d ", root->key);
        }
    }

    void __preorder(BSTNode *root, int a, int b)
    {
        a++;
        if (root)
        {
            string c = to_string(root->key), d = to_string(a), e = to_string(b);
            pre_bst = c + "[lvl:" + d + " row:" + e + "]";
            pre_bst_p.push(pre_bst);
            // printf("%d ", root->key);
            __preorder(root->left, a, b - 1);
            __preorder(root->right, a, b + 1);
        }
    }
};

int main(int argc, char const *argv[])
{
    BST set_BST;
    set_BST.init();
    AVL set_AVL;
    set_AVL.init();

    int a, b;

    scanf("%d", &a);
    while (a--)
    {
        scanf("%d", &b);
        set_BST.bst_insert(b);
        set_AVL.avl_insert(b);
    }

    set_AVL.inorder(0, 0);
    // puts("\n");
    set_AVL.preorder(0, 0);
    // puts("\n");
    set_AVL.postorder(0, 0);
    // puts("\n");
    set_BST.traverseInorder(0, 0);
    // puts("\n");
    set_BST.traversePreorder(0, 0);
    // puts("\n");
    set_BST.traversePostorder(0, 0);
    // puts("\n");

    printf("preorder:\n");
    while (!pre_avl_p.empty() && !pre_bst_p.empty())
    {
        cout << pre_bst_p.front() << " " << pre_avl_p.front() << endl;
        pre_avl_p.pop();
        pre_bst_p.pop();
    }
    puts("\n");

    printf("inorder:\n");
    while (!in_avl_p.empty() && !in_bst_p.empty())
    {
        cout << in_bst_p.front() << " " << in_avl_p.front() << endl;
        in_avl_p.pop();
        in_bst_p.pop();
    }
    puts("\n");

    printf("postorder:\n");
    while (!post_avl_p.empty() && !post_bst_p.empty())
    {
        cout << post_bst_p.front() << " " << post_avl_p.front() << endl;
        post_avl_p.pop();
        post_bst_p.pop();
    }
    puts("\n");

    return 0;
}