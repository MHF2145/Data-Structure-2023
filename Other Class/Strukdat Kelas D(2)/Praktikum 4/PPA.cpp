#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Koordinat // Nyimpen koordinat X dan Y dalam Matriks 
{
    int x;
    int y;
};

int DeteksiAreaTergenang // Mendeteksi luas area tergenang pada matriks ketinggian suatu area 
(vector<vector<int>>& heights, int startX, int startY) 
{
    int numRows = heights.size();
    int numCols = heights[0].size();
    int AreaGenangan = 0;
    
    vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));
    queue<Koordinat> q;
    
    q.push({startX, startY});
    visited[startX][startY] = true;
    
    while (!q.empty()) 
	{
        Koordinat curr = q.front();
        q.pop();
        
        int currX = curr.x;
        int currY = curr.y;
        
        AreaGenangan++;
        
        if (currX - 1 >= 0 && !visited[currX - 1][currY] && heights[currX - 1][currY] <= heights[currX][currY]) 
		{
            q.push({currX - 1, currY});
            visited[currX - 1][currY] = true;
        }
        
        if (currX + 1 < numRows && !visited[currX + 1][currY] && heights[currX + 1][currY] <= heights[currX][currY]) 
		{
            q.push({currX + 1, currY});
            visited[currX + 1][currY] = true;
        }
        
        if (currY - 1 >= 0 && !visited[currX][currY - 1] && heights[currX][currY - 1] <= heights[currX][currY]) 
		{
            q.push({currX, currY - 1});
            visited[currX][currY - 1] = true;
        }
        
        if (currY + 1 < numCols && !visited[currX][currY + 1] && heights[currX][currY + 1] <= heights[currX][currY]) 
		{
            q.push({currX, currY + 1});
            visited[currX][currY + 1] = true;
        }
    }
    
    return AreaGenangan;
}

int main() 
{
    int N, M, startX, startY;
    cin >> N >> M >> startX >> startY;
    
    vector<vector<int>> heights(N, vector<int>(M));
    
    for (int i = 0; i < N; i++) 
	{
        for (int j = 0; j < M; j++) 
		{
            cin >> heights[i][j];
        }
    }
    
    int total = DeteksiAreaTergenang(heights, startX - 1, startY - 1);
    cout << total << endl;
    
    return 0;
}

