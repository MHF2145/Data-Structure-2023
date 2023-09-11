#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *root;

    Node *insertNode(Node *root, int val)
    {
        if (root == nullptr)
        {
            return new Node(val);
        }

        if (val < root->data)
        {
            root->left = insertNode(root->left, val);
        }
        else if (val > root->data)
        {
            root->right = insertNode(root->right, val);
        }

        return root;
    }

    int findLevel(Node *root, int val, int level)
    {
        if (root == nullptr)
        {
            return -1;
        }

        if (val == root->data)
        {
            return level;
        }

        if (val < root->data)
        {
            return findLevel(root->left, val, level + 1);
        }
        else
        {
            return findLevel(root->right, val, level + 1);
        }
    }

    int findKth(Node *root, int k, int &count)
    {
        if (root == nullptr)
        {
            return -1;
        }

        int left = findKth(root->left, k, count);
        if (left != -1)
        {
            return left;
        }

        count++;
        if (count == k)
        {
            return root->data;
        }

        return findKth(root->right, k, count);
    }

   string getPath(Node* root, int value) {
        if (root == nullptr) {
            return "";
        }

        if (root->data == value) {
            return "S";
        }

        if (value < root->data) {
            string leftPath = getPath(root->left, value);
            if (leftPath != "") {
                return "L" + leftPath;
            }
        } else {
            string rightPath = getPath(root->right, value);
            if (rightPath != "") {
                return "R" + rightPath;
            }
        }

        return "";
    }
public:
    BST() : root(nullptr) {}

    void insert(int val)
    {
        root = insertNode(root, val);
    }

    void find(int val)
    {
        int level = findLevel(root, val, 1);
        if (level != -1)
        {
            cout << "on level " << level << endl;
        }
        else
        {
            cout << "no " << val << endl;
        }
    }

    void findKth(int k)
    {
        int count = 0;
        int result = findKth(root, k, count);
        cout << result << endl;
    }

    void findPath(int val)
    {
        string path = getPath(root, val);
        if (path != "") {
            cout << path << endl;
        } else {
            cout << "no " << val << endl;
        }
    }
};

int main()
{
    BST bst;

    string line;
    while (getline(cin, line))
    {
        stringstream ss(line);
        string cmd;
        ss >> cmd;

        if (cmd == "IN")
        {
            int val;
            ss >> val;
            bst.insert(val);
        }
        else if (cmd == "FD")
        {
            int val;
            ss >> val;
            bst.find(val);
        }
        else if (cmd == "RK")
        {
            int k;
            ss >> k;
            bst.findKth(k);
        }
        else if (cmd == "PH")
        {
            int val;
            ss >> val;
            bst.findPath(val);
        }
        else if (cmd == "STOP")
        {
            cout << "done" << endl;
            break;
        }
    }

    return 0;
}
