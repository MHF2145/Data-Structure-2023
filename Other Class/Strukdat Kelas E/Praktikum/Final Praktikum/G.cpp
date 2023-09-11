#include <iostream>
using namespace std;

/**
 * Implementasi Binary Search Tree (ADT: BST)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februari 2019
 * Struktur Data 2020
 * 
 * Implementasi untuk Bahasa C++
 */

struct BSTNode {
    BSTNode* left;
    BSTNode* right;
    int key;
};

struct BST {
    // Member
    BSTNode* _root;
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
        BSTNode* temp = __search(_root, value);
        if (!temp)
            return false;

        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value)
    {
        if (!find(value)) {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void remove(int value)
    {
        if (find(value)) {
            _root = __remove(_root, value);
            _size--;
        }
    }

    void tidaksatuanak()
    {
        bool printed = false;
        ceksatuanak(_root, printed);

        if (!printed) {
            cout << "Use whatever means you must to control our population. Just do it.";
        }

        cout << endl;
    }

private:
    // Utility Function
    BSTNode* __createNode(int value)
    {
        BSTNode* newNode = new BSTNode;
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    BSTNode* __search(BSTNode* root, int value)
    {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* __insert(BSTNode* root, int value)
    {
        if (root == NULL)
            return __createNode(value);

        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);

        return root;
    }

    BSTNode* __findMinNode(BSTNode* node)
    {
        BSTNode* currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;

        return currNode;
    }

    BSTNode* __remove(BSTNode* root, int value)
    {
        if (root == NULL)
            return NULL;

        if (value > root->key)
            root->right = __remove(root->right, value);
        else if (value < root->key)
            root->left = __remove(root->left, value);
        else {

            if (root->left == NULL) {
                BSTNode* rightChild = root->right;
                delete root;
                return rightChild;
            } else if (root->right == NULL) {
                BSTNode* leftChild = root->left;
                delete root;
                return leftChild;
            }

            BSTNode* temp = __findMinNode(root->right);
            root->key = temp->key;
            root->right = __remove(root->right, temp->key);
        }
        return root;
    }

    void ceksatuanak(BSTNode* root, bool& printed)
    {
        if (root == NULL)
            return;

        ceksatuanak(root->left, printed);

        if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
            cout << root->key << " ";
            printed = true;
        }

        ceksatuanak(root->right, printed);
    }
};

int main()
{
    BST set;
    set.init();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int value;
        string command;

        cin >> command;

        if (command == "15") {
            cin >> value;
            set.insert(value);
        } else if (command == "04") {
            cin >> value;
            set.remove(value);
        } else if (command == "89") {
            set.tidaksatuanak();
        }
    }

    return 0;
}
