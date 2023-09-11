#include<bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge
{
    int destination;
    int bahaya;
};

int level(int n, const vector<vector<Edge>> &graph);
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int maxlevel = level(n, graph);
    cout << maxlevel << endl;

    return 0;
}

int level(int n, const vector<vector<Edge>> &graph)
{
    vector<int> maxlevel(n + 1, INF);
    vector<bool> visited(n + 1, false);

    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int village = pq.top().second;
        int bahaya = -pq.top().first;
        pq.pop();

        if (visited[village])
        {
            continue;
        }
        visited[village] = true;

        maxlevel[village] = bahaya;

        for (const Edge &edge : graph[village])
        {
            int destinationVillage = edge.destination;
            int next = max(bahaya, edge.bahaya);
            if (!visited[destinationVillage])
            {
                pq.push({-next, destinationVillage});
            }
        }
    }

    return maxlevel[n];
}
