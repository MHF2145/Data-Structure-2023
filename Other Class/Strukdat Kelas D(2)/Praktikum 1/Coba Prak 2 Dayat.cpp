#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Fungsi untuk membuat node baru pada Binary Search Tree
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi untuk memasukkan data pada Binary Search Tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Fungsi untuk mencari parent dari suatu node pada Binary Search Tree
void findParent(Node* root, int data) {
    Node* parent = NULL;
    while (root != NULL) {
        if (root->data == data) {
            break;
        }
        else if (data <= root->data) {
            parent = root;
            root = root->left;
        }
        else {
            parent = root;
            root = root->right;
        }
    }
    if (root == NULL) {
        cout << "Orphanage, here it comes" << endl;
    }
    else if (parent == NULL) {
        cout << "Root Node" << endl;
    }
    else {
        cout << "Child of " << parent->data << endl;
    }
}

// Fungsi untuk mencari index urutan dari suatu node pada Binary Search Tree
int findIndex(Node* root, int data, int index) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == data) {
        return index;
    }
    else if (data < root->data) {
        return findIndex(root->left, data, 2*index);
    }
    else {
        return findIndex(root->right, data, 2*index+1);
    }
}

int main() {
    int N;
    cin >> N;
    Node* root = NULL;
    for (int i = 0; i < N; i++) {
        string command;
        cin >> command;
        if (command == "Insert") {
            int data;
            cin >> data;
            root = insert(root, data);
        }
        else if (command == "Parent") {
            int data;
            cin >> data;
            findParent(root, data);
        }
        else if (command == "Order") {
            int data;
            cin >> data;
            int index = findIndex(root, data, 1);
            if (index == 0) {
                cout << "Orphanage, here it comes" << endl;
            }
            else {
                cout << "Order : " << index << endl;
            }
        }
    }
    return 0;
}

