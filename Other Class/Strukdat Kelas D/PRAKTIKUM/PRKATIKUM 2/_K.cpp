#include <bits/stdc++.h>
using namespace std;
#define moder 1000000007
typedef long long ll;

class Node{
    public:
        ll key;
        Node*left, *right;
};

class BST{
    public:
        BST();
        unsigned int _size;
        bool isEmpty();
        bool search(ll value);
        void insert(ll value);
        void remove (ll value);

    private:
        Node * _root;
        Node * _find(ll value, Node* tree);
        Node * _min(Node * tree);
        Node * _erase(ll value, Node * tree);
        void _maketree(ll value, Node *&tree);
};


BST::BST(){
    _root=NULL;
    _size=0u;
}

Node * BST::_find(ll value, Node* tree){
    if (tree==NULL) return tree;
    else if(value>tree->key){
        return(_find(value,tree->right));
    }
    else if(value<tree->key){
        return(_find(value,tree->left));
    }
    return tree;
}

Node * BST::_min(Node* tree){
    Node * current = tree;
    while(current&&current->left!=NULL) current=current->left;
    return current;
}

Node * BST::_erase(ll value, Node * tree){ //called in remove
    if(tree==NULL) return NULL;
    else if(value>tree->key) tree->right=_erase(value, tree->right);
    else if(value<tree->key) tree->left=_erase(value, tree->left);
    else{
        if(tree->left==NULL){
            Node* tempr =tree->right;
            free(tree);
            return tempr;
        }
        else if(tree->right==NULL){
            Node* templ=tree->left;
            free(tree);
            return templ;
        }
        Node * temp = _min(tree->right);
        tree->key=temp->key;
        tree->right=_erase(temp->key, tree->right);
    }
    return tree;
}

void BST::_maketree (ll value, Node *&tree){
    if(tree==NULL){
        tree = new Node;
        tree->key=value;
        tree->left= NULL;
        tree->right=NULL;
        BST::_size++;
        return;
    }
    else if(value==tree->key) return;
    else if(value>tree->key){
        return(_maketree(value, tree->right));
    }
    else if(value<tree->key){
        return(_maketree(value, tree->left));
    }
}

bool BST::isEmpty(){
    return _root==NULL;
}

bool BST::search(ll value){
    Node * temp = _find(value, _root);
    if(temp==NULL) return false;
    else if(temp->key==value) return true;
    return false;
}

void BST::insert(ll value){
    return(_maketree(value,_root));
}

void BST::remove(ll value){
    if(search(value)){
        _root=_erase(value,_root);
        _size--;
    }
}

ll doingpow(ll ganjil, ll genap){
    ll  hasil=1;
    while(ganjil>0){
        if((ganjil&1)!=0){
            hasil=(hasil*genap%moder)%moder;
        }
        genap=((genap%moder)*(genap%moder))%moder;
        ganjil=ganjil>>1;
    }
    return hasil;
}

int main(){
    BST tree;
    bool cek = true;
    ll ganjil=-1, genap=-1;
    ll num;
    while(cin>>num){
        cek=tree.search(num);
        if(cek){
            genap%=moder;
            if(ganjil==1){
                cout<<genap<<endl;
                return 0;
            }
            else if(genap==0) cout<<genap<<endl;
            ll hasil;
            hasil=doingpow(ganjil,genap);
            cout<<hasil%moder<<endl;
            return 0;
        }
        else{
            tree.insert(num);
            if(num%2==0)genap=num;
            else if(num%2==1) ganjil=num;
        }
    }
    cout<<"Tidak ada duplikat"<<endl;
    return 0;
}