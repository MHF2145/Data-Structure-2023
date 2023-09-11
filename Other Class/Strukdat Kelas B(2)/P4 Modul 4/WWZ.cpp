#include <bits/stdc++.h>
using namespace std;

// template <int count>
class AdjList {
private:
    int vertexCount;
    vector<vector<pair<int, int>>> adjList;

public:
    AdjList(int v) {
        adjList.resize(v);
        vertexCount = v;
    }

    void addEdge(int src, int dest, int weight = 1) {
        adjList[src].push_back(make_pair(dest, weight));
        adjList[dest].push_back(make_pair(src, weight));
    }

    int bfs(int start) {
        int days = 0;
        vector<bool> visited(vertexCount, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;        

        while (!q.empty()) {
            int temp = q.front();
            q.pop();

            int neighbor = 0;
            for (auto v: adjList[temp]) {
                if (!visited[v.first]) {
                    q.push(v.first);
                    visited[v.first] = true;
                    // cout << v.first << " ";
                    neighbor++;
                }
            }
            if (neighbor > 0) {
                days += (int)log2(neighbor) + 1 + neighbor;
                // cout << endl;
                // cout << "Node " << temp << ": " << (int)log2(neighbor) + 1 + neighbor << endl;
            }
        }

        return days;
    }
};

int main() {
    int N;
    cin >> N;
    AdjList node(N+5);

    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        node.addEdge(a, b);
    }

    cout << node.bfs(1) << endl;

    return 0;
} 