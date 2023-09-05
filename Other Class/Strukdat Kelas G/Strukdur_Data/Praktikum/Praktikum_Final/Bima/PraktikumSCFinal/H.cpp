#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
using namespace std; 

typedef struct bstnode_t {
    int key, idx;
    struct bstnode_t 
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
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

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
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

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

int bst_findParent(BSTNode *bst, int value, int parent) {
    BSTNode *temp = bst;
    if (temp != NULL){
        if (value == temp->key)
            return parent;
        else if (value > temp->key)
            return bst_findParent(temp->right, value, temp->key);
        else if (value < temp->key)
            return bst_findParent(temp->left, value, temp->key);
    }
    return -1;
}

int bst_fsibling(BSTNode *bst, int value){
    BSTNode *temp = bst;
    if (temp != NULL){
        if (value == temp->right->key){
            return (temp->left == NULL ? -1 : temp->left->key);
        }
        else if (value == temp->left->key)
            return (temp->right == NULL ? -1 : temp->right->key);
        else if (value > temp->key)
            return bst_fsibling(temp->right, value);
        else if (value < temp->key)
            return bst_fsibling(temp->left, value);
    }
    return -1;
}

int level(BSTNode *root, int target, int lvl){
    if (root){
        if (root->key < target){
            return level(root->right, target, lvl + 1);
        }
        if (root->key > target){
            return level(root->left, target, lvl + 1);
        }
    }
    return lvl;
}

int id = 0; 
void cariIndex(BSTNode *root, int numb){
	if (root){
        cariIndex(root->left, numb); 
        id++; 
        if (id == numb){
        	cout << root->key << endl; 
		}
//        root->idx = ++id;
        cariIndex(root->right, numb); 
	} 
}

int searchNodeByIndex(BSTNode *node, int value){
	BSTNode* temp = __bst__search(node,  value); 
	if(temp->key == value){
		return temp->idx;
	}
	return 0;
}

bool cekPath(BSTNode *root, int a, string *str){
    *str = "";
    bool flag = 0; 
    while (root){
        if (a == root->key){
            flag = 1;
            *str += "S";
            break;
        }
        else if (a > root->key){
            *str += "R";
            root = root->right;
        }
        else if (a < root->key){
            *str += "L";
            root = root->left;
        }
    }
    return flag;
}
 
int main(){
    fastio; 
    BST set;
    bst_init(&set);
    int t;
    while (1){
    	string opr; 
    	cin >> opr; 
    	if(opr == "IN"){
    		int numb; 
    		cin >> numb; 
    		bst_insert(&set, numb);
		}
		else if (opr == "FD"){
			int numb; 
			cin >> numb; 
            if (bst_find(&set, numb)){
                int NodeLevel = level(set._root, numb, 1); 
                cout << "on level " << NodeLevel << endl;  
                continue;
            }
            cout << "no " << numb << endl; 
		}
        else if (opr == "RK"){
            int numb; 
            cin >> numb; 
            if(numb < 0 || numb > set._size){
            	cout << -1 << endl;
			}
			else {
				id = 0; 
            	cariIndex(set._root, numb);
			}
        }
        else if (opr == "PH"){
            int numb;
            cin >> numb;
           	string str;
           	if(cekPath(set._root, numb, &str)){
           		cout << str << endl; 
           		continue;
			}
			cout << "no " << numb << endl;
        }
        else {
        	cout << "done" << endl; 
        	return 0; 
		}
	}
    return 0;
}
