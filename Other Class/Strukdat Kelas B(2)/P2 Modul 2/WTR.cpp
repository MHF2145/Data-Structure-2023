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
    BSTNode* getLCA(BSTNode* root, int a, int b) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->vertex > a && root->vertex > b) {
            return getLCA(root->left, a, b);
        }

        if (root->vertex < a && root->vertex < b) {
            return getLCA(root->right, a, b);
        }

        return root;
    }

public:
    BST() 
        : m_root(nullptr) {}
    
    void insert(int vertex, int edge) {
        BSTNode *newNode = new BSTNode(vertex, edge);

        if (m_root == nullptr) {
            m_root = newNode;
        }
        else {
            BSTNode* cursor = m_root;
            BSTNode* insertPos = m_root;
            while (cursor != nullptr) {
                insertPos = cursor;
                if (vertex < cursor->vertex) {
                    cursor = cursor->left;
                }
                else {
                    cursor = cursor->right;
                }
            }

            newNode->parent = insertPos;

            if (vertex < insertPos->vertex) {
                insertPos->left = newNode;
            }
            else {
                insertPos->right = newNode;
            }
        }
    }

    int shortestPath(BSTNode* root, bool parent = false) {
        int adder;

        if (root == nullptr) {
            return INT_MAX;
        }

        if (parent) {
            adder = root->parent->edge;
        }
        else {
            adder = root->edge;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return adder;
        }
        else if (root->left == nullptr) {
            return adder + min(shortestPath(root->right), shortestPath(root->parent, true));
        }
        else if (root->right == nullptr) {
            return adder + min(shortestPath(root->left), shortestPath(root->parent, true));
        }
        else {
            return adder + min(min(shortestPath(root->left), shortestPath(root->right)), shortestPath(root->parent, true));
        }
    }

    

    int findNearestLeaf(int vertex) {
        BSTNode* cursor = m_root;
        while (cursor != nullptr) {
            if (vertex < cursor->vertex) {
                cursor = cursor->left;
            }
            else if (vertex > cursor->vertex) {
                cursor = cursor->right;
            }
            else {
                break;
            }
        }

        return shortestPath(cursor) - cursor->edge;
    }
};


int main() {
    int N, T;
    cin >> N >> T;

    BST bst;
    bst.insert(T, 0);
    for (int i = 0; i < N; i++) {
        int s, d;
        cin >> s >> d;
        bst.insert(s, d);
    }

    int M, Mi;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> Mi;
        cout << bst.findNearestLeaf(Mi) << endl;
    }
    return 0;
}