#include <iostream>
#include <vector>

using namespace std;

void ScanPulau(vector<vector<int>>& grid, int row, int col) 
{
    int numRows = grid.size();
    int numCols = grid[0].size();

    if (row < 0 || row >= numRows || col < 0 || col >= numCols || grid[row][col] != 1) 
	{
        return;
    }

    grid[row][col] = -1;


    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) 
	{
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        ScanPulau(grid, newRow, newCol);	//Recursive
    }
}

int Penghitung(vector<vector<int>>& grid) 
{
    int numRows = grid.size();
    int numCols = grid[0].size();
    int count = 0;

    for (int i = 0; i < numRows; i++) 
	{
        for (int j = 0; j < numCols; j++) 
		{
            if (grid[i][j] == 1) 
			{
                ScanPulau(grid, i, j);
                count++;
            }
        }
    }

    return count;
}

int main() 
{
    vector <vector<int>> grid(10, vector<int>(10));

    for (int i = 0; i < 10; i++) 
	{
        for (int j = 0; j < 10; j++) 
		{
            cin >> grid[i][j];
        }
    }

    int JumlahPulau = Penghitung(grid);

    cout << JumlahPulau << endl;

    return 0;
}

