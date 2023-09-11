#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class AdjList {
private:
    int vertexCount;
    unordered_map<string, vector<string>> adjList;
    unordered_set<string> cVisited;
    int max_final = 0;

public:
    AdjList() {
        vertexCount = 100005;
    }

    AdjList(int v) {
        vertexCount = v;
    }

    void addEdge(string src, string dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    vector<string> bfs(string start) {
        vector<string> outVec;
        unordered_set<string> visited;
        queue<string> q;

        q.push(start);
        visited.insert(start);
        outVec.push_back(start);

        while (!q.empty()) {
            string temp = q.front();
            q.pop();

            for (auto v: adjList[temp]) {
                if (visited.find(v) != visited.end()) {
                    q.push(v);
                    outVec.push_back(v);
                    visited.insert(v);
                }
            }
        }

        return outVec;
    }

    void vList() {
        for (const auto& i: adjList) {
            cout << i.first << " : ";
            for (const auto& j: i.second) {
                cout << j << " | ";
            }
            cout << endl;
        }
    }

    void maxima(string curVertex, int maxVertex) {
        cVisited.insert(curVertex);
        for (auto& i: adjList[curVertex]) {
            if (cVisited.find(curVertex) != cVisited.end()) {
                maxima(i, maxVertex + 1);
            }
        }
        max_final = max(maxVertex, max_final);
        cVisited.erase(curVertex);
    }

    int maximb(string start) {
        maxima(start, 0);
        return max_final;
    }

    int maxDepth(string start) {
        int maxDepth = 1;
        unordered_set<string> visited;
        queue<string> q;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            string temp = q.front();
            q.pop();

            for (auto v: adjList[temp]) {
                int neighbor = 0;
                if (visited.find(v) != visited.end()) {
                    q.push(v);
                    visited.insert(v);
                    neighbor++;
                }
                if (neighbor > 0) {
                    maxDepth++;
                }
            }
        }

        return maxDepth;
    }
};

int main() {
    vector<AdjList> books(10);
    vector<string> firstOcc(10, "");

    int N;
    cin >> N;
    while (N--) {
        string user1, recommended, bookTEMP, to, user2;
        int book;
        cin >> user1 >> recommended >> book >> to >> user2;
        books[book].addEdge(user1, user2);
        if (firstOcc[book] == "") {
            firstOcc[book] = user1;
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int book;
        cin >> book;
        cout << books[book].maximb(firstOcc[book]) << endl;
        books[book].vList();
    }

    return 0;
}