#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> bfs(int start, int end, vector<vector<int>>& adjList, int n)
{
    vector<bool> visited(n, false);
    queue<pair<int, int>> q;

    q.push(make_pair(start, 0));

    while (!q.empty())
    {
        int temp = q.front().first;
        int dis = q.front().second;
        q.pop();

        for (auto it : adjList[temp])
        {
            if (!visited[it])
            {
                q.push({it, dis + 1});
                visited[it] = true;
                if (it == end)
                {
                    return vector<int>{dis + 1};
                }
            }
        }
    }
    return vector<int>{0};
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> adjList(N);

    int u, v;
    while (true)
    {
        cin >> u >> v;
        if (u == -1 && v == -1)
            break;
        adjList[u].push_back(v);
    }

    for (int i = 0; i < N; i++)
    {
        vector<int> distances = bfs(i, i, adjList, N);
        if (distances[0] == 0)
            cout << "gak bisa pulang mamah" << endl;
        else
            cout << distances[0] << endl;
    }

    return 0;
}

