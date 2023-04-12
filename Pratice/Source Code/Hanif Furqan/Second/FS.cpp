#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 1003;

vector<int> adj[MAXN];
int parent[MAXN], level[MAXN];

void dfs(int node, int p, int lvl) {
    parent[node] = p;
    level[node] = lvl;
    for (int i = 0; i < adj[node].size(); i++) {
        if (adj[node][i] != p) {
            dfs(adj[node][i], node, lvl + 1);
        }
    }
}

int main() {
    int n, q;
    cin >> n;
    map<int, int> nodeMap;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        nodeMap[val] = i;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[nodeMap[u]].push_back(nodeMap[v]);
        adj[nodeMap[v]].push_back(nodeMap[u]);
    }
    dfs(1, 0, 1);
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        int root = -1;
        for (int i = 0; i < k; i++) {
            int val;
            cin >> val;
            int node = nodeMap[val];
            while (node != 0 && root == -1) {
                if (nodeMap.count(parent[node]) == 0) {
                    root = node;
                }
                node = parent[node];
            }
        }
        cout << nodeMap[root] << " " << level[root] << endl;
    }
    return 0;
}
