#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* preorder(struct TreeNode* root, int target) {
    if (root == NULL) return NULL;
    if (root->val == target) return root;
    
    struct TreeNode* lres = preorder(root->left, target);
    if (lres != NULL) return lres;

    struct TreeNode* rres = preorder(root->right, target);
    return rres;
}

struct TreeNode* inorder(struct TreeNode* root, int target) {
    if (root == NULL) return NULL;
    
    struct TreeNode* lres = inorder(root->left, target);
    if (lres != NULL) return lres;

    if (root->val == target) return root;

    struct TreeNode* rres = inorder(root->right, target);
    return rres;
}

struct TreeNode* postorder(struct TreeNode* root, int target) {
    if (root == NULL) return NULL;

    struct TreeNode* lres = postorder(root->left, target);
    if (lres != NULL) return lres;

    struct TreeNode* rres = postorder(root->right, target);
    if (rres != NULL) return rres;

    if (root->val == target) return root;

    return NULL;
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int target = 5;

    struct TreeNode* pre_res = preorder(root, target);
    if (pre_res != NULL) printf("preorder -> node %d ditemukan\n", target);
    else printf("preorder -> node %d tidak ditemukan\n", target);

    struct TreeNode* in_res = inorder(root, target);
    if (in_res != NULL) printf("inorder -> node %d ditemukan\n", target);
    else printf("inorder -> node %d tidak ditemukan\n", target);

    struct TreeNode* post_res = postorder(root, target);
    if (post_res != NULL) printf("postorder -> node %d ditemukan\n", target);
    else printf("postorder -> node %d tidak ditemukan\n", target);

    return 0;
}