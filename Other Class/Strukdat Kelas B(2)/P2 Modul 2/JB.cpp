#include <bits/stdc++.h>
using namespace std;

// int main() {
//     int x;
//     vector<int> heap;
//     while (cin >> x) {
//         heap.push_back(x);
//     }
    
//     sort(heap.begin(), heap.end());

//     for (int i = heap.size()-2; i >= 0; i--) {
//         heap[i] += heap[i+1];
//     }

//     for (int i = 0; i < heap.size(); i++) {
//         cout << heap[i] << " ";
//     }

//     return 0;
// }

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int data)
        : data(data), left(nullptr), right(nullptr) {} 
};

class BST {
private:
    BSTNode* m_root;

private:
    void inorder(BSTNode* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void calcSum(BSTNode* root, int* sum) {
        if (root != nullptr) {
            calcSum(root->right, sum);
            *sum += root->data;
            root->data = *sum;
            calcSum(root->left, sum);
        }
    }

    BSTNode* insertUtil(BSTNode* root, int data) {
        if (root == nullptr) {
            return new BSTNode(data);
        }

        if (data < root->data) {
            root->left = insertUtil(root->left, data);
        }
        else if (data > root->data) {
            root->right = insertUtil(root->right, data);
        }

        return root;
    }

public:
    BST() 
        : m_root(nullptr) {}
    
    void insert(int data) {
        m_root = insertUtil(m_root, data);
    }

    void printInorder() {
        inorder(m_root);
    }

    void calculateSum() {
        int sum = 0;
        calcSum(m_root, &sum);
    }
    
};

int main() {
    BST bst;
    int x;
    while (cin >> x) {
        bst.insert(x);
    }

    bst.calculateSum();
    bst.printInorder();

    return 0;
}