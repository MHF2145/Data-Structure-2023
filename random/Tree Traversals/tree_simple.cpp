#include<stdlib.h>
#include<stdio.h>

// A BST node
struct bin_tree {
    int data;
    struct bin_tree *left, *right;
};
typedef struct bin_tree node;
 
int count = 0;
 
void print(node *root, int k)
{
    if (root != NULL && count <= k)
    {
        print(root->right, k);
        count++;printf("%d vs %d  %d\n",count,k,root->data);
        if (count == k)  printf("%d \n", root->data);
       print(root->left, k);
    }
}

void printTes(node *root,int sign)
{
	   if(!root) return;
	   printf("%d --> %d\n", sign, root->data);
       printTes(root->left,1);
	   printTes(root->right,2);	
}
void newNode(node **tree, int val)
{
	node *temp = NULL;
    temp = (node *)malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->data = val;
    *tree = temp;    
    printf("insert-> %d\n",val);
}

void insert(node ** tree, int val)
{
	if(!(*tree)) {newNode(tree,val); return;}    
    if(val < (*tree)->data)
    {    insert(&(*tree)->left, val); }
    else if(val > (*tree)->data)
    {    insert(&(*tree)->right, val); }

}


int main()
{
    node *root=NULL;
    int datanya;
    while(scanf("%d",&datanya)==1){
    	insert(&root,datanya);
    	if(getchar()=='\n') break;
	} 
	printf("mencetak ....\n =======\n");
    printTes(root,0);
    printf("print(root,3) ....\n =======\n");
    print(root,3);
    
	system("pause");  
}
