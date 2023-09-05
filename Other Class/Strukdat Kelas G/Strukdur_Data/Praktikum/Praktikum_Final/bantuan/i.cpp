#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& adjList, int start, int N) {
    vector<bool> visited(N, false);
    vector<int> steps(N, -1);

    queue<int> q;
    q.push(start);
    visited[start] = true;
    steps[start] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : adjList[curr]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                steps[next] = steps[curr] + 1;
            } else if (next == start) {
                return steps[curr] + 1;
            }
        }
    }

    return -1;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> adjList(N);

    int from, to;
    while (cin >> from >> to && (from != -1 || to != -1)) {
        adjList[from].push_back(to);
    }

    for (int i = 0; i < N; i++) {
        int steps = bfs(adjList, i, N);
        if (steps == -1) {
            cout << "gak bisa pulang mamah" << endl;
        } else {
            cout << steps << endl;
        }
    }

    return 0;
}
