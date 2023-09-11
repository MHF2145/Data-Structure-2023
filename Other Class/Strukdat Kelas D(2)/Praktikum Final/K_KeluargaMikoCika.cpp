#include <bits/stdc++.h> 
#include <queue>
using namespace std;

typedef struct bstnode_t 
{
    int key;
    struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t 
{
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __insert(BSTNode *root, int val) 
{
    if (root == NULL) 
	{
        BSTNode *node = (BSTNode*)malloc(sizeof(BSTNode));
        node->key = val;
        node->left = NULL;
        node->right = NULL;

        return node;
    }

    if (val < root->key) 
	{
        root->left = __insert(root->left, val);
    } 
	
	else if (val > root->key) 
	{
        root->right = __insert(root->right, val);
    }

    return root;
}

BSTNode* __search(BSTNode *root, int val) 
{
    while (root != NULL) 
	{
        if (val < root->key) 
		{
            root = root->left;
        }
        
        else if (val > root->key) 
		{
            root = root->right;
        }
        
		else 
		{
            return root;
        }
    }

    return root;
}

bool bst_find(BST *bst, int val) 
{
    BSTNode *temp = __search(bst->_root, val);
    if (temp == NULL) 
	{
        return false;
    }

    if (temp->key == val) 
	{
        return true;
    }
    
    else 
	{
        return false;
    }
}

void bst_insert(BST *bst, int val) 
{
    if (!bst_find(bst, val)) 
	{
        bst->_root = __insert(bst->_root, val);
        bst->_size++;
    }
}


bool is_possible(BST *bst, int checker) 
{
    queue<BSTNode*> q;
    if (bst->_root == NULL) 
	{
        return false;
    }

    q.push(bst->_root);

    while (!q.empty()) 
	{
        BSTNode *node = q.front();
        q.pop();

        // 3 nodes
        // -------
        // current + left + left_left
        if (node->left != NULL && node->left->left != NULL && (node-> key + node->left->key + node->left->left->key == checker)) 
		{
            return true;
        }
        
            // current + left + left_right
        else if (node->left != NULL && node->left->right != NULL && (node-> key + node->left->key + node->left->right->key == checker)) 
		{
           	return true;
        }
        	
            // current + left + right
        else if (node->left != NULL && node->right != NULL && (node-> key + node->left->key + node->right->key == checker)) 
		{
           	return true;
        }
        	
            // current + right + right_right
        else if (node->right != NULL && node->right->right != NULL && (node-> key + node->right->key + node->right->right->key == checker)) 
		{
            return true;
        }
        
            // current + right + right_left
        else if (node->right != NULL && node->right->left != NULL && (node-> key + node->right->key + node->right->left->key == checker)) 
		{
            return true;
        }

        if (node->left != NULL) 
		{
            q.push(node->left);
        }
        
        if (node->right != NULL) 
		{
            q.push(node->right);
        }
    }

    return false;
}

int main() 
{
    BST* bst = (BST*) malloc(sizeof(BST));
    bst->_root = NULL;
	
	int n, k;
    cin >> n;

    for (int i = 0; i < n; ++i) 
	{
		int p;
        cin >> p;
        bst_insert(bst, p);
    }

    cin >> k;

    bool possible = is_possible(bst, k);

    if (possible) 
	{
        printf("%d Selamat! Kalian menemukan harta karunnya\n", k);
    } 
	
	else 
	{
        printf("%d Tidak ada kombinasi yang tepat! Bikin ulang.\n", k);
    }

    return 0;
}
