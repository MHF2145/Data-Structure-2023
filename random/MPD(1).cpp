#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std; 

typedef struct AVLNode_t{
    int data;
    struct AVLNode_t *left,*right;
    int height;
}AVLNode;

bool Flag = 0; 

typedef struct AVL_t{
    AVLNode *_root;
    unsigned int _size;
}AVL;

AVLNode* _avl_createNode(int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height = 1;
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

    AVLNode* newParrent = pivotNode->right;
    pivotNode->right    = newParrent->left;
    newParrent->left    = pivotNode;

    pivotNode->height = _max(_getHeight(pivotNode->left) , _getHeight(pivotNode->right)) + 1;
    newParrent->height =_max(_getHeight(newParrent->left) , _getHeight(newParrent->right)) + 1;
    
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

void balancedCheck(int Bfact){
	if(Bfact > 1 || Bfact < -1){
//		cout << "Tree tidak balance" << endl;	
		Flag = 1;
	}
	else {
//		cout << "Tree tetap balance" << endl; 
		Flag = 0; 
	}
}

AVLNode* _insert_AVL(AVL *avl,AVLNode* node,int value) {
    
    if(node==NULL) // udah mencapai leaf
        return _avl_createNode(value);
    if(value < node->data)
        node->left = _insert_AVL(avl,node->left,value);
    else if(value > node->data)
    	node->right = _insert_AVL(avl,node->right,value);
    
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 
	
    int balanceFactor=_getBalanceFactor(node);
//    balancedCheck(balanceFactor);
//    patternCheck(balanceFactor, value, node);
    if(balanceFactor > 1 && value < node->left->data){
    	balancedCheck(balanceFactor);
//        cout << "Tree sedang dalam kondisi Skewed Left" << endl;  
//    	cout << "Tree harus dirotate kanan!" << endl; 
    	return _leftCaseRotate(node);
	}  
    if(balanceFactor > 1 && value > node->left->data){
    	balancedCheck(balanceFactor);
//		cout << "Tree sedang dalam kondisi Left-Right Zigzag (left-right zigzag case)" << endl; 
//    	cout << "Left child harus dirotate kiri kemudian Tree dirotate kanan!" << endl;
    	return _leftRightCaseRotate(node);
	}
    if(balanceFactor < -1 && value > node->right->data){
    	balancedCheck(balanceFactor);
//        cout << "Tree sedang dalam kondisi Skewed Right" << endl;  
//    	cout << "Tree harus dirotate kiri!" << endl; 
    	return _rightCaseRotate(node);
	}
    if(balanceFactor < -1 && value < node->right->data){
    	balancedCheck(balanceFactor);
//		cout << "Tree sedang dalam kondisi Right-Left Zigzag (right-left  zigzag case)" << endl; 
//    	cout << "Left child harus dirotate kanan kemudian Tree dirotate kiri!" << endl;
    	return _rightLeftCaseRotate(node);
	}
//	balancedCheck(balanceFactor);
    return node;
}

AVLNode* _insert_AVL_base(AVL *avl,AVLNode* node,int value){
	 if(node==NULL) // udah mencapai leaf
        return _avl_createNode(value);
    if(value < node->data)
        node->left = _insert_AVL_base(avl,node->left,value);
    else if(value > node->data)
    	node->right = _insert_AVL_base(avl,node->right,value);
    
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 
	
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

void avl_insertMod(AVL *avl,int value){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value);
        avl->_size++;
    }

}

void avl_insertBase(AVL *avl, int value){
	if(!avl_find(avl,value)){
        avl->_root=_insert_AVL_base(avl,avl->_root,value);
        avl->_size++;
    }
}

void avl_remove(AVL *avl,int value){
    if(avl_find(avl,value)){
        avl->_root=_remove_AVL(avl->_root,value);
        avl->_size--;
    }

}

void preorder(AVLNode *root) {
    if (root) {
        preorder(root->left);
        printf("%d ", root->data);
        preorder(root->right);
    }
}

int main(){
	fastio; 
    AVL avlku;
    avl_init(&avlku);
    int t; 
    cin >> t; 
    while (t--){
    	int numb; 
    	cin >> numb; 
    	avl_insertBase(&avlku, numb); 
	}
	int numb; 
	cin >> numb;
	avl_insertMod(&avlku, numb); 
	if (Flag){
		cout << "Tree tidak balance" << endl;
		return 0; 
	}
	cout << "Tree tetap balance" << endl;
return 0; 
}
