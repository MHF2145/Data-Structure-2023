#include <iostream>
#include <climits>
using namespace std;

int a = 0;
class BstNode {
public:
    int key, hargaTol;
    BstNode *left, *right, *parent;

    BstNode(int data, int harga) {
        key = data;
        hargaTol = harga;
        left = right = parent = NULL;
    }
};

class Bst {
public:
    BstNode *root;
    Bst() {
        root = NULL;
    }

    void insert(int data, int harga) {
        BstNode *node = new BstNode(data, harga);
        if(!root) {
            root = node;
            return;
        }

        BstNode *current = root;
        for(;;) {
            if(data < current->key) {
                if(!current->left) {
                    current->left = node;
                    current->left->parent = current;
                    return;
                }
                current = current->left;
            } else {
                if(!current->right) {
                    current->right = node;
                    current->right->parent = current;
                    return;
                }
                current = current->right;
            }
        }
    }

    BstNode* __search(BstNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return NULL;
    }

    void findTroughParentDuaa(BstNode *root, BstNode* temp, int *minUang, int lev) {
        if(root->left == NULL && root->right == NULL) {
            if(lev < (*minUang)) *minUang = lev;
            return;
        }

        int red = INT_MAX, blue = INT_MAX;
        if(root->right != NULL) red = root->right->hargaTol;
        if(root->left != NULL) blue = root->left->hargaTol;

        // cout << *minUang << " " << lev << endl;
        if (root->left != NULL && root->left != temp) findTroughParentDuaa(root->left, root, minUang, lev + blue);
        if (root->right != NULL && root->right != temp) findTroughParentDuaa(root->right, root, minUang, lev + red);
        if (root->parent != NULL && root->parent != temp) findTroughParentDuaa(root->parent, root, minUang, lev + root->hargaTol);
        
    }

    int minMoney(BstNode *root, int value){
        int minUang = INT_MAX;
        BstNode *temp = __search(root, value);
        if(temp == NULL) return -1;
        findTroughParentDuaa(temp, NULL, &minUang, 0);
        // findLeaf(root, 0, &minUang);
        return minUang;
    }

    void preorder(BstNode* root){
        if (root){
            cout << " key : " << root->key;
            if(root->left != NULL) cout << " left : " << root->left->key;
            if(root->right != NULL) cout << " right : " << root->right->key;
            cout << " harga : " << root->hargaTol;
            if(root->parent != NULL)cout << " parent : " << root->parent->key;
            cout << endl;

            preorder(root->left);
            preorder(root->right);
        }
    }
};

int main()
{
    Bst bst;
    int uang, kota, data, tol, testcase, query;
    cin >> uang >> kota >> data;
    // ini buat awal root nya
    bst.insert(data, 0);

    // ini buat insert
    for(int i = 0; i < kota-1; i++){
        cin >> data >> tol;
        bst.insert(data, tol);
    }

    cin >> query;
    while (query--)
    {
        cin >> testcase;
        int result = bst.minMoney(bst.root, testcase);
        if(uang >= result){
            cout << "yey, bisa refreshing :)" << endl;
        } else if(result == -1){
            cout << "bruhh -_-" << endl;
        } else{
            cout << "bruhh -_-" << endl;
        }
    }
    // bst.preorder(bst.root);
    return 0;
}

/*
3
10 6
2 3
7 5
1 1
3 3
10 5
4 1
8 8
5 4
9 7

3
9 8
3 4
1 3
6 5
4 2
7 1
10 1
14 7
13 4

7
15 100
75 5
65 6
60 3
70 4
85 5
80 4
95 3
125 4
115 3
110 5
120 3
150 5
135 1
175 2
5
125
75
100
115
150

*/