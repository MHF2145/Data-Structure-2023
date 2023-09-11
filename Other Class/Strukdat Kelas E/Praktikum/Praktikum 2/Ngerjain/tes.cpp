#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode_t {
    int key;
    struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(1000 * sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key) root->left = __bst__insert(root->left, value);
    else if (value > root->key) root->right = __bst__insert(root->right, value);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key) root = root->left;
        else if (value > root->key) root = root->right;
        else return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL) currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) root->right = __bst__remove(root->right, value);
    else if (value < root->key) root->left = __bst__remove(root->left, value);
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

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

int leftLeaves(BSTNode* root) {
    int sum = 0;
    // If root is NULL, return 0
    if (root == NULL) {
        return 0;
    }
    // If the left child of root is a leaf node, add its value to the sum
    if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
        sum += root->left->key;
    }
    // Recursively calculate the sum of all left leaf nodes in the left and right subtrees
    sum += leftLeaves(root->left);
    sum += leftLeaves(root->right);
    // Return the final sum
    return sum;
}

int sumRightLeaves(BSTNode* root) {
    int sum = 0;
    // If root is NULL, return 0
    if (root == NULL) {
        return 0;
    }
    // If the left child of root is a leaf node, add its value to the sum
    if (root->right != NULL && root->right->left == NULL && root->right->right == NULL) {
        sum += root->right->key;
    }
    // Recursively calculate the sum of all left leaf nodes in the left and right subtrees
    sum += sumRightLeaves(root->left);
    sum += sumRightLeaves(root->right);
    // Return the final sum
    return sum;
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
    else return false;
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

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

bool cekRoot(BSTNode *root) {
    if (root == NULL)   // empty tree
        return false;
    if (root->left == NULL && root->right == NULL)   // single node tree
        return true;
    else return false;
}

int main(){
    BST set;
    bst_init(&set);
    int b;
    char find;
    while (1){
        scanf("%d ", &b);
        if(b == -1) break;
        else bst_insert(&set, b);
    }
    scanf("%c", &find);
    if (find == 'L'){
        if (cekRoot(set._root)){
            printf("gaada pak!");
        }
        else if (!leftLeaves(set._root)){
            printf("gaada pak!");
        }
        else{
            printf("%d", leftLeaves(set._root));
        }
        
    }
    else if (find == 'R'){
        if (cekRoot(set._root)){
            printf("gaada pak!");
            
        }
        else if (!sumRightLeaves(set._root)){
            printf("gaada pak!");
        }
        else{
            printf("%d", sumRightLeaves(set._root));
        }
    }

    return 0;
}