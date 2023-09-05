#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
vector<int> parent;

void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int N, E;
    cin >> N >> E;

    adj.resize(N + 1);
    visited.resize(N + 1, false);
    parent.resize(N + 1, -1);

    for (int i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    bfs(1);

    if (visited[N]) {
        vector<int> path;
        for (int v = N; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;   
    } else {
        cout << "RIP LAPET 2023" << endl;
    }

    return 0;
}
