#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;


struct BSTNode {
    BSTNode *left, *right;
    int key;
};

struct BST {
    
    BSTNode *_root;
    unsigned int _size;

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

    void PH(int value) {
        queue<char> rute;
        BSTNode *temp = __search_PH(_root, &rute, value);
        if (!temp){
            cout << "no " << value << endl;
            return;
        }
        
        if (temp->key == value){
            while(rute.size()>0){
                cout << rute.front();
                rute.pop(); 
            }
            cout << "S" << endl;
        }
        else{
            cout << "no " << value << endl;
            return;
        }
    }

    void FD(int value) {
        int height = 0;
        BSTNode *temp = __search_height(_root, value, &height);
        if (!temp){
            cout << "no " << value << endl;
            return;
        }
        
        if (temp->key == value){
            cout << "on level " << height + 1 << endl;
            return;
        }
        else{
            cout << "no " << value << endl;
            return;
        }
    }

    void IN(int value) {
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

    void RK(int *index) {
        __inorder_RK(_root, index);
    }

    void traversePreorder() {
        __preorder(_root);
    }

    void traversePostorder() {
        __postorder(_root);
    }

private:
   
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

    BSTNode* __search_PH(BSTNode *root, queue<char> *rute, int value) {
        while (root != NULL) {
            if (value < root->key)
            {
                rute->push('L');
                root = root->left;
            }
            else if (value > root->key)
            {
                rute->push('R');
                root = root->right;
            }
            else
                return root;
        }
        return root;
    }
    
    BSTNode* __search_height(BSTNode *root, int value, int *height) {
        while (root != NULL) {
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

    void __inorder_RK(BSTNode *root, int *index)
    {
        if (root) {
            __inorder_RK(root->left, index);
            if(*index == 1)
                cout << root->key << endl;
            *index -= 1;
            __inorder_RK(root->right, index);
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

int main(){
    BST set;
    set.init();
    string command;    
    while(cin >> command){
        if(command == "IN"){
            int x;
            cin >> x;
            set.IN(x);
        }
        else if(command == "FD"){
            int x;
            cin >> x;
            set.FD(x);
        }
        else if(command == "RK"){
            int x;
            cin >> x;
            if(x > set._size){
                cout << "-1" << endl;
                continue;
            }
            set.RK(&x);
        }
        else if(command == "PH"){
            int x;
            cin >> x;
            set.PH(x);
        }
        else if(command == "STOP"){
            cout << "done\n";
            break;
        }
    }
    return 0;
}
