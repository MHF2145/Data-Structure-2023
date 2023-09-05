#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef pair<ll, long double> pld;

vector<pld> bfs(int n, vector<pair<int, ll>> adjList[], int src)
{
    vector<pld> shortestPath(n, make_pair(INT64_MAX, 0));
    queue<int> q;
    q.push(src);
    shortestPath[src] = make_pair(0LL, 1.0);
    vector<bool> visited(n, false);
    visited[src] = true;
    while (!q.empty())
    {
        int currPos = q.front();
        q.pop();
        for (unsigned i = 0; i < adjList[currPos].size(); i++)
        {
            int dest = adjList[currPos][i].first;
            ll newDist = shortestPath[currPos].first + 1;
            if (!visited[dest])
            {
                visited[dest] = true;
                q.push(dest);
            }
            if (newDist < shortestPath[dest].first)
            {
                shortestPath[dest].first = newDist;
                shortestPath[dest].second = shortestPath[currPos].second;
            }
            else if (newDist == shortestPath[dest].first)
                shortestPath[dest].second += shortestPath[currPos].second;
        }
    }
    return shortestPath;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a--, b--;
    vector<pair<int, ll>> adjList[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[--u].push_back(make_pair(--v, w));
        adjList[v].push_back(make_pair(u, w));
    }
    vector<pld> shortestPathFromStart = bfs(n, adjList, a), shortestPathFromDest = bfs(n, adjList, b);
    for (int i = 0; i < n; i++)
    {
        long double countShortestPath = shortestPathFromStart[i].second * shortestPathFromDest[i].second;
        assert(countShortestPath <= 1000000);
        if (shortestPathFromStart[i].first <= shortestPathFromStart[b].first - shortestPathFromDest[i].first)
            cout << setprecision(5) << fixed << (countShortestPath * 2 / shortestPathFromStart[b].second) << "\n";
        else
            cout << setprecision(5) << fixed << ((long double)0) << "\n";
    }
}