#include<bits/stdc++.h>
using namespace std;

int v, e, a, b, w;
int dist[100001], vis[100001];
vector<pair<int, int>> graph[100001];

int solve() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cek = -pq.top().first;
        pq.pop();

        if(vis[cur]) continue;
        vis[cur] = 1;

        dist[cur] = cek;

        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int temp = max(cek, graph[cur][i].second);
            if (!vis[next]) pq.push({-temp, next});
        }
    }

    return dist[v];
}

int main() {
	cin >> v >> e;
	
	while(e--) {
		cin >> a >> b >> w;
		graph[a].push_back({b, w});
	    graph[b].push_back({a, w});
	}
	cout << solve() << endl;
	
	return 0;
}