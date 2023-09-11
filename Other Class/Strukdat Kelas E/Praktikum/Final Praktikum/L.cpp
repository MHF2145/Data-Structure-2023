#include <iostream>
#include <queue>

using namespace std;

struct BSTNode {
    BSTNode *left, *right;
    int key;

    BSTNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

struct BST {
    BSTNode *_root;
    unsigned int _size;

    void init() {
        _root = nullptr;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == nullptr;
    }

    bool find(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;

        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value)) {
            _root = __remove(_root, value);
            _size++;
        }
    }

    void traverseInorder() {
        __inorder(_root);
    }

    void printRightMostNodes() {
        if (_root == nullptr)
            return;

        queue<BSTNode*> levelQueue;
        levelQueue.push(_root);

        while (!levelQueue.empty()) {
            int levelSize = levelQueue.size();
            BSTNode* rightmost = nullptr;

            for (int i = 0; i < levelSize; i++) {
                BSTNode* current = levelQueue.front();
                levelQueue.pop();

                if (current->left)
                    levelQueue.push(current->left);
                if (current->right)
                    levelQueue.push(current->right);

                rightmost = current;
            }

            cout << rightmost->key << endl;
        }
    }

private:
    BSTNode* __createNode(int value) {
        BSTNode *newNode = new BSTNode(value);
        return newNode;
    }

    BSTNode* __search(BSTNode *root, int value) {
        while (root != nullptr) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* __insert(BSTNode *root, int value) {
        if (root == nullptr)
            return __createNode(value);

        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);

        return root;
    }

    BSTNode* __findMinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->left != nullptr)
            currNode = currNode->left;

        return currNode;
    }

    BSTNode* __remove(BSTNode *root, int value) {
        if (root == nullptr) return nullptr;

        if (value > root->key)
            root->right = __remove(root->right, value);
        else if (value < root->key)
            root->left = __remove(root->left, value);
        else {
            if (root->left == nullptr) {
                BSTNode *rightChild = root->right;
                delete root;
                return rightChild;
            }
            else if (root->right == nullptr) {
                BSTNode *leftChild = root->left;
                delete root;
                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);
            root->key = temp->key;
            root->right = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root) {
        if (root) {
            __inorder(root->left);
            cout << root->key << " ";
            __inorder(root->right);
        }
    }
};

int main() {
    BST SINJIIII;
    SINJIIII.init();

    int plsac;

    while (cin >> plsac) {
        SINJIIII.insert(plsac);
    }

    SINJIIII.printRightMostNodes();

    return 0;
}
