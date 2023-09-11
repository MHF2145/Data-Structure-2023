#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    x--;
    y--;

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int area = 1;
    int rowMoves[] = {-1, 1, 0, 0};
    int colMoves[] = {0, 0, -1, 1};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + rowMoves[i];
            int newCol = col + colMoves[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
            {
                if (a[newRow][newCol] <= a[row][col] && !visited[newRow][newCol])
                {
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                    area++;
                }
            }
        }
    }

    cout << area << endl;
    return 0;
}
