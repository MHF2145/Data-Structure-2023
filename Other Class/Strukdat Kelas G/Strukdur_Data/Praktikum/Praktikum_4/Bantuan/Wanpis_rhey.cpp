#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<char>> &grid, int row, int col, int N)
{
    if (row < 0 || row >= N || col < 0 || col >= N || grid[row][col] == '#')
    {
        return 0;
    }
    if (grid[row][col] == 'A')
    {
        return 1;
    }
    grid[row][col] = '#';
    int totalPaths = dfs(grid, row + 1, col, N) + dfs(grid, row - 1, col, N) + dfs(grid, row, col + 1, N) + dfs(grid, row, col - 1, N);
    grid[row][col] = '.';

    return totalPaths;
}

int countPathsToBoss(vector<vector<char>> &grid, int N)
{
    return dfs(grid, 0, 0, N);
}

int main()
{
    int N;
    cin >> N;

    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }

    int totalPaths = countPathsToBoss(grid, N);
    cout << totalPaths << endl;
}