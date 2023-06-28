#include <iostream>

using namespace std;

struct AVLNode {
    int data;
    int height;
    AVLNode *left;
    AVLNode *right;
};

int getHeight(AVLNode *node) {
    if (node == NULL)
        return -1;
    else
        return node->height;
}

AVLNode* rotateLeft(AVLNode *node) {
    AVLNode *newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    return newRoot;
}

AVLNode* rotateRight(AVLNode *node) {
    AVLNode *newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    return newRoot;
}

AVLNode* rotateLeftRight(AVLNode *node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

AVLNode* rotateRightLeft(AVLNode *node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

int getBalanceFactor(AVLNode *node) {
    if (node == NULL)
        return 0;
    else
        return getHeight(node->left) - getHeight(node->right);
}


AVLNode* insertNode(AVLNode *node, int data) {
    if (node == NULL) {
        AVLNode *newNode = new AVLNode;
        newNode->data = data;
        newNode->height = 0;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if (data < node->data) {
        node->left = insertNode(node->left, data);
        if (getBalanceFactor(node) == 2) {
            if (data < node->left->data)
                node = rotateRight(node);
            else
                node = rotateLeftRight(node);
        }
    }
    else if (data > node->data) {
        node->right = insertNode(node->right, data);
        if (getBalanceFactor(node) == -2) {
            if (data > node->right->data)
                node = rotateLeft(node);
            else
                node = rotateRightLeft(node);
        }
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    return node;
}

AVLNode* searchNode(AVLNode *node, int data) {
if (node == NULL || node->data == data)
return node;
else if (data < node->data)
return searchNode(node->left, data);
else
return searchNode(node->right, data);
}

AVLNode* getParentNode(AVLNode *node, AVLNode *root) {
if (node == NULL || root == NULL || root == node)
return NULL;
else if (root->left == node || root->right == node)
return root;
else if (node->data < root->data)
return getParentNode(node, root->left);
else
return getParentNode(node, root->right);
}

AVLNode* getSiblingParentNode(AVLNode *node, AVLNode *root) {
AVLNode *parentNode = getParentNode(node, root);
AVLNode *grandParentNode = getParentNode(parentNode, root);
if (grandParentNode == NULL)
    return NULL;
else if (grandParentNode->left == parentNode)
    return grandParentNode->right;
else if (grandParentNode->right == parentNode)
    return grandParentNode->left;
}

int getDifference(AVLNode *node, AVLNode *root) {
AVLNode *parentNode = getParentNode(node, root);
AVLNode *siblingParentNode = getSiblingParentNode(node, root);
if (siblingParentNode == NULL)
    return parentNode->data;
else
    return abs(parentNode->data - siblingParentNode->data);
}

int main() {
int n, t, r;
cin >> n >> t;
AVLNode *root = NULL;

for (int i = 0; i < n; i++) {
    cin >> r;
    root = insertNode(root, r);
}

for (int i = 0; i < t; i++) {
    int x;
    cin >> x;
    AVLNode *node = searchNode(root, x);
    cout << getDifference(node, root) << endl;
}

return 0;
}