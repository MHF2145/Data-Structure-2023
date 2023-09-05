#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int check(Node *root, int min, int max)
{
    if (!root)
        return true;
    if (root->data > min && root->data < max)
    {
        bool left = check(root->left, min, root->data);
        bool right = check(root->right, root->data, max);
        return left && right;
    }
    else
        return false;

    bool isBST(Node * root)
    {
        return check(root, INT_MIN, INT_MAX);
    }
}

void tv(Node *root, int ind, int level, map<int, pair<int, int>> &m)
{
    if (root == 0)
        return;
    if (m[ind].second == 0)
    {
        m[ind].second = root->data;
        m[ind].first = level;
    }
    else
    {
        if (m[ind].first > level)
        {
            m[ind].first = level;
            m[ind].second = root->data;
        }
    }
    tv(root->left, ind - 1, level + 1, m);
    tv(root->right, ind + 1, level + 1, m);
}

vector<int> topView(Node *root)
{
    vector<int> ans;
    map<int, pair<int, int>> m;
    tv(root, 0, 0, m);
    for (auto i : m)
        ans.push_back(i.second.second);
    return ans;
}