#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) return new TreeNode(key);

    if (key < root->val) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);

    return root;
}

int height(TreeNode* root) {
    if (root == NULL) return 0;

    return 1 + max(height(root->left), height(root->right));
}

int checkBalance(TreeNode* root) {
    if (root == NULL) return 0;

    int left_height = checkBalance(root->left);
    if (left_height == -1) return -1;
    
    int right_height = checkBalance(root->right);
    if (right_height == -1) return -1;

    if (abs(left_height - right_height) > 1) return -1;
    else return 1 + max(left_height, right_height);
}

int main() {
    int n, key;
    cin >> n;
    vector<int> nodes(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i];
    }
    
    int newNode;
    cin >> newNode;

    TreeNode* root = NULL;
    
    for (int i = 0; i < n; ++i) {
        root = insert(root, nodes[i]);
    }
    
    root = insert(root, newNode);

    if (checkBalance(root) != -1) cout << "Tree tetap balance" << endl;
    else cout << "Tree tidak balance" << endl;

    return 0;
}
