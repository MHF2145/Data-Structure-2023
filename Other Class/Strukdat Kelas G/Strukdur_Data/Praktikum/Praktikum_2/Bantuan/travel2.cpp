#include <iostream>
#include <climits>
using namespace std;

int a = INT_MAX;
class BstNode
{
public:
    int key, hargaTol;
    BstNode *left, *right, *parent;

    BstNode(int data, int harga)
    {
        key = data;
        hargaTol = harga;
        left = right = parent = NULL;
    }
};

class Bst
{
public:
    BstNode *root;
    Bst()
    {
        root = NULL;
    }

    void insert(int data, int harga)
    {
        BstNode *node = new BstNode(data, harga);
        if (!root)
        {
            root = node;
            return;
        }

        BstNode *current = root;
        for (;;)
        {
            if (data < current->key)
            {
                if (!current->left)
                {
                    current->left = node;
                    node->parent = current;
                    break;
                }
                current = current->left;
            }
            else
            {
                if (!current->right)
                {
                    current->right = node;
                    node->parent = current;
                    break;
                }
                current = current->right;
            }
        }
        return;
    }

    BstNode *__search(BstNode *root, int value)
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
        return NULL;
    }

    void findLeaf(BstNode *root, int lev, int *minUang)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            if (lev < (*minUang))
                *minUang = lev;
            return;
        }

        int red = INT_MAX, blue = INT_MAX, green = INT_MAX;
        if (root->right != NULL)
            red = root->right->hargaTol;
        if (root->left != NULL)
            blue = root->left->hargaTol;

        findLeaf(root->left, lev + blue, minUang);
        findLeaf(root->right, lev + red, minUang);
        // if(root->parent != NULL && a == 0) findLeaf(root->parent, lev + green, minUang);
        // a++;
    }

    int findTroughParent(BstNode *root, BstNode *temp, int *minUang)
    {
        if (root == NULL)
            return INT_MAX;
        if (root == temp)
        {
            findLeaf(root, 0, minUang);
            return 0;
        }

        int red = INT_MAX, blue = INT_MAX;
        if (root->right != NULL)
            red = root->right->hargaTol;
        if (root->left != NULL)
            blue = root->left->hargaTol;

        // ini buat nyari ke kiri
        int leftDist = findTroughParent(root->left, temp, minUang);
        // ini buat nyari ke kanan
        int rightDist = findTroughParent(root->right, temp, minUang);

        if (leftDist != INT_MAX)
        {
            findLeaf(root->right, leftDist + red + temp->hargaTol, minUang);
            return leftDist + temp->hargaTol;
        }

        if (rightDist != INT_MAX)
        {
            findLeaf(root->left, rightDist + blue + temp->hargaTol, minUang);
            return rightDist + temp->hargaTol;
        }
        return INT_MAX;
    }

    int minMoney(BstNode *root, int value)
    {
        int minUang = INT_MAX;
        BstNode *temp = __search(root, value);
        if (temp == NULL)
            return -1;
        findTroughParent(root, temp, &minUang);
        // findLeaf(root, 0, &minUang);
        return minUang;
    }

    void preorder(BstNode *root)
    {
        if (root)
        {
            cout << " key : " << root->key;
            if (root->left != NULL)
                cout << " left : " << root->left->key;
            if (root->right != NULL)
                cout << " right : " << root->right->key;
            cout << " harga : " << root->hargaTol;
            if (root->parent != NULL)
                cout << " parent : " << root->parent->key;
            cout << endl;

            preorder(root->left);
            preorder(root->right);
        }
    }
};

int main()
{
    Bst bst;
    int uang, kota, data, tol, testcase, query;
    cin >> uang >> kota >> data;
    // ini buat awal root nya
    bst.insert(data, 0);

    // ini buat insert
    for (int i = 0; i < kota - 1; i++)
    {
        cin >> data >> tol;
        bst.insert(data, tol);
    }

    cin >> query;
    while (query--)
    {
        cin >> testcase;
        int result = bst.minMoney(bst.root, testcase);
        if (uang >= result)
        {
            cout << "yey, bisa refreshing :)" << endl;
        }
        else if (result == -1)
        {
            cout << "bruhh -_-" << endl;
        }
        else
        {
            cout << "bruhh -_-" << endl;
        }
    }
    // bst.preorder(bst.root);
    return 0;
}

/*
3
10 6
2 3
7 5
1 1
3 3
10 5
4 1
8 8
5 4
9 7

3
9 8
3 4
1 3
6 5
4 2
7 1
10 1
14 7
13 4
7
3
6
7
10
14
13
4

7
15 100
75 5
65 6
60 3
70 4
85 5
80 4
95 3
125 4
115 3
110 5
120 3
150 5
135 1
175 2
5
125
75
100
115
150

*/