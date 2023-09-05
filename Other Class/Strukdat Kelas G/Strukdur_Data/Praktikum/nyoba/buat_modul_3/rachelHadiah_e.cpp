#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std; 
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


void inorderMod(AVLNode *root, int value, int *count, int *cek, int *start, int *end) {
    if (root) {
        inorderMod(root->left, value, count, cek, start, end);
		(*count)++;
        if (value == root->data){
        	if (*cek == 0){
        		*start =  *count; 
			}
			*end = *count; 
			*cek = 1; 
		}
        inorderMod(root->right, value, count, cek, start, end);
    }
}

void cariNomor(int start, int end){
//	printf("%d %d\n", start, end); 
	if (start == end){
		printf("%d\n", start); 
		return; 
	}
	printf("%d\n", (start+end)/2); 
}

int main(){
	fastio;
    AVL avlku;
    avl_init(&avlku);
    
    int opr, numb, count=0, start, end, cek;


    while(scanf("%d %d", &opr, &numb) != EOF){
        start=0, end=0, cek=0;
        if (opr == 1){
            avl_insert(&avlku, numb);  
			continue;        
        }
        if(!avl_find(&avlku, numb)){
        	printf("M44f h3l c4r1 4ngk4 l4in y4\n");
        	continue;
        }
    	inorderMod(avlku.root, numb, &count,  &cek, &start , &end);
    	cariNomor(start, end);          
        count=0;        
    }
    return 0;

}
