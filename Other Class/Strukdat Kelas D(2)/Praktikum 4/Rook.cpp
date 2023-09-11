#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_SIZE = 20;

struct Position //Utk posisi 
{
    int x, y;
};

//Untuk cek apakah x,y yang diperiksa masih di dalam batas peta
bool isValidPosition(int x, int y, int maxX, int maxY) 
{
    return (x >= 0 && x < maxX && y >= 0 && y < maxY);
}

vector<Position> findShortestPath(vector<vector<char>>& map, Position start, Position end) 
{
    int maxX = map[0].size();
    int maxY = map.size();

    vector<vector<bool>> visited(maxY, vector<bool>(maxX, false));
    vector<vector<Position>> parent(maxY, vector<Position>(maxX, { -1, -1 }));

    queue<Position> q;
    q.push(start);
    visited[start.y][start.x] = true;

    while (!q.empty()) 
    {
        Position curr = q.front();
        q.pop();

        int currX = curr.x;
        int currY = curr.y;

        // Cek sudah di titik akhir
        if (currX == end.x && currY == end.y) 
        {
            // Membangun jalur dari titik akhir ke titik awal menggunakan parent
            vector<Position> path;
            Position pos = end;
            while (pos.x != -1 && pos.y != -1) 
            {
                path.push_back(pos);
                pos = parent[pos.y][pos.x];
            }
            return path;
        }

        //Eksplorasi tetangga-tetangga yang belum dikunjungi
        vector<Position> neighbors = 
        {
            {currX - 1, currY},     // kiri
            {currX + 1, currY},     // kanan
            {currX, currY - 1},     // atas
            {currX, currY + 1}      // bawah
        };

        for (const auto& neighbor : neighbors) 
        {
            int neighborX = neighbor.x;
            int neighborY = neighbor.y;

            if (isValidPosition(neighborX, neighborY, maxX, maxY) &&
                map[neighborY][neighborX] != '#' && !visited[neighborY][neighborX]) 
            {
                q.push(neighbor);
                visited[neighborY][neighborX] = true;
                parent[neighborY][neighborX] = { currX, currY };
            }
        }
    }

    // Jika tidak ditemukan jalur, kembalikan jalur kosong
    return {};
}

// Fungsi mencetak map dengan jalur terpendek
void printMapWithPath(vector<vector<char>>& map, const vector<Position>& path) 
{
	 for (const auto& pos : path) 
    {
        map[pos.y][pos.x] = 'x';	//Print X utk tiap path
    }
    
    Position start = path.front();
    Position end = path.back();
    map[start.y][start.x] = 'B';	//Biar path awal print 'B'
    map[end.y][end.x] = 'A';		//Biar path akhir print 'A'
    
    for (const auto& row : map) 
    {
        for (const auto& cell : row) 
        {
            cout << cell;
        }
        cout << endl;
    }
}

int main() 
{
    int X, Y;
    cin >> X >> Y;

    vector<vector<char>> map(Y, vector<char>(X));

    for (int i = 0; i < Y; i++) 
    {
        for (int j = 0; j < X; j++) 
        {
            cin >> map[i][j];
        }
    }

    Position start, end;

    for (int i = 0; i < Y; i++) 
    {
        for (int j = 0; j < X; j++) 
        {
            if (map[i][j] == 'A') 
			{
                start = { j, i };
            } 
			else if (map[i][j] == 'B') 
			{
                end = { j, i };
            }
        }
    }

    vector<Position> path = findShortestPath(map, start, end);

    printMapWithPath(map, path);

    return 0;
}

