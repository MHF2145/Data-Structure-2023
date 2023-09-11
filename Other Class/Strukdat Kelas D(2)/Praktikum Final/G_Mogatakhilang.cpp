#include <iostream>
using namespace std;

typedef struct node 
{
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* newNode(int value) 
{
    Node* node = new Node;
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* node, int value) 
{
    if (node == NULL) 
	{
        return newNode(value);
    }
    
    if (value < node->data) 
	{
        node->left = insert(node->left, value);
    } 
	
	else if (value > node->data) 
	{
        node->right = insert(node->right, value);
    }
    
    return node;
}

Node* findMin(Node* root) 
{
    if (root == NULL)
	{
        return NULL;
    } 
	
	else if (root->left == NULL) 
	{
        return root;
    } 
	
	else
	{
        return findMin(root->left);
    }
}

Node* deleteNode(Node* root, int data) 
{
    if (root == NULL) 
	{
        return root;
    }

    if (data < root->data) 
	{
        root->left = deleteNode(root->left, data);
    } 
	
	else if (data > root->data) 
	{
        root->right = deleteNode(root->right, data);
    } 
	
	else 
	{
        if (root->left == NULL) 
		{
            Node* temp = root->right;
            free(root);
            return temp;
        } 
		
		else if (root->right == NULL) 
		{
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        Node* minRightSubtree = findMin(root->right);
        root->data = minRightSubtree->data;
        root->right = deleteNode(root->right, minRightSubtree->data);
    }

    return root;
}

//Make inorder traversal
void Mencaritarget(Node* root, int level, int* angkaavl, int& c)
{ 
    if (root == NULL) return;
    
    Mencaritarget(root->left, level + 1, angkaavl, c);

    if ((root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL)) 
	{
        angkaavl[c] = root->data;
        c++;
    }

    Mencaritarget(root->right, level + 1, angkaavl, c);
}

int main()
{
    Node *root = NULL;
    int n, target[100001]={0};
    cin >> n;
    for (int i = 0; i < n; i++)
	{
    	int a, b, c;
        c = 0;
        cin >> a;
        
        if (a == 15) 
		{
            cin >> b;
            root = insert(root,b);
        }
        
        else if (a == 04)
		{
            cin >> b;
            root  = deleteNode(root,b);
        }
        
        
        else if (a == 89)
		{
            Mencaritarget(root,0,target, c);
            if (c==0)
			{
                cout << "Use whatever means you must to control our population. Just do it." << endl;
            }
            
            for (int j = 0; j < c; j++)
			{
                cout << target[j] << " ";
            }
        }
    }
    return 0;
}


