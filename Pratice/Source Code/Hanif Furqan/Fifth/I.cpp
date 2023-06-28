//Bismillah Ga salah lagi!!!, daritadi salah mulu
#include <bits/stdc++.h>

void solve(std::vector<std::vector<int>> &graph, int awal);

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adjList(n);

    int a, b;
    for (std::cin >> a >> b; a != -1; std::cin >> a >> b)
    {
        adjList[a].push_back(b);
    }

    int i = 0;
    while (i < n)
    {
        solve(adjList, i);
        i++;
    }

    return 0;
}


void solve(std::vector<std::vector<int>> &graph, int awal)
{
    int n = graph.size();
    std::vector<int> dist(n, -1);
    std::queue<int> q;

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
                std::cout << dist[curr] + 1 << std::endl;
                return;
            }
        }
    }
    puts("gak bisa pulang mamah");
    return;
}