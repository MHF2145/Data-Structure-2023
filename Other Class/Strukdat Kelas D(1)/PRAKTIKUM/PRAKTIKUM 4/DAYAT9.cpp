#include<bits/stdc++.h>
using namespace std;

int a[] = {0, 1, 0, -1};
int b[] = {1, 0, -1, 0};

char piece[355][355];
bool check[355][355];
int P, Q, N;

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    check[x][y] = true;

    int pieces = 0;

    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + a[i];
            int ny = y + b[i];

            if (nx < 0 || nx >= P || ny < 0 || ny >= Q) continue;
            if (piece[nx][ny] == '#') pieces++;
            else if (!check[nx][ny]) {
                q.push({nx, ny});
                check[nx][ny] = true;
            }
        }
    }
    return pieces;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> P >> Q >> N;
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < Q; j++) {
            cin >> piece[i][j];
        }
    }

    while (N--) {
        memset(check, false, sizeof(check));
        int x, y;
        cin >> x >> y;
        cout << bfs(x - 1, y - 1) << "\n";
    }

    return 0;
}
