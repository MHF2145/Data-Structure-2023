#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#define ull unsigned long long
using namespace std;

typedef struct AVLNode_t
{
    int data;
    struct AVLNode_t *left, *right;
    int height;
} AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
} AVL;

void avl_init(AVL *avl)
{
    avl->_root = NULL;
    avl->_size = 0u;
}

int _getHeight(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int _getBalanceFactor(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return _getHeight(node->left) - _getHeight(node->right);
}

AVLNode *_rightRotate(AVLNode *pivotNode)
{

    AVLNode *newParrent = pivotNode->left;
    pivotNode->left = newParrent->right;
    newParrent->right = pivotNode;

    pivotNode->height = max(_getHeight(pivotNode->left),
                            _getHeight(pivotNode->right)) +
                        1;
    newParrent->height = max(_getHeight(newParrent->left),
                             _getHeight(newParrent->right)) +
                         1;

    return newParrent;
}

AVLNode *_leftCaseRotate(AVLNode *node)
{
    return _rightRotate(node);
}

AVLNode *_leftRotate(AVLNode *pivotNode)
{

    AVLNode *newParrent = pivotNode->right;
    pivotNode->right = newParrent->left;
    newParrent->left = pivotNode;

    pivotNode->height = max(_getHeight(pivotNode->left),
                            _getHeight(pivotNode->right)) +
                        1;
    newParrent->height = max(_getHeight(newParrent->left),
                             _getHeight(newParrent->right)) +
                         1;

    return newParrent;
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

AVLNode *_insert_AVL(AVL *avl, AVLNode *node, int value)
{

    if (node == NULL)
        return _avl_createNode(value);
    if (value < node->data)
        node->left = _insert_AVL(avl, node->left, value);
    else if (value > node->data)
        node->right = _insert_AVL(avl, node->right, value);

    node->height = 1 + max(_getHeight(node->left), _getHeight(node->right));

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

bool avl_find(AVL *avl, int value)
{
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;

    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl, int value)
{
    if (!avl_find(avl, value))
    {
        avl->_root = _insert_AVL(avl, avl->_root, value);
        avl->_size++;
    }
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

    node->height = max(_getHeight(node->left), _getHeight(node->right)) + 1;

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

void avl_remove(AVL *avl, int value)
{
    if (avl_find(avl, value))
    {
        avl->_root = _remove_AVL(avl->_root, value);
        avl->_size--;
    }
}

void dfs(AVLNode *root, int col, map<int, vector<ull>> &columnMap) //masukin avl ke indeks map
{
    if (root == nullptr)
    {
        return;
    }

    columnMap[col].push_back(root->data);

    dfs(root->left, col - 1, columnMap);
    dfs(root->right, col + 1, columnMap);
}

void VerticalPrint(AVLNode *root)	///Vertical print yang akan mengeluarkan nilai tiap indeks
{
    ull jumlah = 0, final = 0;
    if (root == nullptr) //kosong
    {
        cout << 0;
        return;
    }

    std::map<int, std::vector<ull>> columnMap; //deklarasi map memakai vektor agar salah satu kolom bisa nyimpen lebih dari satu
    dfs(root, 0, columnMap); //nyimpen avl ke map

    for (const auto &column : columnMap)//iterasi map 
    {
        // std::cout << "Kolom " << column.first << ":\n";
        for (int data : column.second)  //akses kolom vektor kedua
        {
            jumlah += data;
        }
        final += jumlah * jumlah;
        jumlah = 0;
    }
    cout << final;
}

int main()
{
    AVL Tree;
    avl_init(&Tree);
    int kunci;
    
    string kartu;
    while (cin >> kartu)
    {
        if (kartu == "Insert")
        {
            cin >> kunci;
            avl_insert(&Tree, kunci);
        }
        
        else
        {
            VerticalPrint(Tree._root); 
            cout << endl;
        }
    }
    return 0;
}

