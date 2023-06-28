#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &graph, int awal)
{
    int n = graph.size();
    vector<int> dist(n, -1);
    queue<int> q;

    dist[awal] = 0;
    q.push(awal);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr])
        {
            if (dist[next] == -1)
            {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
            else if (next == awal)
            {
                cout << dist[curr] + 1 << endl;
                return;
            }
        }
    }
    puts("gak bisa pulang mamah");
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    int u, v;
    while (true)
    {
        cin >> u >> v;
        if (u == -1 && v == -1)
        {
            break;
        }
        graph[u].push_back(v);
    }

    for (int i = 0; i < n; i++)
    {
        solve(graph, i);
    }
}
