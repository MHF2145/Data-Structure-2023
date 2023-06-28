#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> list;

struct BSTNode {
    BSTNode *left, *right;
    int key;
};

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
            _size--;
        }
    }

    void traverseInorder() {
        list.clear();
        __inorder(_root);
    }

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

            if (
                (root->left != NULL && root->right == NULL) ||
                (root->right != NULL && root->left == NULL)
            ) list.push_back(root->key);
            
            __inorder(root->right);
        }
    }
};




int main() {
    BST bst;
    bst.init();
    int n, operate, numTemp;
    cin >> n;
    
    while (n--) {
        cin >> operate;
        if (operate == 15) {
            cin >> numTemp;
            bst.insert(numTemp);
        } else if (operate == 04) {
            cin >> numTemp;
            bst.remove(numTemp);
        } else if (operate == 89) {
            bst.traverseInorder();
            if (list.size() == 0)
                cout << "Use whatever means you must to control our population. Just do it." << endl;
            else {
                for (auto &it : list)
                    cout << it << " ";
            }
        }
    }

    return 0;
}