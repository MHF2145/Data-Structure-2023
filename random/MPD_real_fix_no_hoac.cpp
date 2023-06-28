#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    int height;
    TreeNode *left, *right;
};

int getHeight(TreeNode *node) {
    return (node == NULL) ? 0 : node->height;
}

int getBalance(TreeNode *node) {
    return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

TreeNode *newNode(int val) {
    TreeNode *node = new TreeNode;
    node->val = val;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

TreeNode *rightRotate(TreeNode *y) {
    TreeNode *x = y->left, *T2 = x->right;
    x->right = y; y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

TreeNode *leftRotate(TreeNode *x) {
    TreeNode *y = x->right, *T2 = y->left;
    y->left = x; x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

TreeNode *insert(TreeNode *node, int val, bool &isBalanced) {
    if (node == NULL) return newNode(val);
    if (val < node->val) node->left = insert(node->left, val, isBalanced);
    else if (val > node->val) node->right = insert(node->right, val, isBalanced);
    else return node;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);
    if (balance > 1) {
        if (val < node->left->val) node = rightRotate(node);
        else { node->left = leftRotate(node->left); node = rightRotate(node); }
        isBalanced = false;
    } else if (balance < -1) {
        if (val > node->right->val) node = leftRotate(node);
        else { node->right = rightRotate(node->right); node = leftRotate(node); }
        isBalanced = false;
    }
    return node;
}

int main() {
    int n, val;
    cin >> n;
    TreeNode *root = NULL;
    for (int i = 0; i < n; i++) {
        cin >> val; bool isBalanced = true;
        root = insert(root, val, isBalanced);
    }
    cin >> val; bool isBalanced = true;
    root = insert(root, val, isBalanced);
    cout << ((isBalanced) ? "Tree tetap balance\n" : "Tree tidak balance\n");
    return 0;
}
