#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

int bfs(int start)
{
    int N = adj.size();
    vector<bool> visited(N, false);
    vector<int> steps(N, 0);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int neighbor : adj[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                steps[neighbor] = steps[current] + 1;
                q.push(neighbor);
            }
            else if (neighbor == start)
            {
                return steps[current] + 1;
            }
        }
    }

    return -1;
}

int main()
{
    int N;
    cin >> N;

    adj.resize(N);

    int u, v;
    while (cin >> u >> v && !(u == -1 && v == -1))
    {
        adj[u].push_back(v);
    }

    for (int i = 0; i < N; i++)
    {
        int steps = bfs(i);
        if (steps == -1)
        {
            cout << "gak bisa pulang mamah" << endl;
        }
        else
        {
            cout << steps << endl;
        }
    }

    return 0;
}
