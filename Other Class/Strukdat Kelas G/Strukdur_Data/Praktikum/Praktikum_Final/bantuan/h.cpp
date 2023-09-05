#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int level;
    string path;
};

Node* root = NULL;

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->level = 1;
    newNode->path = "";
    return newNode;
}

void insert(Node* node, int data) {
    if (root == NULL) {
        root = createNode(data);
        return;
    }
    if (data < node->data) {
        if (node->left == NULL) {
            node->left = createNode(data);
            node->left->level = node->level + 1;
            node->left->path = node->path + "L";
        }
        else {
            insert(node->left, data);
        }
    }
    else if (data > node->data) {
        if (node->right == NULL) {
            node->right = createNode(data);
            node->right->level = node->level + 1;
            node->right->path = node->path + "R";
        }
        else {
            insert(node->right, data);
        }
    }
}

Node* find(Node* node, int data) {
    if (node == NULL) {
        return NULL;
    }
    if (data == node->data) {
        return node;
    }
    if (data < node->data) {
        return find(node->left, data);
    }
    else {
        return find(node->right, data);
    }
}

int countNodes(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + countNodes(node->left) + countNodes(node->right);
}

Node* kthSmallest(Node* node, int& k) {
    if (node == NULL) {
        return NULL;
    }
    Node* left = kthSmallest(node->left, k);
    if (left != NULL) {
        return left;
    }
    k--;
    if (k == 0) {
        return node;
    }
    return kthSmallest(node->right, k);
}

void printPath(Node* node) {
    if (node == NULL) {
        return;
    }
    cout << node->path + "S" << endl;
}

int main() {
    string command;
    int x, k;
    while (true) {
        cin >> command;
        if (command == "IN") {
            cin >> x;
            if (find(root, x) == NULL) {
                insert(root, x);
            }
        }
        else if (command == "FD") {
            cin >> x;
            Node* node = find(root, x);
            if (node == NULL) {
                cout << "no " << x << endl;
            }
            else {
                cout << "on level " << node->level << endl;
            }
        }
        else if (command == "RK") {
            cin >> k;
            if (k <= countNodes(root)) {
                Node* node = kthSmallest(root, k);
                cout << node->data << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if (command == "PH") {
            cin >> x;
            Node* node = find(root, x);
            if (node == NULL) {
                cout << "no " << x << endl;
            }
            else {
                printPath(node);
            }
        }
        else if (command == "STOP") {
            cout << "done" << endl;
            break;
        }
    }
    return 0;
}
