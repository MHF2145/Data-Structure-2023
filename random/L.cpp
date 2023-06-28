/**
 * Implementasi Binary Search Tree (ADT: BST)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 * 
 * Implementasi untuk Bahasa C++
 */

#include <iostream>
#include <stdlib.h>
#include <queue>
#include <climits>

using namespace std;

/* Node structure */

struct BSTNode {
    BSTNode *left, *right;
    int key;
};

/* uniqueBST */

struct BST {
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;
        
        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value)) {
            _root = __remove(_root, value);
            _size++;
        }
    }

    void traverseInorder() {
        __inorder(_root);
    }

    void traversePreorder() {
        __preorder(_root);
    }

    void traversePostorder() {
        __postorder(_root);
    }

    void traverseRightChild()
    {
        //If the _root is null then simply return
        if(_root == NULL)
            return;
        //Do level order traversal using a single queue
        queue<BSTNode *> q;
        q.push(_root);
        
        while(!q.empty())
        {
            //n denotes the size of the current level in the queue
            int n = q.size();
            
            for(int i =0;i<n;i++)
            {
                BSTNode *temp = q.front();
                q.pop();
                
                //If it is leftmost corner value or rightmost corner value then print it
                if(i==n-1)
                    cout << temp->key << endl;

                //push the left and right children of the temp node
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
    }

    // void traverseRightChild() {

        // if (_root == NULL) return;

        // queue<BSTNode *> q;
        // q.push(_root);

        // while (!q.empty()) {
        //     int levelSize = q.size();
        //     int maxChild = INT_MIN;

        //     for (int i = 0; i < levelSize; i++) {
        //         BSTNode *temp = q.front();
        //         q.pop();

        //         if (temp->key > maxChild) {
        //             maxChild = temp->key;
        //         }

        //         if (temp->left)
        //             q.push(temp->left);
        //         if (temp->right)
        //             q.push(temp->right);
        //     }
        //     cout << maxChild << endl;
        // }
    // }

private:
    // Utility Function
    BSTNode* __createNode(int value) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    BSTNode* __search(BSTNode *root, int value) {
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

    BSTNode* __insert(BSTNode *root, int value) {
        if (root == NULL)
            return __createNode(value);
        
        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);
        
        return root;
    }

    BSTNode* __findMinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        
        return currNode;
    }

    BSTNode* __remove(BSTNode *root, int value) {
        if (root == NULL) return NULL;

        if (value > root->key) 
            root->right = __remove(root->right, value);
        else if (value < root->key) 
            root->left = __remove(root->left, value);
        else {

            if (root->left == NULL) {
                BSTNode *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL) {
                BSTNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);
            root->key     = temp->key;
            root->right   = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root) {
        if (root) {
            __inorder(root->left);
            printf("%d ", root->key);
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root) {
        if (root) {
            __postorder(root->left);
            __postorder(root->right);
            printf("%d ", root->key);
        }
    }

    void __preorder(BSTNode *root) {
        if (root) {
            printf("%d ", root->key);
            __preorder(root->left);
            __preorder(root->right);
        }
    }
};

int main(int argc, char const *argv[])
{
    BST set;
    set.init();

    int inp;
    while (cin >> inp) {
        set.insert(inp);
    }

    set.traverseRightChild();
    puts("");
    return 0;
}