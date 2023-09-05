#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool isPossible(vector<vector<int>> &arr, vector<vector<bool>> &visited, int x, int y)
{
    auto xx = vector<int>::size_type(x);
    auto yy = vector<int>::size_type(y);

    if (xx >= 0 && xx < arr.size() && yy >= 0 && yy < arr[0].size())
    {

        if (arr[x][y] == 1)
        {
            if (!visited[x][y])
            {
                return true;
            }
        }
    }

    // The space is not safe.
    return false;
}

void shortestPath(vector<vector<int>> &arr, vector<vector<bool>> &visited,
                  int i, int j, int x, int y, int &path_count)
{
    if (i == x && j == y)
    {
        path_count++;
        return;
    }

    visited[i][j] = true;

    if (isPossible(arr, visited, i + 1, j))
    {
        shortestPath(arr, visited, i + 1, j, x, y, path_count);
    }
    if (isPossible(arr, visited, i, j + 1))
    {
        shortestPath(arr, visited, i, j + 1, x, y, path_count);
    }
    if (isPossible(arr, visited, i - 1, j))
    {
        shortestPath(arr, visited, i - 1, j, x, y, path_count);
    }
    if (isPossible(arr, visited, i, j - 1))
    {
        shortestPath(arr, visited, i, j - 1, x, y, path_count);
    }

    visited[i][j] = false;
}

int pathLength(vector<vector<int>> &arr, pair<int, int> &asal,
               pair<int, int> &tujuan)
{
    if (arr.size() == 0 || arr[asal.first][asal.second] == 0 ||
        arr[tujuan.first][tujuan.second] == 0)
        return 0;

    int rows = arr.size();
    int colums = arr[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(colums));

    int path_count = 0;
    shortestPath(arr, visited, asal.first, asal.second, tujuan.first, tujuan.second, path_count);

    return path_count;
}

int main()
{
    int testCase;
    cin >> testCase;

    vector<vector<int>> arr(testCase, vector<int>(testCase));
    char c;
    int aa = 0, bb = 0;

    for (int i = 0; i < testCase; i++)
    {
        for (int j = 0; j < testCase; j++)
        {
            cin >> c;

            if (c == '.')
            {
                arr[i][j] = 1;
            }
            else if (c == '#')
            {
                arr[i][j] = 0;
            }
            else
            {
                aa = i;
                bb = j;
                arr[i][j] = 1;
            }
        }
    }

    pair<int, int> asal = make_pair(0, 0);

    pair<int, int> tujuan = make_pair(aa, bb);

    int path_count = pathLength(arr, asal, tujuan);

    cout << path_count << endl;

    return 0;
}
