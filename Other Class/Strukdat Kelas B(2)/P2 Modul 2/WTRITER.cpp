#include <bits/stdc++.h>
using namespace std;

struct BSTNode {
    int vertex;
    int edge;
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;

    BSTNode(int vertex, int edge)
        : vertex(vertex), edge(edge), left(nullptr), right(nullptr), parent(nullptr) {} 
};

class BST {
private:
    BSTNode* m_root;

private:
    int distanceFromRoot(BSTNode* root, int vertex) {
        if (vertex == root->vertex) {
            return root->edge;
        }
        else if (vertex < root->vertex) {
            return root->edge + distanceFromRoot(root->left, vertex);
        }
        else {
            return root->edge + distanceFromRoot(root->right, vertex);
        }
    }

    int distanceFromNode(BSTNode* root, int a, int b) {
        if (root == nullptr) {
            return 0;
        }
 
        if (root->vertex > a && root->vertex > b) {
            return root->left->edge + distanceFromNode(root->left, a, b);
        }
        else if (root->vertex < a && root->vertex < b) {
            return root->right->edge + distanceFromNode(root->right, a, b);
        }
        else if (root->vertex >= a && root->vertex <= b) {
            return distanceFromRoot(root, a) + distanceFromRoot(root, b);
        }

        return 0;
    }

    int getDist(int a, int b) {
        BSTNode* cursor = m_root;

        while (cursor != nullptr) {
            if (a < cursor->vertex) {
                cursor = cursor->left;
            }
            else if (a > cursor->vertex) {
                cursor = cursor->right;
            }
            else {
                break;
            }
        }

        while (cursor->vertex != b) {

        }
    }

public:
    BST() 
        : m_root(nullptr) {}
    
    void insert(int vertex, int edge) {
        BSTNode* newNode = new BSTNode(vertex, edge);

        if (m_root == nullptr) {
            m_root = newNode;
        }
        else {
            BSTNode* cursor = m_root;
            BSTNode* insertPos = m_root;
            while (cursor != nullptr) {
                insertPos = cursor;
                if (vertex <= cursor->vertex) {
                    cursor = cursor->left;
                }
                else {
                    cursor = cursor->right;
                }
            }

            newNode->parent = insertPos;

            if (vertex <= insertPos->vertex) {
                insertPos->left = newNode;
            }
            else {
                insertPos->right = newNode;
            }
        }
    }
    
    int depth(int vertex) {
        return distanceFromRoot(m_root, vertex);
    }

    int dist(int a, int b) {
        return distanceFromNode(m_root, min(a, b), max(a, b));
    }

    
};

int main() {
    int v, w;
    vector<int> vertex;
    BST bst;

    while (cin >> v >> w) {
        bst.insert(v, w);
        vertex.push_back(v);
    }

    cout << "From root: " << endl;
    for (int i = 0; i < vertex.size(); i++) {
        cout << "Vertex " << vertex[i] << ": " << bst.depth(vertex[i]) << endl;
    }

    cout << "From node 9: " << endl;
    for (int i = 0; i < vertex.size(); i++) {
        cout << "Vertex " << vertex[i] << ": " << bst.dist(vertex[i], 9) << endl;
    }

    cout << bst.dist(6, 12);
    
}