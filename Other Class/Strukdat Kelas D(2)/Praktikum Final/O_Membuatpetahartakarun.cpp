#include <bits/stdc++.h>
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;

vector<vector<int>> treasuremap;

void dfs(int x, int y, int count) 
{
    int n = treasuremap.size();
    if (count > 4 || x >= n || x < 0 || y >= n || y < 0)
    {
    	return;
	}
        
    if (treasuremap[x][y] == 0)
    {
    	treasuremap[x][y] = count;
	}
        
    else if (treasuremap[x][y] == 1)
    {
    	return;
	}
        
    else if (treasuremap[x][y] != 0 && treasuremap[x][y] > count)
    {
    	treasuremap[x][y] = count;
	}
        
    for (int i = 0; i < 4; i++) 
	{
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(nx, ny, count + 1);
    }
}

int main() 
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> map;
    for (int i = 0; i < m; i++) 
	{
        int x, y;
        cin >> x >> y;
        map.push_back({x, y});
    }

    treasuremap.assign(n, vector<int>(n, 0));
    for (auto l : map)
    {
    	dfs(l.second - 1, l.first - 1, 1);
	}
        
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
		{
            cout << treasuremap[i][j] << " \n"[j == n - 1];
        }
    }
    return 0;
}
