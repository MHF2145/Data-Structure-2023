#include <bits/stdc++.h>
using namespace std;

string arr[101];
int n, m;

void bfs(int x, int y, int& flag, int vis[101][101]) {
    if(x < 0 || y < 0 || x >= n || y >= m) {
        flag = 1;
        return;
    }

    if(!vis[x][y]) {
        vis[x][y] = 1;

        if(arr[x][y] == 'X') return;
        if(arr[x][y] == '^') {
            flag = 1;
            return;
        }

        bfs(x - 1, y, flag, vis);
        bfs(x, y - 1, flag, vis);
        bfs(x + 1, y, flag, vis);
        bfs(x, y + 1, flag, vis);
    }
}

void solve(int x, int y) {
    int vis[101][101] = {0};
    int flag = 0;
    bfs(x, y, flag, vis);

    if(!flag) arr[x][y] = 'X';
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> arr[i];

    pair<int, int> temp[101 * 101];
    int idx = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 'O') temp[idx++] = make_pair(i, j);
        }
    }

    for(int i = 0; i < idx; i++) solve(temp[i].first, temp[i].second);
    for(int i = 0; i < n; i++) cout << arr[i] << endl;

    return 0;
}