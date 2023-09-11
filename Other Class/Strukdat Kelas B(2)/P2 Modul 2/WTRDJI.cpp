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
    int m_size;

public:
    BST() 
        : m_root(nullptr), m_size(0) {}
    
    // void insert(int vertex, int edge) {
    //     BSTNode *newNode = new BSTNode(vertex, edge);

    //     if (m_root == nullptr) {
    //         m_root = newNode;
    //     }
    //     else {
    //         BSTNode* cursor = m_root;
    //         BSTNode* insertPos = m_root;
    //         while (cursor != nullptr) {
    //             insertPos = cursor;
    //             if (vertex < cursor->vertex) {
    //                 cursor = cursor->left;
    //             }
    //             else {
    //                 cursor = cursor->right;
    //             }
    //         }

    //         newNode->parent = insertPos;

    //         if (vertex < insertPos->vertex) {
    //             insertPos->left = newNode;
    //         }
    //         else {
    //             insertPos->right = newNode;
    //         }
    //     }

    //     m_size++;
    // }

    BSTNode* insertUtil(BSTNode *root, int vertex, int edge) {
        if (root == NULL) 
        	return new BSTNode(vertex, edge);
            
        
        if (vertex < root->vertex) {
        	root->left = insertUtil(root->left, vertex, edge);
        	root->left->parent = root;
		}
            
        else if (vertex > root->vertex) {
        	root->right = insertUtil(root->right, vertex, edge);
        	root->right->parent = root;
		}
        
        return root;
    }

    void insert(int vertex, int edge) {
        m_root = insertUtil(m_root, vertex, edge);
        m_size++;
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

    void getPath(BSTNode* root, vector<vector<pair<int, int>>>& path) {
    	if (root != nullptr) {
    		if (root->parent != nullptr) {
	    		path[root->vertex].push_back(make_pair(root->parent->vertex, root->edge));
	    		path[root->parent->vertex].push_back(make_pair(root->vertex, root->edge));
			}
			getPath(root->left, path);
			getPath(root->right, path);
		}
	}

    vector<int> leaves() {
        vector<int> vec;
        getLeafNodes(m_root, vec);
        return vec;
    }

    vector<vector<pair<int, int>>> paths() {
        vector<vector<pair<int, int>>> path(10000);
        getPath(m_root, path);
        return path;
    }
};

void dijkstra(int src, vector<int>& dist, vector<vector<pair<int, int>>>& path) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty()) {
		int fi = pq.top().first;
		int se = pq.top().second;
		pq.pop();
		
		if (fi <= dist[se]) {
            for (int i = 0; i < path[se].size(); i++) {
                if (dist[path[se][i].first] > dist[se] + path[se][i].second) {
                    dist[path[se][i].first] = dist[se] + path[se][i].second;
                    pq.push(make_pair(dist[path[se][i].first], path[se][i].first));
                }
            }
        }
	}
}


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

    vector<int> leaves = bst.leaves();
    vector<vector<pair<int, int>>> path = bst.paths();
    vector<int> dist(10000);

    for (int i = 1; i < dist.size(); i++) dist[i] = INT_MAX;

    for (auto& leaf: leaves) {
        dijkstra(leaf, dist, path);
    }

    // for (int i = 0; i < 10; i++) {
    //     if (path[i].size() > 0) cout << i << " ---" << endl;
    //     for (auto j: path[i]) {
    //         cout << " " << j.first << " " << j.second << endl;
    //     }
    // }

    int M, Mi;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> Mi;
        cout << dist[Mi] << endl;
    }
    
    return 0;
}