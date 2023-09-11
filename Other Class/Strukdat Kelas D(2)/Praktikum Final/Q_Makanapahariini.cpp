#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> i;
typedef vector<i> ii;
typedef vector<int> iii;

vector<ii> AdjList;
iii dist;

void dijkstra(int value) 
{
    dist.assign(AdjList.size(), INT_MAX);
    dist[value] = 0;
    priority_queue< i, vector<i>, greater<i> > pq;
    pq.push(i(0, value));

    while (!pq.empty()) 
	{
        i front = pq.top(); pq.pop();
        int d = front.first;
		int u = front.second;
        if (d == dist[u])
            for (int j = 0; j < (int)AdjList[u].size(); j++) 
			{
                i v = AdjList[u][j];
                if (dist[u] + v.second < dist[v.first]) 
				{
                    dist[v.first] = dist[u] + v.second;
                    pq.push(i(dist[v.first], v.first));
                }
            }
    }
}

int main() 
{
    int v, e, d;
    cin >> v;
    vector<pair<string, int>> vec;
    AdjList.assign(v + 1, ii());

    for (int i = 1; i <= v; i++) 
	{
        string s; int p;
        cin >> s >> p;
        vec.push_back(make_pair(s, p));
    }

    cin >> e;
    for (int j = 0; j < e; j++) 
	{
        int u, v, w;
        cin >> u >> v >> w;
        AdjList[u].push_back(i(v, w));
        AdjList[v].push_back(i(u, w));
    }

    cin >> d;
    dijkstra(0);

    int minPe = INT_MAX;
    string result;

    for (int i = 1; i <= v; i++) 
	{
        if (dist[i] <= d && vec[i-1].second < minPe)
		 {
            minPe = vec[i-1].second;
            result = vec[i-1].first;
        }
    }

    cout << "hari ini makan di " << result << endl;

    return 0;
}
