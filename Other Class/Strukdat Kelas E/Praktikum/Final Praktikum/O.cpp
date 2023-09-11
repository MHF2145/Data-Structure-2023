#include <iostream>
#include <vector>
using namespace std;

void parkirantw(vector<vector<int>>& matrix, int x, int y, int n) {
    int N = matrix.size();
    if (x < 0 || x >= N || y < 0 || y >= N) {
        return;
    }
    if (matrix[x][y] > 0 && matrix[x][y] < n){
        return;
    }
    

    matrix[x][y] = n;

    parkirantw(matrix, x + 1, y, n);
    parkirantw(matrix, x - 1, y, n);
    parkirantw(matrix, x, y + 1, n);
    parkirantw(matrix, x, y - 1, n);
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> matrix(N, vector<int>(N, 0));

    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> Y >> X;
        matrix[X - 1][Y - 1] = 1;
    }

    int treasureCount = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1) {
                parkirantw(matrix, i, j, ++treasureCount);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == treasureCount - 1) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int n = 2; n <= 4; n++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == 0) {
                    if ((i + 1 < N && matrix[i + 1][j] == n - 1) ||
                        (i - 1 >= 0 && matrix[i - 1][j] == n - 1) ||
                        (j + 1 < N && matrix[i][j + 1] == n - 1) ||
                        (j - 1 >= 0 && matrix[i][j - 1] == n - 1)) {
                        matrix[i][j] = n;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}