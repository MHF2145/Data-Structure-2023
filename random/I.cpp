/*Ternyata masih WA 
Bismillah ngga WA lagi*/
#include <bits/stdc++.h>

struct graph
{
    long vertexCount, edgeCount;
    std::vector<std::vector<long>> adjList;

    void init(long v)
    {
        vertexCount = v;
        edgeCount = 0;

        for (int i = 0; i < vertexCount; i++)
        {
            adjList.push_back({});
        }
    }

    void addEdge(long vertex1, long vertex2)
    {
        adjList[vertex1].push_back(vertex2);
        edgeCount++;
    }

    void bfs(long start)
    {
        std::vector<int> visited(vertexCount, 0);
        std::queue<long> q;
        bool check = false;

        q.push(start);

        while (!q.empty() && !check)
        {
            long temp = q.front();
            q.pop();

            for (auto vertex : adjList[temp])
            {
                if (!visited[vertex])
                {
                    q.push(vertex);
                    int res = visited[temp] + 1;
                    visited[vertex] = res;
                }
                else if (vertex == start)
                {
                    check = true;
                    break;
                }
            }
        }
        if (visited[start])
            std::cout << visited[start] << std::endl;
        else
            std::cout << "gak bisa pulang mamah" << std::endl;
    }
};

int main()
{
    graph g;
    int n;
    std::cin >> n;
    g.init(n);

    int a, b;
    std::cin >> a >> b;
    for (; a != -1; std::cin >> a >> b)
    {
        g.addEdge(a, b);
    }

    int i = 0;
    while (i < n)
    {
        g.bfs(i);
        i++;
    }

    return 0;
}