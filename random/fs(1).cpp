#include <bits/stdc++.h>
using namespace std;

struct BSTNode{
    int val;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* newNode(int val){
    BSTNode* node = new BSTNode;
    node->val = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
     
BSTNode* insert(BSTNode* root, int val){
    if (root == nullptr){
        return newNode(val);
    }
    if (val < root->val){
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

BSTNode* findLCA(BSTNode* root, int n1, int n2){
    if (root == nullptr){
        return nullptr;
    }
    if (root->val > n1 && root->val > n2){
        return findLCA(root->left, n1, n2);
    }
    if (root->val < n1 && root->val < n2){
        return findLCA(root->right, n1, n2);
    }
    return root;
}

BSTNode* findSubtree(BSTNode* root, vector<int> arr){
    int n = arr.size();
    //cout << "aaa";
    sort(arr.begin(), arr.end());
    BSTNode* lca = findLCA(root, arr[0], arr[n-1]);
    return lca;
}

int findLevel(BSTNode* root, int val, int level){
    if (root == nullptr){
        return 0;
    }
    if (root->val == val){
        return level;
    }
    int leftLevel = findLevel(root->left, val, level+1);
    if (leftLevel != 0){
    //cout << "|ll:" << leftLevel << "|" << endl;  
        return leftLevel;
    }
    int rightLevel = findLevel(root->right, val, level+1);
    //cout << "|rl:" << rightLevel << "|" << endl; 
    return rightLevel;
}

int main(){
    int n, q, x;
    cin >> n;
    BSTNode* root = nullptr;
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        root = insert(root, val);
    }
    cin >> q;
    while (q--){
        cin >> x;
        vector<int> arr(x);
        for (int i = 0; i < x; i++){
            cin >> arr[i];
        }
        BSTNode* subtreeRoot = findSubtree(root, arr);
        int level = findLevel(root, subtreeRoot->val, 0);
        cout << subtreeRoot->val << " " << level << endl;
    }
    return 0;
}
