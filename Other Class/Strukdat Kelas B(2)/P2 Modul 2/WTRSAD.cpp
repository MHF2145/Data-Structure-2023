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
    vector<vector<pair<int, int>>> adj;

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

    void getAdj(BSTNode* node) {
        if (node->left != nullptr) {
            adj[node->vertex].push_back(make_pair(node->left->vertex, node->left->edge));
            adj[node->left->vertex].push_back(make_pair(node->vertex, node->left->edge));
            getAdj(node->left);
        }

        if (node->right != nullptr) {
            adj[node->vertex].push_back(make_pair(node->right->vertex, node->right->edge));
            adj[node->right->vertex].push_back(make_pair(node->vertex, node->right->edge));
            getAdj(node->right);
        }
    }



public:
    BST() 
        : m_root(nullptr) {}
    
    void insert(int vertex, int edge) {
        m_root = insertUtil(m_root, vertex, edge);
    }

    vector<int> leaves() {
        vector<int> vec;
        getLeafNodes(m_root, vec);
        return vec;
    }

    vector<vector<pair<int, int>>> adjList() {
        adj.clear();
        adj.resize(3000);
        getAdj(m_root);
        return adj;
    }

    void dijkstra(int src) {
        priority_queue<pair<int, int>, greater<pair<int, int>>> pq;
        vector<int> dist(3000, INT_MAX);
        pq.push(make_pair(0, src));
        dist[src] = 0;

        while (!pq.empty()) {
            
        }
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
    vector<vector<pair<int, int>>> adj = bst.adjList();

    int m, mi;
    cin >> m;
    while (m--) {
        cin >> mi;

        
    }

    return 0;
}