//Bismillah ngga TLE, btw mas makan ramen instant pagi-pagi enak juga
#include <bits/stdc++.h>

struct bintreeNode
{
    bintreeNode *left, *right;
    int key;
};

/* uniquebintree */

struct bintree
{
    // Member
    bintreeNode *_root;
    unsigned int _size;

    // Function
    void init()
    {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty()
    {
        return _root == NULL;
    }

    bool cari(int value)
    {
        bintreeNode *temp = __search(_root, value);
        if (!temp)
            return false;

        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value)
    {
        if (!cari(value))
        {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void remove(int value)
    {
        if (cari(value))
        {
            _root = __remove(_root, value);
            _size--;
        }
    }

    void traverseInorder()
    {
        __inorder(_root);
    }

    void traversePreorder()
    {
        __preorder(_root);
    }

    void traversePostorder()
    {
        __postorder(_root);
    }

    int getLevel(bintreeNode *node, int data, int level = 1)
    {
        if (node == NULL)
            return 0;

        if (data == node->key)
            return level;

        if (data < node->key)
            return getLevel(node->left, data, level + 1);
        else
            return getLevel(node->right, data, level + 1);
    }

    int rk(int x)
    {
        int count = 0;
        return __rk(_root, x, count);
    }

    void ph(int x)
    {
        __ph(_root, x);
        std::cout << "S" << std::endl;
    }

private:
    // Utility Function
    bintreeNode *__createNode(int value)
    {
        bintreeNode *newNode = (bintreeNode *)malloc(sizeof(bintreeNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    bintreeNode *__search(bintreeNode *root, int value)
    {
        while (root != NULL)
        {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
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

    bintreeNode *__cariMinNode(bintreeNode *node)
    {
        bintreeNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;

        return currNode;
    }

    bintreeNode *__remove(bintreeNode *root, int value)
    {
        if (root == NULL)
            return NULL;

        if (value > root->key)
            root->right = __remove(root->right, value);
        else if (value < root->key)
            root->left = __remove(root->left, value);
        else
        {

            if (root->left == NULL)
            {
                bintreeNode *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL)
            {
                bintreeNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            bintreeNode *temp = __cariMinNode(root->right);
            root->key = temp->key;
            root->right = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(bintreeNode *root)
    {
        if (root)
        {
            __inorder(root->left);
            printf("%d ", root->key);
            __inorder(root->right);
        }
    }

    void __postorder(bintreeNode *root)
    {
        if (root)
        {
            __postorder(root->left);
            __postorder(root->right);
            printf("%d ", root->key);
        }
    }

    void __preorder(bintreeNode *root)
    {
        if (root)
        {
            printf("%d ", root->key);
            __preorder(root->left);
            __preorder(root->right);
        }
    }

    int __rk(bintreeNode *node, int x, int &count)
    {
        if (node == NULL)
            return count;

        count = __rk(node->left, x, count);
        count++;

        if (count == x)
        {
            std::cout << node->key << std::endl;
            return count;
        }

        return __rk(node->right, x, count);
    }

    void __ph(bintreeNode *node, int x)
    {
        if (!node)
            return;

        if (x < node->key)
        {
            std::cout << "L";
            __ph(node->left, x);
        }
        else if (x > node->key)
        {
            std::cout << "R";
            __ph(node->right, x);
        }
    }
};

int main()
{
    bintree bintree;
    bintree.init();
    std::string perintah;
    int x;

    std::cin >> perintah;
    while (perintah != "STOP")
    {
        if (perintah == "IN")
        {
            std::cin >> x;
            if (!bintree.cari(x))
                bintree.insert(x);
        }
        else if (perintah == "FD")
        {
            std::cin >> x;
            if (bintree.cari(x))
            {
                int level = bintree.getLevel(bintree._root, x);
                std::cout << "on level " << level << std::endl;
            }
            else
                std::cout << "no " << x << std::endl;
        }
        else if (perintah == "RK")
        {
            std::cin >> x;
            if (x == 0)
                std::cout << -1 << std::endl;
            else if (x <= (int)bintree._size)
            {
                int count = 0;
                bintree.rk(x);
            }
            else
            {
                std::cout << -1 << std::endl;
            }
        }
        else if (perintah == "PH")
        {
            std::cin >> x;
            if (bintree.cari(x))
            {
                bintree.ph(x);
            }
            else
                std::cout << "no " << x << std::endl;
        }

        std::cin >> perintah;
    }
    std::cout << "done" << std::endl;

    return 0;
}
