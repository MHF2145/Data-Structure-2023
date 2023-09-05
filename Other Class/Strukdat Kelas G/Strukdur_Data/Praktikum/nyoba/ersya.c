
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int item)
{
	struct Node* temp
		= (struct Node*)malloc(
			sizeof(struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

void modifyBSTUtil(
	struct Node* root, int* sum)
{
	if (root == NULL)
		return;

	modifyBSTUtil(root->right, sum);

	*sum = *sum + root->data;
	root->data = *sum;

	modifyBSTUtil(root->left, sum);
}

void modifyBST(struct Node* root)
{
	int sum = 0;
	modifyBSTUtil(root, &sum);
}

void inorder(struct Node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

struct Node* insert(
	struct Node* node, int data)
{
	if (node == NULL)
		return newNode(data);

	if (data <= node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);

	return node;
}

int main()
{
	struct Node* root = NULL;
    int a;
    while (scanf("%d", &a) != EOF)
    {
        root = insert(root, a);
    }
    
	modifyBST(root);

	inorder(root);

	return 0;
}
