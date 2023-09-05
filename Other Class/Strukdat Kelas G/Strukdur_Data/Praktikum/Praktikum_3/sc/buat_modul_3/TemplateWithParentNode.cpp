#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std; 

typedef struct AVLNode
{
    int data;
    struct AVLNode *left,*right,*parent;
    int height;
    int status; 
}AVLNode;

typedef struct AVL_t{
    AVLNode *_root;
    unsigned int _size;
}AVL;


AVLNode* avl_createNode(AVLNode *parent, int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    newNode->parent = parent;
    newNode->status = 1;
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

int _getBalanceFactor(AVLNode* node){
    if(node==NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}

//Rotationsss

AVLNode* _rightRotate(AVLNode* pivotNode) {
	
    AVLNode* newParrent = pivotNode->left;
    newParrent->parent = pivotNode->parent;
    pivotNode->left = newParrent->right;
    if(newParrent->right) newParrent->right->parent = pivotNode;
    newParrent->right = pivotNode;
    pivotNode->parent = newParrent;
	
	
    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftRotate(AVLNode* pivotNode) {

    AVLNode* newParrent = pivotNode->right;
    newParrent->parent = pivotNode->parent;
	pivotNode->right = newParrent->left;
	if(newParrent->left) newParrent->left->parent = pivotNode;
    newParrent->left = pivotNode;
    pivotNode->parent = newParrent;

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
	AVLNode *temp = _leftRotate(node->left);
    node->left = temp;
    temp->parent = node;
    return _rightRotate(node);
}

AVLNode* _rightLeftCaseRotate(AVLNode* node){
	AVLNode *temp = _rightRotate(node->right);
    node->right = temp;
    temp->parent = node;
    return _leftRotate(node);
}
//--

AVLNode* _insert_AVL(AVLNode *root, AVLNode *parent, int value) {
    if(root == NULL) // udah mencapai leaf
        return avl_createNode(parent, value);
    if(value < root->data)
        root->left = _insert_AVL(root->left,root,value);
    else if(value > root->data)
			root->right = _insert_AVL(root->right,root,value);
    root->height = 1 + _max(_getHeight(root->left),_getHeight(root->right)); 
    int balanceFactor = _getBalanceFactor(root);
    
    if(balanceFactor > 1 && value < root->left->data) // skewed kiri (left-left case)
        return _leftCaseRotate(root);
    if(balanceFactor > 1 && value > root->left->data) // 
		return _leftRightCaseRotate(root);
    if(balanceFactor < -1 && value > root->right->data)
        return _rightCaseRotate(root);
    if(balanceFactor < -1 && value < root->right->data)
        return _rightLeftCaseRotate(root);
    
    return root;
}

AVLNode *avl_find(AVLNode *root, int value){	
	if(root){
		if(value < root->data) return avl_find(root->left, value);
		if(value > root->data) return avl_find(root->right,value);
	}
	return root;
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
        avl->_root=  _insert_AVL(avl->_root, avl->_root, value);
        avl->_size++;
    }

}

void avl_remove(AVL *avl,int value){
    if(avl_find(avl,value)){
        avl->_root=_remove_AVL(avl->_root,value);
        avl->_size--;
    }

}

int main(){
	AVL avlku; 
	avl_init(&avlku); 
	int n; 
	cin >> n;
	while (n--){
		int opr; 
		cin >> opr; 
		if (opr == 1){
			int numb; 
			cin >> numb; 
			avl_insert(&avlku, numb); 
		}
		else{
			int numb; 
			cout << "Search Parent of :"; 
			cin >> numb; 
			AVLNode *temp = _search(avlku._root, numb); 
			cout << "Parent : " << temp->parent->data << endl;
		}
	}
}
