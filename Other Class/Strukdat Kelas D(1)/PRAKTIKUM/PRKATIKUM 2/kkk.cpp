#include <bits/stdc++.h>
using namespace std;
#define moder 1000000007
typedef long long ull;

class Node{
    public:
        ull key;
        Node*left, *right;
};

class BST{
    public:
        BST();
        unsigned int _size;
        bool isEmpty();
        bool search(ull value);
        void insert(ull value);
        void remove (ull value);

    private:
        Node * _root;
        Node * _find(ull value, Node* tree);
        Node * _min(Node * tree);
        Node * _erase(ull value, Node * tree);
        void _maketree(ull value, Node *&tree);
};

ull doingpow(ull ganjil, ull genap){
    ull  hasil=1;
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
    ull ganjil=-1, genap=-1;
    ull num;
    while(cin>>num){
        cek=tree.search(num);
        if(cek){
            genap%=moder;
            if(ganjil==1){
                cout<<genap<<endl;
                return 0;
            }
            else if(genap==0) cout<<genap<<endl;
            ull hasil;
            hasil=doingpow(ganjil,genap);
            cout<<hasil%moder<<endl;
            return 0;
        }
        else{
            tree.insert(num);
            if(num%2==0)genap=num;
            else if(num%2==1) ganjil=num;
        }
        // if (num==0)break;
        // if(cin.eof()){
        //     cout<<"Tidak ada duplikat"<<endl;
        //     return 0;
        // }
        // else{
        //     cin>>num;
        //     cek=(!tree.search(num));
        //     if(!cek)break;
        //     else{
        //         cout<<"Tidak ada Duplikat"<<endl;
        //         return 0;
        //     }

        // }
    }
    cout<<"Tidak ada duplikat"<<endl;
    return 0;
}


// inisiasi
BST::BST(){
    _root=NULL;
    _size=0u;
}

//hidden func
Node * BST::_find(ull value, Node* tree){ //called in search
    if (tree==NULL) return tree;
    else if(value>tree->key){
        return(_find(value,tree->right));
    }
    else if(value<tree->key){
        return(_find(value,tree->left));
    }
    return tree;
}

Node * BST::_min(Node* tree){ //called in erase
    Node * current = tree;
    while(current&&current->left!=NULL) current=current->left;
    return current;
}

Node * BST::_erase(ull value, Node * tree){ //called in remove
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

void BST::_maketree (ull value, Node *&tree){ //called in insert
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


//for use
bool BST::isEmpty(){
    return _root==NULL;
}

bool BST::search(ull value){ //called in remove
    Node * temp = _find(value, _root);
    if(temp==NULL) return false;
    else if(temp->key==value) return true;
    return false;
}

void BST::insert(ull value){
    return(_maketree(value,_root));
}

void BST::remove(ull value){
    if(search(value)){
        _root=_erase(value,_root);
        _size--;
    }
}
