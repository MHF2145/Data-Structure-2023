#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    int sum;
};

Node* createNode(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    newNode->sum = 0;
    return newNode;
}

void modifyBST(Node* root, int& sum) {
    if (root == NULL) return;

    modifyBST(root->right, sum);

    sum += root->data;
    root->sum = sum;

    modifyBST(root->left, sum);
}

void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->sum << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    // Input BST
    int val;
    while (cin >> val) {
        Node* newNode = createNode(val);
        if (root == NULL) root = newNode;
        else {
            Node* curr = root;
            while (true) {
                if (val < curr->data) {
                    if (curr->left == NULL) {
                        curr->left = newNode;
                        break;
                    }
                    else curr = curr->left;
                }
                else {
                    if (curr->right == NULL) {
                        curr->right = newNode;
                        break;
                    }
                    else curr = curr->right;
                }
            }
        }
    }

    // Modify BST
    int sum = 0;
    modifyBST(root, sum);

    // Inorder Traversal of Modified BST
    inorder(root);

    return 0;
}

