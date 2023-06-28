#include <bits/stdc++.h>
using namespace std;

struct graph
{
    long vertexCount, edgeCount;
    vector<vector<long>> adjList;

    void init(long v)
    {
        vertexCount = v;
        edgeCount = 0;
        adjList.resize(vertexCount);
    }

    void add_edge(long vertex1, long vertex2)
    {
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1);
        edgeCount++;
    }

    void bfs(vector<bool> &visited, long start)
    {
        queue<long> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            long temp = q.front();
            q.pop();

            for (auto vertex : adjList[temp])
            {
                if (!visited[vertex])
                {
                    q.push(vertex);
                    visited[vertex] = true;
                }
            }
        }
    }

    int countComponents()
    {
        vector<bool> visited(vertexCount, false);
        int componentCount = 0;

        for (long v = 0; v < vertexCount; v++)
        {
            if (!visited[v])
            {
                bfs(visited, v);
                componentCount++;
            }
        }

        return componentCount - 1; // Jumlah edge = jumlah komponen - 1
    }
};

int main()
{
    long V, N;
    cin >> V >> N;

    graph g;
    g.init(V);

    for (int i = 0; i < N; i++)
    {
        long A, B;
        cin >> A >> B;
        g.add_edge(A - 1, B - 1); // Mengubah vertex dari 1-indexed menjadi 0-indexed
    }

    int edgeCount = g.countComponents();
    cout << edgeCount << endl;

    return 0;
}
