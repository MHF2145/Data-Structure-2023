#include <bits/stdc++.h>
using namespace std;
const string matrix[9] = {"A1", "B1", "C1",
                          "A2", "B2", "C2",
                          "A3", "B3", "C3"};

int main()
{
    map<string, int> mp;
    for (int i = 0; i < 9; i++)
    {
        mp[matrix[i]] = i;
    }

    int t;
    cin >> t;

    vector<int> v[9];
    for (int i = 0; i < t; i++)
    {
        string a, unused, b;
        cin >> a >> unused >> b;
        v[mp[a]].push_back(mp[b]);
        v[mp[b]].push_back(mp[a]);
    }

    int count = 0;
    vector<bool> vis(9, false);
    function<void(int)> dfs = [&](int cur)
    {
        count++;
        vis[cur] = true;
        for (int i = 0; i < v[cur].size(); i++)
        {
            int nxt = v[cur][i];
            if (!vis[nxt])
            {
                dfs(nxt);
            }
        }
    };

    int cnt = 0;
    map<int, int> node;
    for (int i = 0; i < 9; i++)
    {
        if (!vis[i])
        {
            count = 0;
            dfs(i);
            node[cnt++] = count;
        }
    }

    int ans = 0;
    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            ans += node[i] * node[j];
        }
    }
    cout << ans << '\n';
    return 0;
}