#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int Ruteaman(int n, int m, vector<vector<pair<int, int>>>& adjacencyList) 
{
    vector<int> minDanger(n, INT_MAX);
    minDanger[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) 
	{
        int u = pq.top().second;
        int uDanger = pq.top().first;
        pq.pop();

        if (uDanger > minDanger[u]) 
		{
            continue;
        }

        for (pair<int, int> edge : adjacencyList[u]) 
		{
            int v = edge.first;
            int danger = edge.second;

            if (minDanger[v] > max(minDanger[u], danger)) 
			{
                minDanger[v] = max(minDanger[u], danger);
                pq.push(make_pair(minDanger[v], v));
            }
        }
    }

    return minDanger[n - 1];
}

int main() 
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adjacencyList(n);

    for (int i = 0; i < m; i++) 
	{
        int a, b, c;
        cin >> a >> b >> c;

        adjacencyList[a - 1].push_back(make_pair(b - 1, c));
        adjacencyList[b - 1].push_back(make_pair(a - 1, c));
    }

    int rutefix = Ruteaman(n, m, adjacencyList);
    cout << rutefix << endl;

    return 0;
}

