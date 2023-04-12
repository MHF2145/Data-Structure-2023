// C++ implementation of the approach
#include <iostream>
using namespace std;

/* A binary tree oke has data, pointer
to left child and a pointer
to right child */
struct Oke {
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
void findParent(struct Oke* oke,
				int val, int parent)
{
	if (oke == NULL)
		return;

	// If current oke is the required oke
	if (oke->data == val) {

		// Print its parent
		cout << parent;
	}
	else {

		// Recursive calls for the children
		// of the current oke
		// Current oke is now the new parent
		findParent(oke->left, val, oke->data);
		findParent(oke->right, val, oke->data);
	}
}

// Driver code
int main()
{
	struct Oke* akar = new Oke(1);
	akar->left = new Oke(2);
	akar->right = new Oke(3);
	akar->left->left = new Oke(4);
	akar->left->right = new Oke(5);
	int oke = 3;

	findParent(akar, oke, -1);

	return 0;
}
