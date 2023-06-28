#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
    TreeNode* insert(TreeNode* node, int data) {
        if (!node) {
            return new TreeNode(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    int height(TreeNode* node) {
        if (!node) {
            return 0;
        }
        return 1 + max(height(node->left), height(node->right));
    }

    bool isBalanced(TreeNode* node) {
        if (!node) {
            return true;
        }
        int left_height = height(node->left);
        int right_height = height(node->right);

        if (abs(left_height - right_height) > 1) {
            return false;
        }
        return isBalanced(node->left) && isBalanced(node->right);
    }
};

int main() {
    int t, num;
    cin >> t;
    vector<int> data(t);
    for (int i = 0; i < t; ++i) {
        cin >> data[i];
    }
    cin >> num;

    BinaryTree bt;
    TreeNode *root = NULL;
    for (int i = 0; i < t; ++i) {
        root = bt.insert(root, data[i]);
    }

    root = bt.insert(root, num);
    
    if (bt.isBalanced(root)) {
        cout << "Tree tetap balance" << endl;
    } else {
        cout << "Tree tidak balance" << endl;
    }

    return 0;
}
