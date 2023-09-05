#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct AVLNode
{
    int data, nilai;
    AVLNode *left, *right;
    int height;
};

int data_level[100][50] = {0}, pwr_level[100][50] = {0}, b = 0, kapan_mati = 0;

struct AVL
{
private:
    AVLNode *_root;
    unsigned _size;

    AVLNode *_avl_createNode(int value, int pwr)
    {
        AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->nilai = pwr;
        newNode->height = 1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    AVLNode *_search(AVLNode *root, int value)
    {
        while (root != NULL)
        {
            if (value < root->data)
                root = root->left;
            else if (value > root->data)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    int _getHeight(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int _max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    AVLNode *_rightRotate(AVLNode *pivotNode)
    {
        AVLNode *newParrent = pivotNode->left;
        pivotNode->left = newParrent->right;
        newParrent->right = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left),
                                 _getHeight(pivotNode->right)) +
                            1;
        newParrent->height = _max(_getHeight(newParrent->left),
                                  _getHeight(newParrent->right)) +
                             1;

        return newParrent;
    }

    AVLNode *_leftRotate(AVLNode *pivotNode)
    {
        AVLNode *newParrent = pivotNode->right;
        pivotNode->right = newParrent->left;
        newParrent->left = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left),
                                 _getHeight(pivotNode->right)) +
                            1;
        newParrent->height = _max(_getHeight(newParrent->left),
                                  _getHeight(newParrent->right)) +
                             1;

        return newParrent;
    }

    AVLNode *_leftCaseRotate(AVLNode *node)
    {
        return _rightRotate(node);
    }

    AVLNode *_rightCaseRotate(AVLNode *node)
    {
        return _leftRotate(node);
    }

    AVLNode *_leftRightCaseRotate(AVLNode *node)
    {
        node->left = _leftRotate(node->left);
        return _rightRotate(node);
    }

    AVLNode *_rightLeftCaseRotate(AVLNode *node)
    {
        node->right = _rightRotate(node->right);
        return _leftRotate(node);
    }

    int _getBalanceFactor(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return _getHeight(node->left) - _getHeight(node->right);
    }

    AVLNode *_insert_AVL(AVLNode *node, int value, int pwr)
    {

        if (node == NULL)
            return _avl_createNode(value, pwr);
        if (value < node->data)
            node->left = _insert_AVL(node->left, value, pwr);
        else if (value > node->data)
            node->right = _insert_AVL(node->right, value, pwr);

        node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

        int balanceFactor = _getBalanceFactor(node);

        if (balanceFactor > 1 && value < node->left->data)
            return _leftCaseRotate(node);
        if (balanceFactor > 1 && value > node->left->data)
            return _leftRightCaseRotate(node);
        if (balanceFactor < -1 && value > node->right->data)
            return _rightCaseRotate(node);
        if (balanceFactor < -1 && value < node->right->data)
            return _rightLeftCaseRotate(node);

        return node;
    }

    AVLNode *_findMinNode(AVLNode *node)
    {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }

    AVLNode *_remove_AVL(AVLNode *node, int value)
    {
        if (node == NULL)
            return node;
        if (value > node->data)
            node->right = _remove_AVL(node->right, value);
        else if (value < node->data)
            node->left = _remove_AVL(node->left, value);
        else
        {
            AVLNode *temp;
            if ((node->left == NULL) || (node->right == NULL))
            {
                temp = NULL;
                if (node->left == NULL)
                    temp = node->right;
                else if (node->right == NULL)
                    temp = node->left;

                if (temp == NULL)
                {
                    temp = node;
                    node = NULL;
                }
                else
                    *node = *temp;

                free(temp);
            }
            else
            {
                temp = _findMinNode(node->right);
                node->data = temp->data;
                node->right = _remove_AVL(node->right, temp->data);
            }
        }

        if (node == NULL)
            return node;

        node->height = _max(_getHeight(node->left), _getHeight(node->right)) + 1;

        int balanceFactor = _getBalanceFactor(node);

        if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
            return _leftCaseRotate(node);

        if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
            return _leftRightCaseRotate(node);

        if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
            return _rightCaseRotate(node);

        if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
            return _rightLeftCaseRotate(node);

        return node;
    }

    void _inorder(AVLNode *node, int a)
    {
        if (node)
        {
            printf("%d %d ", node->data, node->nilai);
            _inorder(node->left, a);
            _inorder(node->right, a);
        }
    }

    void diagonalPrint(AVLNode *root)
    {
        int j = 0, k = 0;
        if (root == NULL)
            return;

        queue<AVLNode *> q;

        q.push(root);

        q.push(NULL);

        while (!q.empty())
        {
            AVLNode *temp = q.front();
            q.pop();

            if (temp == NULL)
            {

                if (q.empty())
                    return;

                j++;
                k = 0;
                b = j;
                // cout << endl;

                q.push(NULL);
            }
            else
            {
                while (temp)
                {
                    data_level[j][k] = temp->data;
                    pwr_level[j][k] = temp->nilai;
                    // cout << data_level[j][k] << " " << pwr_level[j][k] << " " << j << " " << k << " ";
                    k++;

                    if (temp->right)
                        q.push(temp->right);

                    temp = temp->left;
                }
            }
        }
    }

public:
    void init()
    {
        _root = NULL;
        _size = 0U;
    }

    bool isEmpty()
    {
        return _root == NULL;
    }

    bool find(int value)
    {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;

        if (temp->data == value)
            return true;
        else
            return false;
    }

    void insert(int value, int pwr)
    {
        if (!find(value))
        {
            _root = _insert_AVL(_root, value, pwr);
            _size++;
        }
    }

    void remove(int value)
    {
        if (find(value))
        {
            _root = _remove_AVL(_root, value);
            _size--;
        }
    }

    void inorder(int a)
    {
        this->_inorder(_root, a);
    }

    void ngelompokin()
    {
        diagonalPrint(_root);
    }
};

bool tarung(int www)
{
    int e, c = www, d;
    for (int i = 0; i < 100; i++)
    {
        e = 0;
        for (int j = 0; j < 50; j++)
        {
            e += pwr_level[i][j];
        }
        // printf("%d", e);
        if (c % 2 == 0)
        {
            d = e * 83 / 100;
            // printf("%d [%d] (%d)\n", e, c, d);
        }
        else
        {
            d = e * 87 / 100;
            // printf("%d [%d] (%d)\n", e, c, d);
        }
        c = c - d;
        if (c < 0)
        {
            // printf("hasil saat mati: %d\n", c);
            kapan_mati = (i);
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    AVL set;
    set.init();
    char nama[100], dungeon[100];
    int jml_monster, pwr_hero, pwr_percil, key_percil;
    scanf("%s %d %d %s", nama, &jml_monster, &pwr_hero, dungeon);
    while (jml_monster--)
    {
        scanf("%d %d", &key_percil, &pwr_percil);
        set.insert(key_percil, pwr_percil);
        // printf("%d %d ", key_percil, pwr_percil);
    }
    // puts("");
    // set.inorder(50);
    set.ngelompokin();

    printf("*****************************************************************************\n");
    printf("The Abyss Game Dungeon %s (Diagonal Mode)\n", dungeon);
    printf("Traveller : %s\n", nama);
    printf("Superpower : %d - Element Unite\n", pwr_hero);
    printf("----------------------------------------------------------------------------\n");

    char huruf_monster;
    int dungeon_ke = 1, monster_ke;
    for (int i = 0; i < 100; i++)
    {
        if (data_level[i + 1][0] == 0)
        {
            break;
        }
        huruf_monster = 'A';
        monster_ke = 1;
        printf("Stage %d:\n", dungeon_ke);

        for (int k = 49; k >= 0; k--)
        {
            if (data_level[i][k] != 0)
            {
                printf("Monster %c%d_%d_%d: %d\n", huruf_monster, data_level[i][k], dungeon_ke, monster_ke, pwr_level[i][k]);
                monster_ke++;
                huruf_monster++;
            }
        }
        dungeon_ke++;
        printf("\n");
    }
    // printf("%d\n", b);
    printf("Final Stage:\n");
    for (int i = 49; i >= 0; i--)
    {
        if (data_level[b][i] != 0)
        {
            printf("Boss %s_%d: %d\n", dungeon, data_level[b][i], pwr_level[b][i]);
        }
    }
    printf("\nHasil:\n");
    if (!tarung(pwr_hero))
    {
        // cout << kapan_mati << endl;
        if (kapan_mati == b)
        {
            printf("%s kalah  dan  mati  di  Dungeon %s pada Final Stage\n", nama, dungeon);
        }
        else
        {
            printf("%s kalah  dan  mati  di  Dungeon %s pada Stage %d\n", nama, dungeon, kapan_mati + 1);
        }
    }
    else
    {
        printf("%s menang melawan Dark Overlord dan memenangkan game di Dungeon %s\n", nama, dungeon);
    }
    printf("*****************************************************************************");
    return 0;
}

// udin 8 100 anjay 4 10 2 10 7 10 1 10 5 10 3 10 8 10 6 30
// 4, 2, 7, 1, 5, 3, 8, 6