#include <iostream>
#include <unordered_set>
using namespace std;

bool flag = false;

struct BSTNode {
    int key;
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;
};

struct BST {
    BSTNode* _root;
    unsigned int _size;
};

BSTNode* createNode(BSTNode* root, int value) {
    BSTNode* newNode = new BSTNode;
    newNode->key = value;
    newNode->parent = root;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

BSTNode* insert(BSTNode* root, BSTNode* node, int value) {
    if (node == nullptr)
        return createNode(root, value);
    if (value < node->key)
        node->left = insert(node, node->left, value);
    else if (value > node->key)
        node->right = insert(node, node->right, value);
    return node;
}

BSTNode* search(BSTNode* root, int value) {
    while (root != nullptr) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

void init(BST* bst) {
    bst->_root = nullptr;
    bst->_size = 0u;
}

bool isEmpty(BST* bst) {
    return bst->_root == nullptr;
}

BSTNode* find(BST* bst, int value) {
    BSTNode* temp = search(bst->_root, value);
    if (temp == nullptr)
        return nullptr;
    if (temp->key == value)
        return temp;
    else
        return nullptr;
}

void insert(BST* bst, int value) {
    if (!find(bst, value)) {
        bst->_root = insert(bst->_root, bst->_root, value);
        bst->_size++;
    }
}

void traverse(BSTNode* root, int value) {
    if (root == nullptr)
        return;
    if (root->parent) {
        if (root->left) {
            int sum = root->key + root->parent->key + root->left->key;
            if (sum == value) {
                flag = true;
                return;
            }
        }
        if (root->right) {
            int sum = root->key + root->parent->key + root->right->key;
            if (sum == value) {
                flag = true;
                return;
            }
        }
    }
    if (root->left && root->right) {
        int sum = root->key + root->left->key + root->right->key;
        if (sum == value) {
            flag = true;
            return;
        }
    }
    traverse(root->left, value);
    traverse(root->right, value);
}

int main() {
    BST bst;
    init(&bst);
    int n, t;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        insert(&bst, x);
    }
    cin >> t;
    traverse(bst._root, t);
    if (flag) {
        cout << t << " Selamat! Kalian menemukan harta karunnya" << endl;
        return 0;
    }
    cout << t << " Tidak ada kombinasi yang tepat! Bikin ulang." << endl;
    return 0;
}
