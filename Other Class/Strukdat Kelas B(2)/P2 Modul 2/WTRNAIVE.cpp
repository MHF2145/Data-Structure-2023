#include <bits/stdc++.h>
using namespace std;

struct BSTNode {
    int vertex;
    int edge;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int vertex, int edge)
        : vertex(vertex), edge(edge), left(nullptr), right(nullptr) {} 
};

class BST {
private:
    BSTNode* m_root;

private:
    BSTNode* insertUtil(BSTNode* root, int vertex, int edge) {
        if (root == nullptr) {
            return new BSTNode(vertex, edge);
        }

        if (vertex < root->vertex) {
            root->left = insertUtil(root->left, vertex, edge);
        }
        else if (vertex > root->vertex) {
            root->right = insertUtil(root->right, vertex, edge);
        }

        return root;
    }

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
            return distanceFromNode(root->left, a, b);
        }
        else if (root->vertex < a && root->vertex < b) {
            return distanceFromNode(root->right, a, b);
        }
        else if (root->vertex == a || root->vertex == b) {
            int distA = distanceFromRoot(m_root, a);
            int distB = distanceFromRoot(m_root, b);
            return max(distA, distB) - min(distA, distB);
        }
        else if (root->vertex >= a && root->vertex <= b) {
            return distanceFromRoot(root, a) + distanceFromRoot(root, b);
        }

        return 0;
    }

    void getLeafNodes(BSTNode* root, vector<int>& vec) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            vec.push_back(root->vertex);
            return;
        }

        if (root->left != nullptr) {
            getLeafNodes(root->left, vec);
        }
        if (root->right != nullptr) {
            getLeafNodes(root->right, vec);
        }
    }

public:
    BST() 
        : m_root(nullptr) {}
    
    void insert(int vertex, int edge) {
        m_root = insertUtil(m_root, vertex, edge);
    }

    int dist(int a, int b) {
        return distanceFromNode(m_root, min(a, b), max(a, b));
    }

    vector<int> leaves() {
        vector<int> vec;
        getLeafNodes(m_root, vec);
        return vec;
    }
};

int main() {
    int n, t;
    cin >> n >> t;

    BST bst;
    bst.insert(t, 0);
    while (n--) {
        int s, d;
        cin >> s >> d;
        bst.insert(s, d);
    }

    vector<int> leaf = bst.leaves();
    // for (auto i: leaf) {
    //     cout << i << " ";
    // }
    // cout << endl;

    int m, mi;
    cin >> m;
    while (m--) {
        cin >> mi;

        int minDist = INT_MAX;
        for (auto i: leaf) {
            minDist = min(minDist, bst.dist(mi, i));
        }

        cout << minDist << endl;
    }

    return 0;
}

// int main() {
//     int v, w;
//     vector<int> vertex;
//     BST bst;

//     while (cin >> v >> w) {
//         bst.insert(v, w);
//         vertex.push_back(v);
//     }

//     vector<int> x = bst.leaves();
    
//     int minDist = INT_MAX;
//     for (auto leaf: x) {
//         minDist = min(minDist, bst.dist(leaf, 48));
//     }

//     cout << minDist;
// }