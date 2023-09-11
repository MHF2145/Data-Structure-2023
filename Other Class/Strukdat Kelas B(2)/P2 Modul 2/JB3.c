#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
	int data;
	struct BSTNode* left;
	struct BSTNode* right;
} BSTNode;

BSTNode* createNode(int data) {
	BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BSTNode* insert(BSTNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }

    return root;
}

void calculateSum(BSTNode* root, int* sum) {
	if (root == NULL) {
		return;
    }

	calculateSum(root->right, sum);
	*sum = *sum + root->data;
	root->data = *sum;
	calculateSum(root->left, sum);
}

void modifyBST(BSTNode* root) {
	int sum = 0;
	calculateSum(root, &sum);
}

// A utility function to print inorder traversal of Binary Tree
void printInorder(BSTNode* node) {
	if (node == NULL) {
		return;
    }
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}

// Driver program to test above function
int main() {
    int x;
    BSTNode* bst = NULL;
    while (scanf("%d", &x) != EOF) {
        bst = insert(bst, x);
    }
	modifyBST(bst);
	printInorder(bst);

	return 0;
}
