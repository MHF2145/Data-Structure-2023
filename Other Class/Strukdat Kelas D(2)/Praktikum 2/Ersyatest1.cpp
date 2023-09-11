#include <iostream>
#include <queue>
using namespace std;

struct Node {
    unsigned long long val;
    Node* left, *right;
};

Node* createNode(unsigned long long val) {
    Node* newNode = new Node();
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(Node* &root, unsigned long long val) {
    if (root == NULL) {
        root = createNode(val);
        return;
    }

    if (val < root->val) insert(root->left, val);
    else if (val > root->val) insert(root->right, val);
}

void inorder(Node* root, unsigned long long& temp, priority_queue<unsigned long long>& out) 
{
    if (root == NULL) return;

    inorder(root->right, temp, out);

    temp += root->val;
    if (root->left == NULL || root->left->val != root->val) 
	{
        out.push(temp);
    }

    inorder(root->left, temp, out);
}

int main() 
{
    Node* root = NULL;

    unsigned long long val;
    while (cin >> val) {
        insert(root, val);
    }

    priority_queue<unsigned long long> out;
    unsigned long long temp = 0;
    inorder(root, temp, out);

    while (!out.empty()) {
        cout << out.top() << " ";
        out.pop();
    }

    return 0;
}

