//DAH DAH SEKARANG WAKTUNYA NGUMPULIN JADE BUAT GACHA SILVERWOLF CHAN!!!
#include <bits/stdc++.h>
#include <unordered_set>

struct bintreeNode
{
    bintreeNode *left, *right;
    int key;
};

struct bintree
{
    bintreeNode *_root;

    void init()
    {
        _root = NULL;
    }

    void insert(int value)
    {
        _root = __insert(_root, value);
    }

    void traverseRightChild()
    {
        if (_root == NULL)
            return;
        std::queue<bintreeNode *> q;
        q.push(_root);

        while (!q.empty())
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                bintreeNode *temp = q.front();
                q.pop();

                if (i == n - 1)
                    std::cout << temp->key << std::endl;

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
    }

private:
    bintreeNode *__createNode(int value)
    {
        bintreeNode *newNode = new bintreeNode;
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    bintreeNode *__insert(bintreeNode *root, int value)
    {
        if (root == NULL)
            return __createNode(value);

        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);

        return root;
    }
};

void reinforceNodes(bintreeNode *node, std::unordered_set<int> &reinforcedNodes);

int main()
{
    bintree set;
    set.init();

    int numnode;
    while (std::cin >> numnode)
    {
        set.insert(numnode);
    }

    std::unordered_set<int> reinforcedNodes;
    while (std::cin >> numnode)
    {
        if (numnode == -1)
        {
            break;
        }
        reinforcedNodes.insert(numnode);
    }

    set.traverseRightChild();
    reinforceNodes(set._root, reinforcedNodes);

    return 0;
}

void reinforceNodes(bintreeNode *node, std::unordered_set<int> &reinforcedNodes)
{
    if (node == nullptr)
    {
        return;
    }

    if (reinforcedNodes.find(node->key) != reinforcedNodes.end())
    {
        std::cout << node->key << std::endl;
    }

    reinforceNodes(node->left, reinforcedNodes);
    reinforceNodes(node->right, reinforcedNodes);
}
