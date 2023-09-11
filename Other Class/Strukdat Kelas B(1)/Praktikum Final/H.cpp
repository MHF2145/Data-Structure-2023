#include<bits/stdc++.h>
using namespace std;

struct BSTNode {
    BSTNode *left, *right;
    int key, level;
};

struct BST {
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
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

    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value, 1);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value)) {
            _root = __remove(_root, value);
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
    
    void fd(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp) {
        	cout << "no " << value << endl;
        	return;
		}
        
        if (temp->key == value) {
        	cout << "on level " << temp->level << endl;
        	return;
		}
        else {
        	cout << "no " << value << endl;
        	return;
		}
    }
    
    void rk(int value) {
	    int cur = 0, res = -1;
	    __rk(_root, cur, value, res);
	    cout << res << endl;
	}
    
    void ph(int value) {
	    if (!__ph(_root, value, "")) {
	        cout << "no " << value << endl;
	    }
	}

private:
    // Utility Function
    BSTNode* __createNode(int value, int _level) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->level = _level;
        newNode->left = newNode->right = NULL;
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

    BSTNode* __insert(BSTNode *root, int value, int _level) {
        if (root == NULL)
            return __createNode(value, _level);
        
        if (value < root->key)
            root->left = __insert(root->left, value, _level + 1);
        else if (value > root->key)
            root->right = __insert(root->right, value, _level + 1);
        
        return root;
    }

    BSTNode* __findMinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        
        return currNode;
    }

    BSTNode* __remove(BSTNode *root, int value) {
        if (root == NULL) return NULL;

        if (value > root->key) 
            root->right = __remove(root->right, value);
        else if (value < root->key) 
            root->left = __remove(root->left, value);
        else {

            if (root->left == NULL) {
                BSTNode *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL) {
                BSTNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);
            root->key     = temp->key;
            root->right   = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root) {
        if (root) {
            __inorder(root->left);
            printf("%d ", root->key);
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
    
    void __rk(BSTNode* root, int& cur, int value, int& res) {
    if (root == NULL) {
        return;
    }
    __rk(root->left, cur, value, res);
    cur++;
    if (cur == value) {
        res = root->key;
        return;
    }
    __rk(root->right, cur, value, res);
}
    
    bool __ph(BSTNode* root, int value, string str) {
	    if (root == NULL) return false;
	    
	    if (root->key == value) {
	        cout << str << "S" << endl;
	        return true;
	    }
	    if(__ph(root->left, value, str + "L")) return true;
	    if(__ph(root->right, value, str + "R")) return true;
	    
	    return false;
	}
};

int main() {
    BST set;
    set.init();
	
	while(1) {
		int n;
		string str;
		cin >> str;
		
		if(str == "IN") {
            cin >> n;
            set.insert(n);
        }
        else if(str == "FD") {
            cin >> n;
            set.fd(n);
        }
        else if(str == "RK") {
            cin >> n;
            set.rk(n);
        }
        else if(str == "PH") {
            cin >> n;
            set.ph(n);
        }
        else {
        	cout << "done\n";
        	return 0;
		}
	}
}