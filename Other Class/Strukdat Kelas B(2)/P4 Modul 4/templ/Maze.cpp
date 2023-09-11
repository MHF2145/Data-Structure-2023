#include <bits/stdc++.h>
using namespace std;

int N, M;
int maze[105][105];
int dist[105][105];
int px[4] = {1, -1, 0, 0};
int py[4] = {0, 0, -1, 1};

queue<pair<int, int>> q;

int bfs(int a, int b) {
	q.push(make_pair(a, b));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == 0 || y == 0 || x == N-1 || y == M-1) {
			return dist[x][y];
		}
		for (int i = 0; i < 4; i++) {
			int xx = px[i]+x;
			int yy = py[i]+y;
			if (dist[xx][yy] != -1 || maze[xx][yy] == -1) continue;
			dist[xx][yy] = dist[x][y]+1;
			q.push(make_pair(xx, yy));
		}
	}
	return -1;
}

int main() {
	cin >> N >> M;
	memset(maze, -1, sizeof maze);
	memset(dist, -1, sizeof dist);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maze[i][j];
		}
	}
	
	int a, b;
	cin >> a >> b;
	dist[--a][--b] = 1;
	cout << bfs(a, b) << endl;
	return 0;
}