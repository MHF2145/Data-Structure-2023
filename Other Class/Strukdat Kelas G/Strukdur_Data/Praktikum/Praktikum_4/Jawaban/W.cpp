#include <iostream>
using namespace std;

int dfs(int x, int y, int adj[][28], int N);

int main()
{
    int n;
    cin >> n;
    char a;
    int peta[n][28];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            if (a == '.')
            {
                peta[i][j] = 0;
            }
            else if (a == '#')
            {
                peta[i][j] = 1;
            }
            else
            {
                peta[i][j] = 2;
            }
        }
    }
    int total_jalan = dfs(0, 0, peta, n);

    cout << total_jalan << endl;
    return 0;
}

int dfs(int x, int y, int adj[][28], int N)
{
    if (adj[x][y] == 1 || y < 0 || y >= N || x < 0 || x >= N)
    {
        return 0;
    }

    if (adj[x][y] == 2)
    {
        return 1;
    }

    adj[x][y] = 1;

    int jalan = dfs(x + 1, y, adj, N) + dfs(x - 1, y, adj, N) + dfs(x, y + 1, adj, N) + dfs(x, y - 1, adj, N);

    adj[x][y] = 0;

    return jalan;
}