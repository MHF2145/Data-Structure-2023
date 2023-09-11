#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//cek linked list ato bukan
bool isLinkedList(const vector<vector<int>>& graph) {
    for (const auto& edges : graph) {
        //vertex lbeih dari 2 edge, bukan linked list
        if (edges.size() != 1 && edges.size() != 2) {
            return false;
        }
    }
    return true;
}

//cek tree ato bukan
bool isTree(const vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    vector<int> parent(numVertices, -1);
    queue<int> q;

    // BFS cek cycle apakah berhubungan ato ga
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            } else if (parent[node] != neighbor) {
                return false;  // Cycle berhubungan, berarti ini graph
            }
        }
    }

    // Check jika semua node dah divisit
    for (bool v : visited) {
        if (!v) {
            return false;  // Graph ga berhubungan, berarti ini tree
        }
    }

    return true;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int E, V;
        cin >> V >> E;
        vector<vector<int>> graph(V);
        for (int j = 0; j < E; j++) {
            int a, b;
            cin >> a >> b;
            //indexing mulai dari 0 buat bantu bikin edges
            graph[a - 1].push_back(b - 1);
            graph[b - 1].push_back(a - 1);
        }
        if (isLinkedList(graph)) {
            cout << "hewan" << endl;
        } else if (isTree(graph)) {
            cout << "pohon" << endl;
        } else {
            cout << "bukan keduanya" << endl;
        }
    }
    return 0;
}
