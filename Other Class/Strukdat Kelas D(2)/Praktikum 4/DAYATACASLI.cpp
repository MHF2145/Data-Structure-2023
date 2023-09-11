#include <iostream>
#include <queue>
using namespace std;

const int MAX = 355;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

char grid[MAX][MAX];
bool visited[MAX][MAX];
int rows, cols, queries;

int bfs(int x, int y) //Buat menghitung jumlah pieces yang terhubung dengan grid
{
	// Parameter x & y sebagai titik mula BFS
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int pieces = 0;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= rows || ny < 0 || ny >= cols)
                continue;

            if (grid[nx][ny] == '#')
                pieces++;
            else if (!visited[nx][ny])
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    return pieces;
}

int main()
{
    cin >> rows >> cols >> queries;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> grid[i][j];
        }
    }

    while (queries--)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                visited[i][j] = false;
            }
        }

        int x, y;
        cin >> x >> y;
        cout << bfs(x - 1, y - 1) << "\n";
    }

    return 0;
}

