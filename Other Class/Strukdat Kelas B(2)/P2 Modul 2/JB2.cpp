#include <bits/stdc++.h>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int data)
        : data(data), left(nullptr), right(nullptr) {}
};

BSTNode* insert(BSTNode* root, int data) {
    if (root == nullptr) {
        return new BSTNode(data);
    }

    if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }

    return root;
}

void printInorder(BSTNode* root) {
    if (root != nullptr) {
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
}

void calculateSum(BSTNode* root) {
    int sum = 0;
    stack<BSTNode*> st;
    BSTNode* cursor = root;
     
    while(!st.empty() || cursor != nullptr ){          
        while(cursor != nullptr) {
            st.push(cursor);
            cursor = cursor->right;
        }
      
        cursor = st.top();
        st.pop();
        sum += cursor->data;
        cursor->data = sum;
       
        cursor = cursor->left;
    }
}

int main() {
    int x;
    BSTNode* bst = nullptr;
    while (cin >> x) {
        bst = insert(bst, x);
    }

    calculateSum(bst);
    printInorder(bst);
    return 0;
}