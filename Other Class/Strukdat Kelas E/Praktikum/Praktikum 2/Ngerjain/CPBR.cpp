#include <iostream>
#include <vector>

using namespace std;

//bikin binary tree
struct Node
{
    int data;
    Node *kiri, *kanan;

    Node(int value){
        data = value;
        kiri = nullptr;
        kanan = nullptr;
    }
};

void masukin(Node *&root, int value) {
    if (root == nullptr)
    {
        root = new Node(value);
        return;
    } if (value < root->data)
    {
        masukin(root->kiri, value);
    } else if (value > root->data)
    {
        masukin(root->kanan, value);
    } else{
        return;
    }   
}

//bikin buat cari lowest common ancestor biar bisa cari jaraknya
Node* cariLCA(Node* root, int n1, int n2){
    if (root == nullptr)
    {
        return nullptr;
    } 
    //kalo angka dalem node lebih besar dari n1 sama n2 berarti dia cari LCA di kiri
    if (root->data > n1 && root->data > n2)
    {
        return cariLCA(root->kiri, n1, n2);
    }
    //kalo lebih kecil berarti di kanan
    if (root->data < n1 && root->data < n2)
    {
        return cariLCA(root->kanan, n1, n2);
    }

    return root;
}

//fungsi cari jarak node dengan ancestor
int cariJarak(Node* root, int n, int jarak){
    //kalo belom ada apa2 selesai program
    if (root == nullptr)
    {
        return -1;
    }
    //kalo ditemuin angka yang dibutuin balikin jarak (rootnya udah node yang dicari gitu)
    if (root->data == n)
    {
        return jarak;
    }
    //kalo belom nemu angka yang dibutuhin hitung jarak dari kanan sama kiri
    int jarakKiri = cariJarak(root->kiri, n, jarak + 1);

    if (jarakKiri != -1)
    {
        return jarakKiri;
    }
    
    return cariJarak(root->kanan, n, jarak + 1);
}

int jarakAntar(Node* root, int n1, int n2){
    Node* ancestor = cariLCA(root, n1, n2);

    int jarak1 = cariJarak(ancestor, n1, 0);
    int jarak2 = cariJarak(ancestor, n2, 0);

    int jaraktot = jarak1 + jarak2;
    return jaraktot;
}

int main(){
    Node *root = nullptr;
    int n,t,a,b;
    vector<int> hasil;

    cin >> n;
    while (n--)
    {
        int i = 0;
        cin >> i;
        masukin(root, i);
    }
    
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        int jarak = jarakAntar(root, a, b);
        hasil.push_back(jarak);
    }

    for (int i = 0; i < hasil.size(); i++)
    {
        cout << hasil[i] << endl;
    }

    return 0;
}