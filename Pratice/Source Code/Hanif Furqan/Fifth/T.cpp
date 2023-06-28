// LOH KOK GA TLE, ANJIR TIME LIMIT NYA BERAPA
#include <bits/stdc++.h>

void add_edge(std::vector<std::vector<int>> &adj, int src, int dest);
bool breadpes(std::vector<std::vector<int>> adj, int src, int dest, int v, int pred[], int dist[]);

void printShortestDistance(std::vector<std::vector<int>> adj, int s, int dest, int v);

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n + 1);

    while (m--)
    {
        int a, b;
        std::cin >> a >> b;
        add_edge(adj, a, b);
    }

    printShortestDistance(adj, 1, n, n + 1);
    return 0;
}

void add_edge(std::vector<std::vector<int>> &adj, int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

bool breadpes(std::vector<std::vector<int>> adj, int src, int dest, int v, int pred[], int dist[])
{
    std::queue<int> queue;
    std::vector<bool> visited(v, false);

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

void printShortestDistance(std::vector<std::vector<int>> adj, int s, int dest, int v)
{
    std::vector<int> pred(v, -1);
    std::vector<int> dist(v, 0);

    if (breadpes(adj, s, dest, v, pred.data(), dist.data()) == false)
    {
        std::cout << "RIP LAPET 2023";
        return;
    }

    std::vector<int> path;
    int crawl = dest;
    path.push_back(crawl);

    while (pred[crawl] != -1)
    {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    std::cout << dist[dest] << std::endl;

    for (int i = path.size() - 1; i >= 0; i--)
        std::cout << path[i] << " ";
}