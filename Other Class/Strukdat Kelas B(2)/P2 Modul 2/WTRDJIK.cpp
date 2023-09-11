#include<bits/stdc++.h>
using namespace std;

int dist[6001];
vector<pair<int, int>> edge[6201];
vector<int> leaf;

struct BSTNode {
    BSTNode *left, *right, *par;
    int key, weight;
};

struct BST {
    BSTNode *_root;
    unsigned int _size;

    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
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

    void insert(int value, int weight) {
        if (!find(value)) {
            _root = insertUtil(_root, value, weight);
            _size++;
        }
    }

    void traverseInorder() {
        __inorder(_root);
    }

    void traversePreorder() {
        __preorder(_root);
    }

    void traversePostorder() {
        __postorder(_root);
    }
    
    void computePath() {
    	__computePath(_root);
	}
	
	void computeLeaf() {
		__computeLeaf(_root);
	}

private:
    // Utility Function
    BSTNode* __createNode(int value, int _weight) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        newNode->weight = _weight;
        newNode->par = NULL;
        return newNode;
    }
    
    BSTNode* __search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* insertUtil(BSTNode *root, int value, int weight) {
        if (root == NULL) 
        	return __createNode(value, weight);
            
        
        if (value < root->key) {
        	root->left = insertUtil(root->left, value, weight);
        	root->left->par = root;
		}
            
        else if (value > root->key) {
        	root->right = insertUtil(root->right, value, weight);
        	root->right->par = root;
		}
        
        return root;
    }

    void __inorder(BSTNode *root) {
        if (root) {
            __inorder(root->left);
            if(root->par != NULL) printf("%d\n", root->par->key);
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root) {
        if (root) {
            __postorder(root->left);
            __postorder(root->right);
            printf("%d ", root->key);
        }
    }

    void __preorder(BSTNode *root) {
        if (root) {
            printf("%d ", root->key);
            __preorder(root->left);
            __preorder(root->right);
        }
    }
    
    void __computePath(BSTNode *root) {
    	if(root) {
    		if(root->par != NULL) {
	    		edge[root->key].push_back({root->par->key, root->weight});
	    		edge[root->par->key].push_back({root->key, root->weight});
			}
			__computePath(root->left);
			__computePath(root->right);
		}
	}
	
	void __computeLeaf(BSTNode *root) {
		if(root) {
			if(root->right == NULL && root->left == NULL) leaf.push_back(root->key);
			__computeLeaf(root->left);
			__computeLeaf(root->right);
		}
	}


};

void dijkstra(int a)
{
	
	priority_queue<pair<int, int>> pq;
	pq.push({0, a});
	dist[a] = 0;
	
	while(pq.size())
	{
		int cur = pq.top().second;
		int cek = pq.top().first;
		pq.pop();
		
		if(cek > dist[cur]) continue;
		for(int i = 0; i < edge[cur].size(); i++)
		{
			if(dist[edge[cur][i].first] > dist[cur] + edge[cur][i].second)
			{
				dist[edge[cur][i].first] = dist[cur] + edge[cur][i].second;
				pq.push({dist[edge[cur][i].first], edge[cur][i].first});
			}
		}
	}
}

int main()
{
    BST set;
    set.init();
	int n, t, m, p, v, w;
	cin >> n >> t;
	
	set.insert(t, 0);
	while(n--) {
		cin >> v >> w;
		set.insert(v, w);
	}
	set.computePath();
	set.computeLeaf();
	
	for(int i = 1; i < 6001; i++) dist[i] = INT_MAX;
	for(int i = 0; i < leaf.size(); i++) {
		dijkstra(leaf[i]);
	}

    for (int i = 0; i < 10; i++) {
        if (edge[i].size()> 0) cout << i << " ---" << endl;
        for (auto j: edge[i]) {
            cout << " " << j.first << " " << j.second << endl;
        }
    }

	cin >> m;
	while(m--) {
		cin >> p;
		// cout << dist[p] << endl;
	}
	
    return 0;
}