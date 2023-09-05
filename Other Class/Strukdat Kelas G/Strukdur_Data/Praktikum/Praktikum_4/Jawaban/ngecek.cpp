#include <iostream>
#include <cstring>
using namespace std;

int dfs(int i, int j, int N, int adj[][30])
{
    if (i < 0 || i >= N || j < 0 || j >= N || adj[i][j] == 0)
        return 0;

    if (adj[i][j] == 2)
        return 1;

    adj[i][j] = 0;

    int path = dfs(i + 1, j, N, adj) + dfs(i - 1, j, N, adj) +
               dfs(i, j + 1, N, adj) + dfs(i, j - 1, N, adj);

    adj[i][j] = 1;

    return path;
}

int main()
{
    int N;
    char inp[2];
    cin >> N;

    int adj[30][30];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> inp;

            if (strcmp(inp, ".") == 0)
                adj[i][j] = 1;

            else if (strcmp(inp, "#") == 0)
                adj[i][j] = 0;

            else if (strcmp(inp, "A") == 0)
                adj[i][j] = 2;
        }
    }

    int path = dfs(0, 0, N, adj);
    cout << path << endl;

    return 0;
}