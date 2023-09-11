#include <iostream>
using namespace std;

bool inpo = true;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insertNode(Node* cur, int value) {
        if (cur == nullptr) {
            return new Node(value);
        }

        if (value < cur->data) {
            cur->left = insertNode(cur->left, value);
        } else if (value > cur->data) {
            cur->right = insertNode(cur->right, value);
        }

        return cur;
    }

    Node* findMinNode(Node* cur) {
        while (cur->left != nullptr) {
            cur = cur->left;
        }
        return cur;
    }

    Node* deleteNode(Node* cur, int value) {
        if (cur == nullptr) {
            return nullptr;
        }

        if (value < cur->data) {
            cur->left = deleteNode(cur->left, value);
        } else if (value > cur->data) {
            cur->right = deleteNode(cur->right, value);
        } else {
            if (cur->left == nullptr) {
                Node* temp = cur->right;
                delete cur;
                return temp;
            } else if (cur->right == nullptr) {
                Node* temp = cur->left;
                delete cur;
                return temp;
            }
            Node* minRightNode = findMinNode(cur->right);
            cur->data = minRightNode->data;
            cur->right = deleteNode(cur->right, minRightNode->data);
        }

        return cur;
    }

    void inorderTraversal(Node* cur) {
        if (cur != nullptr) {
            inorderTraversal(cur->left);

            if ((cur->left == nullptr && cur->right != nullptr) ||
                (cur->left != nullptr && cur->right == nullptr)) {
                inpo = false;
                cout << cur->data << " ";
            }

            inorderTraversal(cur->right);
        }
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }

    void ans() {
        inorderTraversal(root);
    }
};

int main() {
    BST bst;

    int n;
    cin >> n;
    while (n--) {
        int cmd;
        cin >> cmd;
        if (cmd == 15) {
            int x;
            cin >> x;
            bst.insert(x);
        } else if (cmd == 4) {
            int x;
            cin >> x;
            bst.remove(x);
        } else if (cmd == 89) {
            bst.ans();
            cout << endl;
            if (inpo) {
                cout << "Use whatever means you must to control our population. Just do it." << endl;
                inpo = true;
            }
        }
    }

    return 0;
}
