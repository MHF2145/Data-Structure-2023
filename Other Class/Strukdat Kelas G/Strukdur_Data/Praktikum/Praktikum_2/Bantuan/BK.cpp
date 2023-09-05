#include <bits/stdc++.h>

struct Node{
    int data;
    bool requirements;
    struct Node *left, *right;
};
int count = 0;

bool isLeaf(Node *root){
    return (root->left == NULL && root->right == NULL);
}

Node *newNode(int value){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->requirements = true;
    temp->left = temp->right = NULL;

    return temp;
}

Node *insert(Node *root, int value){
    if(root == NULL){
        root = newNode(value);
    }
    else if(value < root->data){
        root->left = insert(root->left, value);
    }
    else if(value > root->data){
        root->right = insert(root->right, value);
    }

    return root;
}

void check(Node *root){
    if(root == NULL || isLeaf(root))
        return;
    
    check(root->left);
    check(root->right);
    if(root->left != NULL)
        if(root->left->requirements)
            root->requirements = false;
    if(root->requirements)
        if(root->right != NULL)
            if(root->right->requirements)
                root->requirements = false;
}

void postorder(Node *root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    if(root->requirements)
        count++;
}
int main(){
    Node *root = NULL;
    int n, value;
    std::cin >> n;
    while(n--){
        std::cin >> value;
        root = insert(root, value);
    }

    check(root);
    postorder(root);
    std::cout << count;
}

