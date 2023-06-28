#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int level;

    Node(int value, int lvl) {
        data = value;
        left = nullptr;
        right = nullptr;
        level = lvl;
    }
};

Node* insert(Node* root, int value, int level) {
    if (root == nullptr) {
        root = new Node(value, level);
    } else if (value < root->data) {
        root->left = insert(root->left, value, level + 1);
    } else if (value > root->data) {
        root->right = insert(root->right, value, level + 1);
    }
    return root;
}

Node* find(Node* root, int value) {
    if (root == nullptr || root->data == value) {
        return root;
    } else if (value < root->data) {
        return find(root->left, value);
    } else {
        return find(root->right, value);
    }
}

int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

void inOrderTraversal(Node* root, int& count, int x, int& result) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left, count, x, result);

    count++;
    if (count == x) {
        result = root->data;
    }

    inOrderTraversal(root->right, count, x, result);
}

string getPath(Node* root, int value) {
    if (root == nullptr) {
        return "";
    } else if (root->data == value) {
        return "S";
    } else if (value < root->data) {
        string leftPath = getPath(root->left, value);
        if (leftPath == "") {
            return "";
        }
        return "L" + leftPath;
    } else {
        string rightPath = getPath(root->right, value);
        if (rightPath == "") {
            return "";
        }
        return "R" + rightPath;
    }
}

int main() {
    Node* root = nullptr;

    string command;
    while (true) {
        cin >> command;
        if (command == "IN") {
            int x;
            cin >> x;
            if (find(root, x) == nullptr) {
                root = insert(root, x, 1);
            }
        } else if (command == "FD") {
            int x;
            cin >> x;
            Node* node = find(root, x);
            if (node != nullptr) {
                cout << "on level " << node->level << endl;
            } else {
                cout << "no " << x << endl;
            }
        } else if (command == "RK") {
            int x;
            cin >> x;
            int count = 0;
            int result = -1;
            inOrderTraversal(root, count, x, result);
            cout << result << endl;
        } else if (command == "PH") {
            int x;
            cin >> x;
            string path = getPath(root, x);
            if (path == "") {
                cout << "no " << x << endl;
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
