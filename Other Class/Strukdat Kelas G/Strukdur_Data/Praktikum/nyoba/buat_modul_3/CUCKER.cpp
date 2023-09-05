#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AVLNode_t
{
    int data;
    struct AVLNode_t *left,*right;
    int height;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *root;
    int size;
}AVL;

int _max(int a,int b){
    return (a > b)? a : b;
}

void avl_init(AVL *avl);
bool avl_isEmpty(AVL *avl);
int _getHeight(AVLNode* node);
int getBalanceFactor(AVLNode* node);
AVLNode* _avl_createNode(int value);
void avl_insert(AVL *avl,int value);
AVLNode* _insert_AVL(AVL *avl,AVLNode *node,int value);
AVLNode* _leftCaseRotate(AVLNode* node);
AVLNode* _rightCaseRotate(AVLNode* node);
AVLNode* _leftRightCaseRotate(AVLNode* node);
AVLNode* _rightLeftCaseRotate(AVLNode* node);
AVLNode* _rightRotate(AVLNode* pivotNode);
AVLNode* _leftRotate(AVLNode* pivotNode);
bool avl_find(AVL *avl, int value); 
AVLNode* search(AVLNode *root, int value);

void avl_init(AVL *avl) 
{
    avl->root = NULL;
    avl->size = 0;
}

bool avl_isEmpty(AVL *avl) 
{
    return avl->root == NULL;
}

int _getHeight(AVLNode* node)
{
    if(node==NULL)
        return 0; 
    return node->height;
}


int _getBalanceFactor(AVLNode* node)
{
    if(node == NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}

AVLNode* _avl_createNode(int value) 
{
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void avl_insert(AVL *avl,int value)
{
   if(!avl_find(avl,value))
   {
        avl->root = _insert_AVL(avl,avl->root,value);
        avl->size++;
    }
}

AVLNode* _insert_AVL(AVL *avl,AVLNode* node,int value) 
{
    
    if(node == NULL) 
        return _avl_createNode(value);
    if(value < node->data)
        node->left = _insert_AVL(avl,node->left,value);
    else if(value > node->data)
        node->right = _insert_AVL(avl,node->right,value);
    
    node->height = 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

    int balanceFactor = _getBalanceFactor(node);
    
    if(balanceFactor > 1 && value < node->left->data) 
        return _leftCaseRotate(node);
    if(balanceFactor > 1 && value > node->left->data)  
        return _leftRightCaseRotate(node);
    if(balanceFactor < -1 && value > node->right->data)
        return _rightCaseRotate(node);
    if(balanceFactor < -1 && value < node->right->data)
        return _rightLeftCaseRotate(node);
    
    return node;
}

AVLNode* _leftCaseRotate(AVLNode* node)
{
    return _rightRotate(node);
}

AVLNode* _rightCaseRotate(AVLNode* node)
{
    return _leftRotate(node);
}

AVLNode* _leftRightCaseRotate(AVLNode* node)
{
    node->left=_leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode* _rightLeftCaseRotate(AVLNode* node)
{
    node->right=_rightRotate(node->right);
    return _leftRotate(node);
}

AVLNode* _rightRotate(AVLNode* pivotNode) 
{
    AVLNode* newParrent = pivotNode->left;
    pivotNode->left = newParrent->right;
    newParrent->right = pivotNode;

    pivotNode->height = _max(_getHeight(pivotNode->left),_getHeight(pivotNode->right)) + 1;
    newParrent->height = _max(_getHeight(newParrent->left),_getHeight(newParrent->right)) + 1;
    
    return newParrent;
}

AVLNode* _leftRotate(AVLNode* pivotNode) 
{
    AVLNode* newParrent = pivotNode->right;
    pivotNode->right = newParrent->left;
    newParrent->left = pivotNode;

    pivotNode->height = _max(_getHeight(pivotNode->left),_getHeight(pivotNode->right)) + 1;
    newParrent->height = _max(_getHeight(newParrent->left),_getHeight(newParrent->right)) + 1;
    
    return newParrent;
}

bool avl_find(AVL *avl, int value) 
{
    AVLNode *temp = search(avl->root, value);
    if (temp == NULL)
        return false;

    if (temp->data == value)
        return true;
    else
        return false;
}
AVLNode* search(AVLNode *root, int value) 
{
    while (root != NULL) {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

AVLNode* cariibu(AVLNode *root, int anak){

    AVLNode *prevNode = root;

    while (root)
    { 
        if(root->data==anak){
             break;
        }
        prevNode = root;

        if(anak>root->data){
            root = root->right;
        }
        else if(anak<root->data){
            root = root->left;
        }
    }
    return prevNode;
}

int main(){

    AVL avlku;
    avl_init(&avlku);

    int N, T, Ni, Ti;

    scanf("%d %d", &N, &T);

    for (int i = 0; i < N; i++){
       scanf("%d ", &Ni);
       avl_insert(&avlku, Ni);
    }
    
    for (int i = 0; i < T; i++){
        scanf("%d\n", &Ti);
        if(!avl_find(&avlku, Ti)){
            printf("Aku Bukan Anggota Keluarga Pawel\n");
        }
        else if(avlku.root->data == Ti){
                printf("Aku adalah Kepala Keluarga Pawel\n");
        }
        else {
          AVLNode* ortu=cariibu(avlku.root, Ti);
          if (ortu->data==avlku.root->data){
              printf("%d\n", ortu->data);
              continue;
          }
          
          AVLNode* grandortu=cariibu(avlku.root, ortu->data);

            if(grandortu->left==NULL ){
                printf("%d\n", ortu->data);
            }
            else if(grandortu->right==NULL){
                printf("%d\n", ortu->data);
            }
            else{
                int cilicih = grandortu->right->data - grandortu->left->data;
                printf("%d\n", cilicih);
            }
            
        }
    }
    
}