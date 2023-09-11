#include <iostream>
#include <vector>
#include <map>
using namespace std;


string arr[101];
int M, N;

void BFS(int x, int y, int& flag, int visited[101][101]) 
{
    if (x < 0 || y < 0 || x >= M || y >= N) 
	{
        flag = 1;
        return;
    }

    if (!visited[x][y]) 
	{
        visited[x][y] = 1;

        if (arr[x][y] == 'X') 
        {
        	return;
		}
		
        if (arr[x][y] == '^') 
		{
            flag = 1;
            return;
        }

        BFS(x - 1, y, flag, visited);
        BFS(x, y - 1, flag, visited);
        BFS(x + 1, y, flag, visited);
        BFS(x, y + 1, flag, visited);
    }
}

int main() 
{
    cin >> M >> N;

	 for (int i = 0; i < M; i++)
	  {
	  	cin >> arr[i];
	  }
	  
    pair<int, int> maptemp[101 * 101];
    int index = 0;

    for (int i = 0; i < M; i++) 
	{
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 'O') maptemp[index++] = make_pair(i, j);
        }
    }

    for (int i = 0; i < index; i++) 
	{
        int x = maptemp[i].first;
        int y = maptemp[i].second;

        int visited[101][101] = {0};
        int flag = 0;

        BFS(x, y, flag, visited);

        if (!flag) arr[x][y] = 'X';
    }

    for (int i = 0; i < M; i++) 
	{
		cout << arr[i] << endl;
	}

    return 0;
}

