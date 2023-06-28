#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}
int findLevel(Node* root, int value, int level) {
    if (root == NULL) {
        return 0;
    }
    if (value == root->data) {
        return level;
    }
    int leftLevel = findLevel(root->left, value, level + 1);
    if (leftLevel != 0) {
        return leftLevel;
    }
    return findLevel(root->right, value, level + 1);
}
void FD(Node* root, int value) {
    int level = findLevel(root, value, 1);
    if (level != 0) {
        cout << "on level " << level << endl;
    }
    else {
        cout << "no " << value << endl;
    }
}
void cariRK(Node* root, int& count, int x, int& result) {
    if (root == NULL) {
        return;
    }
    cariRK(root->left, count, x, result);
    count++;
    if (count == x) {
        result = root->data;
        return;
    }
    cariRK(root->right, count, x, result);
}
void RK(Node* root, int x) {
    int count = 0;
    int result = -1;
    cariRK(root, count, x, result);
    cout << result << endl;
}
bool PH(Node* root, int value, string path) {
    if (root == NULL) {
        return false;
    }
    if (root->data == value) {
        cout << path << "S" << endl;
        return true;
    }
    if (PH(root->left, value, path + "L")) {
        return true;
    }
    if (PH(root->right, value, path + "R")) {
        return true;
    }
    return false;
}

void PH(Node* root, int value) {
    if (!PH(root, value, "")) {
        cout << "no " << value << endl;
    }
}
Node* deleteTree(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    return NULL;
}
int main() {
    Node* root = NULL;

    while (true) {
        string command;
        cin >> command;

        if (command == "IN") {
            int value;
            cin >> value;
            root = insertNode(root, value);
        }
        else if (command == "FD") {
            int value;
            cin >> value;
            FD(root, value);
        }
        else if (command == "RK") {
            int x;
            cin >> x;
            RK(root, x);
        }
        else if (command == "PH") {
            int value;
            cin >> value;
            PH(root, value);
        }
        else if (command == "STOP") {
            break;
        }
    }

    root = deleteTree(root);
    cout << "done" << endl;

    return 0;
}
