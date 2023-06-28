#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}

bool BFS(vector<int> adj[], int src, int dest, int v,
		int pred[], int dist[])
{
	list<int> queue;

	bool visited[v];

	for (int i = 0; i < v; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
		pred[i] = -1;
	}

	visited[src] = true;
	dist[src] = 0;
	queue.push_back(src);

	while (!queue.empty()) {
		int u = queue.front();
		queue.pop_front();
		for (int i = 0; i < adj[u].size(); i++) {
			if (visited[adj[u][i]] == false) {
				visited[adj[u][i]] = true;
				dist[adj[u][i]] = dist[u] + 1;
				pred[adj[u][i]] = u;
				queue.push_back(adj[u][i]);

				if (adj[u][i] == dest)
					return true;
			}
		}
	}

	return false;
}

void printShortestDistance(vector<int> adj[], int s,
						int dest, int v)
{
	int pred[v], dist[v];

	if (BFS(adj, s, dest, v, pred, dist) == false) {
        cout << "RIP LAPET 2023" << endl;
        return;
	}

	vector<int> path;
	int crawl = dest;
	path.push_back(crawl);
	while (pred[crawl] != -1) {
		path.push_back(pred[crawl]);
		crawl = pred[crawl];
	}

	// distance from source is in distance array
	cout << dist[dest] + 1 << endl;

	// printing path from source to destination
	
	for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
        // if (i == 0) cout << endl;
        // else cout << " ";
    }

    cout << endl;
}

// Driver program to test above functions
int main()
{

    int n, e, a, b;
    cin >> n >> e;
    vector<int> adj[n + 1];

    while (e--) {
        cin >> a >> b;
        add_edge(adj, a, b);
    }

    printShortestDistance(adj, 1, n, n + 1);

    return 0;
}
