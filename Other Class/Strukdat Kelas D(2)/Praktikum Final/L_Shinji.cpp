#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* node, int value)
{
    if (node == nullptr)
    {
        return new TreeNode(value);
    }

    if (value < node->value)
    {
        node->left = insert(node->left, value);
    }
    
    else if (value > node->value)
    {
        node->right = insert(node->right, value);
    }

    return node;
}

void nilaiterbesarperlevel(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();
        int maxVal = INT_MIN;

        for (int i = 0; i < levelSize; i++)
        {
            TreeNode* current = q.front();
            q.pop();

            maxVal = std::max(maxVal, current->value);

            if (current->left)
            {
                q.push(current->left);
            }

            if (current->right)
            {
                q.push(current->right);
            }
        }

        cout << maxVal << " ";
    }
}


int main()
{
    TreeNode* root = nullptr;

    int N;
    while (cin >> N)
    {
        root = insert(root, N);
    }

    nilaiterbesarperlevel(root);
    cout << endl;

    return 0;
}


