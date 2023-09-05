#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct Node {
    int row;
    int col;
    int distance;
};

// Ngecek batas matriks / array
bool isPossible(int row, int col, int n, int m) {
    return (row >= 0 && row < n && col >= 0 && col < m);
}

void solve_ShortestPath(vector<vector<int>>& arr, int n, int m) {
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX)); // Initialize dist to maximum value
    queue<Node> q;

    // Mengecek pixel hitam . langsung taruh 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                q.push({i, j, 0});
                dist[i][j] = 0;
            }
        }
    }

    // Perform BFS
    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        int Rows, Cols;

        for (int i = 0; i < 4; i++) {
            if (i == 0) {
                Rows = curr.row - 1; // Up
                Cols = curr.col;
            } else if (i == 1) {
                Rows = curr.row + 1; // Down
                Cols = curr.col;
            } else if (i == 2) {
                Rows = curr.row;
                Cols = curr.col - 1; // Left
            } else {
                Rows = curr.row;
                Cols = curr.col + 1; // Right
            }

            if (isPossible(Rows, Cols, n, m) && dist[Rows][Cols] == INT_MAX) {
                dist[Rows][Cols] = curr.distance + 1;
                q.push({Rows, Cols, curr.distance + 1});
            }
        }
    }

    // Print hasil dari array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {

    int testCase;
    cin >> testCase;

    int n, m;
    char c;

    while (testCase--) {
        cin >> n >> m;
        vector < vector < int >> arr(n, vector < int > (m));

        vector < pair < int, int >> v;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> c;
                arr[i][j] = int(c) - int('0');
                if (arr[i][j] == 1) {
                    v.push_back(make_pair(i, j));
                }
            }
        }

         solve_ShortestPath(arr, n, m);

    }

    return 0;
}