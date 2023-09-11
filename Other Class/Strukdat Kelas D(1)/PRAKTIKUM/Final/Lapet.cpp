#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> findPath(int n, int e, const vector<pair<int, int>>& edges);
void printPath(const vector<int>& path);

int main() {
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> edges(e);
    for (int i = 0; i < e; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<int> path = findPath(n, e, edges);

    if (path.empty()) {
        cout << "RIP LAPET 2023" << endl;
    } else {
        cout << path.size() << endl;
        printPath(path);
    }

    return 0;
}

vector<int> findPath(int n, int e, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < e; i++) {
        int a = edges[i].first;
        int b = edges[i].second;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    vector<int> path;

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == n) {
            int node = n;
            while (node != -1) {
                path.push_back(node);
                node = parent[node];
            }
            reverse(path.begin(), path.end());
            break;
        }

        for (int next : adjList[current]) {
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = current;
                q.push(next);
            }
        }
    }

    return path;
}

void printPath(const vector<int>& path) {
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i != path.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}
