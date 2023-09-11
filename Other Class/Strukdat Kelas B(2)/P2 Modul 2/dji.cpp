#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

// A node in the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node with the given data and return a pointer to it
Node* createNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Insert a new node with the given data into the binary search tree rooted at the given node
void insertNode(Node*& node, int data) {
    if (node == nullptr) {
        node = createNode(data);
    } else if (data < node->data) {
        insertNode(node->left, data);
    } else {
        insertNode(node->right, data);
    }
}

// Find the shortest path from the root node to a leaf node in the binary search tree
void shortestPath(Node* node, std::vector<int>& path, int& minSum) {
    if (node == nullptr) {
        return;
    }
    path.push_back(node->data);
    if (node->left == nullptr && node->right == nullptr) {
        // Found a leaf node
        int sum = 0;
        for (int value : path) {
            sum += value;
        }
        if (sum < minSum) {
            minSum = sum;
        }
    } else {
        shortestPath(node->left, path, minSum);
        shortestPath(node->right, path, minSum);
    }
    path.pop_back();
}


// Wrapper function to find the shortest path from the root node to a leaf node in the binary search tree
int findShortestPath(Node* root) {
    std::vector<int> path;
    int minSum = INT_MAX;
    shortestPath(root, path, minSum);
    return minSum;
}

int main() {
    // Create a sample binary search tree
    Node* root = nullptr;
    insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 13);
    insertNode(root, 17);

    // Find the shortest path from the root node to a leaf node in the binary search tree
    int minSum = findShortestPath(root);
    std::cout << "The shortest path from the root node to a leaf node in the binary search tree is: " << minSum << "\n";

    return 0;
}
