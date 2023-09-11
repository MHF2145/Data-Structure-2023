#include <bits/stdc++.h>
using namespace std;

bool BreadthFirstSearch(vector<int> adj[], int src, int tujuan, int v, int prediksi[], int jarak[]) 
{
    list<int> queue;
    bool visited[v];
 
    for (int i = 0; i < v; i++) 
	{
        visited[i] = false;
        jarak[i] = INT_MAX;
        prediksi[i] = -1;
    }
 
    visited[src] = true;
    jarak[src] = 0;
    queue.push_back(src);
 
    while (!queue.empty()) 
	{
        int u = queue.front();
        queue.pop_front();
        for (unsigned i = 0; i < adj[u].size(); i++) 
		{
            if (visited[adj[u][i]] == false) 
			{
                visited[adj[u][i]] = true;
                jarak[adj[u][i]] = jarak[u] + 1;
                prediksi[adj[u][i]] = u;
                queue.push_back(adj[u][i]);
                
                if (adj[u][i] == tujuan) return true;
            }
        }
    }
 
    return false;
}
 
void shortestPath(vector<int> adj[], int s, int destinasi, int v) 
{
    int prediksi[v], jarak[v];
 
    if (BreadthFirstSearch(adj, s, destinasi, v, prediksi, jarak) == false) 
	{
        cout << "RIP LAPET 2023";
        return;
    }
 
    vector<int> path;
    int crawl = destinasi;
    path.push_back(crawl);
    while (prediksi[crawl] != -1) 
	{
        path.push_back(prediksi[crawl]);
        crawl = prediksi[crawl];
    }
    cout << jarak[destinasi]+1 << endl;

    int f = 0;
    for (unsigned i = path.size() - 1; i >= 0; i--)
	{
        cout << path[i]+1 << " ";
        f++;
        if (f > jarak[destinasi]) break;
    }
}

int main() 
{
    int n, m;
    cin >> n >> m;
    vector<int> edges[n];
    vector<bool> visited(n, false);
    
    while (m--) 
	{
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }

    shortestPath(edges, 0, n-1, n);
    return 0;
}
