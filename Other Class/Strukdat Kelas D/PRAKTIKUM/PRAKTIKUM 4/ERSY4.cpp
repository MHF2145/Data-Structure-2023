#include<bits/stdc++.h>
using namespace std;

void dfs(int arr[][10], int row, int col, bool visited[][10])
{
    visited[row][col] = true;

    int rowMoves[] = {-1, 1, 0, 0};
    int colMoves[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++)
    {
        int newRow = row + rowMoves[i];
        int newCol = col + colMoves[i];

        if (newRow >= 0 && newRow < 10 && newCol >= 0 && newCol < 10 && arr[newRow][newCol] == 1 && !visited[newRow][newCol])
        {
            dfs(arr, newRow, newCol, visited);
        }
    }
}

int count(int arr[][10])
{
    int count = 0;
    bool visited[10][10] = {
        false
    };

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == 1 && !visited[i][j])
            {
                dfs(arr, i, j, visited);
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int arr[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> arr[i][j];
        }
    }

    int island = count(arr);
    cout << island << endl;

    return 0;
}
