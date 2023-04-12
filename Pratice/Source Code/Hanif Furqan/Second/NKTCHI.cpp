#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 100005;

int n, r, t;
int dist[MAXN], parent[MAXN];
vector<pair<int, int>> adj[MAXN];

void bfs(int s) {
    memset(dist, -1, sizeof(dist));
    memset(parent, -1, sizeof(parent));
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& v : adj[u]) {
            if (dist[v.first] == -1) {
                dist[v.first] = dist[u] + v.second;
                parent[v.first] = u;
                q.push(v.first);
            }
        }
    }
}

int main() {
    cin >> n >> r;
    for (int i = 1; i < n; i++) {
        int a, w;
        cin >> a >> w;
        adj[i+1].push_back({a, w});
        adj[a].push_back({i+1, w});
    }
    cin >> t;
    while (t--) {
        int b;
        cin >> b;
        bfs(b);
        int ans = 1e9;
        for (int i = 1; i <= n; i++) {
            if (parent[i] != -1) {
                ans = min(ans, dist[i] + dist[b] - 2 * dist[parent[i]]);
            }
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}
