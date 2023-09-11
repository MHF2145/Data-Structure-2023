#include <iostream>
#include <queue>
using namespace std;

struct Node 
{
    int val;
    int left_size;
    Node *left, *right;

    Node(int v) 
	{
        val = v;
        left_size = 0;
        left = right = NULL;
    }
};

void insert(Node *&root, int value) 
{
    if (root == NULL) 
	{
        root = new Node(value);
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) 
	{
        Node* curr = q.front();
        q.pop();

        if (value <= curr->val) 
		{
            curr->left_size++;
            if (curr->left == NULL) 
			{
                curr->left = new Node(value);
                return;
            }
            else 
			{
                q.push(curr->left);
            }
        }
        else 
		{
            if (curr->right == NULL) 
			{
                curr->right = new Node(value);
                return;
            }
            else 
			{
                q.push(curr->right);
            }
        }
    }
}

int find(Node *root, int value) 
{
    while (root != NULL) 
	{
        if (value == root->val) 
		{
            return root->left_size + 1;
        } 
        else if (value < root->val) 
		{
            root = root->left;
        } 
        else 
		{
            int right_pos = find(root->right, value);
            if (right_pos == -1) 
			{
                return -1;
            } 
            else 
			{
                return root->left_size + 1 + right_pos;
            }
        }
    }
    return -1;
}

int main() 
{
    int N;
    cin >> N;

    Node *root = NULL;

    for (int i = 0; i < N; i++) 
	{
        char CA;
        int A;
        cin >> CA >> A;

        if (CA == 'T') 
		{
            insert(root, A);
        } 
        else 
		{
            int pos = find(root, A);
            cout << pos << endl;
        }
    }

    return 0;
}

