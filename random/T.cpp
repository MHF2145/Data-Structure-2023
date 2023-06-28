#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];
int parent[MAXN];

void BFS(int start, int end) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < adj[current].size(); i++) {
            int next = adj[current][i];
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = current;
                q.push(next);
                if (next == end)
                    return;
            }
        }
    }
}

void printPath(int end) {
    vector<int> path;
    int current = end;
    while (current != 0) {
        path.push_back(current);
        current = parent[current];
    }

    cout << path.size() << endl;
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    cout << endl;
}

int main() {
    int N, E;
    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    int start = 1, end = N;
    BFS(start, end);

    if (visited[end]) {
        printPath(end);
    } else {
        cout << "RIP LAPET 2023" << endl;
    }

    return 0;
}
