#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Node 
{
    int val;
    Node* left, * right;
};

Node* makeNode(int val) 
{
    Node* node = new Node();
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* node, int key) 
{
    if (node == NULL) 
	{
        return makeNode(key);
    }
    
    
    if (key < node->val) 
	{
        node->left = insert(node->left, key);
    }
    
    else if (key > node->val) 
	{
        node->right = insert(node->right, key);
    }
    else return node;

    return node;
}

int getlevel(Node* node, int key, int level) 
{
    if (node == NULL) 
	{
        return -1;
    }

    if (key == node->val) 
	{
        return level;
    }

    if (key < node->val) 
	{
        return getlevel(node->left, key, level + 1);
    }
    
    else 
	{
        return getlevel(node->right, key, level + 1);
    }
}

void printpath(string path) 
{
    if (path.empty()) 
	{
        cout << "S" << endl;
        return;
    }
    cout << path << "S" << endl;
}

void search4path(Node* node, int key, string path, bool& found) 
{
    if (node == NULL) return;

    if (key == node->val) 
	{
        found = true;
        printpath(path);
        return;
    }

    if (key < node->val) 
	{
        search4path(node->left, key, path + "L", found);
    }
    
    else 
	{
        search4path(node->right, key, path + "R", found);
    }
}

int RKnumber(Node* node, int k, int& count) 
{
    if (node == NULL) 
	{
        return -1;
    }

    int leftResult = RKnumber(node->left, k, count);
    if (leftResult != -1) 
	{
        return leftResult;
    }

    count++;
    if (count == k) 
	{
        return node->val;
    }

    return RKnumber(node->right, k, count);
}

int main() 
{
    Node* root = NULL;
    int x;
    string Command;
    while (cin >> Command) 
	{
        if (Command == "IN") 
		{
            cin >> x;
            root = insert(root, x);
        }
        
        else if (Command == "FD") 
		{
            cin >> x;
            int level = getlevel(root, x, 1);
            if (level != -1) 
			{
                cout << "on level " << level << endl;
            }
            
            else 
			{
                cout << "no " << x << endl;
            }
        }
        
        else if (Command == "RK") 
		{
            cin >> x;
            int count = 0;
            int result = RKnumber(root, x, count);
            if (result != -1) 
			{
                cout << result << endl;
            }
            
            else 
			{
                cout << "-1" << endl;
            }
        }
        
        else if (Command == "PH") 
		{
            cin >> x;
            bool found = false;
            search4path(root, x, "", found);
            if (!found) 
			{
                cout << "no " << x << endl;
            }
        }
        else if (Command == "STOP") 
		{
            cout << "done" << endl;
            break;
        }
    }

    return 0;
}
