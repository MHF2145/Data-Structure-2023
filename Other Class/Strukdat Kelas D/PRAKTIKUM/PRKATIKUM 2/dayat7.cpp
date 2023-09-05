#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data) {
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insertNode(Node *root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

Node *findParent(Node *root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (root->left != NULL && root->left->data == data) {
        return root;
    }

    if (root->right != NULL && root->right->data == data) {
        return root;
    }

    if (data < root->data) {
        return findParent(root->left, data);
    } else {
        return findParent(root->right, data);
    }
}

void inorder(Node *root, vector<int> &val) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, val);
    val.push_back(root->data);
    inorder(root->right, val);
}

int main() {
    int N;
    cin >> N;

    Node *root = NULL;

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "Insert") {
            int A;
            cin >> A;
            root = insertNode(root, A);
        } else if (cmd == "Parent") {
            int C;
            cin >> C;
            Node *parent = findParent(root, C);

            if (parent == NULL) {
                cout << "Orphanage, here it comes" << endl;
            } else {
                cout << "Child of " << parent->data << endl;
            }
        } else if (cmd == "Order") {
            int B;
            cin >> B;

            vector<int> val;
            inorder(root, val);

            int index = -1;

            for (int i = 0; i < val.size(); i++) {
                if (val[i] == B) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                cout << "Not Found" << endl;
            } else {
                cout << "Order : " << index + 1 << endl;
            }
        }
    }
    return 0;
}
