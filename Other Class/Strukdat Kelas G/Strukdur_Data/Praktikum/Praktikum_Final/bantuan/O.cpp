#include <bits/stdc++.h>
using namespace std;

using iii = pair<pair<int, int>, int>;

const int dr[] = {-1, 0, 0, 1};
const int dc[] = {0, -1, 1, 0};

void solve()
{
    int n, m;
    cin >> n >> m;

    queue<iii> Q;
    vector<vector<int>> dist(n, vector<int>(n, int(1e9)));

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Q.push({{--b, --a}, 1});
        dist[b][a] = 1;
    }

    while (Q.size())
    {
        iii curr = Q.front();
        Q.pop();
        int c = curr.first.first;
        int r = curr.first.second;
        int d = curr.second;
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 <= nr && nr < n && 0 <= nc && nc < n)
            {
                if (d + 1 < dist[nc][nr])
                {
                    dist[nc][nr] = d + 1;
                    if (d + 1 < 4)
                    {
                        Q.push({{nc, nr}, d + 1});
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (dist[i][j] == int(1e9) ? 0 : dist[i][j]) << (j == n - 1 ? "\n" : " ");
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}