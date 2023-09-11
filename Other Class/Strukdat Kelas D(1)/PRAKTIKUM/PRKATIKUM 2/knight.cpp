#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

struct BSTNode {
    int key, level;
    BSTNode *left, *right;
};

struct BST {
    long long ganjil, genap;
    BSTNode *_root;
    unsigned int _size;

    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;
        
        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value) {
        if (!find(value)) {
            if (value % 2 == 0) {
                genap = value;
            } else if (value % 2 != 0) {
                ganjil = value;
            }
            _root = __insert(_root, value);
            _size++;
        }
    }

private:
    BSTNode* __createNode(int value) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    BSTNode* __search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* __insert(BSTNode *root, int value) {
        if (root == NULL)
            return __createNode(value);
        
        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);
        
        return root;
    }
};

long long power(long long ganjil, long long genap)
{
    long long hasil=1;
    while(ganjil>0){
        if((ganjil&1)!=0){
            hasil=(hasil*genap%mod)%mod;
        }
        genap=((genap%mod)*(genap%mod))%mod;
        ganjil=ganjil>>1;
    }
    return hasil%mod;

}

int main() {
    BST set;
    set.init();
    long long input;
    bool flag = 1;
    while (scanf("%lld", &input) != EOF && flag) {
        if (set.find(input)) {
            flag = 0;
        }
        set.insert(input);
    }
    if (flag) {
        puts("Tidak ada duplikat");
        return 0;
    }
    cout << power(set.ganjil, set.genap);
    return 0;
}