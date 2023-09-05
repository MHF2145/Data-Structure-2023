#include <bits/stdc++.h>
using namespace std;

int n, m;
bool arr[101][101];

void solve(map<pair<int, int>, bool>& treasure, int i, int j, char Map[101][101]) {
    if (Map[i][j] != 'X' && !arr[i][j] && i >= 0 && j >= 0 && i < n && j < m) {
        arr[i][j] = true;
        if (!treasure[{i, j}] && Map[i][j] == 'O') {
            treasure[{i, j}] = true;
        }
        solve(treasure, i + 1, j, Map);
        solve(treasure, i - 1, j, Map);
        solve(treasure, i, j + 1, Map);
        solve(treasure, i, j - 1, Map);
    }
}

int main() {
    cin >> n >> m;
    char Map[101][101];
    map<pair<int, int>, bool> treasure;
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == 'O') {
                treasure[{i, j}] = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && (Map[i][j] == '*' || Map[i][j] == 'O' || Map[i][j] == '^')) {
                solve(treasure, i, j, Map);
            } else if (Map[i][j] == '^') {
                solve(treasure, i, j, Map);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (Map[i][j] == 'O' && !treasure[{i, j}]) {
                cout << 'X';
            } else {
                cout << Map[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
