#include <iostream>
#define SPACE 10
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int a)
    {
        value = a;
        left = NULL;
        right = NULL;
    }
};

class AVLTree
{
public:
    TreeNode *root;
    AVLTree()
    {
        root = NULL;
    }
    bool isTreeEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Get Height
    int height(TreeNode *r)
    {
        if (r == NULL)
        {
            return -1;
        }
        else
        {
            /*compute the height of each subtree*/
            int lheight = height(r->left);
            int rheight = height(r->right);

            /*use the larger one*/
            if (lheight > rheight)
            {
                return (lheight + 1);
            }
            else
            {
                return (rheight + 1);
            }
        }
    }

    // Get balance factor of node N
    int getBalanceFactor(TreeNode *n)
    {
        if (n == NULL)
        {
            return -1;
        }
        return height(n->left) - height(n->right);
    }

    TreeNode *rightRotate(TreeNode *y)
    {
        TreeNode *x = y->left;
        TreeNode *T2 = x->right;

        // perform rotation
        x->right = y;
        y->left = T2;

        return x;
    }

    TreeNode *leftRotate(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;

        // perform rotation
        y->left = x;
        x->right = T2;

        return y;
    }

    TreeNode *insert(TreeNode *r, TreeNode *newNode)
    {
        if (r == NULL)
        {
            r = newNode;
            cout << "Value inserted successfully" << endl;
            return r;
        }

        if (newNode->value < r->value)
        {
            r->left = insert(r->left, newNode);
        }
        else if (newNode->value > r->value)
        {
            r->right = insert(r->right, newNode);
        }
        else
        {
            cout << "No duplicate values allowed!" << endl;
            return r;
        }

        int bf = getBalanceFactor(r);
        // Left-Left Case
        if (bf > 1 && newNode->value < r->left->value)
        {
            return rightRotate(r);
        }

        // Right-Right Case
        if (bf < -1 && newNode->value < r->left->value)
        {
            leftRotate(r);
        }

        // Left-Right Case
        if (bf > 1 && newNode->value > r->left->value)
        {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }

        // Right-Left Case
        if (bf < -1 && newNode->value < r->right->value)
        {
            r->left = rightRotate(r->right);
            return leftRotate(r);
        }

        /*return the (unchanged) node pointer*/
        return r;
    }

    TreeNode *minValueNode(TreeNode *node)
    {
        TreeNode *current = node;
        /* loop down to find the leftmost leaf */
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    TreeNode *deleteNode(TreeNode *r, int v)
    {
        // Base Case
        if (r == NULL)
        {
            return NULL;
        }
        // if the key to be deleted is smaller than the root's key yhen it lies in left subtree
        else if (v < r->value)
        {
            r->left = deleteNode(r->left, v);
        }
        // if the key to be deleted is greater than the root's key, then it lies in right subtree
        else if (v > r->value)
        {
            r->right = deleteNode(r->right, v);
        }
        // if key is same as root's key, then This is the node to be deleted
        else
        {
            // node with only one child or no child
            if (r->left == NULL)
            {
                TreeNode *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                TreeNode *temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                // node with two children: Get the inorder succeccor (smallest in the rihgt subtree)
                TreeNode *temp = minValueNode(r->right);
                // Copy the inorder successor's content to this node
                r->value = temp->value;
                // Delete the inorder successor
                r->right = deleteNode(r->right, temp->value);
            }
        }

        int bf = getBalanceFactor(r);
        // Left-Left Imbalance/Case or Right rotation
        if (bf == 2 && getBalanceFactor(r->left) >= 0)
        {
            return rightRotate(r);
        }
        // Right-Right Imbalance/Case or Left rotation
        else if (bf == -2 && getBalanceFactor(r->right) <= 0)
        {
            return leftRotate(r);
        }
        // Left-Right Imbalance/Case or LR rotation
        else if (bf == 2 && getBalanceFactor(r->left) == -1)
        {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }
        // Right-Left Imbalance/Case or RL rotation
        else if (bf == -2 && getBalanceFactor(r->right) == 1)
        {
            r->right - rightRotate(r->right);
            return leftRotate(r);
        }

        return r;
    }

    void print2D(TreeNode *r, int space)
    {
        // Base Case
        if (r == NULL)
        {
            return;
        }
        // Increase distance between levels 2
        space += SPACE;
        // Process right child first 3
        print2D(r->right, space);
        // 4
        cout << endl;
        // 5
        for (int i = SPACE; i < space; i++)
        {
            // 5.1
            cout << " ";
        }
        // 6
        cout << r->value << "\n";
        // Process left child7
        print2D(r->left, space);
    }
    //(current node, left, right)
    void PreOrder(TreeNode *r)
    {
        if (r == NULL)
        {
            return;
        }
        /* first print data of node */
        cout << r->value << " ";
        /* ther ercur on left subtree */
        PreOrder(r->left);
        /* now recur on fight subtree */
        PreOrder(r->right);
    }
    //(left, current node, right)
    void InOrder(TreeNode *r)
    {
        if (r == NULL)
        {
            return;
        }
        /* first recur on left child */
        InOrder(r->left);
        /* then print the data of node */
        cout << r->value << " ";
        /* now recur on right child */
        InOrder(r->right);
    }
    //(left, right, root)
    void PostOrder(TreeNode *r)
    {
        if (r == NULL)
        {
            return;
        }
        /* first recur on left subtree */
        PostOrder(r->left);
        /* then recur on right subtree */
        PostOrder(r->right);
        /* now deal with the node */
        cout << r->value << " ";
    }

    /* Print nodes at a given level */
    void GivenLevel(TreeNode *r, int level)
    {
        if (r == NULL)
        {
            return;
        }
        else if (level == 0)
        {
            cout << r->value << " ";
        }
        // level > 0
        else
        {
            GivenLevel(r->left, level - 1);
            GivenLevel(r->right, level + 1);
        }
    }

    void LevelOrderBFS(TreeNode *r)
    {
        int h = height(r);
        for (int i = 0; i <= h; i++)
        {
            GivenLevel(r, i);
        }
    }

    TreeNode *iterativeSearch(int a)
    {
        if (root == NULL)
        {
            return root;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (a == temp->value)
                {
                    return temp;
                }
                else if (a < temp->value)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }

    TreeNode *recursiveSearch(TreeNode *r, int val)
    {
        if (r == NULL || r->value == val)
        {
            return r;
        }
        else if (val < r->value)
        {
            return recursiveSearch(r->left, val);
        }
        else
        {
            return recursiveSearch(r->right, val);
        }
    }
};

int main()
{
    AVLTree node;
    int option, val;

    do
    {
        cout << "What operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal AVL Tree values" << endl;
        cout << "5. Height of Tree" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;
        cin.ignore();
        // Node n1
        TreeNode *newNode = new TreeNode();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "AVL INSERT" << endl;
            cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
            cin >> val;
            newNode->value = val;
            node.root = node.insert(node.root, newNode);
            cout << endl;
            break;
        case 2:
            cout << "SEARCH" << endl;
            cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
            cin >> val;
            // newNode = node.iterativeSearch(val);
            newNode = node.recursiveSearch(node.root, val);
            if (newNode != NULL)
            {
                cout << "Value found" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        case 3:
            cout << "DELETE" << endl;
            cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
            cin >> val;
            newNode = node.recursiveSearch(node.root, val);
            if (newNode != NULL)
            {
                node.root = node.deleteNode(node.root, val);
                cout << "Value Deleted" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        case 4:
            cout << "PRINT 2D: " << endl;
            node.print2D(node.root, 5);
            cout << endl;
            // cout <<"Print Level Order BFS: \n";
            // node.LevelOrderBFS(node.root);
            // cout <<endl;
            //	      cout <<"PRE-ORDER: ";
            //	      node.Preorder(node.root);
            //	      cout<<endl;
            //	      cout <<"IN-ORDER: ";
            //	      node.Inorder(node.root);
            //	      cout<<endl;
            //	      cout <<"POST-ORDER: ";
            //	      node.Postorder(node.root);
            break;
        case 5:
            cout << "TREE HEIGHT" << endl;
            cout << "Height : " << node.height(node.root) << endl;
            break;
        case 6:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }
    } while (option != 0);

    return 0;
}