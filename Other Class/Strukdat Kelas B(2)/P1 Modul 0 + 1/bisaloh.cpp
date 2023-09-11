#include <iostream>

using namespace std;
int main() {
    int N;
    cin >> N;

    int arr[11][11];
    bool visited[11][11];
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
            cin >> arr[i][j];
        }
    }

    int x = 0, y = 0;
    while (count < N*N) {
        // kiri ke kanan
        for (int i = 0; i < N; i++) {
            if (!visited[y][i]) {
                visited[y][i] = true;
                cout << arr[y][i] << " ";
                count++;
            }
        }
        y++;

        // atas ke bawah
        for (int i = 0; i < N; i++) {
            if (!visited[i][N-x-1]) {
                visited[i][N-x-1] = true;
                cout << arr[i][N-x-1] << " ";
                count++;
            }
        }
        x++;

        // kanan ke kiri
        for (int i = N-1; i >= 0; i--) {
            if (!visited[N-y][i]) {
                visited[N-y][i] = true;
                cout << arr[N-y][i] << " ";
                count++;
            }
        }

        // bawah ke atas
        for (int i = N-1; i >= 0; i--) {
            if (!visited[i][x-1]) {
                visited[i][x-1] = true;
                cout << arr[i][x-1] << " ";
                count++;
            }
        }

    }
    return 0;
}