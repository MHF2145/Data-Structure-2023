#include<stdio.h>
#include<stdlib.h>
#define ull unsigned long long

ull bagi, add, temp;

ull power_2(ull num){
    bagi = 32;
    add = 16;
    temp = num;
    while(temp != 1){
        temp = num >> bagi;
        if(temp){
        	bagi += add;
		} 
        else {
        	bagi -= add;
		}
        temp = num >> bagi;
        add >>= 1;
    }
    return bagi + 1;
}

int main(){
    ull n,m,max;
    while(1){
        scanf("%llu %llu", &n, &m);
        if(n == -1){
        	break;
		} 
//        printf("%d %d %d %d\n", n, m, power_2(n), power_2(m)); 
        max = (n - power_2(n)) << 1;
        if(m > max){
            puts("N");
            continue; 
		}
        puts("Y");
    }
}

/*
TAMBAHI {int data, left_cost, right_cost; bool cek;}
int _getcost(AVLNode *root) {
    if(root==NULL)return 0;
    root->left_cost = _getcost(root->left);
    root->right_cost = _getcost(root->right);
    
    int ctr = 0;
    if(root->left_cost)ctr++;
    if(root->right_cost)ctr++;
    if(ctr+root->cek)ctr++;
    
    return ctr + root->left_cost + root->right_cost;
}

int getcost(AVL *avl){
    return _getcost(avl->_root);
}

int main(){
    AVL avlku;
    avl_init(&avlku);
    int n, val;
    char c;
    scanf("%d",&n);
    while(n--){
        scanf("%d %c",&val,&c);
        if(c=='Y')avl_insert(&avlku,val,1);
        else avl_insert(&avlku,val,0);
    }
    printf("%d\n",getcost(&avlku));
    return 0;
}
*/
