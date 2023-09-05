#include<iostream>
#include <map>
#include <string>
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

map<int, int> monster;
int jero = 0, x;
string traveller, superpower, dungeon;
int n;

struct node {
    ll val;
    node *left, *right;
    int power, kedalaman;
};

node* _insert(node *root, int x, int pow, int kedalaman) {
    if(root == NULL) {
        node *temp = new node;
        temp->val = x;
        temp->left = temp->right = NULL;
        temp->power = pow;
        temp->kedalaman = kedalaman;
        jero = max(jero, kedalaman);
        return temp;
    }
    if(x < root->val) {
        root->left = _insert(root->left, x, pow, ++kedalaman);
    }else{
        root->right = _insert(root->right, x, pow, ++kedalaman);
    }
    return root;
}
int it = 0;

void _find(node* root, int depth) {
    // cout << root->kedalaman << " ";
    if(root->kedalaman == depth) {
        printf("Monster %c%d_%d_%d: %d\n", 'A'+it, root->val, jero+1-depth, it+1, root->power);
        monster[jero+1-depth] += root->power;
        it++;
        // return;
    }
    if(root->left) _find(root->left, depth);
    if(root->right) _find(root->right, depth);
    // it = 0;
    return;
}

void _eval(node* root) {
    loop1(i, jero+1){
        if(x%2) {
            x -= 80*monster[i]/100;
        }else{
            x -= 90*monster[i]/100;
        }
        if(x < 0) {
            printf("%s kalah dan mati di Dungeon %s pada %sStage", traveller.c_str(), dungeon.c_str(), i == jero+1? "Final " : "" );
            if(i != jero+1) printf(" %d", i);
            return;
        }
    }
    printf("%s menang melawan Dark Overlord dan memenangkan game di Dungeon %s", traveller.c_str(), dungeon.c_str());

}

void solve(){
    node *root = NULL;
    
    cin >> traveller >> n >> superpower >> x >> dungeon;
    loop(i, n) {
        int key, power; cin >> key >> power;
        root = _insert(root, key, power, 0);
    }
    monster[jero+1] += root->power;
    printf("*****************************************************************************\n");
    printf("The Abyss Game Dungeon %s\n\n", dungeon.c_str());
    printf("Traveller : %s\n", traveller.c_str());
    printf("Superpower : %s - %d\n", superpower.c_str(), x);
    printf("----------------------------------------------------------------------------\n");
    
    loop(i, jero) {
        printf("Stage %d:\n", i+1);
        _find(root, jero-i);
        cout << endl;
        it = 0;
    }
    cout << "Final Stage:" << endl;
    printf("Dark Overlord %s_%d: %d\n", dungeon.c_str(), root->val, root->power);
    printf("\nResult:\n");
    _eval(root);
    printf("\n*****************************************************************************");
    return;
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(0);
    // ll t; cin >> t;
    // while(t--)
        solve();

    return 0;
}