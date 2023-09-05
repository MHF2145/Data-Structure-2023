#include <iostream>
#include <map>
#include <math.h>
using namespace std;

typedef struct bstnode_t
{
    int key;
    struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

map <int,int> arr;

BSTNode *__bst__createNode(int value, int level)
{   
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    arr[value] = level;
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, int value, int level)
{
    if (root == NULL)
        return __bst__createNode(value, level);

    if (value < root->key)
    {
        root->left = __bst__insert(root->left, value, level + 1);
    }

    else if (value > root->key)
    {
        root->right = __bst__insert(root->right, value, level + 1);
    }

    return root;
}

BSTNode *__bst__search(BSTNode *root, int value)
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

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst)
{
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value)
{
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value, int level)
{
    if (!bst_find(bst, value))
    {
        bst->_root = __bst__insert(bst->_root, value, level);
        bst->_size++;
    }
}

int main()
{
    BST set;
    bst_init(&set);
    int t;
    cin >> t;
    while(t--)
    {
        int a;
        cin >> a;
        bst_insert(&set, a, 0);
    }
    int n;
    cin >> n;
    while (n--)
    {
        int b,c;
        cin >> b >> c;
        int hasil = abs(arr[b] - arr[c]);
        if(hasil > 0)cout << hasil << endl;
        else cout << "Galaxy berada pada tingkat yang sama" << endl;
    }
    
    return 0;
}