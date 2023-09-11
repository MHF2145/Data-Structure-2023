#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

pair<int, vector<int>> bfsFindPath(vector<vector<int>>& graph, int startNode, int endNode) {
    int nodes = graph.size();
    vector<bool> visited(nodes, false);
    vector<int> parent(nodes, -1);
    int totalPath = 0;

    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        if (currentNode == endNode) {
            break;
        }

        for (int neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = currentNode;
                q.push(neighbor);
            }
        }
    }

    if (visited[endNode]) {
        vector<int> path;
        int currentNode = endNode;
        while (currentNode != startNode) {
            path.push_back(currentNode);
            currentNode = parent[currentNode];
            totalPath++;
        }
        path.push_back(startNode);
        reverse(path.begin(), path.end());
        return make_pair(totalPath, path);
    }

    return make_pair(-1, vector<int>());
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> graph(nodes + 1);

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int startNode = 1, endNode = nodes;

    pair<int, vector<int>> result = bfsFindPath(graph, startNode, endNode);

    if (result.first != -1) {
        cout << result.first + 1 << endl;
        for (auto it = result.second.begin(); it != result.second.end(); ++it) {
            int node = *it;
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "RIP LAPET 2023" << endl;
    }

    return 0;
}
