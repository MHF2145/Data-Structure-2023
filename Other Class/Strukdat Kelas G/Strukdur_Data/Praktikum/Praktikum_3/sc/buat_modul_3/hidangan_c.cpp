#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std; 

typedef struct AVLNode_t{
    int data;
    struct AVLNode_t *left, *right, *parent;
    int height;
}AVLNode;

typedef struct AVL_t{
    AVLNode *_root;
    unsigned int _size;
}AVL;

AVLNode* _avl_createNode(AVLNode* root, int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height = 1;
    newNode->parent = root; 
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode* _search(AVLNode *root, int value) {
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

int _getHeight(AVLNode* node){
    if(node==NULL)
        return 0; 
    return node->height;
}

int _max(int a,int b){
    return (a > b)? a : b;
}

AVLNode* _rightRotate(AVLNode* pivotNode) {

    AVLNode* newParrent = pivotNode->left;
    pivotNode->left     = newParrent->right;
    newParrent->right   = pivotNode;

    pivotNode->height   = _max(_getHeight(pivotNode->left) , _getHeight(pivotNode->right)) + 1;
    newParrent->height  = _max(_getHeight(newParrent->left) , _getHeight(newParrent->right)) + 1;
    
    return newParrent;
}

AVLNode* _leftRotate(AVLNode* pivotNode) {
//    cout << pivotNode->data << " " << pivotNode->right->data << endl;
    AVLNode* newParrent = pivotNode->right;
    pivotNode->right    = newParrent->left;
    newParrent->left    = pivotNode;

    pivotNode->height = _max(_getHeight(pivotNode->left) , _getHeight(pivotNode->right)) + 1;
    newParrent->height =_max(_getHeight(newParrent->left) , _getHeight(newParrent->right)) + 1;
//    newParrent-left->parent = 
    newParrent->parent = pivotNode->parent;
    pivotNode->parent = newParrent;
    
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
    return _getHeight(node->left) - _getHeight(node->right);
}


AVLNode* _insert_AVL(AVL *avl, AVLNode* parent,  AVLNode* node, int value) {
    
    if(node==NULL) 
        return _avl_createNode(parent, value);
    if(value < node->data)
        node->left = _insert_AVL(avl, node, node->left, value);
    else if(value > node->data)
        node->right = _insert_AVL(avl, node, node->right, value);
    
    node->height= 1 + _max(_getHeight(node->left), _getHeight(node->right)); 
    
    int balanceFactor=_getBalanceFactor(node);
    
    if(balanceFactor > 1 && value < node->left->data) // skewed kiri (left-left case)
        return _leftCaseRotate(node);
    if(balanceFactor > 1 && value > node->left->data) // left-right zigzag case
        return _leftRightCaseRotate(node);
    if(balanceFactor < -1 && value > node->right->data) // skewed right (right-right case)
        return _rightCaseRotate(node);
    if(balanceFactor < -1 && value < node->right->data) //right-left  zigzag case
        return _rightLeftCaseRotate(node);
    
    return node;
}

AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

AVLNode* _remove_AVL(AVLNode* node,int value){
    if(node==NULL)
        return node;
    if(value > node->data)
        node->right=_remove_AVL(node->right,value);
    else if(value < node->data)
        node->left=_remove_AVL(node->left,value);
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
            node->data=temp->data;
            node->right=_remove_AVL(node->right,temp->data);
        }    
    }

    if(node==NULL) return node;
    
    node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

    int balanceFactor= _getBalanceFactor(node);
    
    if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
        return _leftCaseRotate(node);

    if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
        return _leftRightCaseRotate(node);
  
    if(balanceFactor < -1 && _getBalanceFactor(node->right)<=0) 
        return _rightCaseRotate(node);

    if(balanceFactor < -1 && _getBalanceFactor(node->right)>0) 
        return _rightLeftCaseRotate(node);
    
    return node;
}

void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, int value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl,int value){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl, avl->_root, avl->_root, value);
        avl->_size++;
    }

}

void avl_remove(AVL *avl,int value){
    if(avl_find(avl,value)){
        avl->_root=_remove_AVL(avl->_root,value);
        avl->_size--;
    }

}

void inorder(AVLNode *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(AVLNode *root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(AVLNode *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void verticalorderBase(AVLNode *root, int mid) {
    if(root) {
        printf("%d ", root->data);
        verticalorderBase(root->left,  mid-1);
        verticalorderBase(root->right,  mid+1);
    }
}

void verticalorder(AVLNode *root, int arr[], int mid) {
    if(root) {
        arr[mid] += root->data;
//        cout << hd << ". "<<  arr[hd] << " " << root->data << endl; 
        verticalorder(root->left, arr, mid-1);
        verticalorder(root->right, arr, mid+1);
    }
}


void tebakkode(AVL *avl, int max) {
    int arr[max+1], i;
    memset(arr, 0, sizeof(arr)); 
    verticalorder(avl->_root, arr, max/2);
    long long sum = 0 ; 
    for(i = 0; i < max+1; i++){
        if(arr[i] != 0){
        	sum += arr[i] * arr[i]; 
        }
    }
	printf("%d ", sum);
    puts("");
}

int main(){
    AVL avlku;
    avl_init(&avlku);
    int n, i, j = 0, jml = 0;
	char input[10];
    while(scanf("%s[^ ]", input)!= EOF){
        if(!strcmp(input, "MASUKKAN")) {
            int x;
            scanf("%d", &x);
            avl_insert(&avlku, x);
            j++;
        }
        else if(!strcmp(input, "HITUNG")) {
            jml = avlku._size; 
            tebakkode(&avlku, jml);
        }
	}
}
