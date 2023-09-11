#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

void insert(Node *&root, int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }
    if (value < root->data) {
        insert(root->left, value);
    }
    else if (value > root->data) {
        insert(root->right, value);
    }
    else {
        return;
    }
}

Node* findLCA(Node* root, int n1, int n2) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data > n1 && root->data > n2) {
        return findLCA(root->left, n1, n2);
    }

    if (root->data < n1 && root->data < n2) {
        return findLCA(root->right, n1, n2);
    }

    return root;
}

int main() {
    Node *root = nullptr;
    int k, n, a, b;

    cin >> k;
    while(k--){
        int i = 0;
        cin >> n;
        insert(root, n);
    }

    cin >> a >> b;
    Node* ancestor = findLCA(root, a, b);
    cout << ancestor -> data <<  endl;
    return 0;
}