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

Node *findNode(Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return findNode(root->left, data);
    } else {
        return findNode(root->right, data);
    }
}

int cariLevel(Node *root, int data, int level) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == data) {
        return level;
    }

    int leftLevel = cariLevel(root->left, data, level + 1);
    if (leftLevel != 0) {
        return leftLevel;
    }

    int rightLevel = cariLevel(root->right, data, level + 1);
    return rightLevel;
}

void inorder(Node *root, vector<int> &sorted) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, sorted);
    sorted.push_back(root->data);
    inorder(root->right, sorted);
}

string cariArah(Node *root, int data) {
    if (root == nullptr) {
        return "";
    }

    if (root->data == data) {
        return "S";
    }

    if (data < root->data) {
        string kiri = cariArah(root->left, data);
        if (kiri != "") {
            return "L" + kiri;
        }
    } else {
        string kanan = cariArah(root->right, data);
        if (kanan != "") {
            return "R" + kanan;
        }
    }

    return "";
}

int main() {
    string command;
    int val;

    Node *root = NULL;

    while (true) {
        cin >> command;

        if (command == "IN") {
            cin >> val;
            if (findNode(root, val) == NULL) {
                root = insertNode(root, val);
            }
        } else if (command == "FD") {
            cin >> val;
            Node *node = findNode(root, val);

            if (node == NULL) {
                cout << "no " << val << endl;
            } else {
                int level = cariLevel(root, val, 1);
                cout << "on level " << level << endl;
            }
        } else if (command == "RK") {
            cin >> val;
            vector<int> sorted;
            inorder(root, sorted);

            if (val > 0 && val <= sorted.size()) {
                cout << sorted[val - 1] << endl;
            } else {
                cout << -1 << endl;
            }
        } else if (command == "PH") {
            cin >> val;
            string path = cariArah(root, val);

            if (path == "") {
                cout << "no " << val << endl;
            } else {
                cout << path << endl;
            }
        } else if (command == "STOP") {
            cout << "done" << endl;
            break;
        }
    }

    return 0;
}
