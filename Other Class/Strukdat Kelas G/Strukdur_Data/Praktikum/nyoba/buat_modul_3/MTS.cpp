#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define max(a,b) (a > b)? a : b

typedef struct AVLNode_t
{
    int data;
    struct AVLNode_t *left,*right;
    int height;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *root;
    unsigned int size;
}AVL;

AVLNode* createNode(int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height=1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode* search(AVLNode *root, int value) {
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

int getHeight(AVLNode* node){
    if(node==NULL)
        return 0;
    return node->height;
}

AVLNode* rightRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->left;
    pivotNode->left=newParrent->right;
    newParrent->right=pivotNode;

    pivotNode->height=max(getHeight(pivotNode->left),getHeight(pivotNode->right))+1;
    newParrent->height=max(getHeight(newParrent->left),getHeight(newParrent->right))+1;

    return newParrent;
}

AVLNode* leftRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->right;
    pivotNode->right=newParrent->left;
    newParrent->left=pivotNode;

    pivotNode->height=max(getHeight(pivotNode->left),getHeight(pivotNode->right))+1;
    newParrent->height=max(getHeight(newParrent->left),getHeight(newParrent->right))+1;

    return newParrent;
}

AVLNode* leftCaseRotate(AVLNode* node){
    return rightRotate(node);
}

AVLNode* rightCaseRotate(AVLNode* node){
    return leftRotate(node);
}

AVLNode* leftRightCaseRotate(AVLNode* node){
    node->left=leftRotate(node->left);
    return rightRotate(node);
}

AVLNode* rightLeftCaseRotate(AVLNode* node){
    node->right=rightRotate(node->right);
    return leftRotate(node);
}

int getBalanceFactor(AVLNode* node){
    if(node==NULL)
        return 0;
    return getHeight(node->left)-getHeight(node->right);
}

AVLNode* insert_AVL(AVL *avl,AVLNode *node,int value) {

    if(node==NULL)
        return createNode(value);
    if(value < node->data)
        node->left = insert_AVL(avl,node->left,value);
    else node->right = insert_AVL(avl,node->right,value);

    node->height= 1 + max(getHeight(node->left),getHeight(node->right));

    int balanceFactor=getBalanceFactor(node);

    if(balanceFactor > 1 && value < node->left->data)
        return leftCaseRotate(node);
    if(balanceFactor > 1 && value > node->left->data)
        return leftRightCaseRotate(node);
    if(balanceFactor < -1 && value > node->right->data)
        return rightCaseRotate(node);
    if(balanceFactor < -1 && value < node->right->data)
        return rightLeftCaseRotate(node);

    return node;
}

void avl_init(AVL *avl) {
    avl->root = NULL;
    avl->size = 0u;
}

bool avl_isEmpty(AVL *avl) {
    return avl->root == NULL;
}

bool avl_find(AVL *avl, int value) {
    AVLNode *temp = search(avl->root, value);
    if (temp == NULL)
        return false;

    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl,int value){
    avl->root=insert_AVL(avl,avl->root,value);
    avl->size++;
}

void inorder(AVLNode *root, int value, int *A, int *count, int *B, int *cek) {
    if (root){

    inorder(root->left, value, A, count, B, cek);

    *count += 1;
    if(value==root->data){
        if (*cek==0){
            *A = *count;
        }
        
        *B = *count;
        *cek += 1;     
       
    }
     
    inorder(root->right, value, A, count, B, cek);
    }
}

void printindeks(int A, int B){
    if(A==B){
        printf("%d\n", A);
    }
    else{
        A = (A+B)/2;
        printf("%d\n", A);
    }
}

int main(){
    AVL avlku;
    avl_init(&avlku);
    
    int X, Y, count=0, A, B, cek;


    while(scanf("%d %d",&X, &Y) != EOF){
        A=0;
        B=0;
        cek=0;
        if (X==1){
            avl_insert(&avlku,Y);          
        }

        else if(X==2){
          if(!avl_find(&avlku, Y)){
          }
          else {
            inorder(avlku.root, Y, &A, &count, &B, &cek);
            printindeks(A, B);
          }          
        } 
        count=0;        
    }
    return 0;

}