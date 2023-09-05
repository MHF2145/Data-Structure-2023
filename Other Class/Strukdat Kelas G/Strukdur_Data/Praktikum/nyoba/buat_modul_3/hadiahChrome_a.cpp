#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std; 

typedef struct AVLNode_t{
    ll data, idx;
    struct AVLNode_t *left,*right;
    int height;
}AVLNode;

typedef struct AVL_t{
    AVLNode *_root;
    unsigned int _size;
}AVL;

AVLNode* _avl_createNode(ll value, ll idx) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->idx = idx; 
    newNode->height=1;
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


AVLNode* _insert_AVL(AVL *avl,AVLNode* node, ll value, ll idx){
    
    if(node==NULL) 
        return _avl_createNode(value, idx);
    if(value < node->data)
        node->left = _insert_AVL(avl,node->left, value, idx);
    else if(value > node->data)
    	node->right = _insert_AVL(avl,node->right,value, idx);
    
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 
	
    int balanceFactor=_getBalanceFactor(node);
    if(balanceFactor > 1 && value < node->left->data){
    	return _leftCaseRotate(node);
	}  
    if(balanceFactor > 1 && value > node->left->data){
    	return _leftRightCaseRotate(node);
	}
    if(balanceFactor < -1 && value > node->right->data){
    	return _rightCaseRotate(node);
	}
    if(balanceFactor < -1 && value < node->right->data){
    	return _rightLeftCaseRotate(node);
	}
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

void avl_insert(AVL *avl, ll value, ll idx){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value, idx);
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

void preorderMod(AVLNode *root){
	if (root){
		cout << root->idx << " " << root->data << endl; 
        preorderMod(root->left);
        preorderMod(root->right);
	}
}

int primeCheck(long long int number) {
    if (number <= 1) return 0;
    long long int i;
    for (i=2; i*i<=number; i++) {
        if (number % i == 0) return 0;
    }
    return 1;
}

ll convert(ll numb){
	ll left, right; 
	left = (ll)sqrt(numb); 
	right = (ll)sqrt(numb) + 1; 
	while (1){
		if (primeCheck(left) && primeCheck(right)){
			if(left * right  <=  numb){
				return left * right; 
			}
			else {
				right = left; 
				left--; 
			}
		}
		else if (!primeCheck(left) && primeCheck(right)){
			left--; 
		}
		else if (primeCheck(left) && !primeCheck(right)){
			right++;
		}
		else {
			left--;
			right++;
		}
	}
	return 0; 
}


int main(){
	fastio; 
    AVL avlku1;
    AVL avlku2;
    avl_init(&avlku1);
    avl_init(&avlku2);

    ll n;
    cin >> n; 
    ll numb, convNumb;
    for (ll i = 1; i <= n; i++) {
        cin >> numb; 
        avl_insert(&avlku1, numb, i);
        convNumb = convert(numb);
        avl_insert(&avlku2, convNumb, i);
    }
    cout << "Hint :\n"; 
    preorderMod(avlku1._root);
	cout << "Kode Rahasia :\n"; 
    preorderMod(avlku2._root);
	return 0; 
}
