#include <iostream>
#include <string>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) 
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) 
{
    if (root == NULL) 
	{
        root = createNode(data);
        return root;
    }
    else if (data <= root->data) 
	{
        root->left = insert(root->left, data);
    }
    else 
	{
        root->right = insert(root->right, data);
    }
    return root;
}

void findParent(Node* root, int data) 
{
    Node* parent = NULL;
    while (root != NULL) 
	{
        if (root->data == data) 
		{
            break;
        }
        else if (data <= root->data) 
		{
            parent = root;
            root = root->left;
        }
        else 
		{
            parent = root;
            root = root->right;
        }
    }
    if (root == NULL) 
	{
        cout << "Orphanage, here it comes" << endl;
    }
    else if (parent == NULL) 
	{
        cout << "Orphanage, here it comes" << endl;
    }
    else 
	{
        cout << "Child of " << parent->data << endl;
    }
}

int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
}

int orderr(Node *root, int data)
{
    int index = 0;
    Node *current = root;

    while (current != NULL)
    {
        if (current->data == data)
        {
            // found the node, return its position
            return index + countNodes(current->left) + 1;
        }
        else if (current->data > data)
        {
            // search in left subtree
            current = current->left;
        }
        else
        {
            // search in right subtree
            index += countNodes(current->left) + 1;
            current = current->right;
        }
    }

    // node not found
    return -1;
}


int main()
{
	int N;
    cin >> N;
    Node* root = NULL;
    for (int i = 0; i < N; i++) 
	{
        string command;
        cin >> command;
        if (command == "Insert") 
		{
            int data;
            cin >> data;
            root = insert(root, data);
            countNodes(root);
        }
        else if (command == "Parent") 
		{
            int data;
            cin >> data;
            findParent(root, data);
        }
        else if (command == "Order") 
		{
            int data;
            cin >> data;
            int index = orderr(root, data);
            if (index == 0) 
			{
                cout << "Orphanage, here it comes" << endl;
            }
            else 
			{
                cout << "Order : " << index << endl;
            }
        }
    }
    return 0;
}
