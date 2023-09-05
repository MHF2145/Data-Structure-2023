#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i,h) for(int i=0;i<h;i++)
#define loop1(i,h) for(int i=1;i<=h;i++)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 998244353

using namespace std;

ll M = 1e9 + 7;
const ll N = 1e4 + 5;
const ll vertex = 1e6 + 5;
ll MM = 1e18;

// vector<string> v(N);

// vector<vector<pair<long,long>>> adjList(N, vector<pair<long,long>> (N));

// void dfs(vector<long> &result, long start){
//     vector<bool> visited(vertex, false);
//     stack<long> st;

//     st.push(start);
//     visited[start] = true;
//     result.push_back(start);

//     while(!st.empty()){
//         long temp = st.top();
//         st.pop();

//         if(!visited[temp]){
//             result.push_back(temp);
//             visited[temp] = true;
//         }

//         for(auto it:adjList[temp]){
//             if (!visited[it.first])
//                 st.push(it.first);
//         }
//     }
// }

// void bfs(vector<long> &result, long start){
//     vector<bool> visited(vertex, false);
//     queue<long> q;

//     q.push(start);
//     visited[start] = true;
//     result.push_back(start);

//     while(!q.empty()){
//         long temp = q.front();
//         q.pop();

//         for(auto it:adjList[temp]){
//             if (!visited[it.first]){
//                 q.push(it.first);
//                 visited[it.first] = true;
//                 result.push_back(it.first);
//             }
//         }
//     }
// }

vector<string> v(N);
vector<vector<int>> hasil(N, vector<int> (N,-1));
vector<vector<int>> cek(N, vector<int> (N,0));
// int jarak(int i, int j, int n, int m) {
//     if(i < 0 || j < 0 || i >= n || j >= m) return M;
//     if(hasil[i][j] != -1) return hasil[i][j];
//     if(v[i][j] == '1') return hasil[i][j] = 0;
//     if(cek[i][j]) {cek[i][j] = 0; return M;}
//     cek[i][j] = 1;
//     hasil[i][j] = min({jarak(i+1, j, n, m), jarak(i-1, j, n, m),  jarak(i, j+1, n, m), jarak(i, j-1, n, m)}) + 1;
//     cek[i][j] = 0;
//     return hasil[i][j];
// }
 
void solve(){
    vector<pair<int,int>> pr;
    int n, m; cin >> n >> m;
    loop(i, n) cin >> v[i];
    loop(i, n) {
        loop(j ,m) {
            if(v[i][j] == '1') {
                pr.pb({i,j});
            }
        }
    }
    loop(i, n) {
        loop(j, m) {
            if(v[i][j] == '1') {
                hasil[i][j] = 0;
            }else{
                int ans = M;
                for(auto it:pr) {
                    ans = min(ans, abs(it.first - i) + abs(it.second - j));
                }
                hasil[i][j] = ans;
            }
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

}
int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(0);
	ll t; cin>>t;
	while(t--) 
	solve();
    return 0;
}

