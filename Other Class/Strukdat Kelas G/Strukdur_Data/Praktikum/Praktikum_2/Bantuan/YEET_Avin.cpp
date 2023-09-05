#include<iostream>
#include <map>
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define loop(i,h) for(ll i=0;i<h;i++)
#define loop1(i,h) for(ll i=1;i<=h;i++)
#define endl '\n'
using namespace std;
const ll M = 1e9 + 7;
const ll N = 1e5 + 5;

map<int,int> mans;
map<pair<int, int>, int> cek;
int jero = 0;

struct node {
    ll val;
    node *left, *right;
    ll size;
};

node* _insert(node *root, int x, int pos, int kedalaman) {
    if(root == NULL) {
        node *temp = new node;
        temp->val = x;
        temp->left = temp->right = NULL;
        temp->size = 1;
        if(cek[{pos, kedalaman}] == 1) mans[kedalaman]++, cek[{pos, kedalaman}]++;
        cek[{pos, kedalaman}]++;
        jero = max(kedalaman, jero);
        return temp;
    }
    if(x < root->val) {
        pos--; kedalaman++;
        root->left = _insert(root->left, x, pos, kedalaman);
    }else{
        pos++; kedalaman++;
        root->right = _insert(root->right, x, pos, kedalaman);
    }
    return root;
}

void solve(){
    node *root = NULL;
    int inp;
    while(cin >> inp) {
        if(inp == -1) return;
        int x; cin >> x;
        if(inp == 1) {
            root = _insert(root, x, 0, 0);
        }else{
            if(x > jero) {
                cout << "kedalaman maksimumnya " << jero << " oi" << endl;
            }else{
                cout << mans[x] << endl;
            }
        }
    }
    return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
    // ll t; cin >> t;
    // while(t--)
        solve();

    return 0;
}