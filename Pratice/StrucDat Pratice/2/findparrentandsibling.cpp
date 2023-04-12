//Soal dari mas Afif
#include <bits/stdc++.h>
using namespace std;

struct Oke
{
	int data;
	struct Oke *left, *right;
	Oke(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

// Recursive function to find the
// parent of the given oke
void findParent(struct Oke* oke,int val, int parent)
{
	if (oke == NULL)
		return;

	// If current oke is the required oke
	if (oke->data == val) {

		// Print its parent
		cout << "Parents:" << parent << std::endl;;
	}
	else
    {

		// Recursive calls for the children
		// of the current oke
		// Current oke is now the new parent
		findParent(oke->left, val, oke->data);
		findParent(oke->right, val, oke->data);
	}
}

// Structure of a node of N-ary tree
struct Node
{
	int key;
	vector<Node*> child;
};

// Function to create a new node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	return temp;
}

// Function to find the siblings
// of the node value
void Siblings(Node* root, int value)
{
	int flag = 0;

	if (root == NULL)
		return;

	// Stores nodes level wise
	queue<Node*> q;

	// Push the root
	q.push(root);

	cout << "Siblings:";

	// Continue until all levels
	// are traversed
	while (!q.empty())
    {

		// Stores current node
		Node* temp = q.front();
		q.pop();

		// Enqueue all children of the current node
		for (int i = 0; i < temp->child.size(); i++)
        {

			// If node value is found
			if (temp->child[i]->key == value)
            {

				flag = 1;

				// Print all children of current node
				// except value as the answer
				for (int j = 0; j < temp->child.size();
					j++)
                {
					if (value!= temp->child[j]->key)
						cout << temp->child[j]->key << " ";
				}
				break;
			}

			// Push the child nodes
			// of temp into the queue
			q.push(temp->child[i]);
		}
	}

	if (flag == 0)
		cout << "No siblings!!";
}

Node* constructTree()
{
	Node* root = newNode(1);
	(root->child).push_back(newNode(2));

	(root->child).push_back(newNode(3));

	(root->child).push_back(newNode(4));

	(root->child[0]->child).push_back(newNode(5));

	(root->child[0]->child).push_back(newNode(6));

	(root->child[1]->child).push_back(newNode(7));

	(root->child[1]->child).push_back(newNode(8));

	(root->child[2]->child).push_back(newNode(9));

	(root->child[2]->child).push_back(newNode(10));

	(root->child[2]->child).push_back(newNode(11));

	return root;
}

// Driver Code
int main()
{

	// Stores root of the
	// constructed tree
	Node* root = constructTree();

	int X;
    printf("Input the number of the tree: ");
    scanf("%d", &X);

    struct Oke* akar = new Oke(1);
	akar->left = new Oke(2);
	akar->right = new Oke(3);
	akar->left->left = new Oke(4);
	akar->left->right = new Oke(5);
	int oke = X;

	findParent(akar, oke, -1);

	// Print siblings of Node X
	Siblings(root, X);


	return 0;

}
