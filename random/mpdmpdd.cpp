#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    int height;
    TreeNode *left, *right;
};

int getHeight(TreeNode *node) {
    if (node == NULL) return 0;
    return node->height;NULL;
}

int getBalance(TreeNode *node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

TreeNode *newNode(int val) {
    TreeNode *node = new TreeNode;
    node->val = val;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

TreeNode *rightRotate(TreeNode *y) {
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

TreeNode *leftRotate(TreeNode *x) {
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

TreeNode *insert(TreeNode *node, int val, bool &isBalanced) {
    if (node == NULL) return newNode(val);

    if (val < node->val) {
        node->left = insert(node->left, val, isBalanced);
    } else if (val > node->val) {
        node->right = insert(node->right, val, isBalanced);
    } else {
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1) {
        if (val < node->left->val) {
            node = rightRotate(node);
        } else {
            node->left = leftRotate(node->left);
            node = rightRotate(node);
        }
        isBalanced = false;
    } else if (balance < -1) {
        if (val > node->right->val) {
            node = leftRotate(node);
        } else {
            node->right = rightRotate(node->right);
            node = leftRotate(node);
        }
        isBalanced = false;
    }

    return node;
}

int main() {
    int n;
    cin >> n;

    TreeNode *root = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        bool isBalanced = true;
        root = insert(root, val, isBalanced);
    }

    int newVal;
    cin >> newVal;
    bool isBalanced = true;
    root = insert(root, newVal, isBalanced);

    if (isBalanced) {
        cout << "Tree tetap balance" << endl;
    } else {
        cout << "Tree tidak balance" << endl;
}

return 0;
}

