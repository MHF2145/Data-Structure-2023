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

    vector<int> dfs(int start) {
        vector<int> outVec;
        vector<bool> visited(vertexCount, false);
        stack<int> st;
        
        st.push(start);
        visited[start] = true;
        outVec.push_back(start);

        while (!st.empty()) {
            int temp = st.top();
            st.pop();

            if (!visited[temp]) {
                outVec.push_back(temp);
                visited[temp] = true;
            }

            for (auto v: adjList[temp]) {
                if (!visited[v.first]) {
                    st.push(v.first);
                }
            }
        }

        return outVec;
    }

    vector<int> bfs(int start) {
        vector<int> outVec;
        vector<bool> visited(vertexCount, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;
        outVec.push_back(start);

        while (!q.empty()) {
            int temp = q.front();
            q.pop();

            for (auto v: adjList[temp]) {
                if (!visited[v.first]) {
                    q.push(v.first);
                    outVec.push_back(v.first);
                    visited[v.first] = true;
                }
            }
        }

        return outVec;
    }
};

int main() {
    // NOTE: first node is 0, if node is 1 2 3 4 5, then size should be 6 (accounting for the 0)
    AdjList a(6);
    a.addEdge(1, 2);
    a.addEdge(1, 3);
    a.addEdge(1, 4);
    a.addEdge(4, 5);

    vector<int> dfs = a.dfs(1);
    vector<int> bfs = a.bfs(1);

    for (auto i: dfs) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i: bfs) {
        cout << i << " ";
    }

    return 0;
}