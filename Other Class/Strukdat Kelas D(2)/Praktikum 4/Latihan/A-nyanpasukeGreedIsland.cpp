#include <iostream>
#include <vector>

using namespace std;

void exploreIsland(vector<vector<int>>& grid, int row, int col) {
    int numRows = grid.size();
    int numCols = grid[0].size();

    // Check if the current cell is within the grid and is part of the island
    if (row < 0 || row >= numRows || col < 0 || col >= numCols || grid[row][col] != 1) {
        return;
    }

    // Mark current cell as visited
    grid[row][col] = -1;

    // Check all 4 directions
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        exploreIsland(grid, newRow, newCol);
    }
}

int countIslands(vector<vector<int>>& grid) {
    int numRows = grid.size();
    int numCols = grid[0].size();
    int count = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            // If a land cell is found, explore the island
            if (grid[i][j] == 1) {
                exploreIsland(grid, i, j);
                count++;
            }
        }
    }

    return count;
}

int main() {
    vector<vector<int>> grid(10, vector<int>(10));

    // Input matrix
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> grid[i][j];
        }
    }

    int islandCount = countIslands(grid);

    cout << islandCount << endl;

    return 0;
}

