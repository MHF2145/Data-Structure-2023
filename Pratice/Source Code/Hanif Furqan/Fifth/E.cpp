#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Tepian
{
    int destination;
    int dangerLevel;
};

int findMaxDangerLevel(int n, const vector<vector<Tepian>> &graph);
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<Tepian>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int maxDanger = findMaxDangerLevel(n, graph);
    cout << maxDanger << endl;

    return 0;
}


int findMaxDangerLevel(int n, const vector<vector<Tepian>> &graph)
{
    vector<int> maxDanger(n + 1, 0);
    vector<bool> visited(n + 1, false);

    priority_queue<pair<int, int>> pq;
    pq.push({0, 1}); // Mulai dari desa 1 dengan tingkat bahaya 0

    while (!pq.empty())
    {
        int village = pq.top().second;
        int dangerLevel = -pq.top().first;
        pq.pop();

        if (visited[village])
        {
            continue;
        }
        visited[village] = true;

        maxDanger[village] = dangerLevel;

        for (const Tepian &Tepian : graph[village])
        {
            int nextVillage = Tepian.destination;
            int nextDanger = max(dangerLevel, Tepian.dangerLevel);
            if (!visited[nextVillage])
            {
                pq.push({-nextDanger, nextVillage});
            }
        }
    }

    return maxDanger[n];
}