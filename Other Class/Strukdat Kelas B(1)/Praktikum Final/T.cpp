#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> vis, par, dist;
int v, e, a, b;

void solve(int s, int e) {
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dist[s] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if(cur == e) break;

        for(int i : graph[cur]) {
            if(!vis[i]) {
                q.push(i);
                vis[i] = 1;
                par[i] = cur;
                dist[i] = dist[cur] + 1;
            }
        }
    }
}

void print(int n) {
    if(n == -1)
        return;

    print(par[n]);
    cout << n << " ";
}

int main() {
    cin >> v >> e;

    graph.resize(v + 1);
    vis.resize(v + 1, 0);
    par.resize(v + 1, -1);
    dist.resize(v + 1, -1);
	
    while(e--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    solve(1, v);

    if(vis[v]) {
        cout <<  dist[v] + 1 << endl;
        print(v);
    } 
	else cout << "RIP LAPET 2023" << endl;

    return 0;
}