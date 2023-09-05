#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// vector <vector <int>> wadahKey(3, vector<int>(3));
// vector <vector <int>> wadahPower(3, vector<int>(3));

int wadahKey[60][60];
int wadahPower[60][60];

struct AVLNode {
    int keynya, powernya;
    AVLNode *left, *right;
    int height;
};

struct AVL
{
private:
    unsigned _size;

    AVLNode* _avl_createNode(int keyyy, int powerrr) {
        AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
        newNode->keynya = keyyy;
        newNode->powernya = powerrr;
        newNode->height =1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    AVLNode* _search(AVLNode *root, int keyyy) {
        while (root != NULL) {
            if (keyyy < root->keynya)
                root = root->left;
            else if (keyyy > root->keynya)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    int _getHeight(AVLNode* node){
        if(node==NULL)
            return 0; 
        return node->height;
    }

    int _max(int a,int b){
        return (a > b)? a : b;
    }

    AVLNode* _rightRotate(AVLNode* pivotNode){
        AVLNode* newParrent=pivotNode->left;
        pivotNode->left=newParrent->right;
        newParrent->right=pivotNode;

        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }

    AVLNode* _leftRotate(AVLNode* pivotNode) {
        AVLNode* newParrent=pivotNode->right;
        pivotNode->right=newParrent->left;
        newParrent->left=pivotNode;

        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }

    AVLNode* _leftCaseRotate(AVLNode* node){
        return _rightRotate(node);
    }

    AVLNode* _rightCaseRotate(AVLNode* node){
        return _leftRotate(node);
    }

    AVLNode* _leftRightCaseRotate(AVLNode* node){
        node->left=_leftRotate(node->left);
        return _rightRotate(node);
    }

    AVLNode* _rightLeftCaseRotate(AVLNode* node){
        node->right=_rightRotate(node->right);
        return _leftRotate(node);
    }

    int _getBalanceFactor(AVLNode* node){
        if(node==NULL)
            return 0;
        return _getHeight(node->left)-_getHeight(node->right);
    }

    AVLNode* _insert_AVL(AVLNode* node,int keyyy, int powerrr) {
        
        if(node==NULL)
            return _avl_createNode(keyyy, powerrr);
        if(keyyy < node->keynya)
            node->left = _insert_AVL(node->left,keyyy, powerrr);
        else if(keyyy > node->keynya)
            node->right = _insert_AVL(node->right,keyyy, powerrr);
        
        node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

        int balanceFactor=_getBalanceFactor(node);
        
        if(balanceFactor > 1 && keyyy < node->left->keynya)
            return _leftCaseRotate(node);
        if(balanceFactor > 1 && keyyy > node->left->keynya)
            return _leftRightCaseRotate(node);
        if(balanceFactor < -1 && keyyy > node->right->keynya)
            return _rightCaseRotate(node);
        if(balanceFactor < -1 && keyyy < node->right->keynya)
            return _rightLeftCaseRotate(node);
        
        return node;
    }

    AVLNode* _findMinNode(AVLNode *node) {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }

    AVLNode* _remove_AVL(AVLNode* node,int keyyy){
        if(node==NULL)
            return node;
        if(keyyy > node->keynya)
            node->right=_remove_AVL(node->right,keyyy);
        else if(keyyy < node->keynya)
            node->left=_remove_AVL(node->left,keyyy);
        else{
            AVLNode *temp;
            if((node->left==NULL)||(node->right==NULL)){
                temp=NULL;
                if(node->left==NULL) temp=node->right;  
                else if(node->right==NULL) temp=node->left;
                
                if(temp==NULL){
                    temp=node;
                    node=NULL;
                }
                else
                    *node=*temp;   
                
                free(temp);
            }
            else{
                temp = _findMinNode(node->right);
                node->keynya=temp->keynya;
                node->right=_remove_AVL(node->right,temp->keynya);
            }    
        }

        if(node==NULL) return node;
        
        node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

        int balanceFactor= _getBalanceFactor(node);
        
        if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
            return _leftCaseRotate(node);

        if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
            return _leftRightCaseRotate(node);
    
        if(balanceFactor<-1 && _getBalanceFactor(node->right)<=0) 
            return _rightCaseRotate(node);

        if(balanceFactor<-1 && _getBalanceFactor(node->right)>0) 
            return _rightLeftCaseRotate(node);
        
        return node;
    }

    void _inorder(AVLNode *node) {
        if (node) {
            _inorder(node->left);
            printf("keyy nya %d \n", node->keynya);
            printf("power nya %d \n", node->powernya);
            printf("------------------------- \n");
            _inorder(node->right);
        }
    }


public:
    AVLNode *_root;

    void init() {
        _root = NULL;
        _size = 0U;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int keyyy) {
        AVLNode *temp = _search(_root, keyyy);
        if (temp == NULL)
            return false;
        
        if (temp->keynya == keyyy) return true;
        else return false;
    }

    void insert(int keyyy, int powerrr) {
        if (!find(keyyy)) {
            _root = _insert_AVL(_root, keyyy, powerrr);
            _size++;
        }
    }

    void remove(int keyyy) {
        if (find(keyyy)) {
            _root = _remove_AVL(_root, keyyy);
            _size--;
        }
    }

    void inorder() {
        this->_inorder(_root);
    }

    int c, d;
    void cariMonster(AVLNode *root, int numLe, int numRe, int &kolom, int &baris){
        c = root->keynya;
        d = root->powernya;
        wadahKey[numLe][numRe] = c;
        wadahPower[numLe][numRe] = d;
        if (!root)
        return;
     
        if (!root->left && !root->right)
        {
            if(kolom <= numRe) kolom = numRe;
            if(baris <= numLe) baris = numLe;
            
            numLe = 0;
            numRe = 0;
            return;
        }
    
        if (root->left){
            cariMonster(root->left, numLe+1, numRe, kolom, baris);
        }
        

        if (root->right){
            numLe++;
            numRe++;
            cariMonster(root->right, numLe, numRe, kolom, baris);

        }
    }
 
};

int main(int argc, char const *argv[])
{
    int perum, temp1, temp2;
    int red, green, blue, yellow;
    red = green = blue = yellow = 0;
    cin >> perum;
    AVL set;
    set.init();

    while (perum--)
    {
        cin >> temp1;
        cin >> temp2;
        set.insert(temp1, temp2);
    }


    set.cariMonster(set._root, red, green, blue, yellow);

    // cout << wadahKey[0][0] << endl;

    int indexWal = blue+1;
    int indexWar = yellow+1;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << "key : " << wadahKey[i][j] << " pow : " << wadahPower[i][j] << endl;
        }
        cout << " ---------------------------------------------------- "<< endl;
    }

    cout << indexWal << endl;
    cout << indexWar << endl;

    // set.inorder();
    return 0;
}

/*

5
1 2
3 4
5 6
7 8
9 10

8
4 1
2 1
7 1
1 2
5 1
3 1
8 1
6 1

*/

// 4, 2, 7, 1, 5, 3, 8, 6
// udin 8 100 anjay 4 10 2 10 7 10 1 10 5 10 3 10 8 10 6 30
