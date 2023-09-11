#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct bstnode_t {
    int key;
    struct bstnode_t
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

void insert(int data)
{
	if(isEmpty())
	{
		root = newNode(data);
	}
	else
	{
		insert(root,data);
	}
}

int main()
{
	BSTNode b;
	int N, A; 
	string O;
	cin >> N;
	
	int i = 0;
	(for i = 0; i < N; i++)
	{
		Cin >> O, A;
		if(O == "Insert")
		{
			b.insert(A)//masukin
		}
		
		else if(O == "Parent")
		{
			//Tunjukin parentnya
		}
		
		else
		{
			//Kasih liat indeksnya
		}
	}
		
}
