#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> traBST, traAVL, bBST, bAVL, cBST, cAVL;

struct AVLNode
{
    int data;
    AVLNode *left, *right;
    int height, row, lvl;
};

struct AVL
{
private:
    AVLNode *_root;
    unsigned _size;

    AVLNode *_avl_createNode(int value, int r, int l)
    {
        AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->height = 1;
        newNode->row = r;
        newNode->lvl = l;
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

    AVLNode *_insert_AVL(AVLNode *node, int value, int row, int lvl)
    {

        if (node == NULL)
            return _avl_createNode(value, row, lvl);
        if (value < node->data)
            node->left = _insert_AVL(node->left, value, row - 1, lvl + 1);
        else if (value > node->data)
            node->right = _insert_AVL(node->right, value, row + 1, lvl + 1);

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

    void _inorder(AVLNode *root2)
    {
        if (root2)
        {
            _inorder(root2->left);
            string d = to_string(root2->data), e = to_string(root2->lvl), f = to_string(root2->row);
            string s_avl = d + "[lvl:" + e + " row:" + f + "]";
            cAVL.push_back(s_avl);
            _inorder(root2->right);
        }
    }
    void _preorder(AVLNode *root2)
    {
        if (root2)
        {
            string d = to_string(root2->data), e = to_string(root2->lvl), f = to_string(root2->row);
            string s_avl = d + "[lvl:" + e + " row:" + f + "]";
            traAVL.push_back(s_avl);
            _preorder(root2->left);
            _preorder(root2->right);
        }
    }
    void _postorder(AVLNode *root2)
    {
        if (root2)
        {
            _postorder(root2->left);
            _postorder(root2->right);
            string d = to_string(root2->data), e = to_string(root2->lvl), f = to_string(root2->row);
            string s_avl = d + "[lvl:" + e + " row:" + f + "]";
            bAVL.push_back(s_avl);
        }
    }

    void _benerin(AVLNode *root, int lvl)
    {
        if (root)
        {
            root->lvl = lvl;
            lvl++;
            _benerin(root->left, lvl);
            _benerin(root->right, lvl);
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

    AVLNode *getRoot()
    {
        return _root;
    }

    // AVLNode* getLeft(int x) {
    //     AVLNode *temp = _search(_root, x);
    //     return temp->left;
    // }
    // AVLNode* getRight(int x) {
    //     AVLNode *temp = _search(_root, x);
    //     return temp->right;
    // }

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

    void insert(int value)
    {
        if (!find(value))
        {
            _root = _insert_AVL(_root, value, 0, 1);
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

    void inorder()
    {
        this->_inorder(_root);
    }

    void preorder()
    {
        this->_preorder(_root);
    }
    void postorder()
    {
        this->_postorder(_root);
    }

    void benerin()
    {
        this->_benerin(_root, 1);
    }
};

struct BSTNode
{
    BSTNode *left, *right;
    int key, row, lvl;
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
            _root = __insert(_root, value, 0, 1);
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
        __postorder(_root, 1);
    }

private:
    // Utility Function
    BSTNode *__createNode(int value, int row, int lvl)
    {
        BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->row = row;
        newNode->lvl = lvl;
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

    BSTNode *__insert(BSTNode *root, int value, int row, int lvl)
    {
        if (root == NULL)
            return __createNode(value, row, lvl);

        if (value < root->key)
            root->left = __insert(root->left, value, row - 1, lvl + 1);
        else if (value > root->key)
            root->right = __insert(root->right, value, row + 1, lvl + 1);

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
            string a = to_string(root->key), b = to_string(root->lvl), c = to_string(root->row);
            string s_bst = a + "[lvl:" + b + " row:" + c + "]";
            cBST.push_back(s_bst);
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root, int lvl)
    {
        if (root)
        {
            lvl++;
            __postorder(root->left, lvl + 1);
            __postorder(root->right, lvl + 1);
            string a = to_string(root->key), b = to_string(root->lvl), c = to_string(root->row);
            string s_bst = a + "[lvl:" + b + " row:" + c + "]";
            bBST.push_back(s_bst);
        }
    }

    void __preorder(BSTNode *root)
    {
        if (root)
        {
            // printf("%d[lvl:%d row:%d] %d[lvl:%d row:%d]\n", root->key, root->lvl, root->row, root2->data, root2->lvl, root->row);
            string a = to_string(root->key), b = to_string(root->lvl), c = to_string(root->row);
            string s_bst = a + "[lvl:" + b + " row:" + c + "]";
            traBST.push_back(s_bst);
            __preorder(root->left);
            __preorder(root->right);
        }
    }
};

int main()
{
    AVL set;
    BST st;
    set.init();
    st.init();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        set.insert(x);
        st.insert(x);
    }
    set.benerin();

    cout << "preorder:" << endl;
    st.traversePreorder();
    set.preorder();
    for (int i = 0; i < n; i++)
    {
        cout << traBST[i] << " " << traAVL[i] << endl;
    }
    cout << endl;

    st.traverseInorder();
    set.inorder();
    cout << "inorder:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << cBST[i] << " " << cAVL[i] << endl;
    }
    cout << endl;

    st.traversePostorder();
    set.postorder();
    cout << "postorder:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << bBST[i] << " " << bAVL[i] << endl;
    }
    return 0;
}