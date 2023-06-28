#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<vector<int>> &adj, int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
    // puts("hi");
}

bool BFS(vector<vector<int>> adj, int src, int dest, int v, int pred[], int dist[])
{
    queue<int> queue;
    vector<bool> visited(v, false); // Menggunakan vector untuk visited

    for (int i = 0; i < v; i++)
    {
        dist[i] = 0;
        pred[i] = -1;
    }

    visited[src] = true;
    dist[src] = 1;
    queue.push(src);

    while (!queue.empty())
    {
        int u = queue.front();
        queue.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            if (!visited[adj[u][i]])
            {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push(adj[u][i]);

                if (adj[u][i] == dest)
                    return true;
            }
        }
    }

    return false;
}

void printShortestDistance(vector<vector<int>> adj, int s, int dest, int v)
{
    vector<int> pred(v, -1);
    vector<int> dist(v, 0);

    if (BFS(adj, s, dest, v, pred.data(), dist.data()) == false)
    {
        cout << "RIP LAPET 2023";
        return;
    }

    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);

    while (pred[crawl] != -1)
    {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    cout << dist[dest] << endl;

    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add_edge(adj, a, b);
    }

    printShortestDistance(adj, 1, n, n + 1);
    return 0;
}
